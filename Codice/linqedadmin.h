/*
   La classe LinQuedInClient modella i metodi per l'interazione tra l'interfaccia grafica dell'utente
   e la sua parte logica.
*/

#ifndef LINQEDADMIN_H
#define LINQEDADMIN_H

#include "db.h"

class LinQedAdmin
{
private:
    DB* db;
public:
    //Costruttore
    LinQedAdmin();

    //Funzioni per l'inserimento, la rimozione e la ricerca di un utente nel DB
    void insert(Utente*);
    Utente* find(const Username&) const;
    void remove(const Username&);

    //Funzione che cambia la tipologia di un utente
    void cambiaTipoUtente(const Username&, const string&);

    vector<Utente*> getDataBase() const;

    //Salvataggio del DB nel file XML
    void save() const;
};

#endif // LINQEDADMIN_H
