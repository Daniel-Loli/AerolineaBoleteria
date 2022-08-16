	//*************************
//bibliotecas
#include<iostream>//Bibiliote standar de c++, sirve principalmente para la entrada y salida de datos.
#include<string>//Adiciona lagunas funciones para trabajar con cadenas.
#include<conio.h>//Entre sus funciones, la invocamos para usar el "getch", de esta forma no se cerrara el ejecutable automaticamente.
#include<locale.h>//La usamos para poder transformar el idioma al que nosotros querramos.
#include<fstream>// Para el manejo de archivos con sus diferentes funciones.
#include<iomanip>
#include<windows.h>// Nos permite desplazarnos por el plano de la interfaz ejecutable.
#include<string.h>//libreria para trabajar con cadenas, propia del lenguaje C.



using namespace std;
//DATOS PERSONALES LINKI
struct Datos_Personales{
    string nombre;
    string apellido;
    string dni;
    string fecha_nacimiento;
    string direccion;
    string telefono;
    string email;
    
    ofstream archivo;//archivo de texto de datospersonales
};
struct Datos_Cuenta_Plataforma{
    string usuario;
    string clave;
    string tipo_usuario;
};

//DATOS DE VUELO
struct Datos_Vuelo{
    string hora_vuelo;
    string fecha_ida;
    int dia_ida;
    string fecha_vuelta;
    string aerolinea;
    string mes_ida;
    string destino;
    string origen;
    int numero_pasajeros;
    float costo;
    int costo_k_equipaje;
    float costo_snacks;
    float costo_total;
    string clase;
    string ofertas;
    string descuentos;
    bool ida_vuelta;
    int equipaje;
    int eleccion_asiento[10];
    string snacks;
    //guardar los datos de los vuelos en un archivo de texto
    ofstream archivo;
};

//DATOS DE PAGO
struct Datos_Pago{
    string metodo_pago;
    string numero_tarjeta;
    string fecha_vencimiento;
    string codigo_seguridad;
    string nombre_titular;
    string apellido_titular;
    string numero_tarjeta_titular;
    //guardar los datos de los pagos en un archivo de texto
    ofstream archivo;

};
    
//DATOS DE USUARIO
struct Datos_Usuario {
    Datos_Personales datos_personales;
    Datos_Vuelo datos_vuelo;
    Datos_Pago datos_pago;
    Datos_Cuenta_Plataforma datos_cuenta_plataforma;
    //combinar los archivos anteriores en un solo archivo de texto
    ofstream archivo;
};


//ESTRUCTURA DE GMAIL
struct estructura_gmail{
	string nombre;
	string apellido;
	string gmail;
	string clave;
}usuario={"daniel","loli","daniel123@gmail.com","clave"};



//DATOS DE CUENTA LINKI
struct datos_personales
{
    string nombre;
    string apellido;
    string dni;
    string fecha_nacimiento;
    string direccion;
    string telefono;
    string email;
    string clave;
}persona1;




//USUARIO DE TARJETA

struct usuario_tarjeta{
	string num_tarjeta; //numero targeta
	string nombre_titular;
	string apellido_titular;
	int mes_esp;
	int anio_esp;
	int dnipago;
	int claveweb;
	int cvv;
	float dinero;
}usuari={"1234 1234 1234 1234","daniel","loli",
	7,25,12345678,6969,245,3500};
