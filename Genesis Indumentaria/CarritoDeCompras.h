#ifndef CARRITODECOMPRAS_H
#define CARRITODECOMPRAS_H
#include <vector>
using namespace std;

class Producto;
class Tienda;

class CarritoDeCompras {
public:
	
	/// El carrito empieza vacío
	CarritoDeCompras();
	
	/// Método para ver si hay productos en el carrito
	bool EstaVacio();
	const vector<Producto>& ObtenerProductos();
	void Agregar(Producto a,Tienda& t);
	void Eliminar(int id,Tienda& t);
	void Vaciar();
	void Aumentars(int id);
	void Aumentarm(int id);
	void Aumentarl(int id);
	void Disminuirs(int id);
	void Disminuirm(int id);
	void Disminuirl(int id);
	Producto MostrarProducto_C(int i);
	float CalcularTotal();
private:
	vector<Producto> compras;
};

#endif

