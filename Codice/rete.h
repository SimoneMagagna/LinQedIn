
/*
    La classe Rete modella la lista di contatti che ogni utente possiede. La classe implementa i
    metodi di rimozione e inserimento di ogni contatto rappresentato da un oggetto Username.
*/

#ifndef RETE_H
#define RETE_H

#include <list>
#include "username.h"
#include <string>

using std::list;
using std::string;

class Rete
{
private:
    list<Username> net;
public:
    //Cotruttore
    Rete();

    //Metodi per la rimozione e l'aggiunta di un contatto
    void add(const Username&);
    void remove(const Username&);

    //Metodo che trasforma il campo dati lista in un unica stringa
    string tuttiContatti() const;

     //Metodo che riempie il campo dati lista partendo da un unica stringa
    void caricaContatti(const string& s);
};

#endif // RETE_H
