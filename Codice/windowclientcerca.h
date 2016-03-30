#ifndef WINDOWCLIENTCERCA_H
#define WINDOWCLIENTCERCA_H

#include "linqedinclient.h"
#include "username.h"
#include <QWidget>
#include "ui_windowclientcerca.h"

namespace Ui {
class windowClientCerca;
}

class windowClientCerca : public QWidget
{
    Q_OBJECT

public:
    //friend class Utente;
    explicit windowClientCerca(LinQedInClient*, Username, QWidget *parent = 0);
    ~windowClientCerca();

public slots:
    void on_pushButtonIndietro_clicked();

private:
    Ui::windowClientCerca *ui;
    LinQedInClient* client;
    Username us;
};

#endif // WINDOWCLIENTCERCA_H
