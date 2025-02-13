#include "Producto.h"

using namespace std;

Producto::Producto(const producto_con_char& meg) {
	nombre = meg.nombre;
	categoria = meg.categoria;
	talle = meg.talle;
	genero = meg.genero;
	id = meg.id_producto;
	precio = meg.precio;
	stock = meg.stock;
}


void Producto::reducirStock(int cantidad){
	stock -= cantidad;
}
string Producto::VerNombre(){return nombre;}
string Producto::VerCategoria(){return categoria;}
string Producto::VerTalle(){return talle;}
string Producto::VerGen(){return genero;}
int Producto::Ver_id(){return id;}
int Producto::VerStock(){return stock;}
float Producto::VerPrecio(){return precio;}

