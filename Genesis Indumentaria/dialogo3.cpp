#include "dialogo3.h"
#include "CarritoDeCompras.h"
#include "Producto.h"
#include <vector>
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include <wx/log.h>
#include "dialogo4.h"
#include <wx/menu.h>
#include "Factura.h"
#include "Tienda.h"
#include "m_ventanuli.h"

dialogo3::dialogo3(wxWindow *parent, CarritoDeCompras *c, Tienda *_t, vector<Factura>* f) : d_Compras(parent), crt(c), t(_t), facts(f) {
	if(!t) {
		wxMessageBox("No se recibió una tienda válida","Error", wxOK | wxICON_EXCLAMATION);
	}
	
	listaCompras->InsertColumn(0,"Producto y Detalle",wxLIST_FORMAT_LEFT,300);
	listaCompras->InsertColumn(1,"Precio Total",wxLIST_FORMAT_RIGHT,100);
	m_Vaciar->Bind(wxEVT_BUTTON, &dialogo3::OnVaciar, this);
	
	listaCompras->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &dialogo3::OnRightClick, this);
	CargarProductos();
	
}

void dialogo3::CargarProductos ( ) {
	/// Borro lo que haya para actualizar en tiempo real
	listaCompras->DeleteAllItems();
	
	for(int i=0;i<crt->CantProductos();i++) { 
		
		/// Obtengo el producto y veo cómo insertarlo en la lista
		Producto* a = crt->ObtenerProductoPtr(i);
		
		if(a && a->VerTalleS() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a->VerNombre(), "S", a->VerTalleS());
			wxString precioStr = wxString::Format(" $%.2f",(a->VerTalleS() * a->VerPrecio()));
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
			listaCompras->SetItemData(index,reinterpret_cast<wxUIntPtr>(&a));
		}
		if(a && a->VerTalleM() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a->VerNombre(), "M", a->VerTalleM());
			wxString precioStr = wxString::Format(" $%.2f",(a->VerTalleM() * a->VerPrecio()));
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
			listaCompras->SetItemData(index,reinterpret_cast<wxUIntPtr>(&a));
		}
		if(a && a->VerTalleL() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a->VerNombre(), "L", a->VerTalleL());
			wxString precioStr = wxString::Format(" $%.2f",(a->VerTalleL() * a->VerPrecio()));
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
			listaCompras->SetItemData(index,reinterpret_cast<wxUIntPtr>(&a));
		}
	}
	this->OnSumarPrecio();
}

dialogo3::~dialogo3() {
	
}

void dialogo3::OnVaciar( wxCommandEvent& event )  {
	int respuesta = wxMessageBox("¿Desea vaciar el carrito?","Confirmación", wxYES_NO | wxICON_QUESTION);
	
	if(respuesta == wxYES){
		if(!t) {
			wxMessageBox("No se pudo acceder a la tienda","Error", wxOK | wxICON_ERROR);
			return;
		}
		for (int i = 0;i<crt->CantProductos();i++){
			t->RestaurarStock(crt->ObtenerProducto(i));
		}
		
		crt->Vaciar();
		
		/// Deleteo los objetos de la lista y actualizo gráficamente
		/// la misma
		listaCompras->DeleteAllItems();
		listaCompras->Refresh();
		listaCompras->Update();
		
		/// Establezco el controlador de texto en $0.00
		m_ValorPrecio->SetValue("$0.00");
	}
}

void dialogo3::OnSumarPrecio ( ) {
	long fila = -1;
	float precioTotal = 0.0;
	
	while ((fila = listaCompras->GetNextItem(fila, wxLIST_NEXT_ALL, wxLIST_STATE_DONTCARE)) != wxNOT_FOUND) {
		wxListItem item;
		item.SetId(fila);
		item.SetColumn(1); 
		item.SetMask(wxLIST_MASK_TEXT);
		
		if (listaCompras->GetItem(item)) {
			wxString precioTexto = item.GetText();
			precioTexto.Replace("$","");
			
			precioTotal += wxAtof(precioTexto);
		}
	}
	wxString precioStr = wxString::Format("$ %.2f", precioTotal);
	m_ValorPrecio->SetValue(precioStr);
}

void dialogo3::OnRightClick (wxListEvent & event) {
	wxMenu menu;
	m_indice = event.GetIndex();
	if(m_indice == wxNOT_FOUND) return;
	
	menu.Append(1001, "Modificar");
	menu.Append(1002, "Eliminar del carrito");
	
	/// Conectar eventos a los ítems del menú
	Bind(wxEVT_MENU, &dialogo3::OnModificarCantidad, this, 1001);
	Bind(wxEVT_MENU, &dialogo3::OnEliminar, this, 1002);
	
	/// Mostrar el menú en la posición del cursor
	PopupMenu(&menu);
}

void dialogo3::OnModificarCantidad (wxCommandEvent & event) {
	long index = listaCompras->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
	if(index != -1){
		Producto* pr = crt->ObtenerProductoPtr(index);
		
		if(pr){
			dialogo4* dlg = new dialogo4(this,pr,t);
			dlg->ShowModal();
			dlg->Destroy();
			this->CargarProductos();
		} else wxMessageBox("Producto no válido","Error", wxOK | wxICON_ERROR);
	} else wxMessageBox("Índice no válido","Error", wxOK | wxICON_ERROR);
}

void dialogo3::OnEliminar (wxCommandEvent & event) {
	
	Producto pCar = crt->ObtenerProducto(m_indice);
	t->RestaurarStock(pCar);
	crt->Eliminar(pCar.Ver_id());
	
	CargarProductos();

}

void dialogo3::OnVender( wxCommandEvent& event )  {
	if(wxMessageBox("¿Confirmar venta?","Atención", wxYES_NO | wxICON_QUESTION) == wxYES){
		
		m_ventanuli* mainWin = dynamic_cast<m_ventanuli*>(GetParent());
		if (mainWin) {
			float p = (float)(wxAtof(m_ValorPrecio->GetValue()));
			mainWin->SetPrecio(p);
		}
		
		Factura a = crt->Vender();
		facts->push_back(a);
		
		listaCompras->DeleteAllItems();
		listaCompras->Refresh();
		listaCompras->Update();
		wxMessageBox("Venta realizada con éxito","Aviso", wxOK | wxICON_INFORMATION);
		
	} else cout << "Hay algo mal que anda mal";
}

