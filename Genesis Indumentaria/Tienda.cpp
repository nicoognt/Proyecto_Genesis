#include "Tienda.h"
#include <fstream>
#include "Producto.h"
#include <algorithm>
#include "Factura.h"
#include "CarritoDeCompras.h"
#include <string>
#include <sys/stat.h>
using namespace std;
void cargar_prueba(string n);

Tienda::Tienda(string nom){
	file_name=nom;
	// Reviso si el archivo ya existe
	if(!(archivoExiste(file_name))){
		cargar_prueba(file_name);
	}
	
	ifstream datos(file_name,ios::binary|ios::ate);
	if(datos.is_open()){
		
		int prod_am=datos.tellg()/sizeof(producto_con_char);
		vector_base.resize(prod_am);
		datos.seekg(0,ios::beg);
		for(int i=0;i<prod_am;i++) { 
			vector_base[i].CargarDesdeBin(datos);
		}
		
		datos.close();
		
	}
	vector_filtros = vector_base;
}

bool Tienda:: EsIgual(int id){
	for(size_t i=0;i<vector_base.size();i++) { 
		if (id == vector_base[i].Ver_id()){
			return true;}
	}
	return false;
}

Producto Tienda::MostrarProducto(int i){
	return vector_filtros[i];
}
Producto * Tienda::Mostrarptr(int i) {
	return &vector_base[i];
}
Producto * Tienda::MostrarConId (int id) {
	for(size_t i=0;i<vector_base.size();i++) { 
		if (vector_base[i].Ver_id() == id) return &vector_base[i];
	}
}

void Tienda::AgregarProducto(Producto A){
	vector_base.push_back(A);
}
void Tienda::EliminarProducto (int id) {
	for (size_t i = 0;i<vector_base.size();i++){
		if(vector_base[i].Ver_id() == id){
			vector_base.erase(vector_base.begin()+i);
		}
	}
}
void Tienda::RestaurarStock (Producto a) {
	for(size_t i=0;i<vector_base.size();i++) { 
		if(vector_base[i].Ver_id() == a.Ver_id()){
			vector_base[i] = vector_base[i] + a;
		}
	}
}

void Tienda::OrdenarVector ( ) {
	sort(vector_base.begin(),vector_base.end(),orden_alfabetico);
	sort(vector_filtros.begin(),vector_filtros.end(),orden_alfabetico);
}

void Tienda::AplicarFiltros (const wxString& genero,const wxString& categoria, const wxString& orden, float precioMin, float precioMax) {
	// Limpio el vector para actualizarlo
	vector_filtros.erase(vector_filtros.begin(),vector_filtros.end());
	
	// Aplico filtros para renovar el vector
	for(auto& producto : vector_base){
		if((genero == "Todos" || producto.VerGen() == genero) && (categoria == "Todas" || producto.VerCategoria() == categoria) && 
			(producto.VerPrecio() >= precioMin && producto.VerPrecio() <= precioMax)){
			vector_filtros.push_back(producto);
		}
	}
	
	// Veo qué formato de orden se seleccionó
	if (orden == "Alfabético"){
		sort(vector_base.begin(),vector_base.end(),orden_alfabetico);
		sort(vector_filtros.begin(),vector_filtros.end(),orden_alfabetico);
	} else if (orden == "Precio ascendente"){
		sort(vector_base.begin(),vector_base.end(),orden_precioAsc);
		sort(vector_filtros.begin(),vector_filtros.end(),orden_precioAsc);
	} else {
		sort(vector_base.begin(),vector_base.end(),orden_precioDes);
		sort(vector_filtros.begin(),vector_filtros.end(),orden_precioDes);
	}
	
}
const vector<Producto> & Tienda::ObtenerFiltros ( ) {
	return vector_filtros;
}

void Tienda::ReestablecerListas ( ) {
	vector_filtros = vector_base;
}

void Tienda::ActualizarBinario ( ) {
	ofstream file(file_name,ios::binary);
	
	if(file.is_open()){
		for (auto p : vector_base) {
			p.SubirEnBin(file);
		}
	}
	
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
bool archivoExiste(const string & n) {
	ifstream file(n,ios::binary);
	return file.good();
}

