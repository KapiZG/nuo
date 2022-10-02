#include "bot.h"
#include "ui_nuo.h"

Bot::Bot(int i, Nuo* n) : Gracz(i,n){
    id = i;
    nuo = n;

    for(int in = 0; in<50; in++){
        mojaTalia[in] = nullptr;
    }
}

void Bot::dobierzKarte(){
    Karta *k = new Karta();
    iloscKartWTali += 1;

    for(int in = 0; in<50; in++){
        if(mojaTalia[in] == nullptr){
            mojaTalia[in] = k;
            break;
        }
    }

    Karta* kwsk = new Karta(k->numer, k->color);
    nuo->ui->talia2->addWidget(kwsk);
    nuo->kolejka--;
}


void Bot::aiBot(){
    bool a = true;
    Karta *kns;
    kns = nuo->aktualna;
    for(int i = 0; i<50; i++){
        if(mojaTalia[i] != nullptr){
            if(mojaTalia[i]->numer == kns->numer || mojaTalia[i]->color == kns->color){
                polozKarte(mojaTalia[i]);
                mojaTalia[i] = nullptr;
                a = false;
                break;
            }
        }
    }
    if(a){
        dobierzKarte();
    }
}

void Bot::polozKarte(Karta *a){
    nuo->ui->talia2->removeItem(nuo->ui->talia2->itemAt(0));

    nuo->aktualna->numer = a->numer;
    nuo->aktualna->color = a->color;
    nuo->aktualna->zaaktualizujGrafike(false);
    iloscKartWTali -= 1;
    czyWygral();
    delete a;
    nuo->kolejka--;
}


