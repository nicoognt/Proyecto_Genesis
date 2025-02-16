#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
using namespace std;

class Producto;

class Factura {
private:
	
	vector<pair<Producto,int>> productosComprados;
	float totalVenta;
public:
	Factura(vector<pair<Producto,int>> items, float total);
	void ImprimirFactura();
};

#endif

