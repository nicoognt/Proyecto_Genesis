#ifndef DIALOGO8_H
#define DIALOGO8_H
#include "wxfb_project.h"

class dialogo8 : public d_DetalleVenta {
	
private:
	
protected:
	void ClicDescargar( wxCommandEvent& event )  override;
	
public:
	dialogo8(wxWindow *parent=NULL);
	~dialogo8();
};

#endif

