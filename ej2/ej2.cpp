#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const string file_name = "ej2/LogReport.txt";

enum sev_level {
    DEBUG=1,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL_ERROR,
    SECURITY,
};

string level_to_string(sev_level level){
    switch (level){
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        case FATAL_ERROR: return "FATAL_ERROR";
        case SECURITY: return "SECURITY";
        default: return "UNKNOWN";
    }
}

void write_in_archive(const string file, const string msg){
    ofstream archive(file,ios::app);
    if(archive.is_open()){
        archive<<msg<<endl;;
        archive.close();
    }
    else cerr<<"No se pudo abrir el archivo";
}

void logMessage(const string msg, sev_level level){
    string severity_str = level_to_string(level);
    write_in_archive(file_name, "["+severity_str+"]<"+msg+">");
}

void logMessage(const string msg, const string arch, int line){
    write_in_archive(file_name,"[FATAL_ERROR]<"+msg+"><En el archivo: "+arch+"><Linea de error: "+to_string(line)+">");
}

void logMessage(const string msg_acceso, const string user_name){
    write_in_archive(file_name,"[SECURITY]<"+msg_acceso+" to: "+user_name+">");
}

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