#ifndef DIALOGO2_H
#define DIALOGO2_H
#include "wxfb_project.h"
#include "CarritoDeCompras.h"
#include "Producto.h"


class dialogo2 : public d_Carrito {
	
private:
	Producto& pr;
	CarritoDeCompras* carrito;
	
protected:
	void clic_OK_carrito( wxCommandEvent& event )  override;
	
public:
	dialogo2(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr,Producto& a=Producto());
	~dialogo2();
};

#endif

