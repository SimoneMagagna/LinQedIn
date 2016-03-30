#ifndef WINDOWCLIENT_H
#define WINDOWCLIENT_H

#include "linqedinclient.h"
#include <QWidget>
#include "ui_windowclient.h"
#include "windowclientprofilo.h"
#include "windowclientaggiorna.h"
#include "windowclientcerca.h"
#include "windowclientprofilo.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include <QErrorMessage>
#include <QMessageBox>

namespace Ui {
class windowClient;
}

class windowClient : public QWidget
{
    Q_OBJECT

public:
    explicit windowClient(LinQedInClient*, QWidget *parent = 0);
    ~windowClient();
private slots:
    void on_pushButtonWindowClientMostra_clicked();
    void on_pushButtonWindowClientAggiorna_clicked();
    void on_pushButtonWindowClientCerca_clicked();
    void on_pushButtonWindowClientSalva_clicked();
    void on_pushButtonLogout_clicked();
    void inserisciContatto();
    void rimuoviContatto();

private:
    Ui::windowClient *ui;
    LinQedInClient* client;
};

#endif // WINDOWCLIENT_H
