#ifndef V_MODIFICAR_H
#define V_MODIFICAR_H
#include "wxfb_project.h"
class Producto;
class V_Modificar : public VentanaModificacion {
	
private:
	Producto *producto_tienda;
protected:
	void Modificar_Stock( wxCommandEvent& event )  override;
public:
	V_Modificar(wxWindow *parent=NULL,Producto* p=nullptr);
	~V_Modificar();
};

#endif

