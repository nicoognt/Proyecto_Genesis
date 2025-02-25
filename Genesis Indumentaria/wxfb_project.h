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
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ventanuli
///////////////////////////////////////////////////////////////////////////////
class ventanuli : public wxFrame 
{
	private:
	
	protected:
		wxTextCtrl* BarraBusqueda;
		wxButton* BotonBuscar;
		wxButton* BotonRefrescar;
		wxGrid* Grilla_Productos;
		wxButton* VerCarro;
		wxButton* VerFiltros;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_buscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_recargar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clic_VerCarro( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clic_VerFiltros( wxCommandEvent& event ) { event.Skip(); }
		
	
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
		wxStaticText* m_staticText3;
		wxTextCtrl* barra_TalleS;
		wxStaticText* m_staticText4;
		wxTextCtrl* barra_TalleM;
		wxStaticText* m_staticText5;
		wxTextCtrl* barra_TalleL;
		wxStaticText* m_staticText7;
		wxTextCtrl* barra_Precio;
	
	public:
		
		dialogo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Detalles del producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 468,333 ), long style = wxDEFAULT_DIALOG_STYLE ); 
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
		wxButton* m_Compra;
		wxButton* m_Vaciar;
		wxStaticText* m_textoPrecio;
		wxTextCtrl* m_ValorPrecio;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnComprar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVaciar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		d_Compras( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Carrito de compras"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,346 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~d_Compras();
	
};

#endif //__WXFB_PROJECT_H__
