#ifndef DIALOGO_H
#define DIALOGO_H
#include "wxfb_project.h"
#include "Producto.h"

class d_Detalles : public dialogo {
	
private:
	
	Producto a_mostrar;
	
protected:
	
public:
	d_Detalles(wxWindow *parent=NULL,Producto x =Producto());
	void CargarDatos();
	~d_Detalles();
};

#endif



