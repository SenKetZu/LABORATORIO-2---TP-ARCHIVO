#include "dibujadoPantalla.h"
#include "funcionesArchivos.h"

void dibujarMenu() {
	setColor(WHITE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* MENU PRINCIPAL *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);


	lineaVerde();
	setColor(WHITE);
	cout << "1) USUARIOS " << endl;
	setColor(GREY);
	cout << "2) ENTENAMIENTOS " << endl;
	setColor(WHITE);
	cout << "3) REPORTES " << endl;
	setColor(GREY);
	cout << "4) CONFIGURACION " << endl;
	lineaVerde();
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


	lineaVerde();
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
	lineaVerde();

	setColor(WHITE);
	cout << "0) VOLVER " << endl;
	setColor(GREY);



}

void mensajeEspera(int distanciaVer, int delayMs, bool anim) {
	if (anim) {
		while (!kbhit()) {
			locate(1, distanciaVer);
			cout << "Presione cualquier tecla para volver    ";
			msleep(delayMs);
			locate(1, distanciaVer);
			cout << "Presione cualquier tecla para volver.";
			msleep(delayMs);
			locate(1, distanciaVer);
			cout << "Presione cualquier tecla para volver..";
			msleep(delayMs);
			locate(1, distanciaVer);
			cout << "Presione cualquier tecla para volver...";
			msleep(delayMs);
		}
	}
	else {
		locate(1, distanciaVer);
		cout << "Presione cualquier tecla para volver";
		anykey();
	}
	locate(1, 1);
}

void lineaVerde() {
	setColor(GREEN);
	cout << "-----------------------------------" << endl;
	setColor(GREY);
}

//esta es para mostrar un usuario por pantalla
void printRegistro(usuarios Us, bool simple) {
	if (simple) {
		cls();

		setColor(LIGHTBLUE);
		cout << "\t\t\t******************" << endl;
		cout << "\t\t\t*      DATOS     *" << endl;
		cout << "\t\t\t******************" << endl << endl;
		setColor(GREY);
		
	}
	cout << "identificador: ";
	setColor(LIGHTBLUE);
	cout << Us.identificador << endl;
	setColor(GREY);
	cout << "fecha nacimiento: ";
	setColor(LIGHTBLUE);
	cout << Us.nacimiento.dia << "/" << Us.nacimiento.mes << "/" << Us.nacimiento.a�o << endl;

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
	//---------------------------------------------------------
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
	lineaVerde();
}

//esta es para mostrar un entrenamiento por pantalla
void printRegistro(entrenamiento En, bool simple) {
	if (simple) {
		cls();

		setColor(LIGHTBLUE);
		cout << "\t\t\t******************" << endl;
		cout << "\t\t\t*      DATOS     *" << endl;
		cout << "\t\t\t******************" << endl << endl;
		setColor(GREY);

	}
	cout << "Identificador Entr: ";
	setColor(LIGHTBLUE);
	cout << En.IDentr << endl;
	setColor(GREY);

	cout << "Identificador Usr: ";
	setColor(LIGHTBLUE);
	cout << En.IDuser << endl;
	setColor(GREY);

	cout << "Fecha Entrenamiento: ";
	setColor(LIGHTBLUE);
	cout << En.fechaEntrenamiento.dia << "/" << En.fechaEntrenamiento.dia << "/" << En.fechaEntrenamiento.dia << endl;
	setColor(GREY);

	cout << "Actividad: ";
	setColor(LIGHTBLUE);
	cout << En.activ << endl;
	setColor(GREY);

	cout << "calorias: ";
	setColor(LIGHTBLUE);
	cout << En.cal << endl;
	setColor(GREY);

	cout << "Duracion: ";
	setColor(LIGHTBLUE);
	cout << En.tiempo << endl;
	setColor(GREY);
	
	lineaVerde();
}

void listarUsTodos() {
	cls();
	setColor(LIGHTBLUE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* LISTA USUARIOS *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);

	usuarios aux;
	bool seguro = true;
	FILE* P;
	P = fopen("Usuarios.fah", "rb+");
	if (P == NULL) { cout << "NO HAY REGISTROS"; seguro = false; }
	


	for (int i = 0; i < cantReg(true);++i) {

		fread(&aux, sizeof(usuarios), 1, P);
		printRegistro(aux, false);
	}


	cout <<endl<< "Presione cualquier tecla para continuar...";
	anykey();
}



