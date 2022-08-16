#include"datos.h"//Esta es una libreria creada por nosotros, donde almacenamos estructuras de datos.
//********************************************************************************************************
//********************************************************************************************************
//Variables globales
float dinero_banco=0;
float resto;
float costoTotal;



void interfaz();
void gmail_plataforma();

//subprogramas del gmail
void acceder_cuenta_gmail();
void crear_cuenta_gmail();
void cuenta_gmail(); 
void pasarela_pago();
void interfaz();
//errores
void error_comparar();
void error_arroba();
//procedimeinto de adorno
void cuadro_general();
void cuadro_crear();
void cuadro_cuenta();
void cuadro_acceso();
void mostrar_boleta();
void politica_privada();

//cuenta
//consistencia gmail

//***************************************************************************
//***************************************************************************
//procedimeinto gotoxy
COORD coord={0,0};
void gotoxy(int x, int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//****************************************************************************

void intermedio(){
	system("cls");
	cout<<"PRECIONE ENTER PARA CONTINUAR";
	getch();
}

//preocedimeinto banco- no mover
void banco();
void acceso_banco();





//****************************************************************************************************************
//MODULO DE LOGIN CUENTA LINKI 
//****************************************************************************************************************

void modulo_login(datos_personales persona1);
void login(datos_personales persona1);
void registrar(datos_personales &persona1);
void error_login(datos_personales persona1);
void error_registrar(datos_personales persona1);

void cuadro_modulo_login();
void cuadro_registrarse();
void cuadro_confirmar();
void cuadro_login();


void modulo_login(datos_personales persona1){
	system("cls");
	int opcion;
	cuadro_modulo_login();
	gotoxy(48,4);
	cout<<"MENU AEROLINIA LINKI";
	gotoxy(25,8);
	cout<<"OPCIONES:";
	gotoxy(25,10);
	cout<<"  1- INICIAR SECCIÓN";
	gotoxy(25,12);
	cout<<"  2- REGISTRARSE" ;
	gotoxy(25,14);
	cout<<"ELEGIR: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			login(persona1);
			break;
		case 2:
			registrar(persona1);
			break;
		default:
			modulo_login(persona1);
			break;
	}
}

void registrar(datos_personales &persona1){
	system("cls");
	string clave2;
	int opcion;
	cuadro_registrarse();
	fflush(stdin); //limpiar el bafer
	
	gotoxy(50,4);
	cout<<"REGISTRAR CUENTA";
	
	gotoxy(25, 8);
	cout<<"INGRESE SU NOMBRE: ";
	gotoxy(25, 9);
	cout<<"  > ";
	getline(cin, persona1.nombre);
	
	
	//nombre que digitara
	gotoxy(25, 11);
	cout<<"INGRESE SU APELLIDO: ";
	gotoxy(25, 12);
	cout<<"  > ";
	getline(cin, persona1.apellido);
	ofstream archivo7;
	archivo7.open("personales.txt");
	archivo7<<persona1.nombre<<endl;
	archivo7<<persona1.apellido;
	archivo7.close();
	
	gotoxy(25, 14);
	cout<<"INGRESE SU CORREO ELECTRÓNICO:";
	gotoxy(25, 15);
	cout<<"  > ";
	getline(cin, persona1.email);
	
	gotoxy(25, 17);
	cout<<"INGRESE SU CONTRASEÑA: ";
	gotoxy(25, 18);
	cout<<"  > ";
	getline(cin, persona1.clave);
	
	gotoxy(25, 20);
	cout<<"INGRESE SU CONTRASEÑA DE NUEVO: ";
	gotoxy(25, 21);
	cout<<"  > ";
	getline(cin, clave2);

	if (clave2.compare(persona1.clave)!=0){
		error_registrar(persona1);
	}
	system("cls");
	cuadro_confirmar();
	gotoxy(50,4);
	cout<<"REGISTRAR CUENTA";
	gotoxy(40, 9);
	cout<<"SE HA REGISTRADO DE MANERA EXITOSA";
	gotoxy(40, 13);
	cout<<" PRECIONE ENTER PARA VOLVER A MENU";
	getch();
	modulo_login(persona1);
}


void login(datos_personales persona1){
	system("cls");
	fflush(stdin); //limpiar el bafer
	int n,m;
	string correo_login,clave_login;
	
	cuadro_login();
	fflush(stdin);
	gotoxy(50,4);
	cout<<"INICIAR SESIÓN";
	
	gotoxy(25, 8);
	cout<<"INGRESE SU CORREO ELECTRÓNICO:";
	gotoxy(25, 9);
	cout<<"  > ";
	getline(cin, correo_login);
	n= correo_login.compare(persona1.email);

	gotoxy(25, 11);
	cout<<"INGRESE SU CONTRASEÑA:";
	gotoxy(25, 12);
	cout<<"  > ";
	getline(cin, clave_login);
	m= clave_login.compare(persona1.clave);
	
	
	if(n==0 && m==0){
		system("cls");
		cuadro_confirmar();
		gotoxy(50,4);
		cout<<"INICIAR SESIÓN";
		gotoxy(45, 9);
		cout<<"SE HA CONECTADO CORRECTAMENTE";
		gotoxy(45, 13);
		cout<<"PRESIONE ENTER PARA CONTINUAR";
		getch();	
	}
	else{
		error_login(persona1);
	}
	
}


//ERORRES***************************************************************++
void error_registrar(datos_personales persona1){
	system("cls");
	for (int i = 0; i < 62; i++) {
		gotoxy(i + 29, 2);
		cout<<"*";
		gotoxy(i + 29, 6);
		cout<<"*";
		gotoxy(i + 29, 8);
		cout<<"*";
	};
	//vertical
	for (int i = 0; i < 6; i++) {
		gotoxy(29, i + 3);
		cout <<"*";
		
		gotoxy(90, i + 3);
		cout<<"*";	
	};
	gotoxy(50,4);
	cout<<"COMETIO UN ERROR";
	gotoxy(40,7);
	cout<<"PRECIONE ENTER PARA VOLVER INTENTAR";
	getch();
	registrar(persona1);
	
}
void error_login(datos_personales persona1){
	system("cls");
	int opcion;
	cuadro_modulo_login();
	
	
	gotoxy(38,4);
	cout<<"LOS DATOS INGRESADOS NO SON LOS CORRECTOS";
	gotoxy(25,8);
	cout<<"OPCIONES:";
	gotoxy(25,10);
	cout<<"  1- VOLVER A INTENTAR";
	gotoxy(25,12);
	cout<<"  2- MENU" ;
	gotoxy(25,14);
	cout<<"ELEGIR: ";
	cin>>opcion;
	switch(opcion){
		case 1:
			login(persona1);
			break;
		case 2:
			modulo_login(persona1);
			break;
		default:
			error_login(persona1);
			break;
	}
	
}
//**************************************************************************************************************
//CUADROS GOTOXI
void cuadro_modulo_login(){
	for (int i = 0; i < 82; i++) {
		//Linea TOP
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 17);
		cout<<"*";
	};

	for (int i = 0; i < 15; i++) {
		//Linea Left
		gotoxy(19, i + 3);
		cout <<"*";

		//Linea Right
		gotoxy(100, i + 3);
		cout<<"*";	
	};
}

void cuadro_registrarse(){
	//horizontales
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 23);
		cout<<"*";
	};
	//verticales
	for (int i = 0; i < 21; i++) {
		gotoxy(19, i + 3);
		cout <<"*";

		gotoxy(100, i + 3);
		cout<<"*";	
	};
}

void cuadro_confirmar(){
	//horizontal
	for (int i = 0; i < 62; i++) {
		gotoxy(i + 29, 2);
		cout<<"*";
		gotoxy(i + 29, 6);
		cout<<"*";
		gotoxy(i + 29, 12);
		cout<<"*";
		gotoxy(i + 29, 14);
		cout<<"*";
	};
	//vertical
	for (int i = 0; i < 12; i++) {
		gotoxy(29, i + 3);
		cout <<"*";
		
		gotoxy(90, i + 3);
		cout<<"*";	
	};
}


void cuadro_login(){
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 14);
		cout<<"*";
	};
	//verticales
	for (int i = 0; i < 12; i++) {
		gotoxy(19, i + 3);
		cout <<"*";

		gotoxy(100, i + 3);
		cout<<"*";	
	};
}


//**************************************************************************************************************
//**************************************************************************************************************


























//**************************************************************************************************************
//MODULO 2 - FORMATO DE VUELO
//**************************************************************************************************************
//hacer un cuadro con gotoxy y un for para dibujar un cuadro de forma horizontal y vertical
void cuadro_vuelo(){
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 17);
		cout<<"*";
	};
	for (int i = 0; i < 15; i++) {
		gotoxy(19, i + 3);
		cout <<"*";
		gotoxy(100, i + 3);
		cout<<"*";	
	};
}
//hacer un cuadro con asteristicos con coordenadas en (23,3) , (100,3), (23,12) y (100,12)
void cuadro_vuelo_2(){
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 5);
		cout<<"*";
		gotoxy(i + 19, 17);
		cout<<"*";
	};
	for (int i = 0; i < 15; i++) {
		gotoxy(19, i + 3);
		cout <<"*";
		gotoxy(100, i + 3);
		cout<<"*";	
	};
}
void  formato_vuelo(){
	system("cls");
    fstream archivo("datos_vuelo.txt",ios::out|ios::app);
    //invocar estructura de datos vuelo
    Datos_Vuelo vuelo;
    int opcion;
	cuadro_vuelo_2();
	gotoxy(52,4);
    cout<<"FORMATO DE VUELO\n"<<endl;
    cin.ignore();
    if(!archivo.is_open()){
        archivo.open("datos_vuelo.txt",ios::out);
    }
    gotoxy(25,6);
    cout<<"ingrese la fecha de ida:";
	gotoxy(25,7);
	getline(cin,vuelo.fecha_ida);   
	gotoxy(25,8);
    cout<<"ingrese la fecha de vuelta:";
	gotoxy(25,9);
	getline(cin,vuelo.fecha_vuelta);
    system("cls");
	cuadro_vuelo_2();
	gotoxy (40,4);
    cout<<"Seleccione uno de los 7 origenes disponibles \n";
	gotoxy(25,6);
    cout<<"1.- Lima\n";
	gotoxy(25,7);
	cout<<"2.- Sántiago\n";
	gotoxy(25,8);
	cout<<"3.- Egipto\n";
	gotoxy(25,9);
	cout<<"4.- Narnia\n";
	gotoxy(25,10);
	cout<<"5.- New york\n";
	gotoxy(25,11);
	cout<<"6.- Afganistan\n";
	gotoxy(25,12);
	cout<<"7.- Cuzco\n";
	gotoxy(25,14);
    cin>>opcion;
    system("cls");
	cuadro_vuelo_2();
    switch(opcion){
        case 1:
            vuelo.origen="Lima";
            break;
        case 2:
            vuelo.origen="Sántiago";
            break;
        case 3:
            vuelo.origen="Egipto";
            break;
        case 4:
            vuelo.origen="Narnia";
            break;
        case 5:
            vuelo.origen="New york";
            break;
        case 6:
            vuelo.origen="Afganistan";
            break;
        case 7:
            vuelo.origen="Cuzco";
            break;
        default:
			gotoxy (25,12);
            cout<<"\nNo existe ese origen\n";
            break;
        }
    system("cls");
	cuadro_vuelo_2();
	gotoxy (40,4);
    cout<<"Seleccione uno de los 7 destinos disponibles ";
	gotoxy(25,6);
    cout<<"1.- Buenos Aires\n";
	gotoxy(25,7);
	cout<<"2.- Córdoba\n";
	gotoxy(25,8);
	cout<<"3.- Mar del Plata\n";
	gotoxy(25,9);
	cout<<"4.- Mendoza\n";
	gotoxy(25,10);
	cout<<"5.- Rosario\n";
	gotoxy(25,11);
	cout<<"6.- Saltan";
	gotoxy(25,12);
	cout<<"7.- San Juan\n";
	gotoxy(25,14);
    cin>>opcion;
    switch(opcion){
        case 1:
            vuelo.destino="Buenos Aires";
            break;
        case 2:
            vuelo.destino="Córdoba";
            break;
        case 3:
            vuelo.destino="Mar del Plata";
            break;
        case 4:
            vuelo.destino="Mendoza";
            break;
        case 5:
            vuelo.destino="Rosario";
            break;
        case 6:
            vuelo.destino="Salta";
            break;
        case 7:
            vuelo.destino="San Juan";
            break;
        default:
			gotoxy (25,12);
            cout<<"opcion no valida"<<endl;
            break;
    }
    system("cls");
	cuadro_vuelo_2();
	gotoxy (40,4);
    cout<<"Seleccione la hora de vuelo \n";
	gotoxy(25,6);
    cout <<"1. 8:00 a.m.\n";
	gotoxy(25,7);
    cout <<"2. 12:00 p.m.\n";
	gotoxy(25,8);
    cout <<"3. 4:00 p.m.\n";
	gotoxy(25,9);
    cout <<"4. 18:00 p.m.\n";
	gotoxy(25,10);
	cin>>opcion;
    switch (opcion)
    {
    case 1:
        vuelo.hora_vuelo="8:00 a.m.";
        break;
    case 2:
        vuelo.hora_vuelo="12:00 p.m.";
        break;
    case 3:
        vuelo.hora_vuelo="4:00 p.m.";
        break;
    case 4:
        vuelo.hora_vuelo="8:00 p.m.";
        break;
    default:
		gotoxy (25,12);
        cout<<"opcion no valida"<<endl;
        break;
    }


    system("cls");
	cuadro_vuelo_2();
	gotoxy (40,4);
    cout<<"Seleccione la clase en la que desea viajar "<<endl;
    //mostrar ofertas, por cada 3 pasajeros se le aplica un descuento de $100
	gotoxy(25,6);
    cout<<"Ofertas: "<<endl;
	gotoxy(25,7);
    cout<<"- Descuentos en clase Económica: $100 al costo total por cada 3 pasajeros"<<endl;
	gotoxy(25,8);
    cout<<"- Descuentos en clase Business: $200 al costo total por cada 3 pasajeros"<<endl;
	gotoxy(25,9);
    cout<<"- Descuentos en clase First: $300 al costo total por cada 3 pasajeros"<<endl;
	gotoxy(25,10);
    cout<<"1.- Económica---costo---500$"<<endl;
	gotoxy(25,11);
    cout<<"2.- Primera---costo---1500$"<<endl;
	gotoxy(25,12);
    cout<<"3.- Business---costo---900$"<<endl;
	gotoxy(25,14);
    cin>>opcion;
    switch(opcion){
        case 1:
            system("cls");
			cuadro_vuelo_2();
            vuelo.clase="Económica";
            //asignarle el costo
            vuelo.costo=500;
            //ingrese el numero de pasajeros
			gotoxy (40,4);
			cout<<"Elección de asientos"<<endl;
			gotoxy (25,6);
            cout<<"ingrese el numero de pasajeros: ";
			gotoxy(25,7);
			cin>>vuelo.numero_pasajeros;
            //por cada pasajero se le asigna un asiento
            for(int i=0;i<vuelo.numero_pasajeros;i++){
				gotoxy (25,8+i);
                cout<<"ingrese el numero de asiento: ";cin>>vuelo.eleccion_asiento[i];
            }
			gotoxy (25,14);
            cout<<"el costo por equipaje adicional es de 5 dolares por kilo"<<endl;
			gotoxy (25,15);
            cout<<"ingrese el peso de equipaje adicional: ";cin>>vuelo.equipaje;
			system("cls");
			cuadro_vuelo_2();
			gotoxy (40,4);
            cout<<"Seleccione los snacks de su preferencia: "<<endl;
			gotoxy(25,6);
            cout<<"1.- Papitas: $10"<<endl;
			gotoxy(25,7);
            cout<<"2.- Cuates:  $20"<<endl;
			gotoxy(25,8);
            cout<<"3.- Cifrut:  $30"<<endl;
			gotoxy(25,9);
            cin>>opcion;
            switch(opcion){
                case 1:
                    vuelo.snacks="Papitas";
                    vuelo.costo_snacks=10;
                    break;
                case 2:
                    vuelo.snacks="Cuates";
                    vuelo.costo_snacks=20;
                    break;
                case 3:
                    vuelo.snacks="Cifrut";
                    vuelo.costo_snacks=30;
                    break;
            }
            vuelo.costo_total= vuelo.costo*vuelo.numero_pasajeros + (vuelo.equipaje)*5+ vuelo.costo_snacks;
            //aplicar descuento si hay 3 o mas pasajeros
            if(vuelo.numero_pasajeros>=3){
                vuelo.costo_total=vuelo.costo_total-100;
            }

            break;
        case 2:
            system("cls");
			cuadro_vuelo_2();
            vuelo.clase="Primera";
            //asignarle el costo
            vuelo.costo=1500;
            //ingrese el numero de pasajeros
			gotoxy (40,4);
			cout<<"Elección de asientos"<<endl;
			gotoxy (25,6);
            cout<<"ingrese el numero de pasajeros: ";cin>>vuelo.numero_pasajeros;
            //por cada pasajero se le asigna un asiento
            for(int i=0;i<vuelo.numero_pasajeros;i++){
				gotoxy (25,8+i);
                cout<<"ingrese el numero de asiento: ";cin>>vuelo.eleccion_asiento[i];
            }
			gotoxy (25,14);
            cout<<"el costo por equipaje adicional es de 5 dolares por kilo"<<endl;
			gotoxy (25,15);
            cout<<"ingrese el peso de equipaje adicional: ";cin>>vuelo.equipaje;
			system("cls");
			cuadro_vuelo_2();
			gotoxy (40,4);
            cout<<"Seleccione los snacks de su preferencia: "<<endl;
			gotoxy(25,6);
            cout<<"1.- Papitas: $10"<<endl;
			gotoxy(25,7);
            cout<<"2.- Cuates:  $20"<<endl;
			gotoxy(25,8);
            cout<<"3.- Cifrut:  $30"<<endl;
			gotoxy(25,9);
            cin>>opcion;
            switch(opcion){
                case 1:
                    vuelo.snacks="Papitas";
                    vuelo.costo_snacks=10;
                    break;
                case 2:
                    vuelo.snacks="Cuates";
                    vuelo.costo_snacks=20;
                    break;
                case 3:
                    vuelo.snacks="Cifrut";
                    vuelo.costo_snacks=30;
                    break;
            }
            vuelo.costo_total= vuelo.costo*vuelo.numero_pasajeros + (vuelo.equipaje)*5+ vuelo.costo_snacks;
            //aplicar descuento si hay 3 o mas pasajeros
            if(vuelo.numero_pasajeros>=3){
                vuelo.costo_total=vuelo.costo_total-200;
            }
            break;
        case 3:
            system("cls");
			cuadro_vuelo_2();
            vuelo.clase="Business";
            //asignarle el costo
            vuelo.costo=900;
            //ingrese el numero de pasajeros
			gotoxy (40,4);
			cout<<"Elección de asientos"<<endl;
			gotoxy (25,6);
            cout<<"ingrese el numero de pasajeros: ";cin>>vuelo.numero_pasajeros;
            //por cada pasajero se le asigna un asiento
            for(int i=0;i<vuelo.numero_pasajeros;i++){
				gotoxy (25,8+i);
                cout<<"ingrese el numero de asiento: ";cin>>vuelo.eleccion_asiento[i];
            }
			gotoxy (25,14);
            cout<<"el costo por equipaje adicional es de 5 dolares por kilo"<<endl;
			gotoxy (25,15);
            cout<<"ingrese el peso de equipaje adicional: ";cin>>vuelo.equipaje;
			system("cls");
			cuadro_vuelo_2();
			gotoxy (40,4);
            cout<<"Seleccione los snacks de su preferencia: "<<endl;
			gotoxy(25,6);
            cout<<"1.- Papitas: $10"<<endl;
			gotoxy(25,7);
            cout<<"2.- Cuates:  $20"<<endl;
			gotoxy(25,8);
            cout<<"3.- Cifrut:  $30"<<endl;
			gotoxy(25,9);
            cin>>opcion;
            switch(opcion){
                case 1:
                    vuelo.snacks="Papitas";
                    vuelo.costo_snacks=10;
                    break;
                case 2:
                    vuelo.snacks="Cuates";
                    vuelo.costo_snacks=20;
                    break;
                case 3:
                    vuelo.snacks="Cifrut";
                    vuelo.costo_snacks=30;
                    break;
            }
            vuelo.costo_total= vuelo.costo*vuelo.numero_pasajeros + (vuelo.equipaje)*5+ vuelo.costo_snacks;
            //aplicar descuento si hay 3 o mas pasajeros
            if(vuelo.numero_pasajeros>=3){
                vuelo.costo_total=vuelo.costo_total-300;
            }
            break;
    }
    //Guardar datos de vuelo en un archivo , cuyo nobmre es datos_vuelo.txt
    archivo<<vuelo.origen<<endl;
    archivo<<vuelo.destino<<endl;
    archivo<<vuelo.hora_vuelo<<endl;
    archivo<<vuelo.fecha_ida<<endl;
    archivo<<vuelo.fecha_vuelta<<endl;
    archivo<<vuelo.costo<<endl;
    archivo<<vuelo.clase<<endl;
    archivo<<vuelo.equipaje<<endl;
    archivo<<vuelo.snacks<<endl;
    archivo<<vuelo.costo_snacks<<endl;
    archivo<<vuelo.costo_total<<endl;
    archivo<<vuelo.numero_pasajeros<<endl;
    for(int i=0;i<vuelo.numero_pasajeros;i++){
        archivo<<vuelo.eleccion_asiento[i]<<endl;
    }
    archivo.close();
    system("cls");
	
	gotoxy (25,4);
	//adorar a la bandera
	cout<<"********************************************************"<<endl;
	gotoxy (25,5);
    cout<<"Vuelo registrado con exito"<<endl;
	gotoxy (25,6);
	cout<<"********************************************************"<<endl;
	gotoxy (25,7);
    cout<<" costo: "<<vuelo.costo_total<<endl;
	gotoxy (25,8);
	cout<<"********************************************************"<<endl;
    costoTotal=vuelo.costo_total;	
    //desea pasar a la pasarela de pago o regresar al menu principal
	gotoxy (25,10);
    cout << "Presione enter para continuar con la compra";
    cin.ignore();
    cin.get();  
}
    
//**************************************************************************************************************
//**************************************************************************************************************



















//**************************************************************************************************************
//MODULO PASARELA
//**************************************************************************************************************

//PREOCEDIMIENTOS
void pasarela_de_pago();
void verificacion();

//errores
void error_comparacion();
void error_pasarela();
void dinero_insuficiente();
//datos
void datos_fijos_tarjeta();
//el cuadro gotoxy
void cuadro();
void cuadro_vereficado_pasarela();
//fin

//MODULO DE PASARELA DE PAGO
void pasarela_de_pago(){
	Datos_Vuelo vuelo;
	system("cls");
	fflush(stdin); //limpiar el bafer
	//VARIABLES DE ENTRADA****************
	// Vector del numero de targeta
	string p_num_tarjeta;
	//Cadena de nombre y apelllido de entrada
	string p_nombre, p_apellido;
	//Entero de dia, mes y año de entrada
	int p_mes, p_anio,  p_cvv;
	
	//cuadro gotoxy
	cuadro();
	
	//titulo
	gotoxy(50,4);
	cout<<"PASARELA DE PAGO";
	
	//Digitar nuemro de targeta a un vector
	gotoxy(25, 8);
	cout<<"Escriba el numero del tarjeta: ";
	gotoxy(25, 9);
	cout<<"  > ";
	getline(cin,p_num_tarjeta);
	
	//nombre que digitara
	gotoxy(25, 11);
	cout<<"Escriba el nombre de su titular: ";
	gotoxy(25, 12);
	cout<<"  > ";
	getline(cin,p_nombre);

	
	//apellido que digitas en consola
	gotoxy(25, 14);
	cout<<"Escriba el apellido del titular: ";
	gotoxy(25, 15);
	cout<<"  > ";
	getline(cin,p_apellido);
	
	
	//fecha de vencimiento consistencia
	gotoxy(25, 17);
	cout<<"Escriba la fecha de vencimiento de tu targeta";
	
	//mes consistenciar
	gotoxy(25, 18);
	cout<<"   > Mes: ";
	cin>>p_mes;
	if(p_mes<0 || p_mes>12){
		error_pasarela();
	}
	
	gotoxy(25, 19);
	//año consistenciar
	cout<<"   > Año: "; 
	cin>>p_anio;
	if(p_anio<10 || p_anio>99){
		error_pasarela();
	}
	
	gotoxy(25, 21);
	//cvv consistenciar
	cout<<"Escriba el CVV: ";
	gotoxy(25, 22);
	cout<<"  > ";
	cin>>p_cvv;
	if(p_cvv<100 || p_cvv>999){
		error_pasarela();
	}
	//comparacion*****************
	int band=0;
	if(p_num_tarjeta.compare(usuari.num_tarjeta)==0){
		band++;
	}
	if(p_nombre.compare(usuari.nombre_titular)==0){
		band++;
	}
	if(p_apellido.compare(usuari.apellido_titular)==0){
		band++;
	}
	if(p_mes == usuari.mes_esp){
		band++;
	}
	if(p_anio == usuari.anio_esp){
		band++;
	}
	if(p_cvv == usuari.cvv){
		band++;
	}
	//comparar las banderas
	if(band == 6){
		verificacion();	
	}
	else{
		error_comparacion();
	}	
}

void verificacion(){
	ifstream archivo;
	fflush(stdin); //limpiar el bafer
    Datos_Vuelo vuelo;//estructura de vuelo
	system("cls");
	
	cuadro_vereficado_pasarela();
	gotoxy(50,4);
	cout<<"PASARELA DE PAGO";
	gotoxy(48, 8);
	cout<<"USUSARIO VERIFICADO";
	gotoxy(25, 11);
	cout<<"NOMBRE: "<<usuari.nombre_titular<<" "<<usuari.apellido_titular;
	
	
	//resta
	resto= usuari.dinero - costoTotal; 
	

	
	gotoxy(45,14);
	cout<<"HAGA CLICK PARA CONTINUAR";
	getch();
	if(resto<0){
		dinero_insuficiente();
	}
	else{
		politica_privada();
		getch();
		system("cls");
		gotoxy(39,17);cout<<"*****************************************";
		gotoxy(39,18);cout<<"*   LA COMPRA SE REALIZÓ EXITOSAMENTE   *";	
		gotoxy(39,19);cout<<"*****************************************";
		getch();	
	}
}

//adornos con gotoxy y extras**************************

//cuadro ganeral de pasarela de pago
void cuadro(){
	//Borde - lineas horizontales
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";

		gotoxy(i + 19, 6);
		cout<<"*";
		
		gotoxy(i + 19, 25);
		cout<<"*";		
	}

	for (int i = 0; i < 22; i++) {

		gotoxy(19, i + 3);
		cout <<"*";


		gotoxy(100, i + 3);
		cout<<"*";		
	}
}


//cuadro y contendio de error pasarela
void error_pasarela(){
	system("cls");
	fflush(stdin); //limpiar el bafer
	//Borde - lineas horizontales
	for (int i = 0; i < 62; i++) {
		//Linea TOP
		gotoxy(i + 29, 2);
		cout<<"*";

		gotoxy(i + 29, 8);
		cout<<"*";
	}

	for (int i = 0; i < 6; i++) {
		//Linea Left
		gotoxy(29, i + 3);
		cout <<"*";

		//Linea Right
		gotoxy(90, i + 3);
		cout<<"*";
		
	};
	gotoxy(43,4);
	cout<<"EL USUARIO HA COMETIDO UN ERROR";
	gotoxy(40,6);
	cout<<"PRECIONE ENTER PARA VOLVER A INTENTAR";
	
	getch();
	pasarela_de_pago();
}

void error_comparacion(){
	system("cls");
	fflush(stdin); //limpiar el bafer
	//Borde - lineas horizontales
	for (int i = 0; i < 82; i++) {
		//Linea TOP
		gotoxy(i + 19, 2);
		cout<<"*";

		gotoxy(i + 19, 8);
		cout<<"*";
	}; cout<<endl;

	for (int i = 0; i < 6; i++) {
		//Linea Left
		gotoxy(19, i + 3);
		cout <<"*";

		//Linea Right
		gotoxy(100, i + 3);
		cout<<"*";
		
	};
	gotoxy(30,4);
	cout<<"LOS DATOS ESCRITOS NO CORRESPONDEN A NINGUNA TARJETA";
	gotoxy(40,6);
	cout<<"PRECIONE ENTER PARA VOLVER A INTENTAR";
	
	getch();
	pasarela_de_pago();
}



//cuadro y dinero insuficiente
void dinero_insuficiente(){
	system("cls");
	fflush(stdin); //limpiar el bafer
	//cuadro gotoxy
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 17);
		cout<<"*";
	};

	for (int i = 0; i < 15; i++) {
		gotoxy(19, i + 3);
		cout <<"*";

		gotoxy(100, i + 3);
		cout<<"*";
		
	};
	//contenido
	int p;
	gotoxy(27,4);
	cout<<"SU TARJETA NO TIENE SUFICIENTE EFECTIVO PARA ADQUIRIR EL SERVICIO";
	gotoxy(25,8);
	cout<<"OPCIONES:";
	gotoxy(25,10);
	cout<<"  1- VOLVER INTENTAR";
	gotoxy(25,12);
	cout<<"  2- CUENTA BANCARIA" ;
	gotoxy(25,14);
	cout<<"ELEGIR: ";
	cin>>p;
	if(p<0 || p>2){
		error_comparacion();
	}
	if(p==1){
		pasarela_de_pago();
	}
	else{
		banco();
	}
}

void cuadro_vereficado_pasarela(){
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 13);
		cout<<"*";
		gotoxy(i + 19, 15);
		cout<<"*";		
	}

	for (int i = 0; i < 13; i++) {

		gotoxy(19, i + 3);
		cout <<"*";


		gotoxy(100, i + 3);
		cout<<"*";		
	}
}


//**************************************************************************************************************
//**************************************************************************************************************


















//**************************************************************************************************************
//MODULO  BANCO
//**************************************************************************************************************
void banco();
void banco2();
void acceso_banco();
void acceso_banco2();
void cuadro_banco_menu();
void cuadro_banco_seleccion();

//BANCO1 VERDADERO
void banco(){
	fflush(stdin); //limpiar el bafer
	system("cls");
	cuadro();

	string p_num_tarjeta;
	int p_dni, p_claveweb;
	
	//titulo
	gotoxy(55,4);cout<<"CUENTA BANCARIA"<<endl;
	//Digitar numero de targeta


	gotoxy(25, 8);
	cout<<"Digite su numero de tarjeta: ";
	gotoxy(25, 9);
	cout<<"  > ";
	getline(cin,p_num_tarjeta);
	
	//dni
	gotoxy(25, 11);
	cout<<"Digite su dni: ";
	gotoxy(25, 12);
	cout<<"  > ";
	cin>>p_dni;
	if(p_dni<0){
		acceso_banco();
	}
	
	//contra web
	gotoxy(25, 14);
	cout<<"Digite su contraseña web: ";
	gotoxy(25, 15);
	cout<<"  > ";
	cin>>p_claveweb;
	if(p_claveweb<0){
		acceso_banco();
	}
	
	//comparacion*****************
	int band=0;
	if(p_num_tarjeta.compare(usuari.num_tarjeta)==0){
		band++;
	}
	if(p_dni==usuari.dnipago){
		band++;
	}
	if(p_claveweb==usuari.claveweb){
		band++;
	}
	//comparar las banderas
	if(band == 3){
		acceso_banco();
	}
	else{
		banco();
	}

}

void acceso_banco(){ // para el banco normal
	system("cls");
	//usar usuari.dinero
	float ingreso, retiro;
	int opcion;
	
	cuadro_banco_menu();
	gotoxy(48,4);
	cout<<"CUENTA BANCARIA";
	gotoxy(25,8);
	cout<<"OPCIONES:";
	gotoxy(25,10);
	cout<<"  1- INGRESE DINERO";
	gotoxy(25,12);
	cout<<"  2- RETIRE DINERO" ;
	gotoxy(25,14);
	cout<<"  3- VOLVER A PASARELA DE PAGO" ;
	gotoxy(25,16);
	cout<<"ELEGIR: ";
	cin>>opcion;
    switch (opcion){
	    case 1 :
	    	system("cls");
	    	cuadro_banco_seleccion();
	    	gotoxy(48,4);
			cout<<"CUENTA BANCARIA";
			gotoxy(25,8);
			cout<<"TU SALDO ES S/."<<usuari.dinero;
			gotoxy(25,10);
			cout<<"INGRESE EL DINERO HA DEPOSITAR";
			gotoxy(25,11);
			cout<<" > ";
			cin>>ingreso;
	
	        usuari.dinero = usuari.dinero + ingreso;
	        gotoxy(25,13);
	        cout<<"TU SALDO ACTUAL ES S/."<<usuari.dinero;
	        
	        gotoxy(20,15);
	        cout<<"********************************************************************************";
	        gotoxy(42,16);
			cout<<"SE HA REALIZADO CORRECTAMENTE";
			gotoxy(40,18);
			cout<<"PRECIONE ENTER PARA VOLVER A MENU";
			getch();
			acceso_banco();
	        
	        
	        break;
	    case 2 :
	    	system("cls");
	    	cuadro_banco_seleccion();
	    	gotoxy(48,4);
			cout<<"CUENTA BANCARIA";
			gotoxy(25,8);
			cout<<"TU SALDO ES S/."<<usuari.dinero;
			gotoxy(25,10);
			cout<<"INGRESE EL DINERO HA RETIRAR";
			gotoxy(25,11);
			cout<<" > ";
			cin>>retiro;
	
	        
	        

	        if( retiro>usuari.dinero ){
	        	gotoxy(20,15);
		        cout<<"********************************************************************************";
		        gotoxy(35,17);
	            cout <<"NO TIENES LOS SUFICIENTES FONDOS DISPONIBLES";
	            getch();
	            acceso_banco();
	        }
			else{
	        	usuari.dinero = usuari.dinero - retiro;
	        	gotoxy(25,13);
		        cout<<"TU SALDO ACTUAL ES S/."<<usuari.dinero;
		        gotoxy(20,15);
		        cout<<"********************************************************************************";
		        gotoxy(42,16);
				cout<<"SE HA REALIZADO CORRECTAMENTE";
				gotoxy(40,18);
				cout<<"PRECIONE ENTER PARA VOLVER A MENU";
			    getch();
			    acceso_banco();
	        }
	        break;
	    case 3 :
	        pasarela_de_pago();break;
	
	    default:
	        acceso_banco();break;
	}
}
//*****************************************************************************************
//BANCO 2
void banco2(){
	fflush(stdin); //limpiar el bafer
	system("cls");
	cuadro();

	string p_num_tarjeta;
	int p_dni, p_claveweb;
	
	//titulo
	gotoxy(55,4);cout<<"CUENTA BANCARIA"<<endl;
	//Digitar numero de targeta


	gotoxy(25, 8);
	cout<<"Digite su numero de tarjeta: ";
	gotoxy(25, 9);
	cout<<"  > ";
	getline(cin,p_num_tarjeta);
	
	//dni
	gotoxy(25, 11);
	cout<<"Digite su dni: ";
	gotoxy(25, 12);
	cout<<"  > ";
	cin>>p_dni;
	if(p_dni<0){
		acceso_banco2();
	}
	
	//contra web
	gotoxy(25, 14);
	cout<<"Digite su contraseña web: ";
	gotoxy(25, 15);
	cout<<"  > ";
	cin>>p_claveweb;
	if(p_claveweb<0){
		acceso_banco2();
	}
	
	//comparacion*****************
	int band=0;
	if(p_num_tarjeta.compare(usuari.num_tarjeta)==0){
		band++;
	}
	if(p_dni==usuari.dnipago){
		band++;
	}
	if(p_claveweb==usuari.claveweb){
		band++;
	}
	//comparar las banderas
	if(band == 3){
		acceso_banco2();
	}
	else{
		banco2();
	}

}

void acceso_banco2(){ // para el banco normal
	system("cls");
	//usar usuari.dinero
	float ingreso, retiro;
	int opcion;
	
	cuadro_banco_menu();
	gotoxy(48,4);
	cout<<"CUENTA BANCARIA";
	gotoxy(25,8);
	cout<<"OPCIONES:";
	gotoxy(25,10);
	cout<<"  1- INGRESE DINERO";
	gotoxy(25,12);
	cout<<"  2- RETIRE DINERO" ;
	gotoxy(25,14);
	cout<<"  3- VOLVER AL MENU PRINCIPAL" ;
	gotoxy(25,16);
	cout<<"ELEGIR: ";
	cin>>opcion;
    switch (opcion){
	    case 1 :
	    	system("cls");
	    	cuadro_banco_seleccion();
	    	gotoxy(48,4);
			cout<<"CUENTA BANCARIA";
			gotoxy(25,8);
			cout<<"TU SALDO ES S/."<<usuari.dinero;
			gotoxy(25,10);
			cout<<"INGRESE EL DINERO HA DEPOSITAR";
			gotoxy(25,11);
			cout<<" > ";
			cin>>ingreso;
	
	        usuari.dinero = usuari.dinero + ingreso;
	        gotoxy(25,13);
	        cout<<"TU SALDO ACTUAL ES S/."<<usuari.dinero;
	        
	        gotoxy(20,15);
	        cout<<"********************************************************************************";
	        gotoxy(42,16);
			cout<<"SE HA REALIZADO CORRECTAMENTE";
			gotoxy(40,18);
			cout<<"PRECIONE ENTER PARA VOLVER A MENU";
			getch();
			acceso_banco2();
	        
	        
	        break;
	    case 2 :
	    	system("cls");
	    	cuadro_banco_seleccion();
	    	gotoxy(48,4);
			cout<<"CUENTA BANCARIA";
			gotoxy(25,8);
			cout<<"TU SALDO ES S/."<<usuari.dinero;
			gotoxy(25,10);
			cout<<"INGRESE EL DINERO HA RETIRAR";
			gotoxy(25,11);
			cout<<" > ";
			cin>>retiro;
	
	        
	        

	        if( retiro>usuari.dinero ){
	        	gotoxy(20,15);
		        cout<<"********************************************************************************";
		        gotoxy(35,17);
	            cout <<"NO TIENES LOS SUFICIENTES FONDOS DISPONIBLES";
	            getch();
	            acceso_banco2();
	        }
			else{
	        	usuari.dinero = usuari.dinero - retiro;
	        	gotoxy(25,13);
		        cout<<"TU SALDO ACTUAL ES S/."<<usuari.dinero;
		        gotoxy(20,15);
		        cout<<"********************************************************************************";
		        gotoxy(42,16);
				cout<<"SE HA REALIZADO CORRECTAMENTE";
				gotoxy(40,18);
				cout<<"PRECIONE ENTER PARA VOLVER A MENU";
			    getch();
			    acceso_banco2();
	        }
	        break;
	    case 3 :
	        interfaz();break;
	
	    default:
	        acceso_banco2();break;
	}
}






//*******************************************************************************************
void cuadro_banco_menu(){
	//horizonatal
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 18);
		cout<<"*";
	}
	//vertical
	for (int i = 0; i < 15; i++) {
		gotoxy(19, i + 3);
		cout <<"*";

		gotoxy(100, i + 3);
		cout<<"*";
		
	}
}
void cuadro_banco_seleccion(){
	for (int i = 0; i < 82; i++) {
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 19);
		cout<<"*";
	}
	//vertical
	for (int i = 0; i < 17; i++) {
		gotoxy(19, i + 3);
		cout <<"*";

		gotoxy(100, i + 3);
		cout<<"*";
		
	}
}
//**************************************************************************************************************
//**************************************************************************************************************













//**************************************************************************************************************
//MODULO POLITICAS DE PRIVACIDAD
//**************************************************************************************************************
void politica_privada(){
	int i;
	
	int privacidad_opcion;
	int politica_aceptacion;
	system("cls");

	for (i = 0; i < 80; i++) {
		gotoxy(i + 20, 2);
		cout<<"*";

		gotoxy(i + 20, 6);
		cout<<"*";

		gotoxy(i + 20, 18);
		cout <<"*";
	}

	for (i = 0; i < 17; i++) {
		//Linea Left
		gotoxy(19, i + 2);
		cout<<"*";

		//Linea Right
		gotoxy(100, i + 2);
		cout<<"*";
	}

	//Titulo
	gotoxy(25, 4);
	cout << "Politica de Privacidad";

	
	//Pop up del navegador con las politicas de privacidad	
	gotoxy(25, 8);cout << "Es necesario aceptar nuestra politica de privacidad.";
	gotoxy(25, 9);cout << "¿Deseas continuar? [1] Si, [0] No: ";
	gotoxy(59, 9);cin >> privacidad_opcion;
	
	//Condicional que advierte si el numero ingresado es el correcto
	if (privacidad_opcion == 0) {
		system("cls");
		gotoxy(25, 5);cout << "Gracias por pensar en nosotros. Hasta luego...\n";
		EXIT_FAILURE;
		
	}
	else if (privacidad_opcion == 1) {
		ShellExecute(NULL, "open", "politica-de-privacidad.html", NULL, NULL, SW_SHOWNORMAL);
		
		gotoxy(25, 11);
		cout << ":: Se muestra en pantalla nuestra politica de privacidad. ::";
		
		
		//aceptacion de las politicas de privacidad
		gotoxy(25, 13); cout << "Aceptas nuestras politicas de privacidad? [1] Si, [0] No: ";
		gotoxy(82, 13); cin >> politica_aceptacion;
		if (politica_aceptacion == 0) {
			system("cls");
			gotoxy(25, 5);cout << "Gracias por pensar en nosotros. Hasta luego...\n";
		}
		else if (politica_aceptacion == 1) {
			int a;//variable del switch
			politica_aceptacion = true;
			system("cls");
			gotoxy(25, 15);
			cout<<"Se ha generado su boleta electronica.\n";
			gotoxy(25, 16);
			cout<<"Seleccione una opción";
			gotoxy(25, 17);
			cout<<"1.Para ver visualizar la boleta emitida.\n ";
			gotoxy(25, 18);
			cout<<"2.Para volver al menú principal.\n ";
			gotoxy(25, 19);
			cin>>a;
			switch(a){
				case 1:
					mostrar_boleta();
					break;
				case 2:
					interfaz();
					break;
				default:
					politica_privada();
					break;
			}
			
			
		}
		else {
			system("cls");
			return politica_privada();
		}
			
	}
	else {
		system("cls");
		return politica_privada();
	}
}

//**************************************************************************************************************
//**************************************************************************************************************












//**************************************************************************************************************
//BOLETA
//**************************************************************************************************************
//cout<<archivo.rdbuf();

void mostrar_boleta(){
	datos_personales persona1;
	system("cls");
    //leer dato por dato del archivo datos_vuelo.txt
    Datos_Vuelo vuelo;
    ifstream archivo;
    archivo.open("datos_vuelo.txt");
    getline(archivo,vuelo.origen);
    getline(archivo,vuelo.destino);
    getline(archivo,vuelo.hora_vuelo);
    getline(archivo,vuelo.fecha_ida);
    getline(archivo,vuelo.fecha_vuelta);
    archivo>>vuelo.costo;
    archivo>>vuelo.clase;
    archivo>>vuelo.equipaje;
    archivo>>vuelo.snacks;
    archivo>>vuelo.costo_snacks;
    archivo>>vuelo.costo_total;
    archivo>>vuelo.numero_pasajeros;
    for(int i=0;i<vuelo.numero_pasajeros;i++){
        archivo>>vuelo.eleccion_asiento[i];
    }
    archivo.close();
    ifstream archivo7;
	archivo7.open("personales.txt");
	getline(archivo7,persona1.nombre);
    getline(archivo7,persona1.apellido);
	archivo7.close();
    //mostrar datos del vuelo


    gotoxy(50,4);
    cout<<"BOLETA DE PAGO";
    gotoxy(25,8);
    cout<<"NOMBRE: ";
    gotoxy(25,9);
    cout<<"ORIGEN DEL VUELO: ";
    gotoxy(25,10);
    cout<<"DESTINO DEL VUELO: ";
    gotoxy(25,11);
    cout<<"LA HORA DEL VUELO: ";
    gotoxy(25,12);
    cout<<"FECHA DE IDA DEL VUELO: ";
    gotoxy(25,13);
    cout<<"FECHA DE VUELTA DEL VUELO: ";
    gotoxy(25,14);
    cout<<"COSTO POR BOLETO: ";
    gotoxy(25,15);
    cout<<"CLASE:";
    gotoxy(25,16);
    cout<<"PESO ADICIONAL DEL EQUIPAJE: ";
    gotoxy(25,17);
    cout<<"SNACK SELECCIONADO: ";
    gotoxy(25,18);
    cout<<"COSTO POR SNACK: ";
    gotoxy(25,19);
    cout<<"NÚMERO DE PASAJEROS: ";
	
	gotoxy(73,8);
	cout<<persona1.nombre<<" "<<persona1.apellido;
    gotoxy(73,9);
    cout<<vuelo.origen;
    gotoxy(73,10);
    cout<<vuelo.destino;
    gotoxy(73,11);
    cout<<vuelo.hora_vuelo;
    gotoxy(73,12);
    cout<<vuelo.fecha_ida;
    gotoxy(73,13);
    cout<<vuelo.fecha_vuelta;
    gotoxy(73,14);
    cout<<"S/."<<vuelo.costo;
    gotoxy(73,15);
    cout<<vuelo.clase;
    gotoxy(73,16);
    cout<<vuelo.equipaje<<"KG";
    gotoxy(73,17);
    cout<<vuelo.snacks;
    gotoxy(73,18);
    cout<<"S/."<<vuelo.costo_snacks;
    gotoxy(73,19);
    cout<<vuelo.numero_pasajeros;
    int lim=vuelo.numero_pasajeros;
    
    for(int i=0;i<lim;i++){
    	gotoxy(25,20+i);
    	cout<<"ASIENTO "<<i+1<<": ";
    	gotoxy(73,20+i);
    	cout<<vuelo.eleccion_asiento[i];
    }
    gotoxy(25,22+ lim);
    cout<<"COSTO TOTAL: ";
	gotoxy(73,22+ lim);
	cout<<"S/."<<vuelo.costo_total;
    for (int i = 0; i < 82; i++){
		gotoxy(i + 19, 2);
		cout<<"*";
		gotoxy(i + 19, 6);
		cout<<"*";
		gotoxy(i + 19, 21+lim);
		cout<<"*";
		gotoxy(i + 19, 23+lim);
		cout<<"*";
	}
	//vertical
	
	for (int i = 0; i < 21+ lim; i++){
		gotoxy(19, i + 3);
		cout <<"*";
		gotoxy(100, i + 3);
		cout<<"*";	
	}
}
//GOTOXY


//**************************************************************************************************************
//**************************************************************************************************************























//**********************************************************************************************************************************
//**********************************************************************************************************************************
void interfaz(){
	Datos_Vuelo vuelo;
	int i;
	int opcion_travel; //Variable que indetifica la opcion a elegir
	datos_personales persona1;
	system("cls");
	system("color F0");
	//Borde - lineas horizontales
	for (i = 0; i < 42; i++) {
		gotoxy(i + 9, 2);
		cout<<"*";
		
		gotoxy(i + 9, 6);
		cout<<"*";
		
		gotoxy(i + 9, 14);
		cout<<"*";
		
		gotoxy(i + 9, 18);
		cout<<"*";
	}

	for(i = 0; i < 15; i++){
		gotoxy(9, i + 3);
		cout<<"*";

		gotoxy(50, i + 3);
		cout<<"*";
	}

	//Titulo
	gotoxy(21, 4);
	cout << " AEROLINIA LINKI";

	//Opciones en el programa
	gotoxy(12, 8);
	cout << "[1] Registrar vuelo ";

	gotoxy(12, 10);
	cout << "[2] Plataforma bancaria";

	gotoxy(12, 12);
	cout << "[3] Salir ";

	gotoxy(12, 16);
	cout << "[#] Ingrese una opcion: ";

	//Ingreso de la opcion
	cin >> opcion_travel;	

	switch (opcion_travel){

		case 1:
			modulo_login(persona1);
			formato_vuelo();
			pasarela_de_pago();
			break;
		case 2:
			banco2(); 

			break;
		case 3:
			system("cls");
			gotoxy(12, 4); cout << "Gracias por confiar en nosotros.\n";
			EXIT_SUCCESS;
			break;
		default:
			system("cls");
			interfaz();
			break;
	}
}

int main(){
	(setlocale(LC_ALL, "spanish"));
	interfaz(); 
    getch();
    return 0;
}
