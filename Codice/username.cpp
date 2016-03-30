#include "username.h"

using std::string;

Username::Username(const string& s) : login(s) {}

string Username::getLogin() const
{
    return login;
}

bool Username::operator==(const Username& u) const
{
    return login==u.login;
}

bool Username::operator!=(const Username& u) const
{
    return login!=u.getLogin();
}
