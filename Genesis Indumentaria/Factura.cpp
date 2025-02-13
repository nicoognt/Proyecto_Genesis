#include "Factura.h"
#include <vector>
#include "Producto.h"
#include <fstream>
using namespace std;

Factura::Factura(vector<pair<Producto,int>> items,float total) {
	productosComprados = items;
	totalVenta = total;
}

void Factura::ImprimirFactura(){
	ofstream guardar("compra.txt");
	if(!guardar.is_open()) throw runtime_error("Error al abrir el archivo para guardar la compra");
	guardar << "compra numero tanto";
	guardar.close();
}
