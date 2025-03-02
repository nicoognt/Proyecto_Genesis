#ifndef FACTS_DETALLE_H
#define FACTS_DETALLE_H
#include "wxfb_project.h"
#include <vector>
#include <string>
using namespace std;
class Producto;
class Facts_detalle : public Ventana_DetalleFacts {
	
private:
	vector<Producto> productosVendidos;
	string fecha_venta;
	string metodo_DePago;
protected:
	void ClicDescargar( wxCommandEvent& event )  override;
public:
	Facts_detalle(wxWindow *parent=NULL,vector<Producto> a={},string fecha="",string metodo="");
	~Facts_detalle();
	void CargarProductos();
};

#endif






