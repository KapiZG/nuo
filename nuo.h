#ifndef NUO_H
#define NUO_H

#include <QMainWindow>
#include "karta.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Nuo; }
QT_END_NAMESPACE

class Nuo : public QMainWindow
{
    Q_OBJECT
    Karta *aktualna;
    int kolejka;
    bool graZaczeta = false;

public:
    Nuo(QWidget *parent = nullptr);
    ~Nuo();
    friend class Karta;
    friend class Bot;
    friend class Gracz;
    void dolaczDoGry();
    Karta* stertaKart();
    void zmianaTur();
signals:
    Nuo* deklaracjaDobrania();

private:
    Ui::Nuo *ui;

};
#endif // NUO_H
