#pragma once

#include "mysql_connection.h"
#include "../Connect/ConnectDB.h"
#include <cppconn/prepared_statement.h>

class User : public ConnectDB
{
	sql::Statement* statement;
	sql::PreparedStatement* preparedStatement;


	void createUserTable();

public:
	User();
	~User();

	void insertUser(std::string name, int dni);

};

