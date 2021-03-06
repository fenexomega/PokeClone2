#include "Logger.h"

#ifdef __unix__

#include <signal.h>
#include <execinfo.h>

#endif
Logger::Logger()
{

}

void Logger::Log(std::string stg)
{
#ifndef RELEASE
    PRINT(stg);
#endif
    logFile << stg << std::endl;
}

void Logger::CreateLogFile()
{
    logFile.open(LOGFILE,std::ios_base::out);
    if(!logFile.is_open())
    {
        PRINT("Couldn't not create the log file! Exiting!");
        exit(1);
    }
	instanceSignalCallbacks();
}

void Logger::CloseLogFile()
{
    LOG("Fechando log");
    logFile.close();
}

Logger::~Logger()
{

}


void Logger::instanceSignalCallbacks()
{
#ifdef __unix__
    signal(SIGSEGV,signalCallbackHandler);
#endif
}

void Logger::generateBackTrace(std::vector<char *> &vec)
{
#ifdef __unix__
    const int maxbtsize = 64;
	int logsize = 0;
	void *bt[maxbtsize];
	char ** logTrace;
	logsize = backtrace(bt,maxbtsize);
	logTrace = backtrace_symbols(bt,maxbtsize);
	for(int i = 0; i < logsize; ++i)
		vec.push_back(logTrace[i]);
#endif

}


void Logger::signalCallbackHandler(int signum)
{
	std::vector<char *> vec;
    std::string logString;

	PRINT("Signal Number Received: " << signum << " \nClosing");
	generateBackTrace(vec);
    LOG("***** BACKTRACE *****");
	for(auto bt : vec)
    {
        LOG(bt);
        logString += bt;
        logString += "\n";
    }
    LOG("***** END *****");
    std::ofstream backtrace;
    backtrace.open("backtrace.log",std::ios_base::out);
    backtrace << logString;
    backtrace.close();

	for(auto bt : vec)
		delete bt;


}
