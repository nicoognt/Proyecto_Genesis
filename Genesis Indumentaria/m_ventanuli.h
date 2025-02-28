#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

#include "Tienda.h"
#include "CarritoDeCompras.h"
#include "Factura.h"
//dialogo = ventana de ver detalles
//dialogo2 = ventana de ingresar al carrito
//dialogo3 = ventana del carrito de compras
//dialogo4 = ventana de modificar stock
//dialogo5 = ventana de los filtros
//dialogo6 = ventana de modificar el stock de un producto
//dialogo7 = ventana de las facturas de venta
//dialogo8 = ventana de los detalles de facturas
//dialogo9 = ventana para agregar un producto a la tienda
class m_ventanuli : public ventanuli {
	
private:
	
	int filaSeleccionada;
	int columnaSeleccionada;
	Tienda* genesis;
	CarritoDeCompras* car;
	vector<Factura> facturas;
	
protected:
	
	/// Botones de la ventana principal
	void m_recargar( wxCommandEvent& event )  override;
	void m_buscar( wxCommandEvent& event )  override;
	void Clic_VerCarro( wxCommandEvent& event )  override;
	void Clic_VerFiltros( wxCommandEvent& event )  override;
	void clicVentas( wxCommandEvent& event )  override;
	void ClicAgregarPNuevo( wxCommandEvent& event )  override;
	
	/// Apartado del menú contextual
	void OnRightClick( wxGridEvent& event );
	void OnVerDetalles( wxCommandEvent& event );
	void OnAgregar( wxCommandEvent& event );
	void OnModificar( wxCommandEvent& event );
	
public:
	
	/// Crear y refrescar la grilla
	void CreaGrilla();
	void RefrescarGrilla();
	
	/// Pasar/modificar el precio final del carrito 
	void SetPrecio(float p);
	float GetPrecio();
	
	/// Compartir la lista de ventas
	vector<Factura>* PasarVector();
	
	/// Compartir el carrito de compras
	CarritoDeCompras* DevolverCarrito();
	
	// Propio de wxFrame
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
	
};

#endif

