#include "V_DetallesProd.h"

V_DetallesProd::V_DetallesProd(wxWindow *parent,Producto x) : DetallesProd(parent) {
	a_mostrar = x;
	
	CargarDatos();
}

V_DetallesProd::~V_DetallesProd() {
	
}

void V_DetallesProd::CargarDatos(){
	barra_Nombre->SetValue(a_mostrar.VerNombre());
	barra_Categoria->SetValue(a_mostrar.VerCategoria());
	barra_Genero->SetValue(a_mostrar.VerGen());
	barra_ID->SetValue(wxString::Format("%d",a_mostrar.Ver_id()));
	barra_TalleS->SetValue(wxString::Format("%d", a_mostrar.VerTalleS()));
	barra_TalleM->SetValue(wxString::Format("%d", a_mostrar.VerTalleM()));
	barra_TalleL->SetValue(wxString::Format("%d", a_mostrar.VerTalleL()));
	barra_Precio->SetValue(wxString::Format("%.2f",a_mostrar.VerPrecio()));
}

