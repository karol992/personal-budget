#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {
    CMarkup xml;
    xml.Load(USERS_FILENAME);
    xml.AddElem( "USER" );
    xml.IntoElem();
    {
        xml.AddElem( "ID", user.getId() );
        xml.AddElem( "LOGIN", user.getLogin() );
        xml.AddElem( "PASSWORD", user.getPassword() );
        xml.AddElem( "NAME", user.getName() );
        xml.AddElem( "SURNAME", user.getSurname() );
    }
    xml.OutOfElem();
    xml.Save(USERS_FILENAME);
}
vector<User> UsersFile::loadUsersFromFile() {
    vector<User> users;

    return users;
}
