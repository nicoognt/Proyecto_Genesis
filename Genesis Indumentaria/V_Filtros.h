#ifndef V_FILTROS_H
#define V_FILTROS_H
#include "wxfb_project.h"
class Tienda;
class V_Filtros : public VentanaFiltros {
	
private:
	Tienda* shop;
protected:
	void OnAceptarf( wxCommandEvent& event )  override;
public:
	V_Filtros(wxWindow *parent=NULL,Tienda* t=nullptr);
	~V_Filtros();
};

#endif

