#include "m_ventanuli.h"
#include <wx/string.h>
#include <wx/regex.h>
#include <wx/wx.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "Tienda.h"
#include "Producto.h"
#include "dialogo.h"
#include "dialogo2.h"
#include "dialogo3.h"
#include "dialogo5.h"
#include <wx/msgdlg.h>
#include "dialogo6.h"
using namespace std;

m_ventanuli::m_ventanuli(wxWindow *parent) : ventanuli(parent) {
	
	filaSeleccionada=-1;
	columnaSeleccionada=-1;
	Grilla_Productos->Bind(wxEVT_GRID_CELL_RIGHT_CLICK, &m_ventanuli::OnRightClick, this);
	
	car=new CarritoDeCompras();
	
	genesis=new Tienda();
	genesis->OrdenarVector();
	
	this->CreaGrilla();
	
}

void m_ventanuli::CreaGrilla ( ) {
	// Obtener los productos filtrados
	const vector<Producto>& productosFiltrados = genesis->ObtenerFiltros();
	
	// Mostrar los productos filtrados en la grilla
	for (size_t i = 0; i < productosFiltrados.size(); i++) {
		Producto a = productosFiltrados[i];
		
		Grilla_Productos->AppendRows(1);
		
		wxString text;
		text << a.VerNombre();
		Grilla_Productos->SetCellValue(i, 0, text);
		text.Clear();
		
		text << (a.VerTalleS() + a.VerTalleM() + a.VerTalleL()) << " unidades";
		Grilla_Productos->SetCellValue(i, 1, text);
		text.Clear();
		
		stringstream ss;
		ss << fixed << setprecision(2) << a.VerPrecio();
		text << "$" << ss.str();
		Grilla_Productos->SetCellValue(i, 2, text);
		text.Clear();
		
		text << a.Ver_id();
		Grilla_Productos->SetCellValue(i, 3, text);
		text.Clear();
	}
}

void m_ventanuli::RefrescarGrilla ( ) {
	
	Grilla_Productos->ClearGrid();
	Grilla_Productos->DeleteRows(0,Grilla_Productos->GetNumberRows());
	
	CreaGrilla();
}

void m_ventanuli::m_buscar( wxCommandEvent& event ){
	
	/// wxString para obtener lo que hay en la barra de busqueda
	wxString texto=BarraBusqueda->GetValue();
	string b = texto.ToStdString();
	
	/// Patron regular para filtrar texto válido o no
	wxRegEx _reg("^[a-zA-Z0-9 ]*$");
	
	if(!_reg.Matches(texto)){
		
		wxMessageBox("Los caracteres especiales (¡!,&,@...) no están permitidos.","Advertencia",wxOK|wxICON_WARNING);
		
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
			
			wxMessageBox("No se encontró el producto en la tienda","Algo fue mal...",wxOK|wxICON_INFORMATION);
			
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
		wxMessageBox("La barra de búsqueda está vacía","Advertencia",wxOK|wxICON_WARNING);
	}
}

void m_ventanuli::m_recargar( wxCommandEvent& event )  {
	genesis->ReestablecerFiltros();
	RefrescarGrilla();
}

void m_ventanuli::OnRightClick (wxGridEvent & event) {
	/// Obtengo la fila y columna donde se clickeo
	filaSeleccionada = event.GetRow(); columnaSeleccionada = event.GetCol();
	
	/// Crear un menú emergente (contextual)
	if(filaSeleccionada != -1 && columnaSeleccionada != -1){
		wxMenu menuContextual;
		
		menuContextual.Append(1001, "Agregar al carrito");
		menuContextual.Append(1002, "Ver detalles");
		menuContextual.Append(1003, "Modificar stock");
		
		/// Conectar eventos a los ítems del menú
		Bind(wxEVT_MENU, &m_ventanuli::OnAgregar, this, 1001);
		Bind(wxEVT_MENU, &m_ventanuli::OnVerDetalles, this, 1002);
		Bind(wxEVT_MENU, &m_ventanuli::OnModificar, this, 1003);
		
		/// Mostrar el menú en la posición del cursor
		PopupMenu(&menuContextual);
	}
}

void m_ventanuli::OnModificar (wxCommandEvent & event) {
	
	Producto pr = genesis->MostrarProductoFiltro(filaSeleccionada);
	Producto* p_original = genesis->MostrarConId(pr.Ver_id());
	
	dialogo6* dlg = new dialogo6(this,p_original);
	if(dlg->ShowModal() == wxID_OK){
		genesis->ReestablecerFiltros();
		RefrescarGrilla();
	}
	dlg->Destroy();
}
void m_ventanuli::OnVerDetalles (wxCommandEvent & event) {
	
	if(filaSeleccionada == -1 || columnaSeleccionada == -1) {
		wxMessageBox("Por favor, seleccione una celda válida","Atención", wxOK | wxICON_INFORMATION);
		return;
	}
	
	d_Detalles* dlg = new d_Detalles(this,genesis->MostrarProductoFiltro(filaSeleccionada));
	dlg->ShowModal();
	dlg->Destroy();
	
}
void m_ventanuli::OnAgregar (wxCommandEvent & event) {
	
	Producto pr = genesis->MostrarProductoFiltro(filaSeleccionada);
	Producto* p_original = genesis->MostrarConId(pr.Ver_id());
	
	dialogo2* dlg = new dialogo2(this,car,p_original);

	dlg->ShowModal();
	dlg->Destroy();
	
	genesis->ReestablecerFiltros();
	RefrescarGrilla();
}

void m_ventanuli::Clic_VerCarro( wxCommandEvent& event )  {
	dialogo3* dlg = new dialogo3(this,car,genesis);
	
	dlg->ShowModal();
	dlg->Destroy();
	
	genesis->ReestablecerFiltros();
	RefrescarGrilla();
}

void m_ventanuli::Clic_VerFiltros( wxCommandEvent& event )  {
	dialogo5* dlg = new dialogo5(this,genesis);
	
	if(dlg->ShowModal() == wxID_OK){
		RefrescarGrilla();
	}
	
	dlg->Destroy();
	
}

CarritoDeCompras * m_ventanuli::DevolverCarrito ( ) {
	return car;
}

m_ventanuli::~m_ventanuli() {
	
}




