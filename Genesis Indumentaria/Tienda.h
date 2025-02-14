#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>
#include "Factura.h"
#include "CarritoDeCompras.h"
using namespace std;

class Producto;
struct

class Tienda {
public:
	
	Tienda(string nom);
	vector<Producto> MostrarVector();
	Producto& MostrarProducto(int i);
	Factura RealizarVenta(CarritoDeCompras& carrito);
	void AgregarProducto(Producto A);
	int CantidadProductos();
	
private:
	
	/** Similar al ejemplo de la agenda: nombre del archivo para importar y exportar datos
	*	así como el vector contenedor con lo que se va a laburar
	**/
	string file_name;
	vector<Producto> vector_base;vector<Producto> vector_filtros;
	
	/// Puede llegar a no servir que esté acá
	bool hombre,mujer;
	bool ta_s,ta_m,ta_l;
	bool precio_asc,precio_des;
	
};
/// Diferentes criterios de comparacion para ordenar el vector de productos.
bool orden_alfabetico(Producto a1,Producto a2);

bool orden_precioAsc(Producto a1,Producto a2);

bool orden_precioDes(Producto a1,Producto a2);

#endif

