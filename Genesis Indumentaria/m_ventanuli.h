#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

#include "Tienda.h"
#include "CarritoDeCompras.h"

class m_ventanuli : public ventanuli {
	
private:
	
	int filaSeleccionada;
	int columnaSeleccionada;
	Tienda* genesis;
	CarritoDeCompras* car;
	
protected:
	
	CarritoDeCompras* DevolverCarrito();
	
	void m_recargar( wxCommandEvent& event )  override;
	void m_buscar( wxCommandEvent& event )  override;
	void Clic_VerCarro( wxCommandEvent& event )  override;
	void Clic_VerFiltros( wxCommandEvent& event )  override;
	
	/// Método para cargar la grilla
	void CreaGrilla();
	void RefrescarGrilla();
	
	/// Apartado del menú contextual
	void OnRightClick( wxGridEvent& event );
	void OnVerDetalles( wxCommandEvent& event );
	void OnAgregar( wxCommandEvent& event );
	void OnModificar( wxCommandEvent& event );
	
public:
	
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
	
};

#endif


