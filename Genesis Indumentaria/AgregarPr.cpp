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
		wxMessageBox("El nombre no puede contener números u otros caracteres","Advertencia", wxOK | wxICON_ERROR);
	}
	int talleS = wxAtoi(barra_TS->GetValue()), talleM = wxAtoi(barra_TM->GetValue()), talleL = wxAtoi(barra_TL->GetValue());
	float precio = wxAtof(barra_Precio->GetValue());
	
	int id = rand()%90000+10000;
	while(genesis->EsIgual(id)){
		id = rand()%90000+10000;
	}
	
	Producto a(nombreIngresado.ToStdString(),categoriaIngresada.ToStdString(),generoIngresado.ToStdString(),talleS,talleM,talleL,id,precio);
	genesis->AgregarProducto(a);
	EndModal(wxID_OK);
}

AgregarPr::~AgregarPr() {
	
}

