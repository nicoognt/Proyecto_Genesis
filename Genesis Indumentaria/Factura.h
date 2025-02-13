#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
using namespace std;

class Producto;

class Factura {
public:
	Factura(vector<pair<Producto,int>> items, float total);
	void ImprimirFactura();
private:
	vector<pair<Producto,int>> productosComprados;
	float totalVenta;
};

#endif

