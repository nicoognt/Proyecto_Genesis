#include "m_ventanuli.h"

m_ventanuli::m_ventanuli(wxWindow *parent) : ventanuli(parent) {
	
}

void m_ventanuli::m_buscar( wxCommandEvent& event )  {
	event.Skip();
}

void m_ventanuli::Casilla_ClicDerecho( wxGridEvent& event )  {
	event.Skip();
}

void m_ventanuli::Clic_VerCarro( wxCommandEvent& event )  {
	event.Skip();
}

void m_ventanuli::Clic_VerFiltros( wxCommandEvent& event )  {
	event.Skip();
}

m_ventanuli::~m_ventanuli() {
	
}

