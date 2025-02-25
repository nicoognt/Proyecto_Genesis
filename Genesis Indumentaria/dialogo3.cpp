#include "dialogo3.h"
#include "CarritoDeCompras.h"
#include "Producto.h"
#include <wx/msgdlg.h>

dialogo3::dialogo3(wxWindow *parent, CarritoDeCompras *c) : d_Compras(parent), crt(c) {
	
	listaCompras->InsertColumn(0,"Producto y Detalle",wxLIST_FORMAT_LEFT,300);
	listaCompras->InsertColumn(1,"Precio Total",wxLIST_FORMAT_RIGHT,100);
	m_Vaciar->Bind(wxEVT_BUTTON, &dialogo3::OnVaciar, this);
	
	CargarProductos();
	
}

void dialogo3::CargarProductos ( ) {
	/// Borro lo que haya para actualizar en tiempo real
	listaCompras->DeleteAllItems();
	
	for(int i=0;i<crt->CantProductos();i++) { 
		
		/// Obtengo el producto y veo cómo insertarlo en la lista
		Producto a = crt->ObtenerProducto(i);
		
		if(a.VerTalleS() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "S", a.VerTalleS());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleS() * a.VerPrecio()));
			
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
		}
		if(a.VerTalleM() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "M", a.VerTalleM());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleM() * a.VerPrecio()));
			
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
		}
		if(a.VerTalleL() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "L", a.VerTalleL());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleL() * a.VerPrecio()));
			
			
			long index = listaCompras->InsertItem(i,descripcion);
			listaCompras->SetItem(index,1,precioStr);
		}
	}
	this->OnSumarPrecio();
}

dialogo3::~dialogo3() {
	
}

void dialogo3::OnComprar( wxCommandEvent& event )  {
	if(wxMessageBox("¿Confirmar compra?","Mensaje de confirmación",wxYES_NO | wxICON_QUESTION) == wxID_YES){
		crt->Vaciar();
		this->CargarProductos();
		
		wxMessageBox("La compra se realizó con éxito","Compra realizada",wxOK);
	} else {
		cout << "No está funcando bien";
	}

}

void dialogo3::OnVaciar( wxCommandEvent& event )  {
	if(wxMessageBox("¿Desea vaciar el carrito de compras?","Confirmación",wxYES_NO | wxICON_QUESTION) == wxID_YES){
		crt->Vaciar();
		
		listaCompras->DeleteAllItems();
		listaCompras->Refresh();
		listaCompras->Update();
		
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

