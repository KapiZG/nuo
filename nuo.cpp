#include "nuo.h"
#include "./ui_nuo.h"
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include "gracz.h"
#include "bot.h"
#include <stdlib.h>

Bot* bwsk;

Nuo::Nuo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Nuo)

{
    ui->setupUi(this);
    qDebug()<<this;
    kolejka = 0;
    Nuo::aktualna = new Karta;

    connect(ui->logowanie, &QPushButton::pressed, this, &Nuo::dolaczDoGry);


}

Nuo::~Nuo()
{
    delete ui;


}

void Nuo::dolaczDoGry(){
    disconnect(ui->logowanie, &QPushButton::pressed, this, &Nuo::dolaczDoGry);
    char taliaa[7] = "talia1";
    char taliab[7] = "talia2";
    Gracz *gracz1 = new Gracz(0,this);
    Bot *bot1 = new Bot(1, this);
    bwsk = bot1;
    connect(ui->zbiorKart, &QPushButton::pressed, this, &Nuo::deklaracjaDobrania);
    connect(this, &Nuo::deklaracjaDobrania, gracz1, &Gracz::dobierzKarte);

    for(int i = 0; i<=6; i++){
        gracz1->dobierzKarte();
        bot1->dobierzKarte();
    }

    graZaczeta = true;
    ui->sterta->addWidget(aktualna);

}

Karta* Nuo::stertaKart(){
    return aktualna;
}

void Nuo::zmianaTur(){
    if(kolejka == 1){
        bwsk->aiBot();
    }

}

