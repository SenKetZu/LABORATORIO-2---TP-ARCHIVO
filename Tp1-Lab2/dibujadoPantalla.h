#pragma once
#include "structs.h"


//dibujado 
void dibujarMenu();
void dibujarMenuUsuario();
void printRegistro(usuarios Us, bool simple);
void printRegistro(entrenamiento En, bool simple);
void listarUsTodos();
void mensajeEspera(int distancia, int delayMs, bool anim);
void lineaVerde();