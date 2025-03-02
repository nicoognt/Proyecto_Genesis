#include "V_NuevaCant.h"
#include "Producto.h"
#include "Tienda.h"
#include <wx/msgdlg.h>

V_NuevaCant::V_NuevaCant (wxWindow * parent, Producto * p, Tienda * _t) : Ventana_NuevaCant(parent), pr(p), t(_t) {
	Producto * pt = t->MostrarConId(pr->Ver_id());
	int talle = pr->VerTalle();
	int tope;
	string letra_talle;
	switch (talle){
	case 1:
		tope = pt->VerTalleS() + pr->VerTalleS();
		letra_talle="S";
		break;
	case 2:
		tope = pt->VerTalleM() + pr->VerTalleM();
		letra_talle="M";
		break;
	case 3:
		tope = pt->VerTalleL() + pr->VerTalleL();
		letra_talle="L";
		break;
	default:
		wxMessageBox("Error inesperado con los talles","Algo anduvo mal...", wxOK | wxICON_ERROR);
	}
	
	m_staticText13->SetLabel(pr->VerNombre()+"- talle "+ letra_talle + " (" + (to_string(tope))+ " disponibles)");
}

void V_NuevaCant::ClicConfirmar( wxCommandEvent& event )  {
	int nueva = wxAtof(m_NuevaCant->GetValue());
	int diferencia = nueva - (pr->VerTalleL()+pr->VerTalleM()+pr->VerTalleS());
	
	int talle = pr->VerTalle();
	Producto* p_original = t->MostrarConId(pr->Ver_id());
	switch (talle){
	case 1:
		if (diferencia > p_original->VerTalleS()){
			wxMessageBox("La cantidad ingresada no es válida","Advertencia", wxOK | wxICON_WARNING);
		} else {
			p_original->Modificar_S(-diferencia);
			pr->Modificar_S(diferencia);
		}
		EndModal(wxID_OK);
		break;
	case 2:
		if (diferencia > p_original->VerTalleM()){
			wxMessageBox("La cantidad ingresada no es válida","Advertencia", wxOK | wxICON_WARNING);
		} else {
			p_original->Modificar_M(-diferencia);
			pr->Modificar_M(diferencia);
		}
		EndModal(wxID_OK);
		break;
	case 3:
		if (diferencia > p_original->VerTalleL()){
			wxMessageBox("La cantidad ingresada no es válida","Advertencia", wxOK | wxICON_WARNING);
		} else {
			p_original->Modificar_L(-diferencia);
			pr->Modificar_L(diferencia);
		}
		EndModal(wxID_OK);
		break;
	default:
		wxMessageBox("Error inesperado con los talles","Algo anduvo mal...", wxOK | wxICON_ERROR);
	}
}

V_NuevaCant::~V_NuevaCant() {
	
}

