#include "Tienda.h"
#include <fstream>
#include "Producto.h"
#include <algorithm>
#include "Factura.h"
#include "CarritoDeCompras.h"
#include <string>
using namespace std;
void cargar_prueba(string n);

Tienda::Tienda(string nom){
	cargar_prueba(nom);
	file_name=nom;
	ifstream datos(file_name.c_str(),ios::binary|ios::ate);
	if(datos.is_open()){
		
		int prod_am=datos.tellg()/sizeof(producto_con_char);
		vector_base.resize(prod_am);
		datos.seekg(0,ios::beg);
		for(int i=0;i<prod_am;i++) { 
			vector_base[i].CargarDesdeBin(datos);
		}
		
		datos.close();
		
	}
}


Producto Tienda::MostrarProducto(int i){
	return vector_base[i];
}
Producto * Tienda::Mostrarptr(int i) {
	return &vector_base[i];
}
void Tienda::AgregarProducto(Producto A){
	vector_base.push_back(A);
}

void Tienda::OrdenarVector ( ) {
	sort(vector_base.begin(),vector_base.end(),orden_alfabetico);
}

int Tienda::CantidadProductos(){return vector_base.size();}

bool orden_alfabetico(Producto a1,Producto a2){
	return (a1.VerNombre() < a2.VerNombre());
}
bool orden_precioAsc(Producto a1,Producto a2){
	return (a1.VerPrecio()<a2.VerPrecio());
}
bool orden_precioDes(Producto a1,Producto a2){
	return (a1.VerPrecio()>a2.VerPrecio());
}

