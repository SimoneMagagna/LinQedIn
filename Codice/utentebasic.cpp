#include "utentebasic.h"

UtenteBasic::UtenteBasic(const Profilo& p, const Username& u) : Utente(p, u) {}
UtenteBasic::UtenteBasic(const Profilo& p, const Username& u, Rete* r) : Utente(p, u, r) {}

void UtenteBasic::userSearch(const DB& d, const Username& u, list<string>& l) const
{
    Utente* su = d.find(u);
    Utente::SearchFunctor sf(1);
    sf(su, l);
}

