#include "dialogo8.h"
#include "Producto.h"
#include <wx/string.h>

dialogo8::dialogo8(wxWindow *parent,vector<Producto> a) : d_DetalleVenta(parent), productosVendidos(a) {
	
	listaDetalles->InsertColumn(0,"Productos vendidos:",wxLIST_FORMAT_CENTER,200);
	listaDetalles->InsertColumn(1,"Precio total:",wxLIST_FORMAT_CENTER,120);
	
	CargarProductos();
}
void dialogo8::CargarProductos ( ) {
	// Borro lo que haya para actualizar en tiempo real
	listaDetalles->DeleteAllItems();
	
	for(int i=0;i<productosVendidos.size();i++) { 
		
		// Obtengo el producto
		Producto a = productosVendidos[i];
		
		// Reviso el talle para agregarlo al nombre
		if(a.VerTalleS() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "S", a.VerTalleS());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleS() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
		if(a.VerTalleM() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "M", a.VerTalleM());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleM() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
		if(a.VerTalleL() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "L", a.VerTalleL());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleL() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
	}
}
void dialogo8::ClicDescargar( wxCommandEvent& event )  {
	event.Skip();
}

dialogo8::~dialogo8() {
	
}

