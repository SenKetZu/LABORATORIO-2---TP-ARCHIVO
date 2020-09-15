#include "func.h"


//CUIDADO: LA POSICION 0 ES EL PRIMER REGISTRO, LA POSICION 1 ES EL SEGUNDO!!!--- POSICION 1 NO ES EL PRIMER REGISTRO.
bool archivarUsuario(usuarios nuevoUs, int posEscribir) {

	FILE* P;
	P = fopen("Usuarios.fah", "rb+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }

	if (posEscribir != 0) {
		fseek(P, int(sizeof(usuarios)) * posEscribir, 0);
	}


	if (fwrite(&nuevoUs, sizeof(usuarios), 1, P)) {

		cout << "TODO CORRECTO TROESMA";
		fclose(P);
		return true;
	}
	else {
		cout << "QUE PICARDIA";
		fclose(P);
		return false;
	}

}


//recive un struct de tipo usuario y lo carga en el archivo.
bool archivarUsuario(usuarios nuevoUs) {

	FILE* P;
	P = fopen("Usuarios.fah", "ab");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return false; }


	//int verf=
	if (fwrite(&nuevoUs, sizeof(usuarios), 1, P)) {

		cout << "TODO CORRECTO TROESMA";
		fclose(P);
		return true;
	}
	else {
		cout << "QUE PICARDIA";
		fclose(P);
		return false;
	}

}


//revisa el ultimo ususario y te genera la siguiente ID, si no habia ususario te genera la primer ID
int generadorID() {

	usuarios ultimo;

	FILE* P;
	P = fopen("Usuarios.fah", "ab+");
	if (P == NULL) { cout << "ERROR SOS PERUANO"; return 0; }
	int i = fseek(P,int(sizeof(usuarios))*-1, 2);
	if (i) {
		fclose(P);
		return 1111;

	}
	else {
		int verif = fread(&ultimo, sizeof(usuarios), 1, P);

		int id = ultimo.identificador;
		id++;
		fclose(P);
		return id;

	}

}

//devuelve el usuario que corresponde al id;
usuarios BuscarUsuarioID(int ID) {

	usuarios elegido;
	usuarios def;
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

	return elegido;
}