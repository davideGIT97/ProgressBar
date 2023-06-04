#include <QApplication>

#include "MainWindow.h"
#include "Loader.h"


int main(int argc, char *argv[]) {


    QApplication App(argc, argv);
    Loader* L = new(Loader);
    MainWindow window(L);

    L->attach(&window);
    window.show();

    return App.exec();
}


