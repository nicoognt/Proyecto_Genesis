#include "CarritoDeCompras.h"
#include "Producto.h"
#include "Tienda.h"
#include <vector>
using namespace std;

CarritoDeCompras::CarritoDeCompras(){
}

void CarritoDeCompras::Agregar(Producto a){
	
}

bool CarritoDeCompras::EstaVacio(){
	return compras.empty();
}

vector<Producto>& CarritoDeCompras::ObtenerProductos(){return compras;}

/*void CarritoDeCompras::Eliminar(int id,Tienda& t){
	for(size_t i=0;i<compras.size();i++) { 
		if(compras[i].first.Ver_id() == id){
			auto it = compras.begin()+i;
			compras.erase(it);
		}
	}
}*/

void CarritoDeCompras::Vaciar(){
	compras.erase(compras.begin(),compras.end());
}


void CarritoDeCompras::Aumentar(int pos){
//	if (compras[pos].VerTalleS()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//			if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_S(-1);
//			}
//		}
//		compras[pos].Modificar_S(1);
//	}
//	if (compras[pos].VerTalleM()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//			if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_M(-1);
//			}
//		}
//		compras[pos].Modificar_M(1);
//	}
//	if (compras[pos].VerTalleL()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//			if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_L(-1);
//			}
//		}
//		compras[pos].Modificar_L(1);
//	}
}

void CarritoDeCompras::Disminuir(int pos){
//	if (compras[pos].VerTalleS()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//		if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_S(1);
//			}
//		}
//		compras[pos].Modificar_S(-1);
//	}
//	if (compras[pos].VerTalleM()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//			if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_M(1);
//			}
//		}
//		compras[pos].Modificar_M(-1);
//	}
//	if (compras[pos].VerTalleL()!=0){
//		vector<Producto*>v = t.MostrarVector();
//		for(int i=0;i<v.size();i++) { 
//			if (v[i]->Ver_id()==compras[pos].Ver_id()){
//				v[i]->Modificar_L(1);
//			}
//		}
//		compras[pos].Modificar_L(-1);
//	}
}

Producto CarritoDeCompras::VerProducto(int id){
	for(Producto pr : compras) { 
		if(pr.Ver_id()==id) return pr;
	}
}

float CarritoDeCompras::CalcularTotal(){
	float total = 0;
	for(auto p : compras) { 
		total += p.VerPrecio()*(p.VerTalleS()+p.VerTalleM()+p.VerTalleL());
	}
	return total;
}
