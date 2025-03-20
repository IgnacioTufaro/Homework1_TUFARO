#include "header2.h" 
#include <fstream>
#include <iostream>
using namespace std;


//Defino el nombre y ruta del archivo de reporte
const string file_name = "ej2/LogReport.txt";

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
    /*Para simplificar el codigo creo esta funcion auxiliar que dado un nombre de archivo .txt
    y un mensaje de tipo string, lo escribe en una nueva linea del archivo */

    ofstream archive(file,ios::app); //Abro el archivo
    if(archive.is_open()){
        archive<<msg<<endl;; //Escribo el mensaje
        archive.close(); //Cierro el archivo
    }
    else cerr<<"No se pudo abrir el archivo"; //Mensaje de error
}

void logMessage(const string msg, sev_level level){
    /*Esta funcion recibe como paramatro un mensaje de tipo string y un nivel de severidad
    Convierto con mi funcion auxiliar el nivel a severidad a string
    y lo escribo en el reporte*/
    string severity_str = level_to_string(level);
    write_in_archive(file_name, "["+severity_str+"]<"+msg+">");
}

void logMessage(const string msg, const string arch, int line){
    /*Esta funcion recibe como parametros un mensaje de tipo de string, un nombre
    de archivo de tipo string y un numero de linea de tipo int*/
    write_in_archive(file_name,"[FATAL_ERROR]<"+msg+"><En el archivo: "+arch+"><Linea de error: "+to_string(line)+">");
}

void logMessage(const string msg_acceso, const string user_name){
    write_in_archive(file_name,"[SECURITY]<"+msg_acceso+" to: "+user_name+">");
}