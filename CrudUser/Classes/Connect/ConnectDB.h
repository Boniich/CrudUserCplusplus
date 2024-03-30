#pragma once

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>

//mysql data

const std::string server = "localhost:3306";
const std::string username = "root";
const std::string password = "123456";

class ConnectDB
{
    sql::Driver* driver;
    

    void Connect();
    void setDataBaseName(std::string dataBaseName);

public:
    ConnectDB();
    ~ConnectDB();
protected:
    sql::Connection* getConnection();
    sql::Connection* con;
};

