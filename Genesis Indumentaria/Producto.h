#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>
#include "Tienda.h"
using namespace std;

struct producto_con_char{
	char nombre[255];
	char categoria[255];
	char talle[10];
	char genero[10];
	int id_producto,stock;
	float precio;
};

class Producto {
public:
	Producto(const producto_con_char& meg);
	void reducirStock(int cantidad);
	string VerNombre();
	string VerCategoria();
	string VerTalle();
	string VerGen();
	int Ver_id();
	int VerStock();
	float VerPrecio();
private:
	string nombre,categoria,talle,genero;
	int id,stock;
	float precio;
};

#endif

