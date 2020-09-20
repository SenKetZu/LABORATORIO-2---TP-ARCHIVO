#include "entradaDatos.h"
#include "funcionesArchivos.h"




//CUIDADO: LA POSICION 0 ES EL PRIMER REGISTRO, LA POSICION 1 ES EL SEGUNDO!!!--- POSICION 1 NO ES EL PRIMER REGISTRO.
bool Archivar(usuarios nuevoUs, int posEscribir) {

	FILE* P;
	P = fopen("Usuarios.fah", "rb+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }

	if (posEscribir != 0) {
		fseek(P, int(sizeof(usuarios)) * posEscribir, 0);
	}


	if (fwrite(&nuevoUs, sizeof(usuarios), 1, P)) {

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


//recive un struct de tipo usuario y lo carga en el archivo.
bool Archivar(usuarios nuevoUs) {

	FILE* P;
	P = fopen("Usuarios.fah", "ab");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }


	//int verf=
	if (fwrite(&nuevoUs, sizeof(usuarios), 1, P)) {

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





//si recive true devuelve la cantidad de ususarios, si envias false devuelve la cantidad de entrenamientos
int cantReg(bool esUsuarios) {
	int tamaño;

	if (esUsuarios) {
		FILE* P = fopen("Usuarios.fah", "ab");
		tamaño=ftell(P);
		tamaño = tamaño / int(sizeof(usuarios));
		fclose(P);
	}
	else {
		FILE* P = fopen("Entrenamientos.fah", "ab");
		tamaño = ftell(P);
		tamaño = tamaño / int(sizeof(entrenamiento));
		fclose(P);
	}

	
	return tamaño;
}

//devuelve el usuario que corresponde al id;
usuarios BuscarUsuarioID(int ID) {

	usuarios elegido;

	int posicion = ID - 1111;


	FILE* P;
	P = fopen("Usuarios.fah", "rb+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; }//mensajeError();

	for (int i = 0; i <= posicion; ++i) {

		fread(&elegido, sizeof(usuarios), 1, P);

	}
	
	if (elegido.identificador != ID) {
		elegido.identificador = 0;		

	}
	fclose(P);
	return elegido;
}


void bajaUsuario() {
	
	int ID = pedirID();
	usuarios darBaja = BuscarUsuarioID(ID);
	darBaja.estado = false;
	Archivar(darBaja, ID - 1111);


}