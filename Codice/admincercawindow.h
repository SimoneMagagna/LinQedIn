#ifndef ADMINCERCAWINDOW_H
#define ADMINCERCAWINDOW_H

#include <QWidget>

namespace Ui {
class adminCercaWindow;
}

class adminCercaWindow : public QWidget
{
    Q_OBJECT

public:
    explicit adminCercaWindow(QWidget *parent = 0);
    ~adminCercaWindow();

private:
    Ui::adminCercaWindow *ui;
};

#endif // ADMINCERCAWINDOW_H
