#pragma once
#include "structs.h"



//manejo archivos
bool Archivar(usuarios nuevoUs);
bool Archivar(usuarios nuevoUs, int posEscribir);
bool Archivar(entrenamiento nuevoEn);
bool Archivar(entrenamiento nuevoEn, int posEscribir);
//BackUps
bool realizarBackUp();
bool cargarBackUp();
//int generadorID();
usuarios BuscarUsuarioID(int ID);

//cuenta la cantidad de registros en el archivo
int cantReg(bool esUsuarios);

void bajaUsuario();
