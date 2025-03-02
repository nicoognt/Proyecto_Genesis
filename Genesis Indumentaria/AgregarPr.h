#ifndef AGREGARPR_H
#define AGREGARPR_H
#include "wxfb_project.h"
class Tienda;
class AgregarPr : public V_AgregarProd {
	
private:
	Tienda* genesis;
protected:
	void ClicAceptarPNuevo( wxCommandEvent& event )  override;
	
public:
	AgregarPr(wxWindow *parent=NULL,Tienda* t=nullptr);
	~AgregarPr();
};

#endif

