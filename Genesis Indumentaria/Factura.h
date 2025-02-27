#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include <string>
using namespace std;

class Producto;

class Factura {
private:
	
	string fecha_venta;
	vector<Producto> productosComprados;
	
public:
	
	Factura(vector<Producto> items, string n="");
	void ImprimirFactura();
	
};

#endif

