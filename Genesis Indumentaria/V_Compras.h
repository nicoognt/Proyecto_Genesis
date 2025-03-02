#ifndef V_COMPRAS_H
#define V_COMPRAS_H
#include "wxfb_project.h"
#include "CarritoDeCompras.h"
#include <vector>
using namespace std;

class Tienda;

class V_Compras : public VentanaCompras {
	
private:
	
	vector<Factura>* facts;
	int m_indice;
	CarritoDeCompras *crt;
	Tienda *t;
	
protected:
	void OnVender( wxCommandEvent& event )  override;
	void OnVaciar( wxCommandEvent& event )  override;
	void OnSumarPrecio();
	
	void OnRightClick( wxListEvent& event );
	void OnModificarCantidad( wxCommandEvent& event );
	void OnEliminar( wxCommandEvent& event );
public:
	V_Compras(wxWindow *parent=NULL,CarritoDeCompras* c=nullptr,Tienda* t=nullptr,vector<Factura>* f=nullptr);
	~V_Compras();
	void CargarProductos();
};

#endif






