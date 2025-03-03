#ifndef LISTA_FACTURAS_H
#define LISTA_FACTURAS_H
#include "wxfb_project.h"
#include <vector>
using namespace std;

class Factura;

class Lista_Facturas : public VentanaFacturas {
	
private:
	long indice;
	vector<Factura> facturas;
protected:
	void OnDobleClic( wxListEvent& event ) ;
	void OnClose( wxCloseEvent& event ) ;
public:
	Lista_Facturas(wxWindow *parent=NULL,vector<Factura> f={});
	~Lista_Facturas();
	// Mostrar las facturas en la lista
	void CargarLista();
	// Guardar las facturas en un binario
	void GuardarFacturas(string file_name="facturas.dat");
	void CargarFacturas(string file_n="facturas.dat");
};

#endif



