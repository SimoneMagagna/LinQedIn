
/*
    La classe DB implemanta il database nel quale andranno salvati tutti gli utenti di LinQuedIn
    tramite puntatori Utente*.
    La classe offre i metodi di inserimento, rimozione e ricerca di un utente e in più la possibilità di
    caricare il DB da file e di salvarlo su file.
*/

#ifndef DB_H
#define DB_H

#include <vector>
#include "utente.h"
#include "profilo.h"
#include <QSettings>
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QXmlStreamWriter>

class Utente;
using std::vector;

class DB
{
private:
    vector<Utente*> db;
public:

    //Costruttore: istanzia un vettore vuoto di Utente*
    DB();

    //Metodi per la rimozione, l'aggiunta e la ricerca di un utente
    void add(Utente*);
    void remove(const Username&);
    Utente* find(const Username&) const;

    //Metodo che ritorna una copia del database
    vector<Utente*> getDB() const;

    //Metodi per caricare e salvare il DB da e nel file XML
    void load();
    void save() const;

    //Metodo per modificare la tipologia di un utente
    void changeSubscriptionType(const Username&, const string&);
};

#endif // DB_H
