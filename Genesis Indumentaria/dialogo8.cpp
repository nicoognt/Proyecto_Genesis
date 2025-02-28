#include "dialogo8.h"
#include "Producto.h"

dialogo8::dialogo8(wxWindow *parent,vector<Producto> a) : d_DetalleVenta(parent), productosVendidos(a) {
	
}

void dialogo8::ClicDescargar( wxCommandEvent& event )  {
	event.Skip();
}

dialogo8::~dialogo8() {
	
}

