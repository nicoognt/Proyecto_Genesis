#include "CarritoDeCompras.h"
#include "Producto.h"
#include "Tienda.h"
#include <vector>
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

bool CarritoDeCompras::EstaVacio(){
	return compras.empty();
}

int CarritoDeCompras::CantProductos ( ) {
	return compras.size();
}

Producto CarritoDeCompras::ObtenerProducto (int i) {
	return compras[i];
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
