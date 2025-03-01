#ifndef DIALOGO7_H
#define DIALOGO7_H
#include "wxfb_project.h"
#include <vector>
using namespace std;

class Factura;

class dialogo7 : public d_Facturas {
	
private:
	
	bool lo_cree_aca;
	long indice;
	vector<Factura> * facturas;
	
protected:
	
	void OnDobleClic( wxListEvent& event ) ;
	void OnClose( wxCloseEvent& event ) ;
	
public:
	// Mostrar las facturas en la lista
	void CargarFacturas();
	// Mantener los registros viejos
	void GuardarDatos();
	void CargarDatos();
	// Guardar las facturas en un binario
	void GuardarFac_Bin(vector<Factura>* facturas,string file_name);
	void CargarFac_Bin(vector<Factura>* facturas,string file_n);
	
	dialogo7(wxWindow *parent=NULL,vector<Factura>* f=nullptr);
	~dialogo7();
};

#endif

