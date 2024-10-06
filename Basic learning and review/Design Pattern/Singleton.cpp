class DatabaseConnection {
private:
	static DatabaseConnection* instance:
	// Private constructor to prevent direct instantiation
	DatabaseConnection(){
		//Perform connection setup
	}
public:
	// Public static method to access the singleton instance
	static DatabaseConnection* getInstance(){
		if(!instance){
			//Perform lazy intialization on first access
			instance = new DatabaseConnection();
		}
		return instance;
	}
};

DatabaseConnection* DatabaseConnection::instance = nullptr;

int main(){
	// Get the singleton instance
	DatabaseConnection* connection = DatabaseConnection::getInstance();
	//Use the connection for database operation
	connection -> query ("SELECT * FROM users");
	connection -> insert("INSERT INTO producs (name, price) VALUES
		('Product 1', 10.99)");
}