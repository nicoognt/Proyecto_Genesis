#include <fstream>
#include "Producto.h"
using namespace std;

void cargar_prueba(string n){
	ofstream file(n,ios::binary);
	if(file.is_open()){
		
		producto_con_char p1={"Short verde","deportivo","mujer",4,2,3,12345,12000};
		producto_con_char p2={"Short negro","entre-casa","hombre",0,0,0,54321,9500};
		producto_con_char p3={"Remera negra","casual","hombre",2,2,1,11111,13500};
		producto_con_char p4={"Pantalon jean","informal","mujer",10,2,0,22222,10000};
		producto_con_char p5={"Pollera larga","festival","mujer",0,9,5,33232,8000};
		producto_con_char p6={"Camisa blanca estampada","elegante","hombre",10,10,22,19403,20000};
		producto_con_char p7={"Zapatillas adidas","running","hombre",11,2,3,75012,50000};
		
		file.write((char*)&p1,sizeof(producto_con_char));
		file.write((char*)&p2,sizeof(producto_con_char));
		file.write((char*)&p3,sizeof(producto_con_char));
		file.write((char*)&p4,sizeof(producto_con_char));
		file.write((char*)&p5,sizeof(producto_con_char));
		file.write((char*)&p6,sizeof(producto_con_char));
		file.write((char*)&p7,sizeof(producto_con_char));
		
	}
	file.close();
}
