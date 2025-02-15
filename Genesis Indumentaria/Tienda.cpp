#include "Tienda.h"
#include <fstream>
#include "Producto.h"
#include <algorithm>
#include "Factura.h"
#include "CarritoDeCompras.h"
#include <string>
using namespace std;

Tienda::Tienda(string nom) {
	file_name=nom;
	ifstream datos(file_name.c_str(),ios::binary|ios::ate);
	if(datos.is_open()){
		
		hombre=mujer=true;
		ta_s=ta_m=ta_l=false;
		precio_asc=precio_des=false;
		
		int prod_am=datos.tellg()/sizeof(producto_con_char);
		vector_base.resize(prod_am);
		datos.seekg(0,ios::beg);
		for(int i=0;i<prod_am;i++) { 
			vector_base[i].CargarDesdeBin(datos);
		}
		
		datos.close();
		
	}
}

vector<Producto*> Tienda::MostrarVector(){
	return  vector_base;
}

Producto& Tienda::MostrarProducto(int i){
	return vector_base[i];
}

//Factura Tienda::RealizarVenta(CarritoDeCompras& carrito){
//	if(carrito.EstaVacio()){
//		cout << "El carrito esta vacio... Llenalo con lo que mas te guste" << endl;
//		return Factura({},0);
//	}
//	
//	float total = carrito.CalcularTotal();
//	auto productos = carrito.ObtenerProductos();
//	
//	for(auto& par : productos){
//		for(auto& p : lista){
//			if(p.Ver_id() == par.first.Ver_id() && p.VerStock() >= par.second){
//				p.reducirStock(par.second);
//			}
//		}
//	}
//	Factura Nueva(productos,total);
//	carrito.Vaciar();
//	
//	return Nueva;
//}

void Tienda::AgregarProducto(Producto A){
	vector_base.push_back(A);
	sort(vector_base.begin(),vector_base.end(),ordenar_producto);
}

int Tienda::CantidadProductos(){return vector_base.size();}

bool ordenar_producto(Producto a1,Producto a2){
	return (a1.VerNombre() < a2.VerNombre());
}

