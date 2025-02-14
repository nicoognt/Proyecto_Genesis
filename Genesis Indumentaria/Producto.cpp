#include "Producto.h"

#include <fstream>
#include <cstring>
using namespace std;

Producto::Producto(string nom,string cat,string gen,int tS,
				   int tM,int tL,int Id,float p){
	nombre=nom;
	categoria=cat;
	talle_s=tS;
	talle_m=tM;
	talle_l=tL;
	genero=gen;
	id=Id;
	precio=p;
}
/// Métodos para modificar el stock de cada talle, ya sea
/// por si se compra o entra ropa.
void Producto::Modificar_S(int cantidad){
	talle_s += cantidad;
}
void Producto::Modificar_M(int cantidad){
	talle_m += cantidad;
}
void Producto::Modificar_L(int cantidad){
	talle_l += cantidad;
}

/// Métodos que devuelven todos los datos de un producto.
string Producto::VerNombre(){return nombre;}
string Producto::VerCategoria(){return categoria;}
int Producto::VerTalleS(){return talle_s;}
int Producto::VerTalleM(){return talle_m;}
int Producto::VerTalleL(){return talle_l;}
string Producto::VerGen(){return genero;}
int Producto::Ver_id(){return id;}
float Producto::VerPrecio(){return precio;}

/// Leer y escribir en un archivo binario.
void Producto::CargarDesdeBin(ifstream& m_file){
	producto_con_char pr;
	m_file.read((char*)&pr,sizeof(pr));
	nombre=pr.nombre;
	categoria=pr.categoria;
	talle_s=pr.talle_s;
	talle_m=pr.talle_m;
	talle_l=pr.talle_l;
	genero=pr.genero;
	id=pr.id_producto;
	precio=pr.precio;
}
void Producto::SubirEnBin(ofstream& _file){
	producto_con_char pr;
	strcpy(pr.nombre,nombre.c_str());
	strcpy(pr.categoria,categoria.c_str());
	strcpy(pr.genero,genero.c_str());
	pr.talle_s=talle_s;
	pr.talle_m=talle_m;
	pr.talle_l=talle_l;
	pr.id_producto=id;
	pr.precio=precio;
	_file.write((char*)&pr,sizeof(pr));
}
