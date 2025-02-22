#include "dialogo.h"

d_Detalles::d_Detalles(wxWindow *parent,Producto x) : dialogo(parent) {
	a_mostrar = x;
	
	CargarDatos();
}

void d_Detalles::CargarDatos ( ) {
	barra_Nombre->SetValue(a_mostrar.VerNombre());
	barra_Categoria->SetValue(a_mostrar.VerCategoria());
	barra_TalleS->SetValue(wxString::Format("%d", a_mostrar.VerTalleS()));
	barra_TalleM->SetValue(wxString::Format("%d", a_mostrar.VerTalleM()));
	barra_TalleL->SetValue(wxString::Format("%d", a_mostrar.VerTalleL()));
	barra_Precio->SetValue(wxString::Format("%.2f",a_mostrar.VerPrecio()));
}


d_Detalles::~d_Detalles() {
}

