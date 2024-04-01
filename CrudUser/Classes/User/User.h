#pragma once

#include "mysql_connection.h"
#include "../Connect/ConnectDB.h"
#include <cppconn/prepared_statement.h>

class User : public ConnectDB
{
	sql::Statement* statement;
	sql::PreparedStatement* preparedStatement;
	sql::ResultSet* res;


	void createUserTable();

public:
	User();
	~User();

	void insertUser(std::string name, int dni);
	void selectAllUsers();
	void selectOneUser(const int id);
	void deleteUser(const int id);

};

