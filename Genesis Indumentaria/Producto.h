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
private:
	
	string nombre,categoria,genero;
	/// Se guarda el stock particular de c/talle
	int talle_s;
	int talle_m;
	int talle_l;
	
	int id;
	float precio;
	
public:
	
	/** Se define el const. de esta forma para que existan
	* métodos que exclusivamente importen o exporten desde
	* un archivo binario.
	**/
	Producto(string nom="",string cat="",string gen="",int tS=0,
			 int tM=0,int tL=0,int Id=0,float p=0);
	
	/// Métodos para modificar c/u de los stocks
	void Modificar_S(int cantidad);
	void Modificar_M(int cantidad);
	void Modificar_L(int cantidad);
	
	/// Métodos que devuelven todos los datos de un producto
	string VerNombre();
	string VerCategoria();
	int VerTalleS();
	int VerTalleM();
	int VerTalleL();
	string VerGen();
	int Ver_id();
	float VerPrecio();
	
	/// Método para importar desde un archivo binario
	void CargarDesdeBin(ifstream& archivo);
	/// Método para exportar a un archivo binario
	void SubirEnBin(ofstream& archivo);
	
	/// Sobrecargas útiles
	Producto operator+(Producto a);
	Producto operator-(Producto a);
	
};

#endif




