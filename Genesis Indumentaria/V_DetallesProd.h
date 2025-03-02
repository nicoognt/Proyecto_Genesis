#ifndef V_DETALLESPROD_H
#define V_DETALLESPROD_H
#include "wxfb_project.h"
#include "Producto.h"

class V_DetallesProd : public DetallesProd {
	
private:
	
	Producto a_mostrar;
	
protected:
	
public:
	V_DetallesProd(wxWindow *parent=NULL,Producto x =Producto());
	void CargarDatos();
	~V_DetallesProd();
};

#endif

