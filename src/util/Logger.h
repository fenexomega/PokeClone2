#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Engine.h"

static std::ofstream logFile;


#define LOGFILE "output.txt"
#define TOSTR(x) std::to_string(x)
#define ERROR(x) std::cerr << x << std::endl
#define PRINT(x)  std::cout << x << std::endl
#define LOG(x) Logger::Log(x)


//TODO fazer com que a classe logger aceite std::ostream
class Logger
{
private:
    Logger();
    ~Logger();
	void static signalCallbackHandler(int signum);
	void static instanceSignalCallbacks();
	void static generateBackTrace(std::vector<char *> &vec);
public:
//  void operator<<(std::ostream &ost);
    static void Log(std::string stg);
    static void CreateLogFile();
    static void CloseLogFile();
};

#endif // LOGGER_H
