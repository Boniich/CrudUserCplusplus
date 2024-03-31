#include <stdlib.h>
#include <iostream>

//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/prepared_statement.h>
//using namespace std;
//
////for demonstration only. never save your password in the code!
//const string server = "tcp://127.0.0.1:3306";
//const string username = "root";
//const string password = "123456";

#include "Classes/User/User.h"

int main()
{

    User user;
    int option = 0;
    bool exit = false;
    std::string name = "";
    int id = 0;
    int dni = 0;

    std::cout << "Bienvenido a este CRUD de usuario" << std::endl;
    while (!exit)
    {
        std::cout << "### Menu de opciones ###" << std::endl;
        std::cout << "1- Leer los usuarios registrados" << std::endl;
        std::cout << "2- Leer un usuario filtrando por ID" << std::endl;
        std::cout << "3- Insertar un nuevo usuario" << std::endl;
        std::cout << "4- Actualizar los datos de un usuario" << std::endl;
        std::cout << "5- Eliminar un usuario" << std::endl;
        std::cout << "Introduce una opcion" << std::endl;

        std::cin >> option;

        switch (option)
        {
        case 1: 
            user.selectAllUsers();
            break;
        case 2:
            
            std::cout << "Inserta el id de un usuario: "; 
            std::cin >> id;
            user.selectOneUser(id);
            break;
        case 3:
            std::cin >> name;
            std::cin >> dni;

            user.insertUser(name, dni);
            break;

        default:
            break;
        }

    }



    //user.insertUser("Ezequiel", 36069300);
    //user.selectAllUsers();

    

    //ConnectDB connect;
    //system("pause");

    //sql::Driver* driver;
    //sql::Connection* con;
    //sql::Statement* stmt;
    //sql::PreparedStatement* pstmt;

    //try
    //{
    //    driver = get_driver_instance();
    //    con = driver->connect(server, username, password);
    //}
    //catch (sql::SQLException e)
    //{
    //    cout << "Could not connect to server. Error message: " << e.what() << endl;
    //    system("pause");
    //    exit(1);
    //}

    ////please create database "quickstartdb" ahead of time
    //con->setSchema("quickstartdb");

    //stmt = con->createStatement();
    //stmt->execute("DROP TABLE IF EXISTS inventory");
    //cout << "Finished dropping table (if existed)" << endl;
    //stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
    //cout << "Finished creating table" << endl;
    //delete stmt;

    //pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
    //pstmt->setString(1, "banana");
    //pstmt->setInt(2, 150);
    //pstmt->execute();
    //cout << "One row inserted." << endl;

    //pstmt->setString(1, "orange");
    //pstmt->setInt(2, 154);
    //pstmt->execute();
    //cout << "One row inserted." << endl;

    //pstmt->setString(1, "apple");
    //pstmt->setInt(2, 100);
    //pstmt->execute();
    //cout << "One row inserted." << endl;

    //delete pstmt;
    //delete con;
    system("pause");
    return 0;
}
