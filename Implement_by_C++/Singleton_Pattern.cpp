#include <iostream>
#include <string>
#include <vector>


class Logger {
public:
	static Logger* GetInstance() {
		return s_instance;
	}

	void printMessage() {
		std::cout << "Accessing the log" << std::endl;
 	}



private:
	Logger() {
		std::cout << "Logger was created " << std::endl;
	}
	
	//Ham huy
	~Logger() {
		std::cout << "Logger was Destructor " << std::endl;
	}

	static Logger* s_instance;
};

Logger* Logger::s_instance = nullptr;


int main() {
	Logger::GetInstance()->printMessage();

	//Logger logger1;
	//Logger logger2;
	//Logger logger3;
	//Logger logger4;

	return 0;
}