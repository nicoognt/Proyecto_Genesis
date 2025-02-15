#ifndef CARRITODECOMPRAS_H
#define CARRITODECOMPRAS_H
#include <vector>
using namespace std;

class Producto;
class Tienda;

class CarritoDeCompras {
public:
	
	/// El carrito empieza vac�o.
	CarritoDeCompras();
	
	/// M�todo para ver si hay productos en el carrito.
	bool EstaVacio();
	vector<Producto>& ObtenerProductos();
	
	/// Agregar o eliminar productos al carrito, y modificar el stock original
	/// de la tienda.
	void Agregar(Producto a,Tienda& t);
	void Eliminar(int id,Tienda& t);
	
	/// M�todo para vaciar el vector de carrito.
	void Vaciar();
	
	/// Aumentar o disminuir cu�ntas unidades se llevan de c/talle.
	void Aumentar(int pos, Tienda &t);
	void Disminuir (int pos, Tienda &t);
	
	
	Producto MostrarProducto_C(int i);
	float CalcularTotal();
	
private:
	vector<Producto> compras;
};

#endif

