///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFB_PROJECT_H__
#define __WXFB_PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/dialog.h>
#include <wx/choice.h>
#include <wx/listctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ventanuli
///////////////////////////////////////////////////////////////////////////////
class ventanuli : public wxFrame 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap1;
		wxTextCtrl* BarraBusqueda;
		wxBitmapButton* BotonBuscar;
		wxBitmapButton* VerFiltros;
		wxBitmapButton* BotonRefrescar;
		wxGrid* Grilla_Productos;
		wxBitmapButton* VerCarro;
		wxBitmapButton* boton_Ventas;
		wxButton* m_AgregarP;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_buscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clic_VerFiltros( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_recargar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clic_VerCarro( wxCommandEvent& event ) { event.Skip(); }
		virtual void clicVentas( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClicAgregarPNuevo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ventanuli( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lista de productos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 606,477 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ventanuli();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DetallesProd
///////////////////////////////////////////////////////////////////////////////
class DetallesProd : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* barra_Nombre;
		wxStaticText* m_staticText6;
		wxTextCtrl* barra_Categoria;
		wxStaticText* m_staticText19;
		wxTextCtrl* barra_Genero;
		wxStaticText* m_staticText20;
		wxTextCtrl* barra_ID;
		wxStaticText* m_staticText3;
		wxTextCtrl* barra_TalleS;
		wxStaticText* m_staticText4;
		wxTextCtrl* barra_TalleM;
		wxStaticText* m_staticText5;
		wxTextCtrl* barra_TalleL;
		wxStaticText* m_staticText7;
		wxTextCtrl* barra_Precio;
	
	public:
		
		DetallesProd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Detalles del producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 468,459 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~DetallesProd();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AddCarrito
///////////////////////////////////////////////////////////////////////////////
class AddCarrito : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText11;
		wxTextCtrl* barra_TS;
		wxStaticText* m_staticText12;
		wxTextCtrl* barra_TM;
		wxStaticText* m_staticText13;
		wxTextCtrl* barra_TL;
		wxButton* boton_dial_OK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AddCarrito( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar al carrito"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 354,342 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~AddCarrito();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaCompras
///////////////////////////////////////////////////////////////////////////////
class VentanaCompras : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText39;
		wxChoice* choice_Metodo;
		wxListCtrl* listaCompras;
		wxButton* m_Vender;
		wxButton* m_Vaciar;
		wxStaticText* m_textoPrecio;
		wxTextCtrl* m_ValorPrecio;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVaciar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaCompras( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Carrito de compras"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 570,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaCompras();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_NuevaCant
///////////////////////////////////////////////////////////////////////////////
class Ventana_NuevaCant : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxTextCtrl* m_NuevaCant;
		wxButton* m_Confirmar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClicConfirmar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Ventana_NuevaCant( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar cantidad"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 329,204 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~Ventana_NuevaCant();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaFiltros
///////////////////////////////////////////////////////////////////////////////
class VentanaFiltros : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxChoice* choiceGenero;
		wxChoice* choiceCategoria;
		wxChoice* choiceOrden;
		wxStaticText* m_staticText17;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_pMax;
		wxTextCtrl* m_pMin;
		wxButton* m_fAceptar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAceptarf( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaFiltros( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Filtros de búsqueda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 399,273 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaFiltros();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaModificacion
///////////////////////////////////////////////////////////////////////////////
class VentanaModificacion : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText21;
		wxTextCtrl* barra_TalleS;
		wxStaticText* m_staticText22;
		wxTextCtrl* barra_NuevoS;
		wxStaticText* m_staticText23;
		wxTextCtrl* barra_TalleM;
		wxStaticText* m_staticText24;
		wxTextCtrl* barra_NuevoM;
		wxStaticText* m_staticText25;
		wxTextCtrl* barra_TalleL;
		wxStaticText* m_staticText26;
		wxTextCtrl* barra_NuevoL;
		wxStaticText* m_staticText27;
		wxTextCtrl* barra_PrecioAct;
		wxStaticText* m_staticText28;
		wxTextCtrl* barra_PrecioNue;
		wxButton* boton_Modificar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Modificar_Stock( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaModificacion( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar stock"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 355,361 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaModificacion();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaFacturas
///////////////////////////////////////////////////////////////////////////////
class VentanaFacturas : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* listaVentas;
	
	public:
		
		VentanaFacturas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Registro de ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 394,393 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaFacturas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class Ventana_DetalleFacts
///////////////////////////////////////////////////////////////////////////////
class Ventana_DetalleFacts : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* listaDetalles;
		wxBitmapButton* botonDescargar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClicDescargar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Ventana_DetalleFacts( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 454,313 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~Ventana_DetalleFacts();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class V_AgregarProd
///////////////////////////////////////////////////////////////////////////////
class V_AgregarProd : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText29;
		wxTextCtrl* barra_Nom;
		wxStaticText* m_staticText30;
		wxChoice* choice_Cat;
		wxStaticText* m_staticText37;
		wxChoice* choice_Gen;
		wxStaticText* m_staticText32;
		wxTextCtrl* barra_TS;
		wxStaticText* m_staticText33;
		wxTextCtrl* barra_TM;
		wxStaticText* m_staticText34;
		wxTextCtrl* barra_TL;
		wxStaticText* m_staticText35;
		wxTextCtrl* barra_Precio;
		wxButton* m_botonAceptar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClicAceptarPNuevo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		V_AgregarProd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Especificar características"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 410,346 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~V_AgregarProd();
	
};

#endif //__WXFB_PROJECT_H__
