#include "Tienda.h"
#include <fstream>
#include "Producto.h"
#include <algorithm>
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
	
	copia_para_filtros = lista;
	
	datos.close();
}

void Tienda::FiltroHombre(){
	if(hombre = false){
		hombre = true;
		mujer = false;
		vector<Producto> Nuevo;
		for(size_t i=0;i<lista.size();i++) { 
			if(lista[i].VerHombre()){
				Nuevo.push_back(lista[i]);
			}
		}
		copia_para_filtros = Nuevo;
	} else {
		hombre = false;
		copia_para_filtros = lista;
	}
}
void Tienda::FiltroMujer(){
	if(mujer = false){
		mujer = true;
		hombre = false;
		vector<Producto> Nuevo;
		for(size_t i=0;i<lista.size();i++) { 
			if(lista[i].VerHombre()){
				Nuevo.push_back(lista[i]);
			}
		}
		copia_para_filtros = Nuevo;
	} else {
		mujer = false;
		copia_para_filtros = lista;
	}
}

void Tienda::Filtro_S(){
	if(ta_s = false){
		ta_s = true;
		ta_m = ta_l = false;
		vector<Producto> Nuevo;
		for(size_t i=0;i<lista.size();i++) { 
			if(lista[i].VerS()){
				Nuevo.push_back(lista[i]);
			}
		}
		copia_para_filtros = Nuevo;
	} else {
		ta_s = false;
		copia_para_filtros = lista;
	}
}
void Tienda::Filtro_M(){
	if(ta_m = false){
		ta_m = true;
		ta_s = ta_l = false;
		vector<Producto> Nuevo;
		for(size_t i=0;i<lista.size();i++) { 
			if(lista[i].VerM()){
				Nuevo.push_back(lista[i]);
			}
		}
		copia_para_filtros = Nuevo;
	} else {
		ta_m = false;
		copia_para_filtros = lista;
	}
}
void Tienda::Filtro_L(){
	if(ta_l = false){
		ta_l = true;
		ta_s = ta_m = false;
		vector<Producto> Nuevo;
		for(size_t i=0;i<lista.size();i++) { 
			if(lista[i].VerL()){
				Nuevo.push_back(lista[i]);
			}
		}
		copia_para_filtros = Nuevo;
	} else {
		ta_l = false;
		copia_para_filtros = lista;
	}
}

void Tienda::Filtro_Precio_Asc(){
	if(precio_asc = false){
		precio_asc = true;
		precio_des = false;
		sort(copia_para_filtros.begin(),copia_para_filtros.end());
	}else{
		precio_asc = false;
	}
}
void Tienda::Filtro_Precio_Des(){
	if(precio_des = false){
		precio_des = true;
		precio_asc = false;
		sort(copia_para_filtros.begin(),copia_para_filtros.end());
		reverse(copia_para_filtros.begin(),copia_para_filtros.end());
	}else{
		precio_des = false;
	}
}
void Tienda::MostrarProducto(){
	
}

