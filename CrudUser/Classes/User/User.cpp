#include "User.h"

User::User() : ConnectDB() {
	
	createUserTable();
}

User::~User()
{
	
}

void User::createUserTable()
{
	
	try
	{
		statement = con->createStatement();
		statement->execute("CREATE TABLE IF NOT EXISTS users (id serial PRIMARY KEY, name VARCHAR(50), dni INTEGER);");
	}
	catch (sql::SQLException e)
	{
		std::cout << "No se pudo crear la tabla";
		system("Pause");
		exit(1);
	}

	delete statement;
	
}