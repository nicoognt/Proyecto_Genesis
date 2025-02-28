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
#include <wx/listctrl.h>
#include <wx/choice.h>

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
/// Class dialogo
///////////////////////////////////////////////////////////////////////////////
class dialogo : public wxDialog 
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
		
		dialogo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Detalles del producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 468,459 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~dialogo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Carrito
///////////////////////////////////////////////////////////////////////////////
class d_Carrito : public wxDialog 
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
		
		d_Carrito( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar al carrito"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 354,342 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Carrito();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Compras
///////////////////////////////////////////////////////////////////////////////
class d_Compras : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* listaCompras;
		wxButton* m_Vender;
		wxButton* m_Vaciar;
		wxStaticText* m_textoPrecio;
		wxTextCtrl* m_ValorPrecio;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVaciar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_Compras( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Carrito de compras"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,346 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Compras();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog4
///////////////////////////////////////////////////////////////////////////////
class MyDialog4 : public wxDialog 
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
		
		MyDialog4( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar cantidad"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 329,204 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog4();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Filtros
///////////////////////////////////////////////////////////////////////////////
class d_Filtros : public wxDialog 
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
		
		d_Filtros( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Filtros de búsqueda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 399,273 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Filtros();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Modificar
///////////////////////////////////////////////////////////////////////////////
class d_Modificar : public wxDialog 
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
		
		d_Modificar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Modificar stock"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 355,361 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Modificar();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_Facturas
///////////////////////////////////////////////////////////////////////////////
class d_Facturas : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* listaVentas;
	
	public:
		
		d_Facturas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Registro de ventas"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 394,393 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Facturas();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_DetalleVenta
///////////////////////////////////////////////////////////////////////////////
class d_DetalleVenta : public wxDialog 
{
	private:
	
	protected:
		wxListCtrl* listaDetalles;
		wxBitmapButton* botonDescargar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClicDescargar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_DetalleVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 454,313 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_DetalleVenta();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class d_AgregarP
///////////////////////////////////////////////////////////////////////////////
class d_AgregarP : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText29;
		wxTextCtrl* barra_Nom;
		wxStaticText* m_staticText30;
		wxChoice* choice_Cat;
		wxStaticText* m_staticText37;
		wxChoice* choice_Gen;
		wxStaticText* m_staticText31;
		wxTextCtrl* barra_ID;
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
		
		d_AgregarP( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Especificar características"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 410,434 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_AgregarP();
	
};

#endif //__WXFB_PROJECT_H__
