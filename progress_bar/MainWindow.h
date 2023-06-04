//
// Created by davide on 18/03/23.
//
#ifndef PROGRESS_BAR_MAINWINDOW_H
#define PROGRESS_BAR_MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include "Loader.h"
#include "Observer.h"


class MainWindow : public QMainWindow, public Observer{
    Q_OBJECT
public:
    explicit MainWindow(Loader* loader);

    ~MainWindow() override {
        loader->detach(this);
    }


    void update() override;


private slots:

    void start_loading();


private:
    Loader* loader;
    list<string> names;

    QTextEdit* errorBox;
    QLabel* text;
    QTextEdit* buf;
    QPushButton* button;
    QProgressBar* progressBar;
    QTextEdit* textBox;
};





#endif //PROGRESS_BAR_MAINWINDOW_H
