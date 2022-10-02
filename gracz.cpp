#include "gracz.h"
#include "nuo.h"
#include "karta.h"
#include "ui_nuo.h"



Gracz::Gracz(int i, Nuo* a){
    id = i;
    nuo = a;
}

void Gracz::dobierzKarte(){
    Karta *a = new Karta(false);
    iloscKartWTali += 1;
    connect(a, &Karta::click, this, &Gracz::polozKarte);


    if(nuo->graZaczeta){
        nuo->ui->talia1->addWidget(a);
        nuo->kolejka++;
        nuo->zmianaTur();
    }else{
        nuo->ui->talia1->addWidget(a);
        nuo->kolejka++;
    }
}

void Gracz::polozKarte(Karta *a){
    if(nuo->kolejka == id){
        Karta *kartaNaStercie;
        kartaNaStercie = nuo->stertaKart();
        if(a->numer == kartaNaStercie->numer || a->color == kartaNaStercie->color){
            nuo->aktualna->numer = a->numer;
            nuo->aktualna->color = a->color;
            nuo->aktualna->zaaktualizujGrafike(false);
            iloscKartWTali -= 1;
            czyWygral();
            delete a;
            switch(nuo->kolejka){
                case 0:
                    nuo->kolejka++;
                    nuo->zmianaTur();
                    break;
                case 1:
                    nuo->kolejka--;
                    break;
            }
        }else{
            qDebug()<<"Nie pasuja";
        }
    }
}

void Gracz::czyWygral(){
    if(iloscKartWTali == 0){
        delete nuo;
    }
}



