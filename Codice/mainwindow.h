#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "windowclient.h"
#include "db.h"
#include <QErrorMessage>

#include <QWidget>

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private slots:
    void on_pushButtonAdminWindow_clicked();
    void accessoCliente();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
