#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>
#include "Factura.h"
#include "CarritoDeCompras.h"
#include <wx/string.h>
using namespace std;

class Producto;

class Tienda {
private:
	// Nombre del archivo donde se encuentran los datos
	string file_name;
	// Dos vectores: uno para conservar/modificar los datos; el otro se utiliza en la muestra de los productos
	vector<Producto> vector_base; vector<Producto> vector_filtros;
	
	
public:
	
	// El constructor recibe un nombre para abrir el archivo donde se encuentren los datos
	Tienda(string nom="Productos_Genesis.dat");
	
	// Retornar un producto de la lista mostrada
	Producto MostrarProducto(int i);
	// Devolver un producto de la lista base usando el id o un indice
	Producto* MostrarConId(int id);
	Producto* Mostrarptr(int i);
	// Metodo utilizado en la creacion aleatoria de un id para un nuevo producto
	bool EsIgual(int id);
	
	// Agregar un producto a la tienda
	void AgregarProducto(Producto A);
	// Buscar un producto en la tienda para sumarle el stock de otro (usado cuando se vacía el carrito de compras)
	void RestaurarStock(Producto a);
	// Cantidad de productos en la tienda
	int CantidadProductos();
	
	// Método para ordenar el vector
	void OrdenarVector();
	// Segun los valores recibidos, se usaran los criterios correspondientes para ordenar los vectores
	void AplicarFiltros(const wxString& genero,const wxString& categoria, const wxString& orden, float precioMin, float precioMax=999999);
	
	// Obtener el vector de filtros para mostrarlo
	const vector<Producto>& ObtenerFiltros();
	// Metodo para igualar la lista base con la mostrada (en cuanto a orden)
	void ReestablecerListas();
	
	// Actualizacion del binario en caso de agregar un producto nuevo
	void ActualizarBinario();
};

/// Diferentes criterios de comparacion para ordenar el vector de productos.
bool orden_alfabetico(Producto a1,Producto a2);

bool orden_precioAsc(Producto a1,Producto a2);

bool orden_precioDes(Producto a1,Producto a2);

bool archivoExiste(const string& n);

#endif




