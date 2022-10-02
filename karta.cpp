#include <iostream>

#include "karta.h"
#include <string.h>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QMouseEvent>

Karta::Karta(bool qwe){
    int numer_karty = rand() % 10;
    numer = numer_karty;
    int numer_coloru = rand() % 5;
    switch(numer_coloru){
        case 1:
            color = 'r';
            break;
        case 2:
            color = 'g';
            break;
        case 3:
            color = 'b';
            break;
        case 4:
            color = 'y';
            break;
        default:
            color = 'y';

    }
    zaaktualizujGrafike(qwe);

}

void Karta::mousePressEvent(QMouseEvent *event){

    emit click(this);
}


void Karta::zaaktualizujGrafike(bool bota = false){
    int numer_karty = numer;
    std::string wse;
    if(!bota){
        wse = std::string("./cards/") + color + std::to_string(numer_karty) + ".png";
    }
    int string_dlugosc = wse.length();
    char sciezka[string_dlugosc + 1];
    strncpy(sciezka, wse.c_str(), string_dlugosc + 100);
    QPixmap imaghe(sciezka);
    this->setPixmap(imaghe);
    this->setScaledContents(true);
}

Karta::Karta(int i, char c){
    numer = i;
    color = c;
    std::string wse = "./cards/q0.png";
    char sciezka[wse.length() + 1];
    strncpy(sciezka, wse.c_str(), wse.length() + 100);
    QPixmap image(sciezka);
    this->setPixmap(image);
    this->setScaledContents(true);
}
