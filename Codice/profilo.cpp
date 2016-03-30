#include "profilo.h"

using std::string;
using std::list;

Profilo::Profilo(const string& nom, const string& cog, const string& em) : nome(nom), cognome(cog), email(em) {}

string Profilo::getNome() const
{
    return nome;
}

string Profilo::getCognome() const
{
    return cognome;
}

string Profilo::getEmail() const
{
    return email;
}

void Profilo::cambiaEmail(const string& e)
{
    email=e;
}

void Profilo::inserisciLingua(const string& l)
{
    lingue.push_back(l);
}

void Profilo::inserisciCompetenza(const string& comp)
{
    competenze.push_back(comp);
}

void Profilo::inserisciTitolo(const string& t)
{
    titoliStudio.push_back(t);
}

void Profilo::inserisciEsperienza(const string& esp)
{
    esperienze.push_back(esp);
}

string Profilo::tutteCompetenze() const
{
    list<string>::const_iterator i;
    string tutteCompetenze;
    for(i=competenze.begin(); i!=competenze.end(); ++i)
    {
        string temp=(*i)+" ";
        tutteCompetenze=tutteCompetenze+temp;
    }
    return tutteCompetenze;
}

string Profilo::tutteEsperienze() const
{
    list<string>::const_iterator i;
    string tutteEsperienze;
    for(i=esperienze.begin(); i!=esperienze.end(); ++i)
    {
        string temp=(*i)+" ";
        tutteEsperienze=tutteEsperienze+temp;
    }
    return tutteEsperienze;
}

string Profilo::tutteLingue() const
{
    list<string>::const_iterator i;
    string tutteLingue;
    for(i=lingue.begin(); i!=lingue.end(); ++i)
    {
        string temp=(*i)+" ";
        tutteLingue=tutteLingue+temp;
    }
    return tutteLingue;
}

string Profilo::tuttiTitoliStudio() const
{
    list<string>::const_iterator i;
    string tuttiTitoliStudio;
    for(i=titoliStudio.begin(); i!=titoliStudio.end(); ++i)
    {
        string temp=(*i)+" ";
        tuttiTitoliStudio=tuttiTitoliStudio+temp;
    }
    return tuttiTitoliStudio;
}

void Profilo::caricaCompetenze(const string& s)
{
    string comp;
    char spazio = ' ';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=spazio)
        {
            comp=comp+s[i];
        }
        else
        {
            competenze.push_back(comp);
            comp="";
        }
        if(i==s.size()-1)
        {
            competenze.push_back(comp);
        }
    }
}

void Profilo::caricaEsperienze(const string& s)
{
    string esp;
    char spazio = ' ';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=spazio)
        {
            esp=esp+s[i];
        }
        else
        {
            esperienze.push_back(esp);
            esp="";
        }
        if(i==s.size()-1)
        {
            esperienze.push_back(esp);
        }
    }
}

void Profilo::caricaLingue(const string& s)
{
    string l;
    char spazio = ' ';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=spazio)
        {
            l=l+s[i];
        }
        else
        {
            lingue.push_back(l);
            l="";
        }
        if(i==s.size()-1)
        {
            lingue.push_back(l);
        }
    }
}

void Profilo::caricaTitoliStudio(const string& s)
{
    string tit;
    char spazio = ' ';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=spazio)
        {
            tit=tit+s[i];
        }
        else
        {
            titoliStudio.push_back(tit);
            tit="";
        }
        if(i==s.size()-1)
        {
            titoliStudio.push_back(tit);
        }
    }
}
