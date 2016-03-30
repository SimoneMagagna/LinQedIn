#ifndef WINDOWCLIENTAGGIORNA_H
#define WINDOWCLIENTAGGIORNA_H

#include "linqedinclient.h"
#include <QWidget>
#include "ui_windowclientaggiorna.h"
#include <QMessageBox>

namespace Ui {
class windowClientAggiorna;
}

class windowClientAggiorna : public QWidget
{
    Q_OBJECT

public:
    explicit windowClientAggiorna(LinQedInClient* c, QWidget *parent = 0);
    ~windowClientAggiorna();

public slots:
    void aggiornaProfilo();


private:
    Ui::windowClientAggiorna *ui;
    LinQedInClient* client;

};

#endif // WINDOWCLIENTAGGIORNA_H
