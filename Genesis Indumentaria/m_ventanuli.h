#ifndef M_VENTANULI_H
#define M_VENTANULI_H
#include "wxfb_project.h"

#include "Tienda.h"
#include "CarritoDeCompras.h"
#include "Factura.h"
// V_DetallesProd = ventana de ver detalles
// V_SumarCarrito = ventana de ingresar al carrito
// V_Compras = ventana del carrito de compras
// V_NuevaCant = ventana de modificar stock
// V_Filtros = ventana de los filtros
// V_Modificar = ventana de modificar el stock de un producto
// Lista_Facturas = ventana de las facturas de venta
// Facts_detalle = ventana de los detalles de facturas
// AgregarPr = ventana para agregar un producto a la tienda
class m_ventanuli : public ventanuli {
	
private:
	// Se guardan tanto la fila como la columna seleccionada al momento de interactuar sobre alguna celda
	int filaSeleccionada;
	int columnaSeleccionada;
	// ¿Que necesita para funcionar? -> La tienda con los productos y un carrito en donde cargar los productos por vender
	Tienda* genesis;
	CarritoDeCompras* car;
	// Al momento de vender, la ventana principal almacena las facturas generadas
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
	
	// Compartir la lista de ventas -> Usado en el carrito de compras, en el caso de vender los productos y generar una factura
	vector<Factura>* PasarVector();
	
	// Compartir el carrito de compras
	CarritoDeCompras* DevolverCarrito();
	
	m_ventanuli(wxWindow *parent=NULL);
	~m_ventanuli();
	
};

#endif

