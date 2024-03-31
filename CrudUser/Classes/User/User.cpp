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

void User::insertUser(std::string name, int dni)
{
	try
	{
		preparedStatement = con->prepareStatement("INSERT INTO users(name,dni) VALUES(?,?)");
		preparedStatement->setString(1, name);
		preparedStatement->setInt(2, dni);
		preparedStatement->execute();

		std::cout << "Registro insertado" << std::endl;
	}
	catch (sql::SQLException e)
	{
		std::cout << "No se pudo insertar el nuevo registro" << std::endl;
		system("pause");
		exit(1);
	}

}

void User::selectAllUsers()
{
	statement = con->createStatement();
	res = statement->executeQuery("SELECT*FROM users");

	while (res->next())
	{
		std::cout << "ID: " << res->getInt("id")
			<< ", Nombre: " << res->getString("name")
			<< ", DNI; " << res->getInt("dni")
			<< std:: endl;
	}

	delete statement;
	delete res;
}

void User::selectOneUser(const int id) {
	preparedStatement = con->prepareStatement("SELECT*FROM users where id = ?");
	preparedStatement->setInt(1, id);
	res = preparedStatement->executeQuery();

	if (!res->next())
	{
		std::cout << "No existe un usuario con el ID " << id << std::endl;;

	}
	else {
		do
		{
			std::cout << "ID: " << res->getInt("id")
				<< ", Nombre: " << res->getString("name")
				<< ", DNI; " << res->getInt("dni")
				<< std::endl;
		} while (res->next());
	}

	delete preparedStatement;
	delete res;
}