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
	
	Tienda(string nom);
	Producto MostrarProducto(int i);
	Factura RealizarVenta(CarritoDeCompras& carrito);
	void AgregarProducto(Producto A);
	int CantidadProductos();
	
private:
	
	/** Similar al ejemplo de la agenda: nombre del archivo para importar y exportar datos
	*	as� como el vector contenedor con lo que se va a laburar
	**/
	string file_name;
	vector<Producto> lista;
	
	bool hombre,mujer;
	bool ta_s,ta_m,ta_l;
	bool precio_asc,precio_des;
	
};

bool ordenar_producto(Producto a1,Producto a2);

#endif

