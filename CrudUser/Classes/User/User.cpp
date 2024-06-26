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

	delete preparedStatement;

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

void User::updateUser(const int id, const std::string name, const int dni)
{
	preparedStatement = con->prepareStatement("SELECT*FROM users where id = ?");
	preparedStatement->setInt(1, id);
	res = preparedStatement->executeQuery();

	if (!res->next())
	{
		std::cout << "No existe un usuario con el ID " << id << std::endl;

	}
	else {
		try
		{
			preparedStatement = con->prepareStatement("UPDATE users SET name = ?, dni = ? where id = ?");
			preparedStatement->setString(1, name);
			preparedStatement->setInt(2, dni);
			preparedStatement->setInt(3, id);
			int affectedRows = preparedStatement->executeUpdate();
			if (affectedRows == 0) {
				std::cout << "No fue posible actualizar el registro de este usuario" << std::endl;
			}
			else {
				std::cout << "El usuario ha sido actualizado con exito";
			}
		}
		catch (const sql::SQLException e)
		{
			std::cout << e.what();
		}

		
	}
	delete preparedStatement;
}


void User::deleteUser(const int id)
{

	preparedStatement = con->prepareStatement("SELECT*FROM users where id = ?");
	preparedStatement->setInt(1, id);
	res = preparedStatement->executeQuery();

	if (!res->next())
	{
		std::cout << "No existe un usuario con el ID " << id << std::endl;

	}
	else {
		preparedStatement = con->prepareStatement("DELETE FROM users where id = ?");
		preparedStatement->setInt(1, id);
		res = preparedStatement->executeQuery();
		std::cout << "El usuario ha sido eliminado con exito";
	}

	delete preparedStatement;
	delete res;
}