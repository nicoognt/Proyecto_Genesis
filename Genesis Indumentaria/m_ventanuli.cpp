#include "m_ventanuli.h"
#include <wx/string.h>
#include <wx/regex.h>
#include <wx/wx.h>
#include <string>
#include <iomanip>
#include <sstream>

#include "Tienda.h"
#include "Producto.h"
#include <algorithm>
using namespace std;

m_ventanuli::m_ventanuli(wxWindow *parent) : ventanuli(parent) {
	
	Grilla_Productos->Bind(wxEVT_GRID_CELL_RIGHT_CLICK, &m_ventanuli::OnRightClick, this);
	
	genesis=new Tienda();
	genesis->OrdenarVector();
	
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
		
		stringstream ss;
		ss<<fixed<<setprecision(2)<<a.VerPrecio();
		text<<"$"<<ss.str();
		Grilla_Productos->SetCellValue(i,2,text);
		text.Clear();
		
		text<<a.Ver_id();
		Grilla_Productos->SetCellValue(i,3,text);
		text.Clear();
		
	}
	
}

void m_ventanuli::m_buscar( wxCommandEvent& event ){
	
	/// wxString para obtener lo que hay en la barra de busqueda
	wxString texto=BarraBusqueda->GetValue();
	string b = texto.ToStdString();
	
	/// Patron regular para filtrar texto v�lido o no
	wxRegEx _reg("^[a-zA-Z0-9 ]*$");
	
	if(!_reg.Matches(texto)){
		
		wxMessageBox("Los caracteres especiales (�!,&,@...) no est�n permitidos.","Advertencia",wxOK|wxICON_WARNING);
		
	}else if(!b.empty()){
		
		/// Vector auxiliar para tener los productos a mostrar
		vector<Producto> aux;
		
		/// Busco la coincidencia entre texto y Producto
		for(int i=0;i<genesis->CantidadProductos();i++){
			Producto a=genesis->MostrarProducto(i);
			if(a.VerNombre().find(texto)!=string::npos){
				aux.push_back(a);
			}
		}
		
		if(aux.empty()){
			
			wxMessageBox("No se encontr� el producto en la tienda","Algo fue mal...",wxOK|wxICON_INFORMATION);
			
		}else{
			
			sort(aux.begin(),aux.end(),orden_alfabetico);
			
			if(Grilla_Productos->GetNumberRows() > 0){
				Grilla_Productos->ClearGrid();
				Grilla_Productos->DeleteRows(0,Grilla_Productos->GetNumberRows());
			}
			
			Grilla_Productos->AppendRows(aux.size());
			
			for(size_t i=0;i<aux.size();i++){
				wxString string_celda;
				
				/// Seteo el nombre, stock disponible y precio p/u de c/producto
				string_celda<<aux[i].VerNombre();
				Grilla_Productos->SetCellValue(i,0,string_celda);
				string_celda.Clear();
				
				string_celda<<(aux[i].VerTalleS()+aux[i].VerTalleM()+aux[i].VerTalleL())<<" unidades";
				Grilla_Productos->SetCellValue(i,1,string_celda);
				string_celda.Clear();
				
				stringstream ss;
				ss<<fixed<<setprecision(2)<<aux[i].VerPrecio();
				string_celda<<"$"<<ss.str();
				Grilla_Productos->SetCellValue(i,2,string_celda);
				string_celda.Clear();
				
				string_celda<<aux[i].Ver_id();
				Grilla_Productos->SetCellValue(i,3,string_celda);
				string_celda.Clear();
				
			}
		}
	}else{
		wxMessageBox("La barra de b�squeda est� vac�a","Advertencia",wxOK|wxICON_WARNING);
	}
}

void m_ventanuli::m_recargar( wxCommandEvent& event )  {
	Grilla_Productos->ClearGrid();
	Grilla_Productos->DeleteRows(0,Grilla_Productos->GetNumberRows());
	
	genesis->OrdenarVector();
	
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
		
		stringstream ss;
		ss<<fixed<<setprecision(2)<<a.VerPrecio();
		text<<"$"<<ss.str();
		Grilla_Productos->SetCellValue(i,2,text);
		text.Clear();
		
		text<<a.Ver_id();
		Grilla_Productos->SetCellValue(i,3,text);
		text.Clear();
		
	}
}

void m_ventanuli::OnRightClick (wxGridEvent & event) {
	/// Obtengo la fila y columna donde se clickeo
	int fila = event.GetRow();
	int columna = event.GetCol();
	
	/// Crear un men� emergente (contextual)
	wxMenu menuContextual;
	
	menuContextual.Append(1001, "Agregar al carrito");
	menuContextual.Append(1002, "Ver detalles");
	menuContextual.Append(1003, "Modificar stock");
	menuContextual.Append(1004, "Eliminar");
	
	/// Conectar eventos a los �tems del men�
	Bind(wxEVT_MENU, &m_ventanuli::OnAgregar, this, 1001);
	Bind(wxEVT_MENU, &m_ventanuli::OnVerDetalles, this, 1002);
	Bind(wxEVT_MENU, &m_ventanuli::OnModificar, this, 1003);
	Bind(wxEVT_MENU, &m_ventanuli::OnEliminar, this, 1004);
	
	/// Mostrar el men� en la posici�n del cursor
	PopupMenu(&menuContextual);
}

void m_ventanuli::OnEliminar (wxCommandEvent & event) {
	wxMessageBox("Opcion de eliminar seleccionada","Epico",wxOK|wxICON_INFORMATION);
}
void m_ventanuli::OnModificar (wxCommandEvent & event) {
	wxMessageBox("Opcion de editar seleccionada","Epico",wxOK|wxICON_INFORMATION);
}
void m_ventanuli::OnVerDetalles (wxCommandEvent & event) {
	wxMessageBox("Opcion de ver stock seleccionada","Epico",wxOK|wxICON_INFORMATION);
}
void m_ventanuli::OnAgregar (wxCommandEvent & event) {
	wxMessageBox("Opcion de agregar seleccionada","Epico",wxOK|wxICON_INFORMATION);}

void m_ventanuli::Clic_VerCarro( wxCommandEvent& event )  {
	event.Skip();
}

void m_ventanuli::Clic_VerFiltros( wxCommandEvent& event )  {
	event.Skip();
}

m_ventanuli::~m_ventanuli() {
	
}




