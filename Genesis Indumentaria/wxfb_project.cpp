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
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	BotonBuscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( BotonBuscar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	BotonRefrescar = new wxButton( this, wxID_ANY, wxT("Recargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( BotonRefrescar, 0, wxALL, 5 );
	
	
	bSizer5->Add( bSizer8, 0, 0, 5 );
	
	
	bSizer3->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	Grilla_Productos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	Grilla_Productos->CreateGrid( 0, 4 );
	Grilla_Productos->EnableEditing( false );
	Grilla_Productos->EnableGridLines( true );
	Grilla_Productos->EnableDragGridSize( false );
	Grilla_Productos->SetMargins( 0, 0 );
	
	// Columns
	Grilla_Productos->SetColSize( 0, 198 );
	Grilla_Productos->SetColSize( 1, 120 );
	Grilla_Productos->SetColSize( 2, 94 );
	Grilla_Productos->SetColSize( 3, 92 );
	Grilla_Productos->EnableDragColMove( false );
	Grilla_Productos->EnableDragColSize( true );
	Grilla_Productos->SetColLabelSize( 30 );
	Grilla_Productos->SetColLabelValue( 0, wxT("Nombre") );
	Grilla_Productos->SetColLabelValue( 1, wxT("Stock disp.") );
	Grilla_Productos->SetColLabelValue( 2, wxT("Precio p/u") );
	Grilla_Productos->SetColLabelValue( 3, wxT("ID") );
	Grilla_Productos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	Grilla_Productos->EnableDragRowSize( true );
	Grilla_Productos->SetRowLabelSize( 80 );
	Grilla_Productos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	Grilla_Productos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer4->Add( Grilla_Productos, 1, wxALL|wxEXPAND, 5 );
	
	
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
	BotonRefrescar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_recargar ), NULL, this );
	VerCarro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
}

ventanuli::~ventanuli()
{
	// Disconnect Events
	BotonBuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_buscar ), NULL, this );
	BotonRefrescar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_recargar ), NULL, this );
	VerCarro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
	
}
