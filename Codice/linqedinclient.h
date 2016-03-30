/*
    La classe LinQuedInClient modella i metodi per l'interazione tra l'interfaccia grafica dell'utente
    e la sua parte logica.
*/

#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H

#include "utente.h"
#include "db.h"
#include <string>
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include <list>

class LinQedInClient
{
private:
    Utente* u;
    DB* db;
public:
    //Costruttore
    LinQedInClient(const Username&);

    Utente* getUtente() const;

    //Metodi per la visualizzazione e la modifica del profilo utente
    Profilo showProfilo() const;
    void modificaEmail(const string&);
    void aggiungiTitolo(const string&);
    void aggiungiEperienza(const string&);
    void aggiungiLingua(const string&);
    void aggiungiCompetenza(const string&);

    //Metodi per l'aggiunta, la rimozione e la ricerca di un utente
    void insertRete(const Username&);
    void removeRete(const Username&);
    Utente* ricercaUsernameContatto(const Username&) const;
    void ricerca(const Username&, list<string>&) const;

    void save();
};

#endif // LINQEDINCLIENT_H
