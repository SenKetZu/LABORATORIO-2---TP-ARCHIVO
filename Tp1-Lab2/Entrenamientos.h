#pragma once
#include "structs.h"

bool Archivar(entrenamiento nuevoEn);
bool Archivar(entrenamiento nuevoEn, int posEscribir);
void agregarEntrenamiento();
void listarEntrMayorProm();
int generadorEntrID();
void dibujarMenuEntrenamientos();
entrenamiento BuscarEntrenamientoID(int ID);
void modificarEntrenamiento();
int pedirIDEntre();
int cantEntrenamientos();
void listarEntrenamientoID(int ID);
void listarEntrUsID(int ID);
void listarEntr();
int verifIDUser();
int verifActv(int IDuser);

