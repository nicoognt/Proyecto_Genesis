#ifndef DIALOGO2_H
#define DIALOGO2_H
#include "wxfb_project.h"
#include "CarritoDeCompras.h"
#include "Producto.h"


class dialogo2 : public d_Carrito {
	
private:
	
	Producto* prod;
	CarritoDeCompras* carrito;
	
protected:
	
	void OnOK( wxCommandEvent& event )  override;
	void OnClose( wxCloseEvent& event );
	
public:
	
	dialogo2(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr,Producto* a=nullptr);
	~dialogo2();
	
};

#endif




