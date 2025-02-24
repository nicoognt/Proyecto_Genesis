#include "dialogo2.h"
#include "CarritoDeCompras.h"
#include <wx/valtext.h>
#include "Producto.h"
#include <wx/msgdlg.h>
#include <wx/utils.h>

dialogo2::dialogo2(wxWindow *parent,CarritoDeCompras* c,Producto* a) : d_Carrito(parent),carrito(c),prod(a) {
	
	if(!carrito){
		wxMessageBox("Error: El carrito no está disponible.", "Error", wxOK | wxICON_ERROR);
		Close();
	}
	if(!prod){
		wxMessageBox("Error: Producto no válido.", "Error", wxOK | wxICON_ERROR);
		Close();
	}
	
	wxTextValidator v(wxFILTER_NUMERIC);
	barra_TS->SetValidator(v);
	barra_TM->SetValidator(v);
	barra_TL->SetValidator(v);
	
}

void dialogo2::clic_OK_carrito( wxCommandEvent& event )  {
	cout << "Entrando en clic_OK_carrito()" << endl;
	
	int ta_s = wxAtoi(barra_TS->GetValue());
	int ta_m = wxAtoi(barra_TM->GetValue());
	int ta_l = wxAtoi(barra_TL->GetValue());
	
	cout << "Valores ingresados: S=" << ta_s << ", M=" << ta_m << ", L=" << ta_l << endl;
	
	if (prod) {
		
		cout << "Producto válido: " << prod->VerNombre() << endl;
		
		if (ta_s > 0) carrito->Agregar(Producto(prod->VerNombre(), prod->VerCategoria(), "S", ta_s));
		if (ta_m > 0) carrito->Agregar(Producto(prod->VerNombre(), prod->VerCategoria(), "M", ta_m));
		if (ta_l > 0) carrito->Agregar(Producto(prod->VerNombre(), prod->VerCategoria(), "L", ta_l));
		
		cout << "Producto agregado correctamente." << endl;
		
	} else {
		wxMessageBox("Error: Producto inválido.", "Error", wxOK | wxICON_ERROR);
	}
	
	this->Close();
}

dialogo2::~dialogo2() {
	
}

