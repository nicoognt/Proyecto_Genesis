#include "Producto.h"

using namespace std;

Producto::Producto(const producto_con_char& meg) {
	nombre = meg.nombre;
	categoria = meg.categoria;
	talle_S = meg.S;
	talle_M = meg.M;
	talle_L = meg.L;
	id_producto = meg.id_producto;
	precio = meg.precio;
	estrellas = meg.estrellas;
}

bool Producto::VerHombre(){return hombre;}
bool Producto::VerMujer(){return mujer;}
bool Producto::VerS(){return talle_S;}
bool Producto::VerM(){return talle_M;}
bool Producto::VerL(){return talle_L;}
int Producto::VerEstrellas(){return estrellas;}
float Producto::VerPrecio(){return precio;}

