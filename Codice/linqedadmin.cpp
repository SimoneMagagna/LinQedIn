#include "linqedadmin.h"

using std::list;

LinQedAdmin::LinQedAdmin()
{
    db=new DB();
    db->load();
}

void LinQedAdmin::save() const
{
    db->save();
}

vector<Utente*> LinQedAdmin::getDataBase() const
{
    return db->getDB();
}

void LinQedAdmin::insert(Utente* u)
{
    db->add(u);
}

Utente* LinQedAdmin::find(const Username& u) const
{
    return db->find(u);
}

void LinQedAdmin::remove(const Username& u)
{
    db->remove(u);
}

void LinQedAdmin::cambiaTipoUtente(const Username& user, const string& tip)
{
    db->changeSubscriptionType(user, tip);
}
