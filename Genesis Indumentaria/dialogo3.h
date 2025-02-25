#ifndef DIALOGO3_H
#define DIALOGO3_H
#include "wxfb_project.h"
#include "CarritoDeCompras.h"

class Tienda;

class dialogo3 : public d_Compras {
	
private:
	
	int m_indice;S
	CarritoDeCompras *crt;
	Tienda *t;
	
protected:
	void OnComprar( wxCommandEvent& event )  override;
	void OnVaciar( wxCommandEvent& event )  override;
	void OnSumarPrecio();
	
	void OnRightClick( wxListEvent& event );
	void OnModificarCantidad( wxCommandEvent& event );
	void OnEliminar( wxCommandEvent& event );
	
public:
	dialogo3(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr,Tienda* t=nullptr);
	void CargarProductos();
	~dialogo3();
};

#endif



