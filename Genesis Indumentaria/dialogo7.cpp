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
	CargarDatos();
	
	for(size_t i=0;i<facturas.size();i++) { 
		wxString fecha;
		fecha << facturas[i].ObtenerFecha();
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

