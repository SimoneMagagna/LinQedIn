#include "rete.h"

using namespace std;

Rete::Rete() {}

void Rete::add(const Username& u)
{
    net.push_back(u);
}

void Rete::remove(const Username& u)
{
    bool trovato=false;
    list<Username>::iterator i;
    for(i=net.begin(); i!=net.end() && !trovato; ++i)
    {
        if(*i==u)
        {
            trovato=true;
             net.erase(i);
        }
    }
}

string Rete::tuttiContatti() const
{
    list<Username>::const_iterator i;
    string tuttiContatti;
    for(i=net.begin(); i!=net.end(); ++i)
    {
        string temp=((*i).getLogin())+" ";
        tuttiContatti=tuttiContatti+temp;
    }
    return tuttiContatti;
}

void Rete::caricaContatti(const string& s)
{
    string cont;
    char spazio = ' ';
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=spazio)
        {
            cont=cont+s[i];
        }
        else
        {
            Username u(cont);
            net.push_back(u);
            cont="";
        }
        if(i==s.size()-1)
        {
            Username u(cont);
            net.push_back(u);
        }
    }
}
