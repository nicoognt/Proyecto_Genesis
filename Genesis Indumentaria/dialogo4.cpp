#include "dialogo4.h"
#include "Producto.h"
#include "Tienda.h"
#include <wx/msgdlg.h>

dialogo4::dialogo4(wxWindow *parent, Producto* p, Tienda* _t) : MyDialog4(parent), pr(p), t(_t) {
	Producto * pt = t->MostrarConId(pr->Ver_id());
	int talle = pr->VerTalle();
	int tope;
	string talle;
	switch (talle){
	case 1:
		tope = pt->VerTalleS() + pr->VerTalleS();
		talle=S;
		break;
	case 2:
		tope = pt->VerTalleM() + pr->VerTalleM();
		talle=M;
		break;
	case 3:
		tope = pt->VerTalleL() + pr->VerTalleL();
		talle=L;
		break;
	default:
		wxMessageBox("Error inesperado con los talles","Algo anduvo mal...", wxOK | wxICON_ERROR);
	}
	
	m_staticText13->SetLabel(pr->VerNombre()+"- talle "+ talle + " " + (+to_string(tope))+ " disponibles)");
	
}

void dialogo4::ClicConfirmar( wxCommandEvent& event )  {
	
	int nueva = wxAtof(m_NuevaCant->GetValue());
	int diferencia = nueva - (pr->VerTalleL()+pr->VerTalleM()+pr->VerTalleS());
	
	int talle = pr->VerTalle();
	Producto* p_original = t->MostrarConId(pr->Ver_id());
	switch (talle){
	case 1:
		if (diferencia > p_original->VerTalleS()){
			wxMessageBox("La cantidad ingresada no es v�lida","Advertencia", wxOK | wxICON_WARNING);
		} else {
			p_original->Modificar_S(-diferencia);
			pr->Modificar_S(diferencia);
		}
		EndModal(wxID_OK);
		break;
	case 2:
		if (diferencia > p_original->VerTalleM()){
			wxMessageBox("La cantidad ingresada no es v�lida","Advertencia", wxOK | wxICON_WARNING);
		} else {
			p_original->Modificar_M(-diferencia);
			pr->Modificar_M(diferencia);
		}
		EndModal(wxID_OK);
		break;
	case 3:
		if (diferencia > p_original->VerTalleL()){
			wxMessageBox("La cantidad ingresada no es v�lida","Advertencia", wxOK | wxICON_WARNING);
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

dialogo4::~dialogo4() {
	
}

