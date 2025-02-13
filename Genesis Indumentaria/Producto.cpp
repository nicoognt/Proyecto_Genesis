#include "Producto.h"

using namespace std;

Producto::Producto(const producto_con_char& meg) {
	nombre = meg.nombre;
	categoria = meg.categoria;
	talle_s = meg.talle_s;
	talle_m = meg.talle_m;
	talle_l = meg.talle_l;
	genero = meg.genero;
	id = meg.id_producto;
	precio = meg.precio;
}
/// Métodos para modificar el stock de cada talle, ya sea
/// por si se compra o entra ropa
void Producto::Modificar_S(int cantidad){
	talle_s += cantidad;
}

void Producto::Modificar_M(int cantidad){
	talle_m += cantidad;
}
void Producto::Modificar_L(int cantidad){
	talle_l += cantidad;
}

string Producto::VerNombre(){return nombre;}
string Producto::VerCategoria(){return categoria;}
int Producto::VerTalleS(){return talle_s;}
int Producto::VerTalleM(){return talle_m;}
int Producto::VerTalleL(){return talle_l;}
string Producto::VerGen(){return genero;}
int Producto::Ver_id(){return id;}
float Producto::VerPrecio(){return precio;}

