#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

#include "Tienda.h"

class m_ventanuli : public ventanuli {
	
private:
	Tienda* genesis;
	
protected:
	void m_recargar( wxCommandEvent& event )  override;
	void m_buscar( wxCommandEvent& event )  override;
	void Clic_VerCarro( wxCommandEvent& event )  override;
	void Clic_VerFiltros( wxCommandEvent& event )  override;
	void OnRightClick( wxGridEvent& event );
	void OnEliminar( wxCommandEvent& event );
	void OnEditar( wxCommandEvent& event );
	void OnVerStock( wxCommandEvent& event );
	
public:
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
};

#endif








