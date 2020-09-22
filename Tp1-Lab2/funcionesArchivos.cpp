#include "entradaDatos.h"
#include "funcionesArchivos.h"
#include "dibujadoPantalla.h"



//CUIDADO: LA POSICION 0 ES EL PRIMER REGISTRO, LA POSICION 1 ES EL SEGUNDO!!!--- POSICION 1 NO ES EL PRIMER REGISTRO.
bool Archivar(usuarios nuevoUs, int posEscribir) {

	FILE* P;
	P = fopen("Usuarios.dat", "rb+");
	if (P == NULL) { cout << "ERROR"; return false; }

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
	P = fopen("Usuarios.dat", "ab");
	if (P == NULL) { cout << "ERROR"; return false; }


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


bool realizarBackUp() {

	
	//proseso de guardado
	if(confirmacionBKP()){
		FILE* P = fopen("Usuarios.dat", "rb");
		FILE* R = fopen("Entrenamientos.dat", "rb");
		if (!(P || R)) {
			cout << "Error";
			return false;
		}



		FILE* Q = fopen("Usuarios.bkp", "wb");
		FILE* S = fopen("Entrenamientos.bkp", "wb");

		if (!(Q || S)) {
			cout << "Error";
			return false;
		}
		usuarios usBack;
		entrenamiento enBack;

		//usuarios
		while (fread(&usBack, sizeof usuarios, 1, P)) {
			fwrite(&usBack, sizeof usuarios, 1, Q);
		}

		//entrenamientos
		while (fread(&enBack, sizeof entrenamiento, 1, R)) {
			fwrite(&enBack, sizeof entrenamiento, 1, S);
		}

		fclose(P);
		fclose(Q);
		fclose(R);
		fclose(S);

		setColor(GREEN);
		cout << "Proceso realizado con exito, pulse cualquier tecla para continuar";
		setColor(GREY);
		anykey();
		return true;
	}
	else {
		setColor(RED);
		cout << "Error en la confirmacion, pulse cualquier tecla para continuar";
		setColor(GREY);
		anykey();
		return false;
	}
	
}


bool cargarBackUp() {
	//proseso de guardado
	if (confirmacionBKP()) {
		FILE* P = fopen("Usuarios.dat", "wb");
		FILE* R = fopen("Entrenamientos.dat", "wb");
		if (!(P || R)) {
			cout << "Error";
			return false;
		}



		FILE* Q = fopen("Usuarios.bkp", "rb");
		FILE* S = fopen("Entrenamientos.bkp", "rb");

		if (!(Q || S)) {
			cout << "Error";
			return false;
		}
		usuarios usBack;
		entrenamiento enBack;

		//usuarios
		while (fread(&usBack, sizeof usuarios, 1, Q)) {
			fwrite(&usBack, sizeof usuarios, 1, P);
		}

		//entrenamientos
		while (fread(&enBack, sizeof entrenamiento, 1, S)) {
			fwrite(&enBack, sizeof entrenamiento, 1, R);
		}

		fclose(P);
		fclose(Q);
		fclose(R);
		fclose(S);

		setColor(GREEN);
		cout << "Proceso realizado con exito, pulse cualquier tecla para continuar";
		setColor(GREY);
		anykey();
		return true;
	}
	else {
		setColor(RED);
		cout << "Error en la confirmacion, pulse cualquier tecla para continuar";
		setColor(GREY);
		anykey();
		return false;
	}

	return false;
}



//si recive true devuelve la cantidad de ususarios, si envias false devuelve la cantidad de entrenamientos
int cantReg(bool esUsuarios) {
	int tamaño;

	if (esUsuarios) {
		FILE* P = fopen("Usuarios.dat", "ab+");
		fseek(P, 0, 2);
		tamaño=ftell(P);
		tamaño = tamaño / int(sizeof(usuarios));
		fclose(P);
	}
	else {
		FILE* P = fopen("Entrenamientos.dat", "ab+");
		fseek(P, 0, 2);
		tamaño = ftell(P);
		tamaño = tamaño / int(sizeof(entrenamiento));
		fclose(P);
	}

	
	return tamaño;
}

//devuelve el usuario que corresponde al id;
usuarios BuscarUsuarioID(int ID) {

	usuarios elegido;

	


	FILE* P;
	P = fopen("Usuarios.dat", "ab+");
	if (P == NULL) { cout << "ERROR"; }
	else {
		while (fread(&elegido, sizeof(usuarios), 1, P)) {
			if (elegido.identificador == ID) {
				return elegido;
			}

		}
	}
	
	elegido.identificador = -1;
	return elegido;
	
}


void bajaUsuario() {
	
	int ID = pedirID();
	usuarios darBaja = BuscarUsuarioID(ID);
	darBaja.estado = false;
	Archivar(darBaja, ID - 1111);


}