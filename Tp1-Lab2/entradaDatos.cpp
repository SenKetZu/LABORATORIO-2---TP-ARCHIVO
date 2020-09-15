#include "func.h"




//sub-ingreso para poner la fecha
fecha ingresarFecha() {

	fecha nacimiento;

	setColor(GREEN);
	cout << "--Fecha de nacimiento--" << endl;
	setColor(GREY);
	
	cout << "dia: ";
	setColor(LIGHTBLUE);
	cin >> nacimiento.dia;
	setColor(GREY);
	
	cout << "mes: ";
	setColor(LIGHTBLUE);
	cin >> nacimiento.mes;
	setColor(GREY);
	
	cout  << "año: ";
	setColor(LIGHTBLUE);
	cin >> nacimiento.año;
	setColor(GREY);

	return nacimiento;

}

//llenado de struct con los datos de un usuario, debe ser mandado a la funcion archivarUsuario() para cargarlo en un archivo.
void agregarUsusario() {
	setColor(GREY);
	usuarios nuevo;

	int id = generadorID();

	if (id) {
		nuevo.identificador = id;

		cout <<endl<< "Nombre: ";
		setColor(LIGHTBLUE);
		cin.getline(nuevo.nombre, 50);
		setColor(GREY);

		cout << "Apellido: ";
		setColor(LIGHTBLUE);
		cin.getline(nuevo.apellido, 50);
		setColor(GREY);

		nuevo.nacimiento = ingresarFecha();


		cin.clear();
		cout << "ingrese altura en cm:";
		setColor(LIGHTBLUE);
		cin >> nuevo.altura;
		setColor(GREY);

		cout << endl << "ingrese el peso en kg:";
		setColor(LIGHTBLUE);
		cin >> nuevo.peso;
		setColor(GREY);

		cout << endl << "ingrese perfil de actividad:";
		setColor(LIGHTBLUE);
		cin >> nuevo.perfilAct;
		setColor(GREY);
	}

	if (archivarUsuario(nuevo)) {

		//mensajeCorrecto();
	}
	else {

		//mensajeError();
	}
	
}

// usa un getch para recibir que numero se pulso y te hace el paso de ascii a decimal.
int numeroPulsado() {


	return getch() - 48;
}

//recibe un usuario y modifica los datos, luego lo manda a archivar.
void modificarUsuario() {
	int ID;
	cout << "Ingrese el ID: ";
	cin >> ID;
	usuarios elegido = BuscarUsuarioID(ID);


	cout << "nuevo peso: ";
	cin >> elegido.peso;

	cout << "perfil de actividad: ";
	cin >> elegido.perfilAct;

	cout << "apta medica: ";
	cin >> elegido.aptMed;

	/*
	peso;
	perfil_actividad;
	aptamedica;
	*/

	if (archivarUsuario(elegido, ID - 1111)) {

		//mensajeCorrecto();
	}
	else {

		//mensajeError();
	}
}

void listarUsID() {
	int ID;
	
	setColor(GREY);
	
	cout << endl << "ingrese el ID del usuario: ";

	setColor(LIGHTBLUE);
	cin >> ID;
	setColor(GREY);
	
	usuarios usuario = BuscarUsuarioID(ID);

	if (usuario.identificador!=0) {
		
		printUsuario(usuario);
	}
	else {
		setColor(RED);
		cout << endl<<"no se encontro el usuario, revise el ID";
		setColor(GREY);
		msleep(5000);
	}

	

}