//
// Created by jerry on 2/12/16.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

namespace lg{
	class Log {
	private:
	    std::string m_log_file_path;
	    std::ofstream m_log_file;
	    bool m_cout_flag;
	public:
	    Log(const std::string file_path = "run.log", const bool cout_flag = true);
	    ~Log();

	    void close();
	    template<class T>
	    Log & operator << (T &log_data)
	    {
	    	m_log_file << log_data;
	    	m_log_file << std::flush;
#if ((defined _RM_DEC_PRINT) && (defined _RM_DEC_LOG_PRINT))
	    	if(m_cout_flag)
	    		std::cout << log_data << std::flush;    		
#endif	    
	    	return *this;
	    }
	};

	extern Log run_log;
}
