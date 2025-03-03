#include "Lista_Facturas.h"
#include "Facts_detalle.h"
#include "Factura.h"
#include <vector>
#include "Producto.h"
#include "m_ventanuli.h"
#include <wx/utils.h>
#include <wx/config.h>
#include <wx/textfile.h>
#include <wx/listctrl.h>
#include <wx/file.h>
#include <wx/arrstr.h>
#include <wx/msgdlg.h>
#include <fstream>
#include <string>
#include <cstdio>

Lista_Facturas::Lista_Facturas(wxWindow *parent,vector<Factura> f) : VentanaFacturas(parent) {
	// Títulos de las columnas
	listaVentas->InsertColumn(0,"Fecha y hora de venta", wxLIST_FORMAT_LEFT,200);
	listaVentas->InsertColumn(1,"Ganancia",wxLIST_FORMAT_RIGHT,150);
	
	// Enlazo el doble clic a la listCtrl
	listaVentas->Bind(wxEVT_LIST_ITEM_ACTIVATED, &Lista_Facturas::OnDobleClic, this);
	
	facturas.clear();
	
	if (!f.empty()) {
		for (auto fact : f){
			facturas.push_back(fact);
		}
		GuardarFacturas("facturas.dat");
	} 
	CargarFacturas("facturas.dat");
	CargarLista();
	
}

Lista_Facturas::~Lista_Facturas() {

}
void Lista_Facturas::OnDobleClic (wxListEvent & event) {
	indice = event.GetIndex();
	if (indice != -1) {
		vector<Producto> productosVendidos = facturas[indice].getProductos(); string fecha = facturas[indice].ObtenerFecha();
		string metodo = facturas[indice].getMetodoPago(); cout << metodo << endl;
		Facts_detalle* dlg = new Facts_detalle(this,productosVendidos,fecha,metodo);
		dlg->ShowModal();
	}
}

void Lista_Facturas::OnClose (wxCloseEvent & event) {
	GuardarFacturas("facturas.dat");
	facturas.clear();
	EndModal(wxID_OK);
}

void Lista_Facturas::CargarLista ( ) {
	listaVentas->DeleteAllItems();
	
	for(size_t i=0;i<facturas.size();i++) { 
		Factura& factActual = facturas[i];
		wxString fecha = wxString::FromUTF8(factActual.ObtenerFecha().c_str());
		wxString totalStr = wxString::Format("Total: %.2f", factActual.getTotal());
		
		long index = listaVentas->InsertItem(i, fecha); 
		
		listaVentas->SetItem(index, 1, totalStr);
	}
}

void Lista_Facturas::GuardarFacturas (string file_name) {

	if (facturas.empty()) return; // Evita guardar si no hay facturas nuevas
	
	ofstream file(file_name, ios::binary | ios::app);
	if (!file.is_open()) {
		wxMessageBox("Error al abrir el archivo para guardar las facturas", "Error", wxOK | wxICON_ERROR);
		return;
	}
	
	for (Factura& fac : facturas) {
		fac.GuardarEnBin(file);  // Guardar cada factura al final del archivo
	}
	
	file.close();
}

void Lista_Facturas::CargarFacturas (string file_n) {

	facturas.clear();
	
	ifstream file(file_n, ios::binary);
	if (!file.is_open()) {
		ofstream newFile(file_n, ios::binary);
		newFile.close();
		return;  // No hay facturas para cargar
	}
	
	int iteracion = 0;
	
	// Determinar el tamaño del archivo
	file.seekg(0, ios::end);
	if (file.tellg() == 0) {
		file.close();
		return;
	}
	file.seekg(0, ios::beg);
	
	while (file.peek() != EOF && !file.eof()) {
		cout << "Cargando factura Nro. " << iteracion << endl;
		Factura fac;
		fac.CargarDesdeBin(file);
		
		string fecha = fac.ObtenerFecha();
		if (!fecha.empty()) {
			facturas.push_back(fac);
			iteracion++;
			cout << "Fecha de la factura -> " << fecha << endl;
			cout << "Total de la factura -> " << fac.getTotal() << endl;
		} else {
			cout << "Error al cargar la factura, se omitirá" << endl;
			break;
		}
		
		// Verificar si aún quedan datos por leer
		if (file.peek() == EOF) {
			break;
		}
	}
	
	cout << "Total de facturas cargadas desde archivo: " << facturas.size() << endl;
	file.close();
}


