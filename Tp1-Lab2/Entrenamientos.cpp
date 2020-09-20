#include "structs.h"
#include "dibujadoPantalla.h"
#include "entradaDatos.h"
#include "funcionesArchivos.h"
#include "Entrenamientos.h"

bool Archivar(entrenamiento nuevoEn) {

	FILE* P;
	P = fopen("Entrenamientos.fah", "ab");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }



	if (fwrite(&nuevoEn, sizeof(entrenamiento), 1, P)) {
		setColor(GREEN);
		cout << "CORRECTO";
		setColor(GREY);
		fclose(P);
		msleep(2000);
		return true;
	}
	else {
		setColor(RED);
		cout << "ERROR";
		setColor(GREY);
		fclose(P);
		msleep(2000);
		return false;
	}



}

bool Archivar(entrenamiento nuevoEn, int posEscribir) {

	FILE* P;
	P = fopen("Entrenamientos.fah", "rb+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }

	if (posEscribir != 0) {
		fseek(P, int(sizeof(entrenamiento)) * posEscribir, 0);
	}


	if (fwrite(&nuevoEn, sizeof(entrenamiento), 1, P)) {

		setColor(GREEN);
		cout << "CORRECTO";
		setColor(GREY);
		fclose(P);
		msleep(2000);
		return true;
	}
	else {
		setColor(RED);
		cout << "ERROR";
		setColor(GREY);
		fclose(P);
		msleep(2000);
		return false;
	}





}

void agregarEntrenamiento() {

	setColor(GREY);
	entrenamiento nuevo;

	int id = generadorEntrID();

	if (id) {

		nuevo.IDentr = id;

		cout << endl << "ID Usuario: ";
		setColor(LIGHTBLUE);
		nuevo.IDuser = numerosBien();
		setColor(GREY);

		nuevo.fechaEntrenamiento = fechaValidada(false);

		cout << "Actividad: ";
		setColor(LIGHTBLUE);
		nuevo.activ = numerosBien();
		setColor(GREY);

		cout << endl << "Calorias: ";
		setColor(LIGHTBLUE);
		cin >> nuevo.cal;
		setColor(GREY);

		cout << endl << "Duracion de la actividad: ";
		setColor(LIGHTBLUE);
		cin >> nuevo.tiempo;
		setColor(GREY);
	}


	Archivar(nuevo);


}

int generadorEntrID() {

	entrenamiento ultimo;

	FILE* P;
	P = fopen("Entrenamientos.fah", "ab+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return 0; }

	int i = fseek(P, int(sizeof(entrenamiento)) * -1, 2);

	if (i) {
		fclose(P);
		return 1;

	}
	else {
		int verif = fread(&ultimo, sizeof(entrenamiento), 1, P);

		int id = ultimo.IDentr;
		id++;
		fclose(P);
		return id;

	}

}

void dibujarMenuEntrenamientos() {
	setColor(WHITE);
	cout << "\t\t\t***********************" << endl;
	cout << "\t\t\t* MENU ENTRENAMIENTOS *" << endl;
	cout << "\t\t\t***********************" << endl << endl;
	setColor(GREY);


	lineaVerde();
	setColor(WHITE);
	cout << "1) NUEVO ENTRENAMIENTO " << endl;
	setColor(GREY);
	cout << "2) MODIFICAR ENTRENAMIENTO " << endl;
	setColor(WHITE);
	cout << "3) LISTAR ENTRENAMIENTO POR ID " << endl;
	setColor(GREY);
	cout << "4) LISTAR ENTRENAMIENTO POR ID USUARIO " << endl;
	setColor(WHITE);
	cout << "5) LISTAR TODOS LOS ENTRENAMIENTOS " << endl;
	setColor(GREY);
	lineaVerde();

	setColor(WHITE);
	cout << "0) VOLVER " << endl;
	setColor(GREY);
}

entrenamiento BuscarEntrenamientoID(int ID) {
	entrenamiento elegido;

	int posicion = ID - 1;


	FILE* P;
	P = fopen("Entrenamientos.fah", "rb+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; }

	for (int i = 0; i <= posicion; ++i) {

		fread(&elegido, sizeof(usuarios), 1, P);

	}

	if (elegido.IDentr != ID) {
		elegido.IDentr = 0;

	}
	fclose(P);
	return elegido;


}

void modificarEntrenamiento() {

	int ID;
	cout << endl << "Ingrese el ID: ";
	cin >> ID;
	lineaVerde();
	entrenamiento elegido = BuscarEntrenamientoID(ID);

	if (ID == elegido.IDentr) {
		cout << "nuevo tiempo: ";
		cin >> elegido.tiempo;

		cout << "Cal quemadas: ";
		cin >> elegido.cal;

		Archivar(elegido, ID - 1);


	}
	else {
		setColor(RED);
		cout << "¡Error entrenamiento no encontrado!";
		setColor(GREY);
	}
}

int pedirIDEntre() {
	int ID;

	setColor(GREY);

	cout << endl << "ingrese el ID del entrenamiento: ";

	setColor(LIGHTBLUE);
	cin >> ID;
	setColor(GREY);
	return ID;
}

int cantEntrenamientos() {
	int cant = generadorEntrID() - 1;

	return cant;
}

void listarEntrenamientoID(int ID) {
	entrenamiento elegido = BuscarEntrenamientoID(ID);

	if (elegido.IDentr != 0) {

		printRegistro(elegido, true);
		mensajeEspera(30, 600, true);
	}
	else {
		setColor(RED);
		cout << endl << "no se encontro el Entrenamiento, revise el ID";
		setColor(GREY);
		msleep(2000);
	}

}

void listarEntrUsID(int ID) {

	cls();
	setColor(LIGHTBLUE);
	cout << "\t\t\t************************" << endl;
	cout << "\t\t\t* LISTA ENTRENAMIENTOS *" << endl;
	cout << "\t\t\t************************" << endl << endl;
	setColor(GREY);

	for (int i = 0; i < cantEntrenamientos(); ++i) {

		entrenamiento aux = BuscarEntrenamientoID(1 + i);

		if (aux.IDuser == ID) {
			printRegistro(aux, false);
		}
	}

	cout << endl << "presiones cualquier tecla para continuar";
	anykey();

}

void listarEntr() {

	cls();
	setColor(LIGHTBLUE);
	cout << "\t\t\t************************" << endl;
	cout << "\t\t\t* LISTA ENTRENAMIENTOS *" << endl;
	cout << "\t\t\t************************" << endl << endl;
	setColor(GREY);

	for (int i = 0; i < cantReg(false); ++i) {

		entrenamiento aux = BuscarEntrenamientoID(1 + i);

		printRegistro(aux, false);

	}

	cout << endl << "presiones cualquier tecla para continuar";
	anykey();

}