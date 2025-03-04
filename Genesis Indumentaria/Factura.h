#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Producto;

class Factura {
private:
	// Datos relevantes de una factura de venta
	float total;
	string fecha_venta;
	vector<Producto> productosComprados;
	string metodo_pago;
public:
	Factura(vector<Producto> items={}, string n="");
	// Obtener los datos de una factura
	string ObtenerFecha();
	vector<Producto> getProductos();
	// Modificar/obtener el total de la venta
	void setTotal(float t);
	float getTotal();
	// Modificar/obtener el metodo de pago
	void setMetodoPago(string metodo);
	string getMetodoPago();
	// Guardar uan factura en binario y cargarla
	void GuardarEnBin(ofstream& file);
	void CargarDesdeBin(ifstream& file);
};

#endif






