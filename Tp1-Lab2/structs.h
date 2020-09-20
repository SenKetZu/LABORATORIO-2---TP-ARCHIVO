#pragma once

#include <iostream>
#include "rlutil.h"
#include <time.h>
#include <locale.h>



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


struct entrenamiento {
	int IDentr;
	int IDuser;

	fecha fechaEntrenamiento;
	//tipo de actividad
	int activ;
	//cantidad de calorias gastadas
	float cal;
	//tiempo que duro la actividad
	int tiempo;

};




