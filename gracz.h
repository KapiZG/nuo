#ifndef GRACZ_H
#define GRACZ_H

#include "nuo.h"


class Gracz : public QObject{
    Q_OBJECT
protected:
    int id;
    Nuo* nuo;
    int iloscKartWTali;

public:
    friend class Karta;
    Gracz(int, Nuo*);
    void polozKarte(Karta*);
    void dobierzKarte();
    void czyWygral();
    void aiBot();

signals:
    void nastepny();

};

#endif // GRACZ_H
