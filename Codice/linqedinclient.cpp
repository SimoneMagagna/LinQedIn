#include "linqedinclient.h"

LinQedInClient::LinQedInClient(const Username& un)
{
    db=new DB();
    db->load();
    u=db->find(un);
}

Utente* LinQedInClient::getUtente() const
{
    return u;
}

void LinQedInClient::save()
{
    db->save();
}

Profilo LinQedInClient::showProfilo() const
{
    return u->getProfilo();
}

void LinQedInClient::modificaEmail(const string& e)
{
    u->changeEmail(e);
}

void LinQedInClient::aggiungiTitolo(const string& t)
{
    u->insertTitolo(t);
}

void LinQedInClient::aggiungiEperienza(const string& e)
{
    u->insertEsperienza(e);
}

void LinQedInClient::aggiungiLingua(const string& l)
{
    u->insertLingua(l);
}

void LinQedInClient::aggiungiCompetenza(const string& c)
{
    u->insertCompetenza(c);
}

void LinQedInClient::insertRete(const Username& un)
{
    (u->getRete())->add(un);
}

void LinQedInClient::removeRete(const Username& un)
{
    (u->getRete())->remove(un);
}

Utente* LinQedInClient::ricercaUsernameContatto(const Username& us) const
{
    return db->find(us);
}

void LinQedInClient::ricerca(const Username& un, list<string>& l) const
{
   u->userSearch(*db, un, l);
}

