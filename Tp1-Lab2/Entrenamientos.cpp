#include "structs.h"
#include "dibujadoPantalla.h"
#include "entradaDatos.h"
#include "funcionesArchivos.h"
#include "Entrenamientos.h"

bool Archivar(entrenamiento nuevoEn) {

	FILE* P;
	P = fopen("Entrenamientos.dat", "ab");
	if (P == NULL) { cout << "ERROR"; return false; }



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
	P = fopen("Entrenamientos.dat", "rb+");
	if (P == NULL) { cout << "ERROR"; return false; }

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
		nuevo.IDuser = verifIDUser();
		setColor(GREY);

		nuevo.fechaEntrenamiento = fechaValidada(false);

		cout << "Actividad: ";
		setColor(LIGHTBLUE);
		nuevo.activ = verifActv(nuevo.IDuser);
		setColor(GREY);

		cout << endl << "Calorias: ";
		setColor(LIGHTBLUE);
		cin >> nuevo.cal;
		setColor(GREY);

		cout << endl << "Duracion de la actividad(minutos): ";
		setColor(LIGHTBLUE);
		cin >> nuevo.tiempo;
		cin.ignore();
		setColor(GREY);
	}


	Archivar(nuevo);


}

int verifIDUser() {

	int correct,ID;
	bool correcto = false;
	usuarios paraVerif;
	do {
		ID=numerosBien();

		paraVerif=BuscarUsuarioID(ID);

		if (paraVerif.identificador==ID) {
			correct = ID;
			correcto = true;
		}
		else {
			setColor(RED);
			cout << "La ID del usuario no se encontro, intentelo nuevamente: ";
			setColor(LIGHTBLUE);
		}





	} while (!correcto);




	return correct;
}

int verifActv(int IDuser){

	int act;
	bool actCorrecta = false;

	do {
		act = numerosBien();
		
		switch (act){
			case 1:
			case 2:
			case 3:actCorrecta = true; break;
			case 4: if (BuscarUsuarioID(IDuser).aptMed) {
				actCorrecta = true;
				break;
			}
			else {
				setColor(RED);
				cout << "Actividad no valida, ingrese otra: ";
				setColor(LIGHTBLUE);

				break;
			}
			case 5:	if (BuscarUsuarioID(IDuser).aptMed) {
				actCorrecta = true;
				break;
			}
			else {
				setColor(RED);
				cout << "Actividad no valida, ingrese otra: ";
				setColor(LIGHTBLUE);

				break;
			}
			default: {
				setColor(RED);
				cout << "Actividad no valida, ingrese otra: ";
				setColor(LIGHTBLUE);
				break;
			}
		}
	} while (!actCorrecta);



	return act;
}

int generadorEntrID() {

	entrenamiento ultimo;

	FILE* P;
	P = fopen("Entrenamientos.dat", "ab+");
	if (P == NULL) { cout << "ERROR"; return 0; }

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
	cout << "6) LISTAR ENTRENAMIENTOS MAYORES AL PROMEDIO " << endl;
	lineaVerde();

	setColor(WHITE);
	cout << "0) VOLVER " << endl;
	setColor(GREY);
}

entrenamiento BuscarEntrenamientoID(int ID) {
	entrenamiento elegido;

	int posicion = ID - 1;


	FILE* P;
	P = fopen("Entrenamientos.dat", "ab+");
	if (P == NULL) { cout << "ERROR"; }

	for (int i = 0; i <= posicion; ++i) {

		fread(&elegido, sizeof(entrenamiento), 1, P);

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
		mensajeEspera(13, 600, true);
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
	usuarios elegido = BuscarUsuarioID(ID);
	if (elegido.estado) {
		for (int i = 0; i < cantEntrenamientos(); ++i) {

			entrenamiento aux = BuscarEntrenamientoID(1 + i);

			if (aux.IDuser == ID) {
				printRegistro(aux, false);
			}
		}
	}
	else { 
		setColor(RED);
		cout<<"no se encontro el usuario o no esta habilitado"<<endl;
		setColor(GREY);
	}
	
	cout << "Presione cualquier tecla para continuar";
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

	cout << endl << "presione cualquier tecla para continuar";
	anykey();

}

//--------------------------


void listarEntrMayorProm() {
	vector<entrenamiento> listaEntre;
	entrenamiento aux;
	FILE* P = fopen("Entrenamientos.dat", "rb");
	
	
	while (fread(&aux,sizeof entrenamiento,1,P)) {
		listaEntre.push_back(aux);
	}

	int prom = 0;

	for (int i = 0; i < listaEntre.size();++i) {
		prom += listaEntre[i].tiempo;
	}
	prom /= listaEntre.size();

	cls();
	setColor(LIGHTBLUE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t*PROMEDIO: "<<prom << "  *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);


	for (int i = 0; i < listaEntre.size(); ++i) {
		if (listaEntre[i].tiempo>prom) {
			printRegistro(listaEntre[i],false);
		}
		

	}
	fclose(P);
	cout << "presiones cualquier tecla para volver";
	anykey();

}