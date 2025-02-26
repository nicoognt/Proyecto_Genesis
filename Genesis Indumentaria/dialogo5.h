#ifndef DIALOGO5_H
#define DIALOGO5_H
#include "wxfb_project.h"

class Tienda;

class dialogo5 : public d_Filtros {
	
private:
	
	Tienda* shop;
	
protected:
	
	void OnAceptarf( wxCommandEvent& event )  override;
	
public:
	dialogo5(wxWindow *parent=NULL,Tienda* t=nullptr);
	~dialogo5();
};

#endif

