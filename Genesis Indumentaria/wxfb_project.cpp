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
	bSizer8->Add( BotonBuscar, 0, wxALL, 5 );
	
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
	
	boton_Ventas = new wxButton( this, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( boton_Ventas, 0, wxALL, 5 );
	
	
	bSizer9->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_AgregarP = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_AgregarP, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer9, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	BotonBuscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_buscar ), NULL, this );
	BotonRefrescar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_recargar ), NULL, this );
	VerCarro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
	boton_Ventas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::clicVentas ), NULL, this );
	m_AgregarP->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::ClicAgregarPNuevo ), NULL, this );
}

ventanuli::~ventanuli()
{
	// Disconnect Events
	BotonBuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_buscar ), NULL, this );
	BotonRefrescar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::m_recargar ), NULL, this );
	VerCarro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerCarro ), NULL, this );
	VerFiltros->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::Clic_VerFiltros ), NULL, this );
	boton_Ventas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::clicVentas ), NULL, this );
	m_AgregarP->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanuli::ClicAgregarPNuevo ), NULL, this );
	
}

dialogo::dialogo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer8->Add( m_staticText1, 0, wxALL, 5 );
	
	barra_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_Nombre->Enable( false );
	barra_Nombre->SetMinSize( wxSize( 300,25 ) );
	barra_Nombre->SetMaxSize( wxSize( 300,25 ) );
	
	bSizer8->Add( barra_Nombre, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Categoría:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer8->Add( m_staticText6, 0, wxALL, 5 );
	
	barra_Categoria = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_Categoria->Enable( false );
	barra_Categoria->SetMinSize( wxSize( 300,25 ) );
	barra_Categoria->SetMaxSize( wxSize( 300,25 ) );
	
	bSizer8->Add( barra_Categoria, 0, wxALL, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Género:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer8->Add( m_staticText19, 0, wxALL, 5 );
	
	barra_Genero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_Genero->Enable( false );
	barra_Genero->SetMinSize( wxSize( 300,25 ) );
	barra_Genero->SetMaxSize( wxSize( 300,25 ) );
	
	bSizer8->Add( barra_Genero, 0, wxALL, 5 );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("ID:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer8->Add( m_staticText20, 0, wxALL, 5 );
	
	barra_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_ID->Enable( false );
	
	bSizer8->Add( barra_ID, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer8, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Talles S:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer10->Add( m_staticText3, 0, wxALL, 5 );
	
	barra_TalleS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleS->Enable( false );
	barra_TalleS->SetMinSize( wxSize( -1,25 ) );
	barra_TalleS->SetMaxSize( wxSize( -1,25 ) );
	
	bSizer10->Add( barra_TalleS, 0, wxALL, 5 );
	
	
	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Talles M:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer11->Add( m_staticText4, 0, wxALL, 5 );
	
	barra_TalleM = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleM->Enable( false );
	barra_TalleM->SetMinSize( wxSize( -1,25 ) );
	barra_TalleM->SetMaxSize( wxSize( -1,25 ) );
	
	bSizer11->Add( barra_TalleM, 0, wxALL, 5 );
	
	
	bSizer9->Add( bSizer11, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Talles L:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer12->Add( m_staticText5, 0, wxALL, 5 );
	
	barra_TalleL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleL->Enable( false );
	barra_TalleL->SetMinSize( wxSize( -1,25 ) );
	barra_TalleL->SetMaxSize( wxSize( -1,25 ) );
	
	bSizer12->Add( barra_TalleL, 0, wxALL, 5 );
	
	
	bSizer9->Add( bSizer12, 1, wxEXPAND, 5 );
	
	
	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer13->Add( m_staticText7, 0, wxALL, 5 );
	
	barra_Precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_Precio->Enable( false );
	
	bSizer13->Add( barra_Precio, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer13, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer7 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

dialogo::~dialogo()
{
}

d_Carrito::d_Carrito( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("¿Cuántas unidades p/talle desesa llevar?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer15->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Talles S:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer15->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	barra_TS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( barra_TS, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Talles M:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer15->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	barra_TM = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( barra_TM, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Talles L:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer15->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	barra_TL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( barra_TL, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );
	
	boton_dial_OK = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( boton_dial_OK, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	this->SetSizer( bSizer14 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	boton_dial_OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Carrito::OnOK ), NULL, this );
}

d_Carrito::~d_Carrito()
{
	// Disconnect Events
	boton_dial_OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Carrito::OnOK ), NULL, this );
	
}

d_Compras::d_Compras( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	listaCompras = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxSize( 425,210 ), wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer16->Add( listaCompras, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_Vender = new wxButton( this, wxID_ANY, wxT("Vender"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_Vender, 0, wxALL, 5 );
	
	m_Vaciar = new wxButton( this, wxID_ANY, wxT("Vaciar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_Vaciar, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textoPrecio = new wxStaticText( this, wxID_ANY, wxT("Precio final:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textoPrecio->Wrap( -1 );
	bSizer17->Add( m_textoPrecio, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_ValorPrecio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_ValorPrecio->Enable( false );
	
	bSizer17->Add( m_ValorPrecio, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer19->Add( bSizer17, 0, 0, 5 );
	
	
	bSizer16->Add( bSizer19, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer16 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Vender->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnVender ), NULL, this );
	m_Vaciar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnVaciar ), NULL, this );
}

d_Compras::~d_Compras()
{
	// Disconnect Events
	m_Vender->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnVender ), NULL, this );
	m_Vaciar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnVaciar ), NULL, this );
	
}

MyDialog4::MyDialog4( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Ingrese nueva cantidad de unidades:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer22->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer22->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_NuevaCant = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_NuevaCant, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer20->Add( bSizer22, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_Confirmar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_Confirmar, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizer20->Add( bSizer21, 0, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer20 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_Confirmar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClicConfirmar ), NULL, this );
}

MyDialog4::~MyDialog4()
{
	// Disconnect Events
	m_Confirmar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog4::ClicConfirmar ), NULL, this );
	
}

d_Filtros::d_Filtros( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Género:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer24->Add( m_staticText14, 1, wxALL, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Categoría:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer24->Add( m_staticText15, 1, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Orden:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer24->Add( m_staticText16, 1, wxALL, 5 );
	
	
	bSizer23->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString choiceGeneroChoices[] = { wxT("Todos"), wxT("Hombre"), wxT("Mujer") };
	int choiceGeneroNChoices = sizeof( choiceGeneroChoices ) / sizeof( wxString );
	choiceGenero = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceGeneroNChoices, choiceGeneroChoices, 0 );
	choiceGenero->SetSelection( 0 );
	bSizer25->Add( choiceGenero, 1, wxALL, 5 );
	
	wxString choiceCategoriaChoices[] = { wxT("Todas"), wxT("Deportivo"), wxT("Formal"), wxT("Urbano") };
	int choiceCategoriaNChoices = sizeof( choiceCategoriaChoices ) / sizeof( wxString );
	choiceCategoria = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceCategoriaNChoices, choiceCategoriaChoices, 0 );
	choiceCategoria->SetSelection( 0 );
	bSizer25->Add( choiceCategoria, 1, wxALL, 5 );
	
	wxString choiceOrdenChoices[] = { wxT("Alfabético"), wxT("Precio ascendente"), wxT("Precio descendente"), wxEmptyString };
	int choiceOrdenNChoices = sizeof( choiceOrdenChoices ) / sizeof( wxString );
	choiceOrden = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceOrdenNChoices, choiceOrdenChoices, 0 );
	choiceOrden->SetSelection( 0 );
	bSizer25->Add( choiceOrden, 0, wxALL, 5 );
	
	
	bSizer23->Add( bSizer25, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Precio máximo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer27->Add( m_staticText17, 0, wxALL, 5 );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Precio mínimo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer27->Add( m_staticText18, 0, wxALL, 5 );
	
	
	bSizer26->Add( bSizer27, 0, 0, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	m_pMax = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_pMax, 0, wxALL, 5 );
	
	m_pMin = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_pMin, 0, wxALL, 5 );
	
	
	bSizer26->Add( bSizer28, 1, wxEXPAND, 5 );
	
	
	bSizer23->Add( bSizer26, 1, wxEXPAND, 5 );
	
	m_fAceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_fAceptar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer23 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_fAceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Filtros::OnAceptarf ), NULL, this );
}

d_Filtros::~d_Filtros()
{
	// Disconnect Events
	m_fAceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Filtros::OnAceptarf ), NULL, this );
	
}

d_Modificar::d_Modificar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Talles S existentes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer32->Add( m_staticText21, 0, wxALL, 5 );
	
	barra_TalleS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleS->Enable( false );
	
	bSizer32->Add( barra_TalleS, 0, wxALL, 5 );
	
	
	bSizer30->Add( bSizer32, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Nueva cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer33->Add( m_staticText22, 0, wxALL, 5 );
	
	barra_NuevoS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( barra_NuevoS, 0, wxALL, 5 );
	
	
	bSizer30->Add( bSizer33, 1, wxEXPAND, 5 );
	
	
	bSizer29->Add( bSizer30, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Talles M existentes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer34->Add( m_staticText23, 0, wxALL, 5 );
	
	barra_TalleM = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleM->Enable( false );
	
	bSizer34->Add( barra_TalleM, 0, wxALL, 5 );
	
	
	bSizer31->Add( bSizer34, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Nueva cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer35->Add( m_staticText24, 0, wxALL, 5 );
	
	barra_NuevoM = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( barra_NuevoM, 0, wxALL, 5 );
	
	
	bSizer31->Add( bSizer35, 1, wxEXPAND, 5 );
	
	
	bSizer29->Add( bSizer31, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Talles L existentes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer37->Add( m_staticText25, 0, wxALL, 5 );
	
	barra_TalleL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_TalleL->Enable( false );
	
	bSizer37->Add( barra_TalleL, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer37, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Nueva cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer38->Add( m_staticText26, 0, wxALL, 5 );
	
	barra_NuevoL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( barra_NuevoL, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer38, 1, wxEXPAND, 5 );
	
	
	bSizer29->Add( bSizer36, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Precio actual:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer42->Add( m_staticText27, 0, wxALL, 5 );
	
	barra_PrecioAct = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_PrecioAct->Enable( false );
	
	bSizer42->Add( barra_PrecioAct, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer42, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Nuevo precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer43->Add( m_staticText28, 0, wxALL, 5 );
	
	barra_PrecioNue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( barra_PrecioNue, 0, wxALL, 5 );
	
	
	bSizer41->Add( bSizer43, 1, wxEXPAND, 5 );
	
	
	bSizer29->Add( bSizer41, 1, wxEXPAND, 5 );
	
	boton_Modificar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( boton_Modificar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer29 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	boton_Modificar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Modificar::Modificar_Stock ), NULL, this );
}

d_Modificar::~d_Modificar()
{
	// Disconnect Events
	boton_Modificar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Modificar::Modificar_Stock ), NULL, this );
	
}

d_Facturas::d_Facturas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	listaVentas = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer39->Add( listaVentas, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer39 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

d_Facturas::~d_Facturas()
{
}

d_DetalleVenta::d_DetalleVenta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	listaDetalles = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT );
	bSizer40->Add( listaDetalles, 1, wxALL|wxEXPAND, 5 );
	
	botonDescargar = new wxButton( this, wxID_ANY, wxT("Descargar comprobante"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( botonDescargar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer40 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	botonDescargar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_DetalleVenta::ClicDescargar ), NULL, this );
}

d_DetalleVenta::~d_DetalleVenta()
{
	// Disconnect Events
	botonDescargar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_DetalleVenta::ClicDescargar ), NULL, this );
	
}

d_AgregarP::d_AgregarP( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Nombre del producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer44->Add( m_staticText29, 0, wxALL, 5 );
	
	barra_Nom = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	barra_Nom->SetMinSize( wxSize( 250,30 ) );
	barra_Nom->SetMaxSize( wxSize( 250,30 ) );
	
	bSizer44->Add( barra_Nom, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Categoría:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer50->Add( m_staticText30, 0, wxALL, 5 );
	
	wxString choice_CatChoices[] = { wxT("Todas"), wxT("Urbano"), wxT("Deportivo"), wxT("Formal") };
	int choice_CatNChoices = sizeof( choice_CatChoices ) / sizeof( wxString );
	choice_Cat = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choice_CatNChoices, choice_CatChoices, 0 );
	choice_Cat->SetSelection( 0 );
	bSizer50->Add( choice_Cat, 0, wxALL, 5 );
	
	
	bSizer49->Add( bSizer50, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, wxT("Género:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	bSizer51->Add( m_staticText37, 0, wxALL, 5 );
	
	wxString choice_GenChoices[] = { wxT("Todos"), wxT("Hombre"), wxT("Mujer") };
	int choice_GenNChoices = sizeof( choice_GenChoices ) / sizeof( wxString );
	choice_Gen = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choice_GenNChoices, choice_GenChoices, 0 );
	choice_Gen->SetSelection( 0 );
	bSizer51->Add( choice_Gen, 0, wxALL, 5 );
	
	
	bSizer49->Add( bSizer51, 1, wxEXPAND, 5 );
	
	
	bSizer44->Add( bSizer49, 0, wxEXPAND, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("ID: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer44->Add( m_staticText31, 0, wxALL, 5 );
	
	barra_ID = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( barra_ID, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Talles S:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer46->Add( m_staticText32, 0, wxALL, 5 );
	
	barra_TS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( barra_TS, 0, wxALL, 5 );
	
	
	bSizer45->Add( bSizer46, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Talles M:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer47->Add( m_staticText33, 0, wxALL, 5 );
	
	barra_TM = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( barra_TM, 0, wxALL, 5 );
	
	
	bSizer45->Add( bSizer47, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Talles L:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer48->Add( m_staticText34, 0, wxALL, 5 );
	
	barra_TL = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( barra_TL, 0, wxALL, 5 );
	
	
	bSizer45->Add( bSizer48, 1, wxEXPAND, 5 );
	
	
	bSizer44->Add( bSizer45, 0, wxEXPAND, 5 );
	
	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Precio por unidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer44->Add( m_staticText35, 0, wxALL, 5 );
	
	barra_Precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( barra_Precio, 0, wxALL, 5 );
	
	m_botonAceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( m_botonAceptar, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer44 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_botonAceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarP::ClicAceptarPNuevo ), NULL, this );
}

d_AgregarP::~d_AgregarP()
{
	// Disconnect Events
	m_botonAceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarP::ClicAceptarPNuevo ), NULL, this );
	
}
