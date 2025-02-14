#include "CarritoDeCompras.h"
#include "Producto.h"
#include "Tienda.h"
#include <vector>
using namespace std;

CarritoDeCompras::CarritoDeCompras(){
}

void CarritoDeCompras::Agregar(Producto a,Tienda& t){
	pair<Producto,int> b = {a,1};
	compras.push_back(b);
}

bool CarritoDeCompras::EstaVacio(){
	return compras.empty();
}

const vector<Producto>& CarritoDeCompras::ObtenerProductos(){return compras;}

void CarritoDeCompras::Eliminar(int id,Tienda& t){
	for(size_t i=0;i<compras.size();i++) { 
		if(compras[i].first.Ver_id() == id){
			auto it = compras.begin()+i;
			compras.erase(it);
		}
	}
}

void CarritoDeCompras::Vaciar(){
	compras.erase(compras.begin(),compras.end());
}

void CarritoDeCompras::Aumentar(int id){
	for(auto pr : compras){ 
		if(pr.Ver_id() == id){
			;
		}
	}
}

void CarritoDeCompras::Disminuir(int id){
	for(size_t i=0;i<compras.size();i++) { 
		if(compras[i].first.Ver_id() == id){
			compras[i].second--;
			if (compras[i].second == 0){
				Eliminar(compras[i].first.Ver_id());
			}
		}
	}
}

Producto CarritoDeCompras::MostrarProducto_C(int i){return compras[i];}

float CarritoDeCompras::CalcularTotal(){
	float total = 0;
	for(auto p : compras) { 
		total += p.VerPrecio()*(p.VerTalleS()+p.VerTalleM()+p.VerTalleL());
	}
	return total;
}
