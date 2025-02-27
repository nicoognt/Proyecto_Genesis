#ifndef DIALOGO7_H
#define DIALOGO7_H
#include "wxfb_project.h"
#include "Factura.h"
#include <vector>
using namespace std;

class dialogo7 : public d_Facturas {
	
private:
	
	float pFinal;
	long indice;
	vector<Factura> facturas;
	
protected:
	
	void OnDobleClic( wxListEvent& event ) ;
	
public:
	void CargarFacturas();
	dialogo7(wxWindow *parent=NULL,vector<Factura> f={});
	~dialogo7();
};

#endif






