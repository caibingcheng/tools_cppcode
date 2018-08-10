//
// Created by jerry on 2/12/16.
//

#include "Log.h"

namespace lg{

	Log run_log;
	Log detect_log("run.log", false);

	Log::Log(const std::string file_path, const bool cout_flag)
	{
		m_cout_flag = cout_flag;
		// system("mkdir $HOME/data/log");
	    struct timeval tv;     
	    gettimeofday(&tv,NULL);
	    std::string home = getenv("HOME"); 
	    std::random_device rd;  
	    std::default_random_engine e(rd());  
	    std::uniform_int_distribution<> u(0,1000000);
	    usleep(u(e));
	    std::string log_file_path = home + "/data/log/" +
	                            std::to_string((tv.tv_sec * 1000) % 1000000 + tv.tv_usec / 1000) +
	                            std::to_string(u(e)) +
	 							file_path;
	    m_log_file_path = log_file_path;
	    m_log_file.open(m_log_file_path, std::ios::app);
	}

	Log::~Log()
	{
	    m_log_file.close();
	    std::cout << "-- Log Destructor successfully!" << std::endl;
	}

	void Log::close()
	{
		m_log_file.close();
	}

}
