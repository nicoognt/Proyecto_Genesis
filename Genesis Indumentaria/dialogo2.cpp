#include "dialogo2.h"
#include "CarritoDeCompras.h"
#include <wx/valtext.h>
#include "Producto.h"
#include <wx/msgdlg.h>
#include <wx/utils.h>


dialogo2::dialogo2(wxWindow *parent,CarritoDeCompras* c,Producto* a) : d_Carrito(parent),carrito(c),prod(a){
	
	if(!carrito){
		wxMessageBox("Error: El carrito no está disponible.", "Error", wxOK | wxICON_ERROR);
		Close();
	}
	if(!prod){
		wxMessageBox("Error: Producto no válido.", "Error", wxOK | wxICON_ERROR);
		Close();
	}
	
	m_staticText11->SetLabel("Talles S ("+prod->VerTalleS+" disponibles):";
	m_staticText12->SetLabel("Talles M ("+prod->VerTalleM+" disponibles):";
	m_staticText13->SetLabel("Talles L ("+prod->VerTalleL+" disponibles):";
	
	wxTextValidator v(wxFILTER_NUMERIC);
	barra_TS->SetValidator(v);
	barra_TM->SetValidator(v);
	barra_TL->SetValidator(v);
	
}

void dialogo2::OnOK( wxCommandEvent& event )  {
	
	int ta_s = wxAtoi(barra_TS->GetValue());
	int ta_m = wxAtoi(barra_TM->GetValue());
	int ta_l = wxAtoi(barra_TL->GetValue());
	
	cout << "Valores ingresados: S=" << ta_s << ", M=" << ta_m << ", L=" << ta_l << endl;
	
	if (prod) {
		
		cout << "Producto válido: " << prod->VerNombre() << endl;
		
		if(ta_s <= prod->VerTalleS() && ta_m <= prod->VerTalleM() && ta_l <= prod->VerTalleL()){
			
			if (ta_s > 0) carrito->Agregar(Producto(prod->VerNombre(),prod->VerCategoria(),prod->VerGen(),ta_s,0,0,prod->Ver_id(),prod->VerPrecio()));
			if (ta_m > 0) carrito->Agregar(Producto(prod->VerNombre(),prod->VerCategoria(),prod->VerGen(),0,ta_m,0,prod->Ver_id(),prod->VerPrecio()));
			if (ta_l > 0) carrito->Agregar(Producto(prod->VerNombre(),prod->VerCategoria(),prod->VerGen(),0,0,ta_l,prod->Ver_id(),prod->VerPrecio()));
			
			wxMessageBox("El producto se agregó correctamente","Aviso",wxOK | wxICON_INFORMATION);
			cout << "Producto agregado correctamente." << endl;
			
		} else {
			wxMessageBox("La cantidad ingresada no es vàlida","Advertencia", wxOK | wxICON_EXCLAMATION);
		}
	} else {
		
		wxMessageBox("Error: Producto inválido.", "Error", wxOK | wxICON_ERROR);
		
	}
	
	EndModal(wxID_OK);
	
}

void dialogo2::OnClose (wxCloseEvent & event) {
	EndModal(wxID_CANCEL);
}

dialogo2::~dialogo2() {
	
}



