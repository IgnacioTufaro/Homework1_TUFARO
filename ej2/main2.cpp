#include <iostream>
#include "header2.h"
using namespace std;

/*
Ejecutar en consola:
g++ -o ej2/main_ex ej2/main2.cpp ej2/funcs2.cpp
./ej2/main_ex
*/

int main(){
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
            if(level==0) break;

            if(level>SECURITY || level<0){
                cout<<"Nivel de severidad inexistente"<<endl;
                continue;
            }

            if(level>0 && level<=CRITICAL){
                string msg;
                cout<<"Ingrese el mensaje: "<<endl;
                cin>>ws;
                getline(cin, msg);
                logMessage(msg,static_cast<sev_level>(level));
            }
            
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

            if(level==FATAL_ERROR) throw runtime_error("Ocurrio un error fatal en el codigo");
            
        }
    }catch(const exception& e){
        logMessage(e.what(),__FILE__, __LINE__);
        cout<<"Ocurrio un error fatal en el codigo, se detuvo la ejecucion"<<endl;
        return -1;
    }

    return 0;
}