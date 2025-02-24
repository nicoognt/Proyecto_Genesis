#include "dialogo2.h"
#include "CarritoDeCompras.h"
#include <wx/valtext.h>

dialogo2::dialogo2(wxWindow *parent,CarritoDeCompras* c,Producto& a) : d_Carrito(parent),carrito(c),pr(a) {
	
	wxTextValidator v(wxFILTER_NUMERIC);
	barra_TS->SetValidator(v);
	barra_TM->SetValidator(v);
	barra_TL->SetValidator(v);
}

void dialogo2::clic_OK_carrito( wxCommandEvent& event )  {
	
	int ta_s = wxAtoi (barra_TS->GetValue());
	int ta_m = wxAtoi (barra_TM->GetValue());
	int ta_l = wxAtoi (barra_TL->GetValue());
	
	if(ta_s>0){
		Producto a(pr.VerNombre(),pr.VerCategoria(),pr.VerGen(),ta_s,0,0,pr.Ver_id(),pr.VerPrecio());
		carrito->Agregar(a);
	}
	if(ta_m>0){
		Producto b(pr.VerNombre(),pr.VerCategoria(),pr.VerGen(),0,ta_m,0,pr.Ver_id(),pr.VerPrecio());
		carrito->Agregar(b);
	}
	if(ta_l>0){
		Producto c(pr.VerNombre(),pr.VerCategoria(),pr.VerGen(),0,0,ta_l,pr.Ver_id(),pr.VerPrecio());
		carrito->Agregar(c);
	}
	
	this->Close();
}

dialogo2::~dialogo2() {
	
}

