#pragma once
#include "structs.h"

void ajustes();
//dibujado 
bool confirmacionBKP();
void dibujarMenu();
void dibujarMenuUsuario();
void dibujarMenuConfiguraciones();
void printRegistro(usuarios Us, bool simple);
void printRegistro(entrenamiento En, bool simple);
void listarUsTodos();
void mensajeEspera(int distancia, int delayMs, bool anim);
void lineaVerde();