#include "m_ventanuli.h"
#include <wx/string.h>
#include <wx/regex.h>
#include <wx/wx.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <wx/msgdlg.h>

#include "Tienda.h"
#include "Producto.h"
#include "V_DetallesProd.h"
#include "V_SumarCarrito.h"
#include "V_Compras.h"
#include "V_Filtros.h"
#include "V_Modificar.h"
#include "Lista_Facturas.h"
#include "AgregarPr.h"
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
		
		// Agrego una fila por cada producto en la lista
		Grilla_Productos->AppendRows(1);
		
		// Escribo el nombre, las unidades, precio por unidad y el ID
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
	// Limpio la grilla y la vuelvo a crear
	if(Grilla_Productos->GetNumberRows() == 0){
		CreaGrilla();
	} else {
		Grilla_Productos->ClearGrid();
		Grilla_Productos->DeleteRows(0,Grilla_Productos->GetNumberRows());
		
		CreaGrilla();
	}
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
		
		/* Busco un producto en la tienda por:
			- coincidencia en el nombre.
			- ID exacto.
		*/
		for(int i=0;i<genesis->CantidadProductos();i++){
			Producto a=genesis->MostrarProducto(i);
			stringstream ss; ss << a.Ver_id();
			if((a.VerNombre().find(texto)!=string::npos) || (ss.str()) == b){
				aux.push_back(a);
			}
		}
		
		if(aux.empty()){ // Si el vector está vacío, es porque el producto no se encontró
			
			wxMessageBox("No se encontró el producto en la tienda","Algo anduvo mal...",wxOK|wxICON_INFORMATION);
			
		} else { // Si hay algo, se ordena alfabeticamente y se los muestra
			
			sort(aux.begin(),aux.end(),orden_alfabetico);
			
			if(Grilla_Productos->GetNumberRows() > 0){
				Grilla_Productos->ClearGrid();
				Grilla_Productos->DeleteRows(0,Grilla_Productos->GetNumberRows());
			}
			
			Grilla_Productos->AppendRows(aux.size());
			
			for(size_t i=0;i<aux.size();i++){
				wxString string_celda;
				
				// Seteo el nombre, stock disponible, precio por unidad e ID de c/producto
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
		RefrescarGrilla();
	}
}

void m_ventanuli::m_recargar( wxCommandEvent& event )  {
	genesis->ReestablecerListas();
	RefrescarGrilla();
}

void m_ventanuli::OnRightClick (wxGridEvent & event) {
	/// Obtengo la fila y columna donde se clickeo
	filaSeleccionada = event.GetRow(); columnaSeleccionada = event.GetCol();
	
	/// Crear un menú emergente (contextual)
	if(filaSeleccionada != -1 && columnaSeleccionada != -1){
		wxMenu menuContextual;
		
		// Defino las opciones del menú
		menuContextual.Append(1001, "Agregar al carrito");
		menuContextual.Append(1002, "Ver detalles");
		menuContextual.Append(1003, "Modificar stock");
		menuContextual.Append(1004, "Eliminar producto");
		
		// Conectar eventos a los ítems del menú
		Bind(wxEVT_MENU, &m_ventanuli::OnAgregar, this, 1001);
		Bind(wxEVT_MENU, &m_ventanuli::OnVerDetalles, this, 1002);
		Bind(wxEVT_MENU, &m_ventanuli::OnModificar, this, 1003);
		Bind(wxEVT_MENU, &m_ventanuli::OnEliminar, this, 1004);
		
		// Mostrar el menú en la posición del cursor
		PopupMenu(&menuContextual);
	}
}

void m_ventanuli::OnModificar (wxCommandEvent & event) {
	
	Producto pr = genesis->MostrarProducto(filaSeleccionada);
	Producto* p_original = genesis->MostrarConId(pr.Ver_id());
	
	V_Modificar* dlg = new V_Modificar(this,p_original);
	if(dlg->ShowModal() == wxID_OK){
		genesis->ReestablecerListas();
		RefrescarGrilla();
		genesis->ActualizarBinario();
	}
	
	dlg->Destroy();
}
void m_ventanuli::OnVerDetalles (wxCommandEvent & event) {
	V_DetallesProd* dlg = new V_DetallesProd(this,genesis->MostrarProducto(filaSeleccionada));
	dlg->ShowModal();
	dlg->Destroy();
	
}
void m_ventanuli::OnAgregar (wxCommandEvent & event) {
	
	Producto pr = genesis->MostrarProducto(filaSeleccionada);
	Producto* p_original = genesis->MostrarConId(pr.Ver_id());
	
	V_SumarCarrito* dlg = new V_SumarCarrito(this,car,p_original);

	dlg->ShowModal();
	dlg->Destroy();
	
	genesis->ReestablecerListas();
	RefrescarGrilla();
}
void m_ventanuli::OnEliminar (wxCommandEvent & event) {
	// Mensaje de confirmación
	if(wxMessageBox("¿Está seguro de eliminar el producto?","Confirmación", wxYES_NO | wxICON_QUESTION) == wxYES){
		Producto pr = genesis->MostrarProducto(filaSeleccionada);
		genesis->EliminarProducto(pr.Ver_id()); // Se elimina del vector base
		genesis->ReestablecerListas(); // Se reestablecen los dos vectores
		RefrescarGrilla();
		genesis->ActualizarBinario(); // Se actualiza el binario sin el producto
	}
	
	
}
void m_ventanuli::Clic_VerCarro( wxCommandEvent& event )  {
	V_Compras* dlg = new V_Compras(this,car,genesis,PasarVector());
	
	dlg->ShowModal();
	dlg->Destroy();
	
	genesis->ReestablecerListas();
	RefrescarGrilla();
}

void m_ventanuli::Clic_VerFiltros( wxCommandEvent& event )  {
	V_Filtros* dlg = new V_Filtros(this,genesis);
	
	if(dlg->ShowModal() == wxID_OK){
		RefrescarGrilla();
	}
	
	dlg->Destroy();
	
}

void m_ventanuli::clicVentas( wxCommandEvent& event )  {
	Lista_Facturas* dlg = new Lista_Facturas(this,facturas);
	dlg->ShowModal();
	dlg->Destroy();
	facturas.clear();

}

CarritoDeCompras * m_ventanuli::DevolverCarrito ( ) {
	return car;
}

vector<Factura> * m_ventanuli::PasarVector ( ) {
	return &facturas;
}

m_ventanuli::~m_ventanuli() {
	
}

void m_ventanuli::ClicAgregarPNuevo( wxCommandEvent& event )  {
	AgregarPr* dlg = new AgregarPr(this,genesis);
	if (dlg->ShowModal() == wxID_OK){
		genesis->ReestablecerListas();
		genesis->OrdenarVector();
		RefrescarGrilla();
		genesis->ActualizarBinario();
	}
}

