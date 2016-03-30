
/*
    Utrente Basic modella una tipologia di utente, la quale differisce dalla altre per la
    diversa implementazione del metodo di ricerca di un altro utente userSearch. I campi visibili
    di un altro utente saranno:
    - Nome
    - Cognome
    - E-mail
*/

#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H
#include "utente.h"

class UtenteBasic : public Utente
{
public:
    UtenteBasic(const Profilo&, const Username&);
    UtenteBasic(const Profilo&, const Username&, Rete*);
    void userSearch(const DB&, const Username&, list<string>&) const;
};

#endif // UTENTEBASIC_H
