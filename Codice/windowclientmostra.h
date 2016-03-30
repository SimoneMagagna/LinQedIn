#ifndef WINDOWCLIENTMOSTRA_H
#define WINDOWCLIENTMOSTRA_H

#include <QWidget>

namespace Ui {
class windowClientMostra;
}

class windowClientMostra : public QWidget
{
    Q_OBJECT

public:
    explicit windowClientMostra(QWidget *parent = 0);
    ~windowClientMostra();

private:
    Ui::windowClientMostra *ui;
};

#endif // WINDOWCLIENTMOSTRA_H
