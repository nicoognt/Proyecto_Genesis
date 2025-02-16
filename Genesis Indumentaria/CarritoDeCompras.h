#ifndef CARRITODECOMPRAS_H
#define CARRITODECOMPRAS_H
#include <vector>
using namespace std;

class Producto;
class Tienda;

class CarritoDeCompras {
private:
	
	vector<Producto> compras;
	
public:
	
	/// El carrito empieza vacío.
	CarritoDeCompras();
	
	/// Método para ver si hay productos en el carrito.
	bool EstaVacio();
	vector<Producto>& ObtenerProductos();
	
	/// Agregar o eliminar productos al carrito, y modificar el stock original
	/// de la tienda.
	void Agregar(Producto a);
	void Eliminar(int id);
	
	/// Método para vaciar el vector de carrito.
	void Vaciar();
	
	/// Aumentar o disminuir cuántas unidades se llevan de c/talle.
	void Aumentar(int pos);
	void Disminuir (int pos);
	
	Producto VerProducto(int id);
	float CalcularTotal();
	
};

#endif

