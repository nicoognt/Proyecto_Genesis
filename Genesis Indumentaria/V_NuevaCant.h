#ifndef V_NUEVACANT_H
#define V_NUEVACANT_H
#include "wxfb_project.h"
class Producto;
class Tienda;
class V_NuevaCant : public Ventana_NuevaCant {
	
private:
	Producto *pr;
	Tienda *t;
protected:
	void ClicConfirmar( wxCommandEvent& event )  override;
public:
	V_NuevaCant(wxWindow *parent=NULL,Producto* p=nullptr,Tienda* t=nullptr);
	~V_NuevaCant();
};

#endif




