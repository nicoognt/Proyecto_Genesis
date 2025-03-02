#ifndef V_SUMARCARRITO_H
#define V_SUMARCARRITO_H
#include "wxfb_project.h"
#include "Producto.h"
#include "CarritoDeCompras.h"

class V_SumarCarrito : public AddCarrito {
	
private:
	
	Producto* prod;
	CarritoDeCompras* carrito;
	
protected:
	
	void OnOK( wxCommandEvent& event )  override;
	void OnClose( wxCloseEvent& event );
	
public:
	V_SumarCarrito(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr,Producto* a=nullptr);
	~V_SumarCarrito();
};

#endif




