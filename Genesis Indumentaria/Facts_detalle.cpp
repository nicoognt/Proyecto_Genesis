#include "Facts_detalle.h"
#include "Producto.h"
#include <wx/string.h>
#include <wx/textfile.h>
#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <string>
using namespace std;
Facts_detalle::Facts_detalle (wxWindow * parent, vector<Producto> a, string fecha, string metodo) : Ventana_DetalleFacts(parent),productosVendidos(a),fecha_venta(fecha),metodo_DePago(metodo) {
	SetLabel("Venta registrada (" + fecha_venta + ")");
	listaDetalles->InsertColumn(0,"Productos vendidos:",wxLIST_FORMAT_CENTER,200);
	listaDetalles->InsertColumn(1,"Precio total:",wxLIST_FORMAT_CENTER,120);
	
	CargarProductos();
}

void Facts_detalle::ClicDescargar( wxCommandEvent& event )  {
	wxFileDialog archivo_guardar(this, _("Guardar factura como"), "", "","Archivos de texto (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	
	if (archivo_guardar.ShowModal() == wxID_CANCEL) {
		return; // El usuario canceló la operación
	}
	
	// Ruta donde se guardó el archivo
	wxString filePath = archivo_guardar.GetPath();
	
	// Forzar la extensión .txt si no está presente
	if (!filePath.EndsWith(".txt")) {
		filePath += ".txt";
	}
	
	// Crear y escribir el archivo
	wxTextFile file(filePath);
	if (!file.Exists()) {
		file.Create();
	} else {
		file.Open();
	}
	
	file.Clear();
	file.AddLine("Factura de venta - " + fecha_venta);
	file.AddLine("Productos vendidos:");
	
	for (auto producto : productosVendidos) {
		if (producto.VerTalleS() > 0) {
			wxString line = wxString::Format("%s - Talle S (x%d) - $%.2f", producto.VerNombre(), producto.VerTalleS(), producto.VerTalleS() * producto.VerPrecio());
			file.AddLine(line);
		}
		if (producto.VerTalleM() > 0) {
			wxString line = wxString::Format("%s - Talle M (x%d) - $%.2f", producto.VerNombre(), producto.VerTalleM(), producto.VerTalleM() * producto.VerPrecio());
			file.AddLine(line);
		}
		if (producto.VerTalleL() > 0) {
			wxString line = wxString::Format("%s - Talle L (x%d) - $%.2f", producto.VerNombre(), producto.VerTalleL(), producto.VerTalleL() * producto.VerPrecio());
			file.AddLine(line);
		}
	}
	wxString linea_metodo; linea_metodo << "Metodo utilizado: "+metodo_DePago;
	file.AddLine(linea_metodo);
	file.Write();
	file.Close();
	
	wxMessageBox("Factura guardada correctamente en: " + filePath, "Éxito", wxOK | wxICON_INFORMATION);
}

Facts_detalle::~Facts_detalle() {
	
}

void Facts_detalle::CargarProductos ( ) {
	// Borro lo que haya para actualizar en tiempo real
	listaDetalles->DeleteAllItems();
	
	for(int i=0;i<productosVendidos.size();i++) { 
		
		// Obtengo el producto
		Producto a = productosVendidos[i];
		
		// Reviso el talle para agregarlo al nombre
		if(a.VerTalleS() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "S", a.VerTalleS());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleS() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
		if(a.VerTalleM() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "M", a.VerTalleM());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleM() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
		if(a.VerTalleL() > 0){
			wxString descripcion = wxString::Format("%s - Talle %s (x%d)", a.VerNombre(), "L", a.VerTalleL());
			wxString precioStr = wxString::Format(" $%.2f",(a.VerTalleL() * a.VerPrecio()));
			
			long index = listaDetalles->InsertItem(i,descripcion);
			listaDetalles->SetItem(index,1,precioStr);
		}
	}
}

