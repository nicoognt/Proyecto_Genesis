#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include <string>
using namespace std;

class Producto;

class Factura {
private:
	
	float total;
	string fecha_venta;
	vector<Producto> productosComprados;
	
public:
	
	Factura(vector<Producto> items, string n="");
	string ObtenerFecha();
	void ImprimirFactura();
	void setTotal(float t);
	float getTotal();
	
};

#endif


