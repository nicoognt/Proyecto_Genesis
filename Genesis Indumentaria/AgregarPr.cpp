#include "AgregarPr.h"
#include <wx/regex.h>
#include <wx/msgdlg.h>
#include <wx/valtext.h>
#include <wx/string.h>
#include "Producto.h"
#include "Tienda.h"

AgregarPr::AgregarPr(wxWindow *parent,Tienda *t) : V_AgregarProd(parent),genesis(t) {
	wxTextValidator v(wxFILTER_NUMERIC);
	barra_Precio->SetValidator(v); barra_TL->SetValidator(v); barra_TM->SetValidator(v); barra_TS->SetValidator(v);
}

void AgregarPr::ClicAceptarPNuevo( wxCommandEvent& event )  {
	wxRegEx reg("^[a-zA-Z ]*$");
	
	wxString nombreIngresado = barra_Nom->GetValue();
	wxString categoriaIngresada = choice_Cat->GetStringSelection();
	wxString generoIngresado = choice_Gen->GetStringSelection();
	
	if (!reg.Matches(nombreIngresado)){
		wxMessageBox("El nombre no puede contener números","Advertencia", wxOK | wxICON_ERROR);
	}
	int talleS = wxAtoi(barra_TS->GetValue()), talleM = wxAtoi(barra_TM->GetValue()), talleL = wxAtoi(barra_TL->GetValue()), id = rand()%99998+1;
	float precio = wxAtof(barra_Precio->GetValue());
	if (id >= 100000 || id < 1) {
		wxMessageBox("Ingrese otro id","Error");
	}
	for(int i=0;i<genesis->CantidadProductos();i++){
		Producto t = genesis->MostrarProducto(i);
		if (t.Ver_id() == id){
			wxMessageBox("Id coincidente con otro producto, prueba con otro","Advertencia");
			return;
		}
	}
	Producto a(nombreIngresado.ToStdString(),categoriaIngresada.ToStdString(),generoIngresado.ToStdString(),talleS,talleM,talleL,id,precio);
	genesis->AgregarProducto(a);
	EndModal(wxID_OK);
}

AgregarPr::~AgregarPr() {
	
}

