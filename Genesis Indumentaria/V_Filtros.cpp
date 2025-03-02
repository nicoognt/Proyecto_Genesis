#include "V_Filtros.h"
#include <wx/valnum.h>
#include "Tienda.h"
#include <wx/msgdlg.h>
V_Filtros::V_Filtros(wxWindow *parent,Tienda *t) : VentanaFiltros(parent),shop(t) {
	if(!shop) wxMessageBox("Puntero de tienda no válido","Error", wxOK | wxICON_ERROR);
	
	wxFloatingPointValidator<double> val(2);
	m_pMax->SetValidator(val);
	m_pMin->SetValidator(val);
}

void V_Filtros::OnAceptarf( wxCommandEvent& event )  {
	int seleccionGenero = choiceGenero->GetSelection();
	wxString generoSeleccionado = choiceGenero->GetString(seleccionGenero);
	
	int seleccionCategoria = choiceCategoria->GetSelection();
	wxString categoriaSeleccionada = choiceCategoria->GetString(seleccionCategoria);
	
	int seleccionOrden = choiceOrden->GetSelection();
	wxString ordenSeleccionado = choiceOrden->GetString(seleccionOrden);
	
	float precio_max = float(wxAtof(m_pMax->GetValue()));
	float precio_min = float(wxAtof(m_pMin->GetValue()));
	
	if(precio_max==0){
		shop->AplicarFiltros(generoSeleccionado,categoriaSeleccionada,ordenSeleccionado,precio_min);
	} else {
		shop->AplicarFiltros(generoSeleccionado,categoriaSeleccionada,ordenSeleccionado,precio_min,precio_max);
	}
	
	
	EndModal(wxID_OK);
}

V_Filtros::~V_Filtros() {
	
}

