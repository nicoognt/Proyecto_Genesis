#include "dialogo6.h"
#include "Producto.h"
#include <wx/valtext.h>
#include <wx/msgdlg.h>

dialogo6::dialogo6(wxWindow *parent, Producto* p) : d_Modificar(parent), producto_tienda(p) {
	
	barra_TalleS->SetValue(wxString::Format("%d",producto_tienda->VerTalleS()));
	barra_TalleM->SetValue(wxString::Format("%d",producto_tienda->VerTalleM()));
	barra_TalleL->SetValue(wxString::Format("%d",producto_tienda->VerTalleL()));
	barra_PrecioAct->SetValue(wxString::Format("%.2f",producto_tienda->VerPrecio()));
	
	wxTextValidator v(wxFILTER_NUMERIC);
	barra_NuevoS->SetValidator(v); barra_NuevoM->SetValidator(v); barra_NuevoL->SetValidator(v); barra_PrecioNue->SetValidator(v);
	
}

dialogo6::~dialogo6() {
	
}

void dialogo6::Modificar_Stock( wxCommandEvent& event )  {
	
	int NuevoS, NuevoM, NuevoL;
	float NuevoP;
	if(wxAtof(barra_NuevoS->GetValue())<0 || wxAtof(barra_NuevoM->GetValue())<0 || wxAtof(barra_NuevoL->GetValue())<0){
		wxMessageBox("No se pueden ingresar números negativos","Error", wxOK | wxICON_ERROR);
		return;
	}
	
	if(barra_NuevoS->IsEmpty()) {
		NuevoS=producto_tienda->VerTalleS();
	} else {
		NuevoS=wxAtof(barra_NuevoS->GetValue());
	}
	if(barra_NuevoM->IsEmpty()) {
		NuevoM=producto_tienda->VerTalleM();
	} else {
		NuevoM=wxAtof(barra_NuevoM->GetValue());
	}
	if(barra_NuevoL->IsEmpty()) {
		NuevoL=producto_tienda->VerTalleL();
	} else {
		NuevoL=wxAtof(barra_NuevoL->GetValue());
	}
	if(barra_PrecioNue->IsEmpty()){
		NuevoP = producto_tienda->VerPrecio();
	} else {
		NuevoP = (float)(wxAtof(barra_PrecioNue->GetValue()));
	}
	int dif_S=NuevoS-producto_tienda->VerTalleS(), dif_M=NuevoM-producto_tienda->VerTalleM(), dif_L=NuevoL-producto_tienda->VerTalleL();
	
	if(dif_S>0 || dif_S<0){
		producto_tienda->Modificar_S(dif_S);
	} else if(dif_S==0){
		producto_tienda->Modificar_S(dif_S);
	}
	
	if(dif_M>0 || dif_M<0){
		producto_tienda->Modificar_M(dif_M);
	} else if(dif_M==0){
		producto_tienda->Modificar_M(dif_M);
	}
	
	if(dif_L>0 || dif_L<0){
		producto_tienda->Modificar_L(dif_L);
	} else if(dif_L==0){
		producto_tienda->Modificar_L(dif_L);
	}
	
	producto_tienda->ModificarPrecio(NuevoP);
	EndModal(wxID_OK);
}

