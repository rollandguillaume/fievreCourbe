#include <QApplication>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);//creation d'une application

    MainWindow fen;//creation de la fenetre de jeu

    fen.show();//affichage de la fen

    return app.exec();
}
