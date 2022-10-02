#ifndef KARTA_H
#define KARTA_H

#include <QLabel>
#include <QLayout>
#include <QMouseEvent>
#include <QEvent>


class Karta : public QLabel{
    Q_OBJECT
    int numer;
    char color;

public:

    friend class Gracz;
    friend class Bot;
//    Karta();
    Karta(bool = false);
    Karta(int, char);
    void zaaktualizujGrafike(bool);
    QWidget* pobierzNuo;


signals:
    void click(Karta*);
protected:
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // KARTA_H
