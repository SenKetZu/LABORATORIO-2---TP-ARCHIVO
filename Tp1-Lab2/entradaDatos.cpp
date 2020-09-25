#include "structs.h"
#include "entradaDatos.h"
#include "funcionesArchivos.h"
#include "dibujadoPantalla.h"
#include <limits>
#include <limits.h>

#undef max





//verifica que lo ingresado sean numeros enteros
float numerosBien() {
	string str; // Cadena leída
	float dato;
	

	while (getline(cin, str)) {
		const char* idx = str.c_str();

		// Mientras que no lleguemos al final de la cadena,
		// y el caracter sea un dígito.
		while (*idx && *idx >= '0' && *idx <= '9')
			++idx;

		// Si llegamos al final de la cadena, la validación es correcta.
		if (!(*idx))
			break;
		//LA TENES ADENTRO BRIAN, sin tu funcion esa que no anda en c++ 11 gato


	}

	// Convertimos la cadena en entero.
	dato = atof(str.c_str());

	
	return dato;

}

//sub-ingreso para poner la fecha
fecha ingresarFecha(bool nac) {
	cin.clear();
	fecha nacimiento;
	if (nac) {
		setColor(GREEN);
		cout << "--Fecha de nacimiento--" << endl;
		setColor(GREY);
	}
	else {
		setColor(GREEN);
		cout << "--Fecha de entrenamiento--" << endl;
		setColor(GREY);
	}
	
	
	cout << "dia: ";
	setColor(LIGHTBLUE);
	nacimiento.dia= numerosBien();
	setColor(GREY);

	
	

	cout <<endl<< "mes: ";
	setColor(LIGHTBLUE);
	nacimiento.mes= numerosBien();
	setColor(GREY);
	
	

	cout  <<endl<< "año: ";
	setColor(LIGHTBLUE);
	nacimiento.año= numerosBien();

	
	lineaVerde();
	return nacimiento;

}

//devuelve la fecha si es valida, de otra forma vuelve a pedir el ingreso
fecha fechaValidada(bool nacimiento) {
	fecha ingresada;
	bool fechaCorrecta;
	
	
	
	do {
		fechaCorrecta = true;
		ingresada = ingresarFecha(nacimiento);

		int edad = (fechaActual().tm_year + 1900)- ingresada.año;
		
		if (edad < 13&&nacimiento||edad<0) {
			fechaCorrecta = false;
		}
		//verifica que la fecha ingresada no sea mayor a la actual
		
		if (ingresada.año == fechaActual().tm_year + 1900){
			if (ingresada.mes > fechaActual().tm_mon + 1) {
				fechaCorrecta = false;
			}
			else if (ingresada.mes == fechaActual().tm_mon + 1&& ingresada.dia > fechaActual().tm_mday) {

				fechaCorrecta = false;

			}
		}
		//poco probable que alguien de mas de 120 años se inscriba al programa
		if ( ingresada.año<1900) {
			fechaCorrecta = false;
		}
		//vector que almacena los dias que tiene cada mes (si el ano es bisiesto, sumaremos +1 al febrero)
		int dias_mes[] = {0, 31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31 };

		//Comprobar si el ano es bisiesto y anadir dia en febrero en caso afirmativo
		if (biciesto( ingresada.año))
			dias_mes[2]++;

		//Comprobar que el mes sea valido
		if (ingresada.mes < 1 || ingresada.mes> 12) {
			fechaCorrecta = false;
		}
		else if (ingresada.dia < 1 || ingresada.dia > dias_mes[ingresada.mes]) {
			fechaCorrecta = false;
		}
		if (!fechaCorrecta) { cout << "Fecha no valida, ingrese una valida"<<endl; }
		msleep(100);
	} while (!fechaCorrecta);
	
	return ingresada;
}

//obtener fecha actual
tm fechaActual() {
	time_t t = time(NULL);
	tm* tiempo = localtime(&t);
	return *tiempo;
} 

//devuelve verdadero si es biciesto, o falso si no lo es.
bool biciesto(int año) {

	if (año%4==0) {
		if (año%100==0) {
			if (año%400) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}
//verifica que el Id no este usado ya
int verifIDnousado(){

	int ID;
	bool unico = false;

	do {
		ID = numerosBien();
		if (BuscarUsuarioID(ID).identificador==-1) {
			unico = true;
		}
		else{
			setColor(RED);
			cout<<"el ID ya existe, por favor elija otro: ";
			setColor(LIGHTBLUE);
		}



	}while (!unico);



	return ID;
}
//llenado de struct con los datos de un usuario, debe ser mandado a la funcion archivarUsuario() para cargarlo en un archivo.
void agregarUsusario() {
	usuarios nuevo;
	

	
	
	setColor(GREY);
	cout << endl << "ID: ";
	setColor(LIGHTBLUE);
	nuevo.identificador = verifIDnousado();
	setColor(GREY);	

	cout << "Nombre: ";
	setColor(LIGHTBLUE);
	cin.getline(nuevo.nombre, 50);
	setColor(GREY);

	cout << "Apellido: ";
	setColor(LIGHTBLUE);
	cin.getline(nuevo.apellido, 50);
	setColor(GREY);

	nuevo.nacimiento = fechaValidada(true);
			


	cout << "ingrese altura en cm:";
	setColor(LIGHTBLUE);
	cin >> nuevo.altura;
	setColor(GREY);

	cout << endl << "ingrese el peso en kg:";
	setColor(LIGHTBLUE);
	cin >> nuevo.peso;
	setColor(GREY);

	cout << endl << "ingrese perfil de actividad:";
	setColor(LIGHTBLUE);
	nuevo.perfilAct = teclaPulsada();
	setColor(GREY);

	cout << endl << "Apta medica:";
	setColor(LIGHTBLUE);
	cin >> nuevo.aptMed;
	cin.ignore();
	setColor(GREY);
	

	Archivar(nuevo);
}

// usa un getch para recibir que numero se pulso y te hace el paso de ascii a decimal.
int numeroPulsado() {

	int pulsado=getch() - 48;
	cleanGetch();
	return pulsado;

}

char teclaPulsada() {
	char tecla[1];
	bool correcta = false;
	do {
		
		cin >> tecla[0];
		switch (tecla[0]){

			case 'a':case'A':case'b':case'B':case'c':case'C':correcta = !correcta; break;

			default: {
				setColor(RED);
				cout << "intentelo nuevamente :";
				setColor(LIGHTBLUE);
				break;
			}
		}
	} while (!correcta);

	return tecla[0];
}

//recibe un usuario y modifica los datos, luego lo manda a archivar.
void modificarUsuario() {
	int ID;

	cout <<endl<< "Ingrese el ID: ";
	setColor(LIGHTBLUE);
	cin >> ID;
	cin.ignore();
	setColor(GREY);

	lineaVerde();
	usuarios elegido = BuscarUsuarioID(ID);

	if (ID == elegido.identificador&&elegido.estado) {

		cout << "nuevo peso: ";
		setColor(LIGHTBLUE);
		cin >> elegido.peso;
		setColor(GREY);

		cout << "perfil de actividad: ";
		setColor(LIGHTBLUE);
		cin >> elegido.perfilAct;
		setColor(GREY);

		cout << "apta medica: ";
		setColor(LIGHTBLUE);
		cin >> elegido.aptMed;
		setColor(GREY);
		cin.ignore();
		

		Archivar(elegido, ID - 1111);

	}
	else {
		setColor(RED);
		cout << "¡Error usuario no encontrado!";
		setColor(GREY);
		msleep(1500);
	}	
}

//pide ID y te 
void listarUsID(int ID) {
	usuarios usuario = BuscarUsuarioID(ID);

	if (usuario.identificador!=0) {

		printRegistro(usuario,true);
		mensajeEspera(30,600,true);
	}
	else {
		setColor(RED);
		cout << endl<<"no se encontro el usuario, revise el ID";
		setColor(GREY);
		msleep(2000);
	}
}

//forma estandar de pedir ID
int pedirID() {
	int ID;

	setColor(GREY);

	cout << endl << "ingrese el ID del usuario: ";

	setColor(LIGHTBLUE);
	cin >> ID;
	setColor(GREY);
	return ID;
}

//verifica que el perfil de Act sea uno valido
char ingPerfAct() {
	bool correcta = false;
		char tecla;
	do {

		
		tecla = teclaPulsada();
		if (tecla=='a'|| tecla == 'A') {
			return tecla;
		}
		else if (tecla == 'b'|| tecla == 'B') {
			return tecla;
		}
		else if (tecla == 'c'|| tecla == 'C') {
			return tecla;
		}
	
	
	
	} while (!correcta);


	return tecla;
}

//limpiar bufer getch
void cleanGetch() {
	while (kbhit()) {
		getch();
	}
}

//---------------------------------------------

int cantidadEntre2020(int ID) {
	entrenamiento aux;
	int cant = 0;
	FILE* P = fopen("Entrenamientos.dat","rb");
	if (!P) {
		cout<<"error";
		return 0;
	}

	while (fread(&aux,sizeof entrenamiento,1,P)) {
		if (aux.IDuser==ID&&aux.fechaEntrenamiento.año==2020) {
			cant++;
		}
	}
	fclose(P);
	return cant;
}

void listarEntre2020UsID() {

	int ID = pedirID();
	
		cls();

		setColor(LIGHTBLUE);
		cout << "\t\t\t******************" << endl;
		cout << "\t\t\t*  "<<ID<<"  *" << endl;
		cout << "\t\t\t******************" << endl << endl;
		setColor(GREY);

	usuarios elegido=BuscarUsuarioID(ID);
	
	lineaVerde();

	cout << "apellido: ";
	setColor(LIGHTBLUE);
	cout << elegido.apellido << endl;
	setColor(GREY);

	cout << "nombre: ";
	setColor(LIGHTBLUE);
	cout << elegido.nombre << endl;
	setColor(GREY);

	cout << "cantidad de entrenamientos en 2020: ";
	setColor(LIGHTBLUE);
	cout << cantidadEntre2020(ID) << endl;
	setColor(GREY);

	lineaVerde();

	cout << "presione cualquier tecla para volver";
	anykey();

}


void listarXpesoDes() {

	vector<usuarios> ordenados;
	usuarios aux;
	bool seguro = true;

	FILE* P = fopen("Usuarios.dat", "rb+");

	if (P == NULL) { cout << "NO HAY REGISTROS"; anykey(); }

	int cant = cantReg(true);

	for (int i = 0; i < cant; ++i) {
		fread(&aux, sizeof(usuarios), 1, P);
		int tamaño = ordenados.size();
		
		bool seUbico = false;
		for (int j = 0; j < tamaño&& !seUbico;++j) {
			
			if (ordenados[j].peso <aux.peso ) {

				ordenados.insert(ordenados.begin()+j,aux);
				seUbico = true;

			}
			

		}
		if (!seUbico) {
			ordenados.push_back(aux);
		}
		
	}
	cls();
	setColor(LIGHTBLUE);
	cout << "\t\t\t******************" << endl;
	cout << "\t\t\t* LISTA USUARIOS *" << endl;
	cout << "\t\t\t******************" << endl << endl;
	setColor(GREY);
	for (int i = 0; i < cant;++i) {
		printRegistro(ordenados[i], false);
	}


	cout << endl << "Presione cualquier tecla para continuar...";
	anykey();


}
