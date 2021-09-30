#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena=new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,700,500);
    pac=new bola(285,195,20);
    escena->addItem(pac);
    ui->label->setText("Puntos:");
    ui->label_2->setText(QString::number(contador));

    obtencionMuros();   
    obtencionComida();

    peligro1=new enemigo(35,35,15);
    escena->addItem(peligro1);

    direccion1=1+rand()%(5-1);
    QTimer *timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(movimientoEnemigo()));
    timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::movimientoEnemigo(){
    QList<muros*> :: Iterator it;
    switch (direccion1) {
    case 1:{
        peligro1->moveRight();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(peligro1->collidesWithItem(*it)){
                peligro1->moveLeft();
                direccion1=1+rand()%(5-1);
            }
        }
        break;
    }
    case 2:{
        peligro1->moveLeft();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(peligro1->collidesWithItem(*it)){
                peligro1->moveRight();
                direccion1=1+rand()%(5-1);
            }
        }
        break;
    }
    case 3:{
        peligro1->moveUp();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(peligro1->collidesWithItem(*it)){
                peligro1->moveDown();
                direccion1=1+rand()%(5-1);
            }
        }
        break;
    }
    case 4:{
        peligro1->moveDown();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(peligro1->collidesWithItem(*it)){
                peligro1->moveUp();
                direccion1=1+rand()%(5-1);
            }
        }
        break;
    }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    QList<muros*> :: Iterator it;
    list<comida*> :: iterator itComida;
    if(evento->key()==Qt::Key_D)
    {
        pac->moveRight();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(pac->collidesWithItem(*it))
                pac->moveLeft();

        }

    }
    else if(evento->key()==Qt::Key_A)
     {
        pac->moveLeft();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(pac->collidesWithItem(*it))
                pac->moveRight();

        }
     }
    else if(evento->key()==Qt::Key_W)
    {
        pac->moveUp();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(pac->collidesWithItem(*it))
                pac->moveDown();

        }
    }
    else if(evento->key()==Qt::Key_S)
    {
        pac->moveDown();
        for(it=laberinto.begin();it!=laberinto.end();it++)
        {
            if(pac->collidesWithItem(*it))
                pac->moveUp();

        }
    }
    for(itComida=almuerzo.begin();itComida!=almuerzo.end();itComida++)
    {
        if(pac->collidesWithItem(*itComida)){
            escena->removeItem(*itComida);
            almuerzo.erase(itComida);
            contador+=1;
            ui->label_2->setText(QString::number(contador));
            if(contador==88)
                QApplication::quit();
        }
    }
    if(pac->collidesWithItem(peligro1))
        QApplication::quit();

}

void MainWindow::obtencionMuros()
{

    leer.open("../P5/P4/muros.txt");
    try {
        if(!leer.is_open())
            throw '1';
        else
            throw '2';
    }  catch (char c) {
        if(c=='1')
            cout<<"No lo lee";
    }
    string linea;
    while(getline(leer, linea)){
        string pedazoLinea;
        short int valores[4];
        int tramo=0;

        for(int i=0;i<4;i++){
            if(i<3){
                tramo=linea.find(',');
                pedazoLinea=linea.substr(0,tramo);
                valores[i]=atoi(pedazoLinea.c_str());
                linea=linea.substr(tramo+1);
            }
            else
                valores[i]=atoi(linea.c_str());
        }
        laberinto.push_back(new muros(valores[0],valores[1],valores[2],valores[3]));
        escena->addItem(laberinto.back());
    }
    leer.close();
}

void MainWindow::obtencionComida()
{
    leer.open("../P5/P4/comidas.txt");
    string linea,pedazoLinea;
    int tramo;
    int coordenadas[2];
    try {
        if(!leer.is_open())
            throw '1';
        else
            throw '2';
    }  catch (char c) {
        if(c=='1')
            cout<<"No lo lee";
    }
    while(getline(leer,linea)){
        tramo=linea.find(',');
        pedazoLinea=linea.substr(0,tramo);
        coordenadas[0]=atoi(pedazoLinea.c_str());
        pedazoLinea=linea.substr(tramo+1);
        coordenadas[1]=atoi(pedazoLinea.c_str());
        almuerzo.push_back(new comida(coordenadas[0],coordenadas[1]));
        escena->addItem(almuerzo.back());
    }
    leer.close();
}
