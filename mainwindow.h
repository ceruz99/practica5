#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <bola.h>
#include <muros.h>
#include <comida.h>
#include <enemigo.h>
#include <string.h>
#include <iostream>
#include <QFile>
#include <list>
#include <fstream>
#include <QTimer>
#include <stdlib.h>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<muros*> laberinto;
    list<comida*> almuerzo;
    int direccion1;

public slots:
    void movimientoEnemigo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    bola *pac;
    enemigo *peligro1;
    void keyPressEvent(QKeyEvent *evento);
    void obtencionMuros();



};
#endif // MAINWINDOW_H
