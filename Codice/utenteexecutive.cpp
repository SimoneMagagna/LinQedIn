#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(const Profilo& p, const Username& u) : Utente(p, u) {}
UtenteExecutive::UtenteExecutive(const Profilo& p, const Username& u, Rete* r) : Utente(p, u, r) {}

void  UtenteExecutive::userSearch(const DB& d, const Username& u, list<string>& l) const
{
    Utente* su = d.find(u);
    Utente::SearchFunctor sf(3);
    sf(su, l);
}
