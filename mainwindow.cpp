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

    //muros principales encierran
    laberinto.push_back(new muros(0,0,600,20));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(0,200,600,20));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(0,0,20,400));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(300,0,20,420));
    escena->addItem(laberinto.back());

    // 2 T apuntando a la derecha ubicadas a la izquierda
    laberinto.push_back(new muros(35,35,20,110));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(35,120,20,110));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(45,60,110,20));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(45,145,110,20));
    escena->addItem(laberinto.back());

    //T grande apunta a la izquierda
    laberinto.push_back(new muros(130,35,20,280));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(80,100,100,20));
    escena->addItem(laberinto.back());
    //T grande apunta derecha
    laberinto.push_back(new muros(165,35,20,280));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(175,100,100,20));
    escena->addItem(laberinto.back());

    //T pequeñas de la derecha
    laberinto.push_back(new muros(260,35,20,110));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(260,120,20,110));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(205,60,110,20));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(205,145,110,20));
    escena->addItem(laberinto.back());

    //cuadros esquinas
    laberinto.push_back(new muros(70,10,60,45));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(70,180,60,40));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(205,10,60,45));
    escena->addItem(laberinto.back());
    laberinto.push_back(new muros(205,180,60,40));
    escena->addItem(laberinto.back());

    //comidas
    almuerzo.push_back(new comida(40,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,120));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,200));//
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,280));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(40,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(70,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(70,200));//
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(70,360));//
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(100,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,200));//
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(100,360));//
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(130,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(130,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(130,200));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(130,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(130,320));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(160,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(160,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(160,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(160,320));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(190,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(190,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(190,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(190,320));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(220,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,120));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,280));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(220,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(250,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(250,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(295,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,120));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,280));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(295,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(340,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(340,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(380,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,120));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,280));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(380,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(420,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(420,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(420,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(420,320));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(460,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(460,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(460,200));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(460,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(460,320));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(490,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,200));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(490,360));
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(520,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(520,200));//
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(520,360));//
    escena->addItem(almuerzo.back());

    almuerzo.push_back(new comida(560,40));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,80));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,120));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,160));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,200));//
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,240));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,280));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,320));
    escena->addItem(almuerzo.back());
    almuerzo.push_back(new comida(560,360));
    escena->addItem(almuerzo.back());

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
    QFile leer;
    leer.setFileName("doc.txt");
    try {
        leer.open(QIODevice::ReadOnly | QIODevice::Text);
        if(!leer.isOpen())
            throw '1';
    }  catch (char c) {
            if(c=='1')
                cout<<"hubo un problema con la lectura del archivo muros.txt"<<endl;
    }
    string linea;
    while(!leer.atEnd()){
        linea=leer.readLine();
        string pedazoLinea;
        short int valores[4];
        int tramo1=0,tramo2=linea.find(",");
        pedazoLinea=linea.substr(tramo1,tramo2);
        for(int i=0;i<4;i++){
            pedazoLinea=linea.substr(tramo1,tramo2);
            valores[i]=atoi(pedazoLinea.c_str());
            if(i<3){
            pedazoLinea=linea.substr(tramo2+1);
            tramo2=pedazoLinea.find(",");
            }
        }
        laberinto.push_back(new muros(valores[0],valores[1],valores[2],valores[3]));
        escena->addItem(laberinto.back());
    }
    leer.close();
}
