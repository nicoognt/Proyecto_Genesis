#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

#include "Tienda.h"
#include "CarritoDeCompras.h"
#include "Factura.h"

class m_ventanuli : public ventanuli {
	
private:
	
	int filaSeleccionada;
	int columnaSeleccionada;
	Tienda* genesis;
	CarritoDeCompras* car;
	vector<Factura> facturas;
	float PrecioFinal = 0.0f;
	
protected:
	void clicVentas( wxCommandEvent& event )  override;
	
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
	void SetPrecio(float p);
	float GetPrecio();
	vector<Factura>* PasarVector();
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
	
};

#endif

