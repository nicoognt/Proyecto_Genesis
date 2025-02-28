#ifndef DIALOGO7_H
#define DIALOGO7_H
#include "wxfb_project.h"
#include <vector>
using namespace std;

class Factura;

class dialogo7 : public d_Facturas {
	
private:
	
	long indice;
	vector<Factura> facturas;
	
protected:
	
	void OnDobleClic( wxListEvent& event ) ;
	
public:
	// Mantener los registros viejos
	void GuardarDatos();
	void CargarDatos();
	// Guardar las facturas en un binario
	void GuardarFac_Bin(const vector<Factura> facturas,string file_name);
	void CargarFac_Bin(vector<Factura>& facturas,string file_n);
	void CargarFacturas();
	dialogo7(wxWindow *parent=NULL,vector<Factura> f={});
	~dialogo7();
};

#endif




