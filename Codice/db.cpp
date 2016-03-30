#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include "db.h"

using namespace std;

DB::DB() {}

Utente* DB::find(const Username& u) const
{
    vector<Utente*>::const_iterator i;
    for(i=db.begin(); i!=db.end(); ++i)
    {
        if((*i)->getUsername()==u)
        {
            return *i;
        }
    }
    return 0;
}

void DB::add(Utente* su)
{
    db.push_back(su);
}

void DB::remove(const Username& u)
{
    vector<Utente*>::iterator i;
    for(i=db.begin(); i<db.end(); ++i)
    {
        if((*i)->getUsername()==u)
        {
            delete *i;
            db.erase(i);
        }
    }
}

vector<Utente*> DB::getDB() const
{
    return db;
}

void DB::save() const
{
    /*
      The QFile class provides an interface for reading from and writing to files.
      QFile is an I/O device for reading and writing text and binary files and resources.
      A QFile may be used by itself or, more conveniently, with a QTextStream or QDataStream.
    */
    QFile* file = new QFile("../database.xml");
    /*
      The QIODevice class is the base interface class of all I/O devices in Qt.
      QIODevice provides both a common implementation and an abstract interface for
      devices that support reading and writing of blocks of data, such as QFile, QBuffer and QTcpSocket.
      QIODevice is abstract and can not be instantiated, but it is common to use the interface it defines
      to provide device-independent I/O features. For example, Qt's XML classes operate on a QIODevice pointer,
      allowing them to be used with various devices (such as files and buffers).
    */
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
       QMessageBox err;
       err.setText("Errore nell'apertura del file");
       err.exec();
    }
    else
    {
       /*
         The QXmlStreamWriter class provides an XML writer with a simple streaming API.
         QXmlStreamWriter is the counterpart to QXmlStreamReader for writing XML.
         Like its related class, it operates on a QIODevice specified with setDevice().
         The API is simple and straightforward: for every XML token or event you want to write,
         the writer provides a specialized function.
         You start a document with writeStartDocument() and end it with writeEndDocument().
         This will implicitly close all remaining open tags.
       */
       QXmlStreamWriter* inp = new QXmlStreamWriter;
       inp->setAutoFormatting(true);
       //Sets the current device to device.
       inp->setDevice(file);
       inp->writeStartDocument();
       inp->writeStartElement("utenti");
       for(vector<Utente*>::const_iterator it = db.begin(); it != db.end(); ++it)
       {
           inp->writeStartElement("utente");
           inp->writeTextElement("nome", QString::fromStdString(((*it)->getProfilo()).getNome()));
           inp->writeTextElement("cognome", QString::fromStdString(((*it)->getProfilo()).getCognome()));
           inp->writeTextElement("username", QString::fromStdString(((*it)->getUsername()).getLogin()));
           inp->writeTextElement("email", QString::fromStdString(((*it)->getProfilo()).getEmail()));
           if(dynamic_cast<UtenteBasic*>(*(it)))
           {
               inp->writeTextElement("tipoutente", QString::fromStdString("Utente Basic"));
           }
           else if(dynamic_cast<UtenteBusiness*>(*(it)))
           {
               inp->writeTextElement("tipoutente", QString::fromStdString("Utente Business"));
           }
           else
           {
               inp->writeTextElement("tipoutente", QString::fromStdString("Utente Executive"));
           }
           inp->writeTextElement("competenze", QString::fromStdString((*it)->getProfilo().tutteCompetenze()));
           inp->writeTextElement("esperienze", QString::fromStdString((*it)->getProfilo().tutteEsperienze()));
           inp->writeTextElement("lingue", QString::fromStdString((*it)->getProfilo().tutteLingue()));
           inp->writeTextElement("titolistudio", QString::fromStdString((*it)->getProfilo().tuttiTitoliStudio()));
           inp->writeTextElement("contatti", QString::fromStdString(((*it)->getRete())->tuttiContatti()));
           inp->writeEndElement();
        }
        inp->writeEndElement();
        inp->writeEndDocument();
        file->close();

        QMessageBox msgBox;
        msgBox.setText("Salvataggio avvenuto con successo");
        msgBox.exec();
    }
}

void DB::load()
{
    QFile* file = new QFile("../database.xml");
        if(file->exists()){
            if(!file->open(QFile::ReadOnly | QFile::Text)){
                QMessageBox err;
                err.setText("Errore nell'apertura del file");
                err.exec();
            }
            else{
                /*
                  The QDomDocument class represents an XML document.
                  The QDomDocument class represents the entire XML document.
                  Conceptually, it is the root of the document tree, and provides the
                  primary access to the document's data.
                */
                QDomDocument doc;
                /*
                  This is an overloaded function.
                  This function reads the XML document from the IO device dev,
                  returning true if the content was successfully parsed; otherwise returns false.
                */
                if(!doc.setContent(file)){
                    return;
                }
                //The QDomElement class represents one element in the DOM tree.
                QDomElement docElem = doc.documentElement();
                /*
                  The QDomNodeList class is a list of QDomNode objects.
                  Lists can be obtained by QDomDocument::elementsByTagName() and QDomNode::childNodes().
                  The Document Object Model (DOM) requires these lists to be "live": whenever you change
                  the underlying document, the contents of the list will get updated.
                */
                QDomNodeList nodes = docElem.elementsByTagName("utente");
                for(int i=0; i<nodes.count(); ++i)
                {
                    QDomElement el = nodes.at(i).toElement();
                    QDomNode nodo = el.firstChild();
                    QString n, c, u, e, esp, comp, l, tit, tu, cont;
                    while (!nodo.isNull()) {
                        QDomElement elemento = nodo.toElement();
                        QString tagName = elemento.tagName();

                        if(tagName=="nome")
                        {
                            n=elemento.text();
                        }
                        if(tagName=="cognome")
                        {
                            c=elemento.text();
                        }
                        if(tagName=="username")
                        {
                            u=elemento.text();
                        }
                        if(tagName=="email")
                        {
                            e=elemento.text();
                        }
                        if(tagName=="tipoutente")
                        {
                            tu=elemento.text();
                        }
                        if(tagName=="esperienze")
                        {
                            esp=elemento.text();
                        }
                        if(tagName=="competenze")
                        {
                            comp=elemento.text();
                        }
                        if(tagName=="lingue")
                        {
                            l=elemento.text();
                        }
                        if(tagName=="titolistudio")
                        {
                            tit=elemento.text();
                        }
                        if(tagName=="contatti")
                        {
                            cont=elemento.text();
                        }
                        nodo=nodo.nextSibling();
                    }
                    Utente* ut = 0;
                    if(tu == "Utente Basic")
                    {
                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
                        Username us(u.toStdString());
                        ut=new UtenteBasic(prof, us);

                        if(esp.size()!=0)
                           ut->loadEsperienze(esp.toStdString());
                        if(comp.size()!=0)
                           ut->loadCompetenze(comp.toStdString());
                        if(l.size()!=0)
                           ut->loadLingue(l.toStdString());
                        if(tit.size()!=0)
                           ut->loadTitoliStudio(tit.toStdString());
                        if(cont.size()!=0)
                           ut->loadContatti(cont.toStdString());
                    }
                    if( tu == "Utente Business")
                    {
                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
                        Username us(u.toStdString());
                        ut=new UtenteBusiness(prof, us);

                        if(esp.size()!=0)
                           ut->loadEsperienze(esp.toStdString());
                        if(comp.size()!=0)
                           ut->loadCompetenze(comp.toStdString());
                        if(l.size()!=0)
                           ut->loadLingue(l.toStdString());
                        if(tit.size()!=0)
                           ut->loadTitoliStudio(tit.toStdString());
                        if(cont.size()!=0)
                           ut->loadContatti(cont.toStdString());
                    }
                    if( tu == "Utente Executive")
                    {
                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
                        Username us(u.toStdString());
                        ut=new UtenteExecutive(prof, us);

                        if(esp.size()!=0)
                           ut->loadEsperienze(esp.toStdString());
                        if(comp.size()!=0)
                           ut->loadCompetenze(comp.toStdString());
                        if(l.size()!=0)
                           ut->loadLingue(l.toStdString());
                        if(tit.size()!=0)
                           ut->loadTitoliStudio(tit.toStdString());
                        if(cont.size()!=0)
                           ut->loadContatti(cont.toStdString());
                    }

                    db.push_back(ut);
                }
                file->close();
            }
      }
}

void DB::changeSubscriptionType(const Username& user, const string& tipoUtente)
{
    bool trovato=false;
    vector<Utente*>::iterator it;
    for(it=db.begin(); it!=db.end() && !trovato; ++it)
    {
     if((*it)->getUsername()==user)
        {
            Profilo pf=(*it)->getProfilo();
            Username u=(*it)->getUsername();
            Rete* r=new Rete(*((*it)->getRete()));
             delete *it;
            if(tipoUtente=="Utente Basic")
                *it=new UtenteBasic(pf, u, r);
             if(tipoUtente=="Utente Business")
                *it=new UtenteBusiness(pf, u, r);
            if(tipoUtente=="Utente Executive")
                *it=new UtenteExecutive(pf, u, r);
            trovato=true;
        }
    }
}
