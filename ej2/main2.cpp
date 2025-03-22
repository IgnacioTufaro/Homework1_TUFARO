#include <iostream>
#include "header2.h"
using namespace std;

/*
Ejecutar en consola:
g++ -o ej2/main_ex ej2/main2.cpp ej2/funcs2.cpp
./ej2/main_ex
*/

int main(){
    /*Idea: Para probar que todas las funciones cumplan correctamente, se crea un entorno en el que el usuario interactua
    y puede comprobrar manualmente que mensaje desea ingresar segun el nivel de severidad. En los casos de Security, le 
    pide un usuario y si tiene acceso valido o no. En el caso de un error fatal (FATAL_ERROR) el codigo captura el error, 
    se frena la ejecucion y se registra el archivo y linea en el que ocurrio. En cualquier otro caso el programa seguira 
    registrando tantos error como el ususario lo pida.*/
    try{
        while(true){
            int level;
            cout<<"\nIngrese el nivel de severidad"<<endl;
            cout<<DEBUG<<"- "<<level_to_string(DEBUG)<<endl;
            cout<<INFO<<"- "<<level_to_string(INFO)<<endl;
            cout<<WARNING<<"- "<<level_to_string(WARNING)<<endl;
            cout<<ERROR<<"- "<<level_to_string(ERROR)<<endl;
            cout<<CRITICAL<<"- "<<level_to_string(CRITICAL)<<endl;
            cout<<FATAL_ERROR<<"- "<<level_to_string(FATAL_ERROR)<<endl;
            cout<<SECURITY<<"- "<<level_to_string(SECURITY)<<endl;
            cout<<0<<"- Exit"<<endl;
            cin>>level;

            //Se verifica que el nivel de severidad sea un int y que este dentro del rango valido de los niveles de severidad.
            if(cin.fail()){
                cout<<"Nivel de severidad no valido"<<endl;
                //Limpio el buffer de la consola para evitar errores
                cin.clear(); 
                cin.ignore(9223372036854775807, '\n');
                continue;
            }
            //Si el usuario desea salir por su cuenta, frena el programa
            if(level==0) break;
            
            if(level>SECURITY || level<0){
                cout<<"Nivel de severidad inexistente"<<endl;
        
                continue;
            }

            //Ejecuto todas los niveles de severidad que funcionan con la primer funcion de logMessage
            if(level>0 && level<=CRITICAL){
                //pido al usuario que ingrese el mensaje
                string msg;
                cout<<"Ingrese el mensaje: "<<endl;
                cin>>ws;
                getline(cin, msg);
                logMessage(msg,static_cast<sev_level>(level));
            }
            //En el caso de que sea nivel de severidad correspondiente a SECURITY, llamo a su funcion logMessage correspondiente
            if(level==SECURITY){
                string nombre;
                cout<<"Ingrese el nombre: ";
                cin>>nombre;
                string msg_acceso;
                cout<<"Ingrese mensage de acceso (Access Granted/Access Denied): ";
                cin>>ws;
                getline(cin,msg_acceso);
                logMessage(msg_acceso, nombre);
            }
            //Si es un error fatal, lanzo el error en consola
            if(level==FATAL_ERROR) throw runtime_error("Ocurrio un error fatal en el codigo");
            
        }
    }//Atrapo el error, llamo a su funcion correspondiente de logMessage y termino el programa con 1
    catch(const exception& e){ //
        logMessage(e.what(),__FILE__, __LINE__);
        cout<<"Ocurrio un error fatal en el codigo, se detuvo la ejecucion"<<endl;
        return 1;
    }

    return 0;
}