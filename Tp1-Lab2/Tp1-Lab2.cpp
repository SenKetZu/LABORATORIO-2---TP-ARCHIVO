#include "structs.h"
#include "dibujadoPantalla.h"
#include "entradaDatos.h"
#include "funcionesArchivos.h"
#include "Entrenamientos.h"


/*
bool menuReportes();


*/

void menuConfiguraciones() {
	int control;
	do {

		cls();
		dibujarMenuConfiguraciones();

		control = numeroPulsado();

		switch (control) {

		case 1: {
			realizarBackUp();
			break;
		}

		case 2: {
			cargarBackUp();
			break;
		}
		default:break;
		}

		setColor(RED);
		if (control > 5) { cout << endl << "Elija una opcion valida"; msleep(1000); }

		setColor(GREY);

	} while (control != 0);

}














void menuEntrenamiento() {
	int control;
	do {

		cls();
		dibujarMenuEntrenamientos();
		
		control = numeroPulsado();

		switch (control) {

			case 1: {
				agregarEntrenamiento();
				break;
			}
			case 2: {
				modificarEntrenamiento();
				break;
			}
			case 3: {
				listarEntrenamientoID(pedirIDEntre());
				break;
			}
			case 4: {
				listarEntrUsID(pedirID());
				break;
			}
			case 5: {
				listarEntr();
				break;
			}
			default: {

				setColor(RED);
				if (control > 5) { cout << endl << "Elija una opcion valida"; msleep(1000); }
				setColor(GREY);

				break;
			}
		}

		

	} while (control != 0);
}


void menuUsuario() {
	
	
	int control;
	do {
		
		cls();
		dibujarMenuUsuario();
		cleanGetch();
		control = numeroPulsado();

		switch (control) {

			case 1: {
				agregarUsusario();
				break;
			}

			case 2: {
				modificarUsuario();
				break;
			}

			case 3: {
				listarUsID(pedirID());
				break;
			}

			case 4: {
				listarUsTodos();
				break;
			}

			case 5: {
				bajaUsuario();
				break;
			}
			default:break;
		}

		setColor(RED);
		if (control > 5) { cout <<endl<< "Elija una opcion valida"; msleep(1000);}
		
		setColor(GREY);

	} while (control!=0);

	


}

void Menu() {
	cleanGetch();
	ajustes();
	int control;

	do {
		cls();
		dibujarMenu();
		control = numeroPulsado();


		switch (control) {
			case 1: {
				menuUsuario();

				break;
			}

			case 2: {
				menuEntrenamiento();
				break;
			}
			case 3: {
				break;
			}
			case 4: {
				menuConfiguraciones();
				break;
			}



			default:break;
		}

		setColor(RED);
		if (control > 5) { cout<<endl<< "Elija una opcion valida"; msleep(1000);}
		setColor(GREY);

	}while (control!=0);

	
}

int main(){

	
	hidecursor();
	//showcursor();


	


	Menu();
	//cout << getch();
	//cout << numerosBien();


	

	return 0;
}
