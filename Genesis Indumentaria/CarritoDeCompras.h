#ifndef CARRITODECOMPRAS_H
#define CARRITODECOMPRAS_H
#include <vector>
using namespace std;

class Producto;



class CarritoDeCompras {
public:
	
	/// El carrito empieza vacío
	CarritoDeCompras();
	
	/// Método para ver si hay productos en el carrito
	bool EstaVacio();
	const vector<pair<Producto,int>>& ObtenerProductos();
	void Agregar(Producto a);
	void Eliminar(int id);
	void Vaciar();
	void Aumentar(int id);
	void Disminuir(int id);
	pair<Producto,int> MostrarCompra(int i);
	float CalcularTotal();
private:
	vector<pair<Producto,int>> compras;
};

#endif

