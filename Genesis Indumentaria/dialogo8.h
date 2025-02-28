#ifndef DIALOGO8_H
#define DIALOGO8_H
#include "wxfb_project.h"
#include <vector>
using namespace std;

class Producto;

class dialogo8 : public d_DetalleVenta {
	
private:
	
	vector<Producto> productosVendidos;
	
protected:
	
	void ClicDescargar( wxCommandEvent& event )  override;
	
public:
	dialogo8(wxWindow *parent=NULL,vector<Producto> a={});
	~dialogo8();
};

#endif

