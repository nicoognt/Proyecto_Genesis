#include "Factura.h"
#include <vector>
#include <fstream>
#include "Producto.h"
using namespace std;

Factura::Factura(vector<Producto> items,string n) {
	productosComprados = items;
	fecha_venta = n;
}

string Factura::ObtenerFecha ( ) {
	return fecha_venta;
}
vector<Producto> Factura::getProductos(){
	return productosComprados;
}
void Factura::setTotal (float t) {total = t;}
float Factura::getTotal ( ) {return total;}

void Factura::GuardarEnBin (ofstream& file) {
	// Tener la longitud de la fecha para saber cuánto escribir
	size_t longFecha = fecha_venta.size();
	file.write(reinterpret_cast<const char*>(&longFecha),sizeof(longFecha));
	file.write(fecha_venta.c_str(),longFecha);
	
	// Tener la cantidad de productos para saber cuántas veces iterar
	size_t cantProductos = productosComprados.size();
	file.write(reinterpret_cast<const char*>(&cantProductos),sizeof(cantProductos));
	for(size_t i=0;i<cantProductos;i++){
		productosComprados[i].SubirEnBin(file);
	}
	
	file.write(reinterpret_cast<const char*>(&total),sizeof(total));
}

void Factura::CargarDesdeBin (ifstream & file) {
	size_t longFecha;
	file.read(reinterpret_cast<char*>(&longFecha),sizeof(longFecha));
	fecha_venta.resize(longFecha);
	file.read(reinterpret_cast<char*>(&fecha_venta),longFecha);
	
	size_t cantProductos;
	file.read(reinterpret_cast<char*>(&cantProductos),sizeof(cantProductos));
	productosComprados.resize(cantProductos);
	for(size_t i=0;i<cantProductos;i++){
		productosComprados[i].CargarDesdeBin(file);
	}
	
	file.read(reinterpret_cast<char*>(&total),sizeof(total));
}
