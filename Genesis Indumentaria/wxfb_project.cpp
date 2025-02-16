///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

ventanuli::ventanuli( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	BarraBusqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( BarraBusqueda, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	BotonBuscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( BotonBuscar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer5->Add( bSizer8, 0, wxEXPAND, 5 );
	
	
	bSizer3->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 5, 4 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 168 );
	grilla->SetColSize( 1, 103 );
	grilla->SetColSize( 2, 80 );
	grilla->SetColSize( 3, 80 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("Categoria") );
	grilla->SetColLabelValue( 2, wxT("Stock disp.") );
	grilla->SetColLabelValue( 3, wxT("Precio p/u") );
	grilla->SetColLabelValue( 4, wxEmptyString );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 80 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer4->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	VerCarro = new wxButton( this, wxID_ANY, wxT("Ver carrito"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( VerCarro, 0, wxALL, 5 );
	
	VerFiltros = new wxButton( this, wxID_ANY, wxT("Ver filtros"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( VerFiltros, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer9, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	BotonBuscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_buscar ), NULL, this );
	grilla->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( ventanuli::Casilla_ClicDerecho ), NULL, this );
	VerCarro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
}

ventanuli::~ventanuli()
{
	// Disconnect Events
	BotonBuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_buscar ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( ventanuli::Casilla_ClicDerecho ), NULL, this );
	VerCarro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
	
}
