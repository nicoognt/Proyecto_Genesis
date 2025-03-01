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
	cout << "jelooou, soy la ventana de los registros de venta. Si es la primera vez que me usas, no voy a tener ninguna factura\n";
	// Títulos de las columnas
	listaVentas->InsertColumn(0,"Fecha y hora de venta", wxLIST_FORMAT_LEFT,200);
	listaVentas->InsertColumn(1,"Ganancia",wxLIST_FORMAT_RIGHT,150);
	
	// Enlazo el doble clic a la listCtrl
	listaVentas->Bind(wxEVT_LIST_ITEM_ACTIVATED, &dialogo7::OnDobleClic, this);
	// Cargo los datos desde el binario
	cout << "transitando el metodo GuardarFac_Bin...\n";
	GuardarFac_Bin(facturas,"facturas.dat");
	
	cout << "transitando el metodo CargarFac_Bin...\n";
	CargarFac_Bin(facturas,"facturas.dat");
	
	cout << "utilizando el metodo GuardarDatos()...\n";
	GuardarDatos();
	
	cout << "ya casi, usando CargarDatos()...\n";
	CargarDatos();
	
	cout << "finalmente, entrando a CargarFacturas...\n";
	CargarFacturas();
	
	cout << "hice todo y sin problemas pa B)\n";
	
}

void dialogo7::OnDobleClic (wxListEvent & event) {
	indice = event.GetIndex();
	if (indice != -1) {
		vector<Producto> productosVendidos = facturas[indice].getProductos();
		dialogo8* dlg = new dialogo8(this,productosVendidos);
		dlg->ShowModal();
	}
}


void dialogo7::OnClose (wxCloseEvent & event) {
	GuardarDatos();
	GuardarFac_Bin(facturas,"Facturas.dat");
	EndModal(wxID_OK);
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
	wxTextFile archivo("Facturas.txt");
	
	// Crear archivo si no existe
	if (!archivo.Exists()) {
		cout << "el archivo con las fechas y los totales no está (le cambiaste el nombre)\n";
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

void dialogo7::CargarDatos(){
	wxTextFile archivo("Facturas.txt");
	
	if (!archivo.Exists()) cout << "no encuentro el archivo uwun't\ncreo uno nuevo"; return; // Verificar si el archivo existe
	
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
	
	cout << "termine de cargar los datos :0\n";
	archivo.Close();
}

void dialogo7::GuardarFac_Bin (vector<Factura> facturas, string file_name) {
	ofstream file(file_name,ios::binary);
	cout << "TRUE = archivo existiendo y abierto\nFALSE = archivo no existiendo\n";
	if (file.good()) cout << "TRUE\n";
	else cout << "FALSE\n";
	if(!file.is_open()) {
		wxMessageBox("Error al abrir el archivo para guardar las facturas","Error", wxOK | wxICON_ERROR);
		return;
	}
	
	size_t numFacturas = facturas.size(); cout << numFacturas << " facturas existentes\n";
	file.write(reinterpret_cast<const char*>(&numFacturas), sizeof(numFacturas));
	
	for (size_t i=0;i<facturas.size();i++) {
		facturas[i].GuardarEnBin(file);
	}
	cout << "termine con el metodo :)\n";
	file.close();
}

void dialogo7::CargarFac_Bin (vector<Factura>  facturas, string file_n) {
	ifstream file(file_n,ios::binary|ios::ate);
	
	if (!file.is_open()){
		wxMessageBox("Error al abrir el archivo para cargar las facturas, se creará uno nuevo","Error", wxOK | wxICON_ERROR);
		ofstream file1(file_n,ios::binary);
		if(!file1.is_open()){
			wxMessageBox("Error al crear el nuevo archivo","Error", wxOK | wxICON_ERROR);
		}
		size_t numFacts = 0;
		file1.write(reinterpret_cast<const char*>(&numFacts),sizeof(numFacts));
		file1.close();
		return;
	}
	cout << "actualmente tengo " << file.tellg() << " bits\n"; file.seekg(0,ios::beg);
	size_t numFacturas;
	file.read(reinterpret_cast<char*>(&numFacturas),sizeof(numFacturas));
	cout << "facts existentes: " << numFacturas << endl;
	cout << "tamanio del vector actual: " << facturas.size() << endl;
	facturas.resize(numFacturas);
	cout << "nuevo tamanio: " << facturas.size() << endl;
	
	for(size_t i=0;i<numFacturas;i++){
		facturas[i].CargarDesdeBin(file);
	}
	
	cout << "termine con el metodo :D\n";
	file.close();
}

