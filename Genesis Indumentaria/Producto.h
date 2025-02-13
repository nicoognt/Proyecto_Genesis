#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>
#include "Tienda.h"
using namespace std;

struct producto_con_char{
	char nombre[255];
	char categoria[255];
	char genero[10];
	int talle_s;
	int talle_m;
	int talle_l;
	int id_producto;
	float precio;
};

class Producto {
public:
	Producto(const producto_con_char& meg);
	
	void Modificar_S(int cantidad);
	void Modificar_M(int cantidad);
	void Modificar_L(int cantidad);
	
	string VerNombre();
	string VerCategoria();
	int VerTalleS();
	int VerTalleM();
	int VerTalleL();
	string VerGen();
	int Ver_id();
	float VerPrecio();
private:
	string nombre,categoria,genero;
	int talle_s;
	int talle_m;
	int talle_l;
	int id,stock;
	float precio;
};

#endif

