#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

class m_ventanuli : public ventanuli {
	
private:
	
protected:
	void m_buscar( wxCommandEvent& event )  override;
	void Casilla_ClicDerecho( wxGridEvent& event )  override;
	void Clic_VerCarro( wxCommandEvent& event )  override;
	void Clic_VerFiltros( wxCommandEvent& event )  override;
	
public:
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
};

#endif

