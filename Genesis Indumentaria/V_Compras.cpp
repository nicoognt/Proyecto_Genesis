#include "V_Compras.h"
#include "CarritoDeCompras.h"
#include "Producto.h"
#include "V_NuevaCant.h"
#include <vector>
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include <wx/log.h>
#include <wx/menu.h>
#include "Factura.h"
#include "Tienda.h"
#include "m_ventanuli.h"

V_Compras::V_Compras(wxWindow *parent,CarritoDeCompras* c,Tienda* _t,vector<Factura>* f) : VentanaCompras(parent),crt(c),t(_t),facts(f) {
	if(!t) {
		wxMessageBox("No se recibió una tienda válida","Error", wxOK | wxICON_EXCLAMATION);
	}
	// Titulo de las columnas en el carrito de compras
	listaCompras->InsertColumn(0,"Producto y Detalle",wxLIST_FORMAT_LEFT,300);
	listaCompras->InsertColumn(1,"Precio Total",wxLIST_FORMAT_RIGHT,100);
	// Enlazo el evento del clic en el boton vaciar
	m_Vaciar->Bind(wxEVT_BUTTON, &V_Compras::OnVaciar, this);
	// Relaciono el clic derecho en la ventana
	listaCompras->Bind(wxEVT_LIST_ITEM_RIGHT_CLICK, &V_Compras::OnRightClick, this);
	CargarProductos();
}

void V_Compras::CargarProductos ( ) {
	// Borro lo que haya para actualizar en tiempo real
	listaCompras->DeleteAllItems();
	
	for(int i=0;i<crt->CantProductos();i++) { 
		
		// Obtengo el producto y veo cómo insertarlo en la lista
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

void V_Compras::OnVender( wxCommandEvent& event )  {
	// Se revisa si el carrito tiene algún producto por vender
	if (crt->CantProductos() == 0){
		wxMessageBox ("Agregue productos al carrito","Aviso"); return;
	} // En caso de que sí haya algo por vender:
	if(wxMessageBox("¿Confirmar venta?","Atención", wxYES_NO | wxICON_QUESTION) == wxYES){
		// El carrito de compras genera una factura de venta
		Factura a = crt->Vender();
		// Se consigue el metodo de pago usado y se lo agrega en la factura
		wxString metodo = choice_Metodo->GetStringSelection();
		a.setMetodoPago(metodo.ToStdString());
		// Se agrega la factura en el vector de la tienda
		facts->push_back(a);
		
		// Se limpia y actualiza la lista en la ventana
		listaCompras->DeleteAllItems();
		listaCompras->Refresh();
		listaCompras->Update();
		// Se actualiza el binario con los stocks reducidos
		t->ActualizarBinario();
		
		wxMessageBox("Se realizó la venta con éxito","Exito");
	}
}

void V_Compras::OnVaciar( wxCommandEvent& event )  {
	int respuesta = wxMessageBox("¿Desea vaciar el carrito?","Confirmación", wxYES_NO | wxICON_QUESTION);
	// Se revisa la eleccion
	if(respuesta == wxYES){ // En caso afirmativo:
		if(!t) {
			wxMessageBox("No se pudo acceder a la tienda","Error", wxOK | wxICON_ERROR);
			return;
		}
		// Se restaura el stock de cada producto en la tienda
		for (int i = 0;i<crt->CantProductos();i++){
			t->RestaurarStock(crt->ObtenerProducto(i));
		}
		
		crt->Vaciar();
		
		// Borro los productos de la lista y la refresco
		listaCompras->DeleteAllItems();
		listaCompras->Refresh();
		listaCompras->Update();
		
		// Establezco el controlador de texto en $0.00
		m_ValorPrecio->SetValue("$0.00");
	}
}

void V_Compras::OnSumarPrecio ( ) {
	// Se inicia la fila (lo que se va a iterar) en el principio de la lista con -1
	long fila = -1;
	float precioTotal = 0.0;
	
	while ((fila = listaCompras->GetNextItem(fila, wxLIST_NEXT_ALL, wxLIST_STATE_DONTCARE)) != wxNOT_FOUND) { // Mientras se pueda conseguir el item siguiente:
		wxListItem item;
		item.SetId(fila);
		item.SetColumn(1); 
		item.SetMask(wxLIST_MASK_TEXT);
		
		if (listaCompras->GetItem(item)) { // Retorna verdadero en caso de conseguir el item de la lista
			wxString precioTexto = item.GetText();
			precioTexto.Replace("$",""); // Le saco el simbolo de pesos
			
			precioTotal += wxAtof(precioTexto); // Lo convierto a flotante
		}
	}
	wxString precioStr = wxString::Format("$ %.2f", precioTotal);
	m_ValorPrecio->SetValue(precioStr);
}

void V_Compras::OnRightClick (wxListEvent & event) {
	wxMenu menu;
	m_indice = event.GetIndex();
	if(m_indice == wxNOT_FOUND) return;
	
	menu.Append(1001, "Modificar");
	menu.Append(1002, "Eliminar del carrito");
	
	// Conectar eventos a los items del menu
	Bind(wxEVT_MENU, &V_Compras::OnModificarCantidad, this, 1001);
	Bind(wxEVT_MENU, &V_Compras::OnEliminar, this, 1002);
	
	// Mostrar el menu en la posicion del cursor
	PopupMenu(&menu);
}

void V_Compras::OnModificarCantidad (wxCommandEvent & event) {
	long index = listaCompras->GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);
	if(index != -1){
		Producto* pr = crt->ObtenerProductoPtr(index);
		
		if(pr){
			V_NuevaCant* dlg = new V_NuevaCant(this,pr,t);
			dlg->ShowModal();
			dlg->Destroy();
			this->CargarProductos();
		} else wxMessageBox("Producto no válido","Error", wxOK | wxICON_ERROR);
	} else wxMessageBox("Índice no válido","Error", wxOK | wxICON_ERROR);
}

void V_Compras::OnEliminar (wxCommandEvent & event) {
	Producto pCar = crt->ObtenerProducto(m_indice); // Se obtiene el producto del carrito
	t->RestaurarStock(pCar); // Se restaura el stock del mismo en la tienda
	crt->Eliminar(pCar.Ver_id()); // Elimino el producto del carrito
	
	CargarProductos(); // Vuelvo a generar la lista
}
V_Compras::~V_Compras() {
	
}

