#ifndef DIALOGO4_H
#define DIALOGO4_H
#include "wxfb_project.h"

class Producto;
class Tienda;

class dialogo4 : public MyDialog4 {
	
private:
	
	Producto *pr;
	Tienda *t;
	
protected:
	void ClicConfirmar( wxCommandEvent& event )  override;
	
public:
	dialogo4(wxWindow *parent=NULL,Producto* p=nullptr,Tienda* t=nullptr);
	~dialogo4();
};

#endif

