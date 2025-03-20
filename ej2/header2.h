#ifndef LOG_REPORT_
#define LOG_REPORT_

#include <string>
using namespace std;

//Defino los niveles de severidad
enum sev_level {
    DEBUG=1,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL_ERROR,
    SECURITY,
};

//Funciones auxiliar
string level_to_string(sev_level level);
void write_in_archive(const string file, const string msg);

//Funcion principal logMessage (item a)
void logMessage(const string msg, sev_level level);

//Funcion para registrar un error fatal (item b-ii)
void logMessage(const string msg, const string arch, int line);

//Funcion para registrar un mensaje de acceso (item b-iii)
void logMessage(const string msg_acceso, const string user_name);

#endif