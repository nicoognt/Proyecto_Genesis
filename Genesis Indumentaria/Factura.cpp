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
void Factura::setMetodoPago (string metodo) {metodo_pago=metodo;}
string Factura::getMetodoPago ( ) {return metodo_pago;}
void Factura::GuardarEnBin (ofstream& file) {
	// Tener la longitud de la fecha para saber cu�nto escribir
	size_t longFecha = fecha_venta.size();
	file.write(reinterpret_cast<const char*>(&longFecha),sizeof(longFecha));
	cout << "tamanio de la fecha guardado: " << longFecha << endl;
	
	file.write(fecha_venta.c_str(),longFecha);
	cout << "fecha guardada: " << fecha_venta << endl;
	
	// Tener la cantidad de productos para saber cu�ntas veces iterar
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
	if (longFecha <= 0 || longFecha > 100){
		cout << "error, tamanio de la fecha invalido\n";
		return;
	}
	
	fecha_venta.resize(longFecha);
	file.read(&fecha_venta[0],longFecha); cout << "fecha de la factura: " << fecha_venta << endl;
	
	size_t cantProductos;
	file.read(reinterpret_cast<char*>(&cantProductos),sizeof(cantProductos)); cout << "cantidad de productos: " << cantProductos << endl;
	productosComprados.resize(cantProductos);
	for(size_t i=0;i<cantProductos;i++){
		productosComprados[i].CargarDesdeBin(file);
	}
	
	file.read(reinterpret_cast<char*>(&total),sizeof(total));
}
