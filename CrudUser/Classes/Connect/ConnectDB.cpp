#include "ConnectDB.h"

ConnectDB::ConnectDB()
{
	Connect();
	setDataBaseName("crud_user");
	
}

ConnectDB::~ConnectDB()
{
	delete con;
}

void ConnectDB::Connect()
{
	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
		std::cout << "conexion exitosa";
		
	}
	catch (sql::SQLException e)
	{
		std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
		system("pause");
		exit(1);
	}
}

sql::Connection* ConnectDB::getConnection()
{
	return con;
}

void ConnectDB::setDataBaseName(std::string dataBaseName)
{
	try
	{
		con->setSchema(dataBaseName);
	}
	catch (sql::SQLException e)
	{
		std::cout << "" << std::endl;
		std::cout << "No existe una base de datos con ese nombre" << std::endl;
		system("pause");
		exit(1);
	}
}