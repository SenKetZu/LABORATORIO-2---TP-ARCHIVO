#include "func.h"

bool menuEntrenamiento();
bool menuReportes();
bool menuConfiguraciones();



/*
setColor(WHITE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* MENU PRINCIPAL *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);


*/














void menuUsuario() {
	
	
	int control;
	do {
		cls();
		dibujarMenuUsuario();
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
				listarUsID();
				break;
			}


			default:break;
		}

		setColor(RED);
		if (control > 5) { cout << "Elija una opcion valida"; msleep(1000);}
		
		setColor(GREY);

	} while (control!=0);

	


}

void Menu() {
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




			default:break;
		}

		setColor(RED);
		if (control > 5 && control != 0) { cout << "Elija una opcion valida"; msleep(1000);}
		setColor(GREY);

	}while (control!=0);

	
}

int main(){

	system("mode con: cols=66 lines=30");
	system("color 08");
	hidecursor();
	//showcursor();


	


	Menu();
	
	

	
	anykey();
	return 0;
}
