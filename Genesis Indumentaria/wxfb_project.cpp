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
	bSizer14->Add( boton_dial_OK, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	
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
	
	m_Compra = new wxButton( this, wxID_ANY, wxT("Comprar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_Compra, 0, wxALL, 5 );
	
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
	m_Compra->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnComprar ), NULL, this );
	m_Vaciar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnVaciar ), NULL, this );
}

d_Compras::~d_Compras()
{
	// Disconnect Events
	m_Compra->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Compras::OnComprar ), NULL, this );
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
	bSizer21->Add( m_Confirmar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	
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
	
	m_fReestablecer = new wxButton( this, wxID_ANY, wxT("Reestablecer"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_fReestablecer, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer23 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

d_Filtros::~d_Filtros()
{
}
