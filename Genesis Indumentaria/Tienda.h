#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>
#include "Factura.h"
#include "CarritoDeCompras.h"
using namespace std;

class Producto;

class Tienda {
private:
	
	/** Similar al ejemplo de la agenda: nombre del archivo para importar y exportar datos
	*	así como el vector contenedor con lo que se va a laburar
	**/
	string file_name;
	vector<Producto> vector_base; vector<Producto> vector_filtros;
	
	
public:
	
	/// El constructor recibe un nombre para abrir el archivo donde se encuentren los datos
	Tienda(string nom="Productos_Genesis.dat");
	
	/// Retornar un elemento cuando se lo muestre en la interfaz
	Producto MostrarProducto(int i);
	Producto* Mostrarptr(int i);
	
	/// Agregar un producto a la tienda y guardarlo en el .dat
	void AgregarProducto(Producto A);
	
	/// Cuántos productos hay en la tienda
	int CantidadProductos();
	
	/// Método para ordenar el vector
	void OrdenarVector();
};

/// Diferentes criterios de comparacion para ordenar el vector de productos.
bool orden_alfabetico(Producto a1,Producto a2);

bool orden_precioAsc(Producto a1,Producto a2);

bool orden_precioDes(Producto a1,Producto a2);

#endif


