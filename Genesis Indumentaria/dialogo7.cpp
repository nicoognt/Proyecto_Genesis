#include "dialogo7.h"
#include "dialogo8.h"
#include "Factura.h"
#include <vector>
#include "Producto.h"
#include "m_ventanuli.h"
using namespace std;

dialogo7::dialogo7(wxWindow *parent,vector<Factura> f) : d_Facturas(parent), facturas(f) {
	
	listaVentas->InsertColumn(0,"Fecha y hora de venta", wxLIST_FORMAT_LEFT,150);
	listaVentas->InsertColumn(1,"Ganancia",wxLIST_FORMAT_RIGHT,100);
	
	CargarFacturas();
}

void dialogo7::OnDobleClic (wxListEvent & event) {
//	indice = event.GetIndex();
//	if (indice != -1) {
//		dialogo8* dlg = new dialogo8(this);
//	}
	event.Skip();
}

void dialogo7::CargarFacturas ( ) {
	m_ventanuli* mainWin = dynamic_cast<m_ventanuli*>(GetParent());
	if (mainWin) {
		float total = mainWin->GetPrecio();
		wxString totalStr = wxString::Format("Total: %.2f", total);
		listaVentas->InsertItem(0, totalStr);
	}
}

dialogo7::~dialogo7() {
	
}

