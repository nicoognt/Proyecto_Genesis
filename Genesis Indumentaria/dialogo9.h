#ifndef DIALOGO9_H
#define DIALOGO9_H
#include "wxfb_project.h"

class Tienda;

class dialogo9 : public d_AgregarP {
	
private:
	
	Tienda* genesis;
	
protected:
	
	void ClicAceptarPNuevo( wxCommandEvent& event )  override;
	
public:
	dialogo9(wxWindow *parent=NULL, Tienda *t=nullptr);
	~dialogo9();
};

#endif

