#ifndef DIALOGO3_H
#define DIALOGO3_H
#include "wxfb_project.h"
#include "CarritoDeCompras.h"


class dialogo3 : public d_Compras {
	
private:
	
	CarritoDeCompras *crt;
	
protected:
	void OnComprar( wxCommandEvent& event )  override;
	void OnVaciar( wxCommandEvent& event )  override;
	void OnSumarPrecio();
	
public:
	dialogo3(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr);
	void CargarProductos();
	~dialogo3();
};

#endif



