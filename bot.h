#ifndef BOT_H
#define BOT_H

#include "gracz.h"

class Bot : public Gracz {

    Karta* mojaTalia[50];
public:
    Bot(int, Nuo*);
    void dobierzKarte();
    void aiBot();
    void polozKarte(Karta*);
};

#endif // BOT_H
