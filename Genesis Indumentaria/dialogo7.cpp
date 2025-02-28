#include "dialogo7.h"
#include "dialogo8.h"
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
using namespace std;

dialogo7::dialogo7(wxWindow *parent,vector<Factura> f) : d_Facturas(parent), facturas(f) {
	
	// Títulos de las columnas
	listaVentas->InsertColumn(0,"Fecha y hora de venta", wxLIST_FORMAT_LEFT,200);
	listaVentas->InsertColumn(1,"Ganancia",wxLIST_FORMAT_RIGHT,150);
	
	// Enlazo el doble clic a la listCtrl
	listaVentas->Bind(wxEVT_LIST_ITEM_ACTIVATED, &dialogo7::OnDobleClic, this);
	// Cargo los datos desde el binario
	GuardarFac_Bin(facturas,"facturas.dat");
	CargarFac_Bin(facturas,"facturas.dat");
	CargarFacturas();
	
}

void dialogo7::OnDobleClic (wxListEvent & event) {
	indice = event.GetIndex();
	if (indice != -1) {
		vector<Producto> productosVendidos = facturas[indice].getProductos();
		dialogo8* dlg = new dialogo8(this,productosVendidos);
		dlg->ShowModal();
	}
}

void dialogo7::CargarFacturas ( ) {
	listaVentas->DeleteAllItems();
	
	for(size_t i=0;i<facturas.size();i++) { 
		wxString fecha = wxString::FromUTF8((facturas[i].ObtenerFecha()).c_str());
		wxString totalStr = wxString::Format("Total: %.2f", facturas[i].getTotal());
		
		long index = listaVentas->InsertItem(i, fecha); 
		
		listaVentas->SetItem(index, 1, totalStr);
	}
	if (!facturas.empty()) {
		GuardarDatos();
	}
}

dialogo7::~dialogo7() {
	
}

void dialogo7::GuardarDatos() {
	wxTextFile archivo("facturas.txt");
	
	// Crear archivo si no existe
	if (!archivo.Exists()) {
		archivo.Create();
	} else {
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
	archivo.Close();
}

void dialogo7::CargarDatos(){
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

void dialogo7::GuardarFac_Bin (const vector<Factura> facturas, string file_name) {
	ofstream file(file_name,ios::binary);
	cout << "si ves true, se abrio bien el archivo/existe, lo contrario si es false :p\n";
	if (file.good()) cout << "true";
	else cout << "false";
	if(!file.is_open()) {
		wxMessageBox("Error al abrir el archivo para guardar las facturas","Error", wxOK | wxICON_ERROR);
		return;
	}
	
	size_t numFacturas = facturas.size();
	file.write(reinterpret_cast<const char*>(&numFacturas), sizeof(numFacturas));
	
	for (auto factura : facturas) {
		factura.GuardarEnBin(file);
	}
	
	file.close();
}

void dialogo7::CargarFac_Bin (vector<Factura> & facturas, string file_n) {
	ifstream file(file_n,ios::binary);
	
	if (!file.is_open()){
		wxMessageBox("Error al abrir el archivo para cargar las facturas, se creará uno nuevo","Error", wxOK | wxICON_ERROR);
	}
	
	size_t numFacturas;
	file.read(reinterpret_cast<char*>(&numFacturas),sizeof(numFacturas));
	cout << "facts existentes: " << numFacturas << endl;
	cout << "tamaño del vector actual: " << facturas.size() << endl;
	facturas.resize(numFacturas);
	cout << "nuevo tamaño: " << facturas.size() << endl;
	
	for(size_t i=0;i<numFacturas;i++){
		facturas[i].CargarDesdeBin(file);
	}
	
	file.close();
}

