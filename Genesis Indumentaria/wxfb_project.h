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
		wxGrid* Grilla_Productos;
		wxButton* VerCarro;
		wxButton* VerFiltros;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_buscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void Casilla_ClicDerecho( wxGridEvent& event ) { event.Skip(); }
		virtual void Clic_VerCarro( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clic_VerFiltros( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ventanuli( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lista de productos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 530,477 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ventanuli();
	
};

#endif //__WXFB_PROJECT_H__
