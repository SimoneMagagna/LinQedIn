#ifndef WINDOWCLIENTPROFILO_H
#define WINDOWCLIENTPROFILO_H

#include "linqedinclient.h"
#include <QWidget>
#include "ui_windowclientprofilo.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"

namespace Ui {
class windowClientProfilo;
}

class windowClientProfilo : public QWidget
{
    Q_OBJECT

public:
    explicit windowClientProfilo(LinQedInClient*, QWidget *parent = 0);
    ~windowClientProfilo();

public slots:
    void on_pushButtonIndietro_clicked();


private:
    Ui::windowClientProfilo *ui;
    LinQedInClient* client;

};

#endif // WINDOWCLIENTPROFILO_H
