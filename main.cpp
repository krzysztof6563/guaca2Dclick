#include "mainwindow.h"
#include <QApplication>
#include <SDL2/SDL_mixer.h>
#include <QStyleFactory>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qApp->setStyle(QStyleFactory::create("Fusion"));
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window, QColor(30,30,30));
        darkPalette.setColor(QPalette::WindowText, QColor(220,220,220));
        darkPalette.setColor(QPalette::Base, QColor(25,25,25));
        darkPalette.setColor(QPalette::AlternateBase, QColor(30,30,30));
        darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
        darkPalette.setColor(QPalette::ToolTipText, Qt::white);
        darkPalette.setColor(QPalette::Text, QColor(220,220,220));
        darkPalette.setColor(QPalette::Button, QColor(35,35,35));
        darkPalette.setColor(QPalette::ButtonText, Qt::white);
        darkPalette.setColor(QPalette::BrightText, Qt::red);
        darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

        darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        darkPalette.setColor(QPalette::HighlightedText, Qt::black);

        qApp->setPalette(darkPalette);

        qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");    

    gGl.argc = argc;
    if (argc > 1){
        for (int i=1;i<argc;i++){
            std::string str = argv[i];
            gGl.argv.push_back(str);
        }
    }
    w.loadConf();
    w.show();

    Mix_CloseAudio();
    return a.exec();
}
