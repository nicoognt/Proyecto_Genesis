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

Lista_Facturas::Lista_Facturas(wxWindow *parent,vector<Factura> *f) : VentanaFacturas(parent),facturas(f) {
	if (facturas == nullptr){
		facturas = new vector<Factura> ();
		lo_cree_aca = true;
	}
	// Títulos de las columnas
	listaVentas->InsertColumn(0,"Fecha y hora de venta", wxLIST_FORMAT_LEFT,200);
	listaVentas->InsertColumn(1,"Ganancia",wxLIST_FORMAT_RIGHT,150);
	
	// Enlazo el doble clic a la listCtrl
	listaVentas->Bind(wxEVT_LIST_ITEM_ACTIVATED, &Lista_Facturas::OnDobleClic, this);
	// Cargo los datos desde el binario
	GuardarFac_Bin(facturas,"facturas.dat");
	
	CargarFac_Bin(facturas,"facturas.dat");
	
	GuardarDatos();
	
	CargarDatos();
	
	CargarFacturas();
	
}

Lista_Facturas::~Lista_Facturas() {
	if (facturas != nullptr && lo_cree_aca) {
		delete facturas;
	}
}
void Lista_Facturas::OnDobleClic (wxListEvent & event) {
	indice = event.GetIndex();
	if (indice != -1) {
		vector<Producto> productosVendidos = (*facturas)[indice].getProductos(); string fecha = (*facturas)[indice].ObtenerFecha();
		string metodo = (*facturas)[indice].getMetodoPago();
		Facts_detalle* dlg = new Facts_detalle(this,productosVendidos,fecha,metodo);
		dlg->ShowModal();
	}
}

void Lista_Facturas::OnClose (wxCloseEvent & event) {
	GuardarDatos();
	EndModal(wxID_OK);
}

void Lista_Facturas::CargarFacturas ( ) {
	if (facturas == nullptr){
		wxMessageBox("El vector de facturas no está inicializado.", "Error", wxOK | wxICON_ERROR);
		return;
	}
	
	listaVentas->DeleteAllItems();
	
	for(size_t i=0;i<facturas->size();i++) { 
		Factura factActual = (*facturas)[i];
		wxString fecha = wxString::FromUTF8(factActual.ObtenerFecha().c_str());
		wxString totalStr = wxString::Format("Total: %.2f", factActual.getTotal());
		
		long index = listaVentas->InsertItem(i, fecha); 
		
		listaVentas->SetItem(index, 1, totalStr);
	}
	if (!facturas->empty()) {
		GuardarDatos();
	}
}

void Lista_Facturas::GuardarDatos ( ) {
	wxTextFile archivo("facturas.txt");
	
	// Crear archivo si no existe
	if (!archivo.Exists()) {
		cout << "el archivo con las fechas y los totales no esta (le cambiaste el nombre)\n";
		archivo.Create();
	} else {
		cout << "el archivo está vivito y culeando\n";
		archivo.Open();
	}
	
	// Guardamos las ventas anteriores en una lista para no duplicarlas
	wxArrayString lineasExistentes;
	for (size_t i = 0; i < archivo.GetLineCount(); i++) {
		lineasExistentes.Add(archivo.GetLine(i));
	}
	
	int filas = listaVentas->GetItemCount();
	archivo.Clear();
	
	for (int i = 0; i < filas; i++) {
		wxString fecha = listaVentas->GetItemText(i, 0);
		wxString total = listaVentas->GetItemText(i, 1);
		wxString linea = fecha + " - " + total;
		
		if (lineasExistentes.Index(linea) == wxNOT_FOUND) {  // Evita duplicados
			archivo.AddLine(linea);
		}
	}
	
	archivo.Write();
	cout << "termine con el guardado de datos :3\n";
	archivo.Close();
}

void Lista_Facturas::CargarDatos ( ) {
	wxTextFile archivo("facturas.txt");
	if (!archivo.Exists()) return; // Verificar si el archivo existe
	
	archivo.Open();
	listaVentas->DeleteAllItems(); // Limpiar la lista antes de cargar
	
	for (size_t i = 0; i < archivo.GetLineCount(); i++) {
		wxString linea = archivo.GetLine(i);
		wxArrayString partes = wxSplit(linea, '-');
		
		if (partes.size() == 2) {
			long indice = listaVentas->InsertItem(i, partes[0].Trim()); // Fecha
			listaVentas->SetItem(indice, 1, partes[1].Trim()); // Total
		}
	}
	
	archivo.Close();
}

void Lista_Facturas::GuardarFac_Bin (vector<Factura> * facturas, string file_name) {
	if (facturas == nullptr || facturas->empty()) {
		return;
	}
	ofstream file(file_name,ios::binary);
	if(!file.is_open()) {
		wxMessageBox("Error al abrir el archivo para guardar las facturas","Error", wxOK | wxICON_ERROR);
		return;
	}
	
	size_t numFacturas = facturas->size();
	file.write(reinterpret_cast<const char*>(&numFacturas), sizeof(numFacturas));
	
	for (size_t i=0;i<facturas->size();i++) {
		(*facturas)[i].GuardarEnBin(file);
	}
	file.close();
}

void Lista_Facturas::CargarFac_Bin (vector<Factura> * facturas, string file_n) {
	ifstream file(file_n,ios::binary|ios::ate);
	
	if (!file.is_open()){ // Si el mismo no existe, creo otro
		wxMessageBox("Error al abrir el archivo para cargar las facturas, se creará uno nuevo","Error", wxOK | wxICON_ERROR);
		file.close();
		
		// Creo el nuevo archivo
		ofstream file1(file_n,ios::binary);
		if(!file1.is_open()){
			wxMessageBox("Error al crear el nuevo archivo","Error", wxOK | wxICON_ERROR);
		}
		// Ingreso la cantidad de facturas = 0
		size_t numFacts = 0;
		file1.write(reinterpret_cast<const char*>(&numFacts),sizeof(numFacts));
		// Cierro el archivo nuevo
		file1.close();
		// Abro el anterior
		file.open(file_n,ios::binary);
	}
	size_t numFacturas;
	file.read(reinterpret_cast<char*>(&numFacturas),sizeof(numFacturas));
	cout << "la cantidad de facturas en el archivo es -> " << numFacturas << endl;
	// Si la lectura de la cantidad de facturas falla, aparece el mensaje de error
	if (file.fail()) {
		wxMessageBox("Error al leer el número de facturas desde el archivo.", "Error", wxOK | wxICON_ERROR);
		return;
	}
	if(facturas == nullptr) {
		facturas = new vector<Factura>();
		lo_cree_aca = true;
	}
	facturas->resize(numFacturas);
	for(size_t i=0;i<numFacturas;i++){
		(*facturas)[i].CargarDesdeBin(file);
	}
	file.close();
}


