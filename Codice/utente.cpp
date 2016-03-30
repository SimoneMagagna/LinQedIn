#include "utente.h"

Utente::Utente(const Profilo& p, const Username& u) : pf(p), un(u)
{
    rete = new Rete();
}

Utente::Utente(const Profilo& p, const Username& u, Rete* r) : pf(p), un(u), rete(r) {}

Utente::~Utente()
{
   delete rete;
}

Username Utente::getUsername() const
{
    return un;
}

Profilo Utente::getProfilo() const
{
    return pf;
}

Rete* Utente::getRete() const
{
    return rete;
}

void Utente::loadLingue(const string& s)
{
    pf.caricaLingue(s);
}

void Utente::loadCompetenze(const string& s)
{
    pf.caricaCompetenze(s);
}

void Utente::loadEsperienze(const string& s)
{
    pf.caricaEsperienze(s);
}

void Utente::loadTitoliStudio(const string& s)
{
    pf.caricaTitoliStudio(s);
}

void Utente::loadContatti(const string& s)
{
    rete->caricaContatti(s);
}

void Utente::changeEmail(const string& e)
{
    pf.cambiaEmail(e);
}

void Utente::insertCompetenza(const string& comp)
{
    pf.inserisciCompetenza(comp);
}

void Utente::insertEsperienza(const string& esp)
{
    pf.inserisciEsperienza(esp);
}

void Utente::insertLingua(const string& l)
{
    pf.inserisciLingua(l);
}

void Utente::insertTitolo(const string& t)
{
    pf.inserisciTitolo(t);
}
