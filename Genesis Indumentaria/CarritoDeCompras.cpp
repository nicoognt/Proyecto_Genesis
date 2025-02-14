#include "CarritoDeCompras.h"
#include "Producto.h"
#include "Tienda.h"
#include <vector>
using namespace std;

CarritoDeCompras::CarritoDeCompras(){
}

void CarritoDeCompras::Agregar(Producto a,Tienda& t){
	for(int i=0;i<t.CantidadProductos();i++) { 
		Producto aux= t.MostrarProducto(i);
		if a.Ver_id()==aux.Ver_id(){
		}
	}
	compras.push_back(a);
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

void CarritoDeCompras::Aumentars(int id){
	for(auto pr : compras){ 
		if(pr.Ver_id() == id){
			pr.Modificar_S(1);
		}
	}
}
void CarritoDeCompras::Aumentarm(int id){
	for(auto pr : compras){ 
		if(pr.Ver_id() == id){
			pr.Modificar_M(1);
		}
	}
}
void CarritoDeCompras::Aumentarl(int id){
	for(auto pr : compras){ 
		if(pr.Ver_id() == id){
			pr.Modificar_L(1);
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
