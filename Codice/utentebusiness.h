
/*
    Utrente Business modella una tipologia di utente, la quale differisce dalla altre per la
    diversa implementazione del metodo di ricerca di un altro utente userSearch. I campi visibili
    di un altro utente saranno:
    - Nome
    - Cognome
    - E-mail
    - Lingue
    - Comnpetenze
    - Esperienze
    - Titoli di studio
*/

#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H
#include "utente.h"
class UtenteBusiness : public Utente
{
public:
    UtenteBusiness(const Profilo&, const Username&);
    UtenteBusiness(const Profilo&, const Username&, Rete*);
    void userSearch(const DB&, const Username&, list<string>&) const;
};

#endif // UTENTEBUSINESS_H
