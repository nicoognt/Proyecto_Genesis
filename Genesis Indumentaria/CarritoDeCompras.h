#ifndef CARRITODECOMPRAS_H
#define CARRITODECOMPRAS_H
#include <vector>
using namespace std;

class Producto;
class Tienda;
class Factura;

class CarritoDeCompras {
private:
	
	vector<Producto> compras;
	
public:
	
	/// El carrito empieza vacío.
	CarritoDeCompras();
	
	/// Método para ver si hay productos en el carrito.
	bool EstaVacio();
	int CantProductos();
	Producto ObtenerProducto(int i);
	Producto* ObtenerProductoPtr(int i);
	
	/// Agregar o eliminar productos al carrito, y modificar el stock original
	/// de la tienda.
	void Agregar(Producto a);
	void Eliminar(int id);
	Factura Vender();
	
	/// Método para vaciar el vector de carrito.
	void Vaciar();
	
	Producto VerProducto(int id);
	float CalcularTotal();
	
};

#endif






