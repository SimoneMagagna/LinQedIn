#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(const Profilo& p, const Username& u) : Utente(p, u) {}

UtenteBusiness::UtenteBusiness(const Profilo& p, const Username& u, Rete* r) : Utente(p, u, r) {}

void  UtenteBusiness::userSearch(const DB& d, const Username& u, list<string>& l) const
{
    Utente* su = d.find(u);
    Utente::SearchFunctor sf(2);
    sf(su, l);
}
