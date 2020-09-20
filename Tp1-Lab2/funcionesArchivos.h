#pragma once
#include "structs.h"



//manejo archivos
bool Archivar(usuarios nuevoUs);
bool Archivar(usuarios nuevoUs, int posEscribir);
bool Archivar(entrenamiento nuevoEn);
bool Archivar(entrenamiento nuevoEn, int posEscribir);
//int generadorID();
usuarios BuscarUsuarioID(int ID);
int cantReg(bool esUsuarios);
void bajaUsuario();
