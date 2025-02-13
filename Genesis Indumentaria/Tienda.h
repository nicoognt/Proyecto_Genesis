#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>
#include "Factura.h"
#include "CarritoDeCompras.h"
using namespace std;

class Producto;

class Tienda {
public:
	
	Tienda();
	Producto MostrarProducto(int i);
	Factura RealizarVenta(CarritoDeCompras& carrito);
	void AgregarProducto(Producto A);
	int CantidadProductos();
	
private:
	
	vector<Producto> lista;
	bool hombre,mujer;
	bool ta_s,ta_m,ta_l;
	bool precio_asc,precio_des;
	int estrellas;
	string busqueda;
	
	
};

bool ordenar_producto(Producto a1,Producto a2);

#endif

