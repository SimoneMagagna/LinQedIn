#ifndef UTENTE_H
#define UTENTE_H

#include <iostream>
#include "string"
#include "profilo.h"
#include "username.h"
#include "db.h"
#include <iostream>
#include "rete.h"

using namespace std;

class Rete;
class DB;
class Utente
{
    friend class SearchFunctor;

private:
    Profilo pf;
    Rete* rete;
    Username un;
public:
    //Costruttori
    Utente(const Profilo&, const Username&);
    Utente(const Profilo&, const Username&, Rete*);

    //Metodi che ritornano i campi dati di un Utente
    Username getUsername() const;
    Profilo getProfilo() const;
    Rete* getRete() const;

    //Distruttore ridefinito
    virtual ~Utente();

    //Funzioni che richiamano le funzioni di trasformazione di un unica stringa in lista della classe Profilo
    void loadEsperienze(const string&);
    void loadLingue(const string&);
    void loadTitoliStudio(const string&);
    void loadCompetenze(const string&);
    void loadContatti(const string&);

    //Funzioni che richiamano le funzioni di modofica della classe Profilo
    void changeEmail(const string&);
    void insertCompetenza(const string&);
    void insertEsperienza(const string&);
    void insertLingua(const string&);
    void insertTitolo(const string&);

    //Funzione virtuale pura di ricerca di un utente che verrà implementata nelle classi derivate
    virtual void userSearch(const DB&, const Username&, list<string>&) const=0;
protected:
    //Classe Funtore utile per la ricerca di un utente
    class SearchFunctor
    {
    public:
        int searchType;
        SearchFunctor(int x=0) : searchType(x) {}
        void operator() (const Utente* x, list<string>& l) const
        {
            switch(searchType)
            {
                case 1:
                    l.push_back(x->un.getLogin());
                    l.push_back(x->pf.getNome());
                    l.push_back(x->pf.getCognome());
                    l.push_back(x->pf.getEmail());
                    break;

                case 2:
                    l.push_back(x->un.getLogin());
                    l.push_back(x->pf.getNome());
                    l.push_back(x->pf.getCognome());
                    l.push_back(x->pf.getEmail());
                    l.push_back(x->pf.tutteCompetenze());
                    l.push_back(x->pf.tutteEsperienze());
                    l.push_back(x->pf.tuttiTitoliStudio());
                    l.push_back(x->pf.tutteLingue());
                    break;

                case 3:
                    l.push_back(x->un.getLogin());
                    l.push_back(x->pf.getNome());
                    l.push_back(x->pf.getCognome());
                    l.push_back(x->pf.getEmail());
                    l.push_back(x->pf.tutteCompetenze());
                    l.push_back(x->pf.tutteEsperienze());
                    l.push_back(x->pf.tuttiTitoliStudio());
                    l.push_back(x->pf.tutteLingue());
                    l.push_back(x->rete->tuttiContatti());
                    break;
            }
        }
    };
};

#endif // UTENTE_H

