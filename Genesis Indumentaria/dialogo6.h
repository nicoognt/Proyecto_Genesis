#ifndef DIALOGO6_H
#define DIALOGO6_H
#include "wxfb_project.h"

class Producto;

class dialogo6 : public d_Modificar {
	
private:
	
	Producto *producto_tienda;
	
protected:
	
	void Modificar_Stock( wxCommandEvent& event )  override;
	
public:
	dialogo6(wxWindow *parent=NULL, Producto *p=nullptr);
	~dialogo6();
};

#endif

