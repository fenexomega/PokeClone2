#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "math/Vector2D.h"

static std::ofstream logFile;


#define LOGFILE "output.txt"
#define TOSTR(x) std::to_string(x)
#define ERROR(x) std::cerr << x << std::endl
#define PRINT(x)  std::cout << x << std::endl




class Logger
{
private:
    Logger();
    ~Logger();
	void static signalCallbackHandler(int signum);
	void static instanceSignalCallbacks();
	void static generateBackTrace(std::vector<char *> &vec);
public:

    //Imprime a string no Log
    static void Log(std::string stg);

    //Cria e ativa o arquivo de Log
    static void CreateLogFile();

    //Fecha o arquivo de Log
    static void CloseLogFile();
};

inline void LOG(std::string x){ Logger::Log(x); }



#endif // LOGGER_H
