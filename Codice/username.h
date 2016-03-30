
/*
    La classe Username modella la username con la quale l'utente si connetterà al suo
    account specifico di LinQuedIn. La classe implementa i metodi di visualizzazione
    della login personale e dell'operazione di ugualgianza ridefinito per due oggetti
    Username.
*/

#ifndef USERNAME_H
#define USERNAME_H

#include<string>

using std::string;

class Username
{
private:
    string login;
public:
    //Costruttore
    Username(const string&);

    //Metodo che restituisce la login di un utente
    string getLogin() const;

    //Overload dell'operatore di uguaglianza
    bool operator==(const Username&) const;
    bool operator!=(const Username&) const;
};

#endif // USERNAME_H
