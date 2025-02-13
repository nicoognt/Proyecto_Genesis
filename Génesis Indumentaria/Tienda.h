#ifndef TIENDA_H
#define TIENDA_H
#include <vector>
#include <string>
using namespace std;

class Producto;

class Tienda {
public:
	Tienda();
	void FiltroHombre();
	void FiltroMujer();
	void Filtro_S();
	void Filtro_M();
	void Filtro_L();
	void Filtro_Precio_Asc();
	void Filtro_Precio_Des();
	void MostrarProductos();
private:
	vector<Producto> lista;
	vector<Producto> copia_para_filtros;
	bool hombre,mujer;
	bool ta_s,ta_m,ta_l;
	bool precio_asc,precio_des;
	int estrellas;
	string busqueda;
};

#endif

