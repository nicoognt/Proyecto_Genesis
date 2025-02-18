#include "m_ventanuli.h"
#include <wx/string.h>
#include <wx/regex.h>
#include <wx/wx.h>
#include <string>

#include "Tienda.h"
#include "Producto.h"
using namespace std;

m_ventanuli::m_ventanuli(wxWindow *parent) : ventanuli(parent) {
	genesis=new Tienda();
	for(int i=0;i<genesis->CantidadProductos();i++){
		
		wxString text;
		Producto a = genesis->MostrarProducto(i);
		Grilla_Productos->AppendRows(1);
		
		text<<a.VerNombre();
		Grilla_Productos->SetCellValue(i,0,text);
		text.Clear();
		
		text<<(a.VerTalleS()+a.VerTalleM()+a.VerTalleL())<<" unidades";
		Grilla_Productos->SetCellValue(i,1,text);
		text.Clear();
		
		text<<"$"<<a.VerPrecio();
		Grilla_Productos->SetCellValue(i,2,text);
		text.Clear();
		
	}
	
}

void m_ventanuli::m_buscar( wxCommandEvent& event )  {
	/// wxString para obtener lo que hay en la barra de busqueda
	wxString texto=BarraBusqueda->GetValue();
	
	/// Patron regular para filtrar texto válido o no
	wxRegEx _reg("^[a-zA-Z0-9]*$]");
	
	if(!_reg.Matches(texto)){
		wxMessageBox("Los caracteres especiales (¡!,&,@...) no están permitidos.","Advertencia",wxOK|wxICON_WARNING);
	}else{
		
		/// Vector auxiliar para tener los productos a mostrar
		vector<Producto> aux;
		
		/// Busco la coincidencia entre texto y Producto
		for(int i=0;i<genesis->CantidadProductos();i++){
			Producto a=genesis->MostrarProducto(i);
			if(a.VerNombre()==texto.ToStdString()){
				aux.push_back(a);
			}
		}
		
		for(size_t i=0;i<aux.size();i++){
			wxString string_celda;
			
			/// Seteo el nombre, stock disponible y precio p/u de c/producto
			string_celda<<aux[i].VerNombre();
			Grilla_Productos->SetCellValue(i,0,string_celda);
			string_celda.Clear();
			
			string_celda<<(aux[i].VerTalleS()+aux[i].VerTalleM()+aux[i].VerTalleL())<<" unidades";
			Grilla_Productos->SetCellValue(i,1,string_celda);
			string_celda.Clear();
			
			string_celda<<"$"<<aux[i].VerPrecio();
			Grilla_Productos->SetCellValue(i,2,string_celda);
			string_celda.Clear();
		}
	}

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

