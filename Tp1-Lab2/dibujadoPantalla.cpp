#include "func.h"



void dibujarMenu() {
	setColor(WHITE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* MENU PRINCIPAL *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);


	cout << "--------------" << endl;
	setColor(WHITE);
	cout << "1) USUARIOS " << endl;
	setColor(GREY);
	cout << "2) ENTENAMIENTOS " << endl;
	setColor(WHITE);
	cout << "3) REPORTES " << endl;
	setColor(GREY);
	cout << "4) CONFIGURACION " << endl;
	cout << "----------------------" << endl;
	setColor(WHITE);
	cout << "0) SALIR DEL PROGRAMA" << endl;
	setColor(GREY);
}

void dibujarMenuUsuario() {

	setColor(WHITE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* MENU USUARIOS  *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);


	cout << "--------------" << endl;
	setColor(WHITE);
	cout << "1) NUEVO USUSARIO " << endl;
	setColor(GREY);
	cout << "2) MODIFICAR USUARIO " << endl;
	setColor(WHITE);
	cout << "3) LISTAR USUARIO POR ID " << endl;
	setColor(GREY);
	cout << "4) LISTAR TODOS LOS USUARIOS " << endl;
	setColor(WHITE);
	cout << "5) ELIMINAR USUARIO " << endl;
	setColor(GREY);
	cout << "----------------------" << endl;

	setColor(WHITE);
	cout << "0) VOLVER " << endl;
	setColor(GREY);



}

void mensajeCorrecto(string mensaje) {

}

void mensajeError(string mensaje) {

}


void printUsuario(usuarios Us) {
	cls();

	setColor(WHITE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t*      DATOS     *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);
	
	cout << "identificador: ";
	setColor(LIGHTBLUE);
	cout << Us.identificador << endl;
	setColor(GREY);
	cout << "fecha nacimiento: ";
	setColor(LIGHTBLUE);
	cout << Us.nacimiento.dia << "/" << Us.nacimiento.mes << "/" << Us.nacimiento.año << endl;

	setColor(GREY);
	cout << "identificador: ";
	setColor(LIGHTBLUE);
	cout << Us.identificador << endl;
	setColor(GREY);
	cout << "nombre: ";
	setColor(LIGHTBLUE);
	cout << Us.nombre << endl;
	setColor(GREY);
	cout << "apellido: ";
	setColor(LIGHTBLUE);
	cout << Us.apellido << endl;
	setColor(GREY);
	cout << "perfil de actividad: ";
	setColor(LIGHTBLUE);
	cout << Us.perfilAct << endl;
	setColor(GREY);
	cout << "altura: ";
	setColor(LIGHTBLUE);
	cout << Us.altura << endl;
	setColor(GREY);
	cout << "peso: ";
	setColor(LIGHTBLUE);
	cout << Us.peso << endl;
	setColor(GREY);



	if (Us.aptMed) {
		cout << "apta medica: ";
		setColor(LIGHTBLUE);
		cout << "alta" << endl;
		setColor(GREY);
	}
	else {
		cout << "apta medica: ";
		setColor(LIGHTBLUE);
		cout << "baja" << endl;
		setColor(GREY);
	}

	if (Us.estado) {
		cout << "estado: ";
		setColor(LIGHTBLUE);
		cout << "en el sistema" << endl;
		setColor(GREY);
	}
	else {
		cout << "estado: ";
		setColor(LIGHTBLUE);
		cout << "dado de baja" << endl;
		setColor(GREY);
	}
	
	anykey();
}