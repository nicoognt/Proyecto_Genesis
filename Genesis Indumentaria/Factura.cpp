#include "Factura.h"
#include <vector>
#include <fstream>
#include "Producto.h"
using namespace std;

Factura::Factura(vector<Producto> items,string n) {
	productosComprados = items;
	fecha_venta = n;
}

void Factura::ImprimirFactura(){
	ofstream guardar("compra.txt");
	if(!guardar.is_open()) throw runtime_error("Error al abrir el archivo para guardar la compra");
	guardar << "compra numero tanto";
	guardar.close();
}

string Factura::ObtenerFecha ( ) {
	return fecha_venta;
}
vector<Producto> Factura::getProductos(){
	return productosComprados;
}
void Factura::setTotal (float t) {total = t;}
float Factura::getTotal ( ) {return total;}

