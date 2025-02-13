#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>
#include "Tienda.h"
using namespace std;

struct producto_con_char{
	char nombre[255];
	char categoria[255];
	bool S,M,L,hombre,mujer;
	int id_producto,estrellas;
	float precio;
};

class Producto {
public:
	Producto(const producto_con_char& meg);
	string VerNombre();
	bool VerHombre();
	bool VerMujer();
	bool VerS();
	bool VerM();
	bool VerL();
	int VerEstrellas();
	float VerPrecio();
private:
	string nombre;
	bool talle_S,talle_M,talle_L,hombre,mujer;
	int estrellas;
	float precio;
};

#endif

