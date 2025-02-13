#include "Tienda.h"
#include <fstream>
#include "Producto.h"
#include <algorithm>
#include "Factura.h"
#include "CarritoDeCompras.h"
using namespace std;

Tienda::Tienda() {
	hombre = mujer = true;
	ta_s = ta_m = ta_l = false;
	precio_asc = precio_des = false;
	estrellas = 1;
	busqueda = "";
	
	fstream datos("lista_de_ropa.bin",ios::binary|ios::in|ios::ate);
	if(!datos.is_open()) throw runtime_error ("Hubo un problema con abrir el archivo");
	
	producto_con_char aux;
	
	int cant_productos = datos.tellg()/sizeof(producto_con_char);
	datos.seekg(0);
	
	for(int i=0;i<cant_productos;i++) { 
		datos.read(reinterpret_cast<char*>(&aux),sizeof(aux));
		Producto A(aux);
		lista.push_back(A);
	}
	
	datos.close();
}

Producto Tienda::MostrarProducto(int i){return lista[i];}

Factura Tienda::RealizarVenta(CarritoDeCompras& carrito){
	if(carrito.EstaVacio()){
		cout << "El carrito esta vacio... Llenalo con lo que mas te guste" << endl;
		return Factura({},0);
	}
	
	float total = carrito.CalcularTotal();
	auto productos = carrito.ObtenerProductos();
	
	for(auto& par : productos){
		for(auto& p : lista){
			if(p.Ver_id() == par.first.Ver_id() && p.VerStock() >= par.second){
				p.reducirStock(par.second);
			}
		}
	}
	Factura Nueva(productos,total);
	carrito.Vaciar();
	
	return Nueva;
}

int Tienda::CantidadProductos(){return lista.size();}

