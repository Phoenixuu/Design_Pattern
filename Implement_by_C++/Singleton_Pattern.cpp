#include <iostream>
#include <string>
#include <vector>

class Logger {
public:
	static Logger& GetInstance() {
		static Logger* s_instance = new Logger;

		return *s_instance;
	}

	void printMessage() {
		std::cout << "Accessing the log" << std::endl;
		for (auto& e : m_messages) {
			std::cout << e << std::endl;
		}
	}

	void addMessage(std::string s) {
		m_messages.push_back(s);
	}

private:
	Logger() {
		std::cout << "Logger was created " << std::endl;
	}

	//Ham huy
	//~Logger() {
	//	std::cout << "Logger was Destructor " << std::endl;
	//}

	static Logger* s_instance;
	std::vector<std::string> m_messages;
};

//Logger* Logger::s_instance = nullptr;


int main() {

	Logger::GetInstance().addMessage("Hello, IPhone 1");
	Logger::GetInstance().addMessage("Hello, IPhone 2");
	Logger::GetInstance().addMessage("Hello, IPhone 3");
	Logger::GetInstance().addMessage("Hello, IPhone 4");
	Logger::GetInstance().addMessage("Hello, IPhone 5");
	Logger::GetInstance().printMessage();

	//Logger::GetInstance()->addMessage("Hello, Phone 1");
	//Logger::GetInstance()->addMessage("Hello, Phone 2");
	//Logger::GetInstance()->addMessage("Hello, Phone 3");
	//Logger::GetInstance()->addMessage("Hello, Phone 4");
	//Logger::GetInstance()->addMessage("Hello, Phone 5");
	//Logger::GetInstance()->printMessage();

	//Logger* pointer_to_Logger = Logger::GetInstance();
	//delete pointer_to_Logger;

	//Logger::GetInstance()->addMessage("Hello, Apple 5");


	//Logger logger1;
	//Logger logger2;
	//Logger logger3;
	//Logger logger4;

	return 0;
}