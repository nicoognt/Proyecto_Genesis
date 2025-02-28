#include "CarritoDeCompras.h"
#include "Producto.h"
#include "Tienda.h"
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Factura.h"
#include <sstream>
using namespace std;

CarritoDeCompras::CarritoDeCompras(){
}

void CarritoDeCompras::Agregar(Producto a){
	compras.push_back(a);
}
void CarritoDeCompras::Eliminar (int id) {
	for(int i = 0;i<compras.size();i++){
		if (compras[i].Ver_id() == id){
			compras.erase(compras.begin()+i);
			return;
		}
	}
}

Factura CarritoDeCompras::Vender ( ) {
	auto now = chrono::system_clock::now();
	time_t now_time_t = chrono::system_clock::to_time_t(now);
	tm now_tm = *localtime(&now_time_t);
	
	stringstream ss;
	ss << put_time(&now_tm, "%d/%m/%Y %H:%M:%S");
	float total = CalcularTotal();
	Factura a(compras,ss.str());
	a.setTotal(total);
	compras.clear();
	return a;
}


bool CarritoDeCompras::EstaVacio(){
	return compras.empty();
}

int CarritoDeCompras::CantProductos ( ) {
	return compras.size();
}

Producto CarritoDeCompras::ObtenerProducto (int i) {
	return compras[i];
}
Producto * CarritoDeCompras::ObtenerProductoPtr (int i) {
	return &compras[i];
}
Producto CarritoDeCompras::VerProducto(int id){
	for(Producto pr : compras) { 
		if(pr.Ver_id()==id) return pr;
	}
}

void CarritoDeCompras::Vaciar(){
	compras.clear();
}

float CarritoDeCompras::CalcularTotal(){
	float total = 0;
	for(auto p : compras) { 
		total += p.VerPrecio()*(p.VerTalleS()+p.VerTalleM()+p.VerTalleL());
	}
	return total;
}
