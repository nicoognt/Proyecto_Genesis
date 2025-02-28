#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Producto;

class Factura {
private:
	
	float total;
	string fecha_venta;
	vector<Producto> productosComprados;
	
public:
	
	Factura(vector<Producto> items={}, string n="");
	
	string ObtenerFecha();
	vector<Producto> getProductos();
	
	void setTotal(float t);
	float getTotal();
	
	void GuardarEnBin(ofstream& file);
	void CargarDesdeBin(ifstream& file);
};

#endif



