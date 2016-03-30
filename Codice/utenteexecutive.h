
/*
    Utrente Executive modella una tipologia di utente, la quale differisce dalla altre per la
    diversa implementazione del metodo di ricerca di un altro utente userSearch. I campi visibili
    di un altro utente saranno:
    - Nome
    - Cognome
    - E-mail
    - Lingue
    - Comnpetenze
    - Esperienze
    - Titoli di studio
    - Rete di contatti
*/

#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H
#include "utente.h"

class UtenteExecutive : public Utente
{
public:
    UtenteExecutive(const Profilo&, const Username&);
    UtenteExecutive(const Profilo&, const Username&, Rete*);
    void userSearch(const DB&, const Username&, list<string>&) const;
};

#endif // UTENTEEXECUTIVE_H
