/*
    La classe profilo conterrà tutti i campi dati relativi alle informazioni dell'utente
    e i metodi per visualizzarli e modificarli e per l'inserimento di nuovi dati.
*/

#ifndef PROFILO_H
#define PROFILO_H

#include "string"
#include <list>

using std::string;
using std::list;

class Profilo
{
private:
    string nome;
    string cognome;
    string email;
    list<string> titoliStudio;
    list<string> lingue;
    list<string> competenze;
    list<string> esperienze;
public:
    //Costruttore
    Profilo(const string&, const string&, const string&);

    //Metodi che restituiscono i campi dati del Profilo
    string getNome() const;
    string getCognome() const;
    string getEmail() const;

    //Metodi che modificano i campi dati del Profilo
    void cambiaEmail(const string&);
    void inserisciLingua(const string&);
    void inserisciCompetenza(const string&);
    void inserisciTitolo(const string&);
    void inserisciEsperienza(const string&);

    //Metodi che trasformano i campi dati liste in un unica stringa
    string tutteCompetenze() const;
    string tutteEsperienze() const;
    string tutteLingue() const;
    string tuttiTitoliStudio() const;

    //Metodi che riempiono i campi dati liste partendo da un unica stringa
    void caricaCompetenze(const string&);
    void caricaEsperienze(const string&);
    void caricaLingue(const string&);
    void caricaTitoliStudio(const string&);
};
#endif // PROFILO_H
