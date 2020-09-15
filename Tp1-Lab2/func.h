#pragma once
#include <iostream>
#include "rlutil.h"

using namespace std;
using namespace rlutil;



//estructuras
struct fecha {
	int dia;
	int mes;
	int año;
};
struct usuarios {

	int identificador;
	fecha nacimiento;
	char nombre[50];
	char apellido[50];
	char perfilAct;
	float altura;
	float peso;
	bool aptMed;
	bool estado;

};


//manejo archivos
bool archivarUsuario(usuarios nuevoUs);
bool archivarUsuario(usuarios nuevoUs, int posEscribir);
int generadorID();
usuarios BuscarUsuarioID(int ID);


//ingreso datos
fecha ingresarFecha();
void agregarUsusario();
int numeroPulsado();
void modificarUsuario();
void listarUsID();

//dibujado 
void dibujarMenu();
void dibujarMenuUsuario();
void mensajeCorrecto(string mensaje);
void mensajeError(string mensaje);
void printUsuario(usuarios Us);