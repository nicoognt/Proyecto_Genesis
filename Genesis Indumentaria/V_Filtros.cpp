#include "V_Filtros.h"
#include <wx/valnum.h>
#include "Tienda.h"
#include <wx/msgdlg.h>
V_Filtros::V_Filtros(wxWindow *parent,Tienda *t) : VentanaFiltros(parent),shop(t) {
	if(!shop) wxMessageBox("Puntero de tienda no válido","Error", wxOK | wxICON_ERROR);
	
	// Validadores para los textCtrl
	wxFloatingPointValidator<double> val(2);
	m_pMax->SetValidator(val);
	m_pMin->SetValidator(val);
}

void V_Filtros::OnAceptarf( wxCommandEvent& event )  {
	// Se obtiene el numero de seleccion de los choice y se los convierte en wxString
	int seleccionGenero = choiceGenero->GetSelection();
	wxString generoSeleccionado = choiceGenero->GetString(seleccionGenero);
	
	int seleccionCategoria = choiceCategoria->GetSelection();
	wxString categoriaSeleccionada = choiceCategoria->GetString(seleccionCategoria);
	
	int seleccionOrden = choiceOrden->GetSelection();
	wxString ordenSeleccionado = choiceOrden->GetString(seleccionOrden);
	
	float precio_max = float(wxAtof(m_pMax->GetValue())); // Se pasa a flotante, el double obtenido de las barras de texto
	float precio_min = float(wxAtof(m_pMin->GetValue()));
	
	if(precio_max==0){ // En el caso de que el usuario no escriba precio maximo (o sea, no se ingrese), no se pondra un tope
		shop->AplicarFiltros(generoSeleccionado,categoriaSeleccionada,ordenSeleccionado,precio_min);
	} else {
		shop->AplicarFiltros(generoSeleccionado,categoriaSeleccionada,ordenSeleccionado,precio_min,precio_max);
	}
	
	
	EndModal(wxID_OK);
}

V_Filtros::~V_Filtros() {
	
}

