#include <stdlib.h>
#include <iostream>

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
    system("pause");
    return 0;
}
