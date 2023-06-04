//
// Created by davide on 23/03/23.
//
#include "MainWindow.h"

#include <memory>

MainWindow::MainWindow(Loader* concreteLoader) : loader(concreteLoader){

    this->setFixedSize(1000, 900);

    //title setting
    text = new QLabel("Text file viewer", this);
    text->setGeometry(QRect(QPoint(0, 0), QSize(1000, 50)));
    text->setStyleSheet("QLabel { background-color : black; color : white; }");
    text->setWordWrap(true);
    text->setAlignment(Qt::AlignCenter);

    //button setting
    button = new QPushButton("Load files", this);
    button->setGeometry(QRect(QPoint(50, 75), QSize(150, 120)));
    connect(button, SIGNAL (released()), this, SLOT (start_loading()));


    //progress bar setting
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(QRect(QPoint(50, 220), QSize(900, 30)));
    progressBar->setAlignment(Qt::AlignCenter);
    progressBar->setMinimum(0);
    progressBar->setMaximum(1000);
    progressBar->setValue(0);

    //bufferbox setting
    buf = new QTextEdit("Upload :", this);
    buf->setGeometry(QRect(QPoint(250, 75), QSize(325, 120)));
    buf->setStyleSheet("QLabel { background-color : white; color : black; }");
    buf->setReadOnly(true);
    //buf->setAlignment(Qt::AlignCenter);

    //textBox setting
    textBox = new QTextEdit("",this);
    textBox->setGeometry(QRect(QPoint(50, 270), QSize(900, 600)));
    textBox->setReadOnly(true);

    //error label setting
    errorBox = new QTextEdit("", this);
    errorBox->setGeometry(QRect(QPoint(625, 75), QSize(325, 120)));
    errorBox->setStyleSheet("QLabel { background-color : white; color : black; }");
    errorBox->setReadOnly(true);
    errorBox->setAlignment(Qt::AlignCenter);

}


void MainWindow::start_loading() {
    list<string> real_files;


    real_files.push_back("Divina Commedia - Inferno");
    real_files.push_back("Divina Commedia - Prosa");
    real_files.push_back("Divina Commedia - Purgatorio");
    real_files.push_back("Divina Commedia - Inferno");
    real_files.push_back("Divina Commedia - Paradisoo");
    real_files.push_back("Divina Commedia - Paradiso");



    loader->load(real_files);

    if (loader->LoadingComplete()) {
        errorBox->setTextColor("green");
        errorBox->setText("All files are loaded.");
    } else {
        errorBox->setTextColor("red");
        errorBox->setText("Files not loaded: ");
        for (auto &itr : loader->getNotLoaded()){
            errorBox->append(itr.c_str());
        }
    }
    button->setEnabled(false);
}


void MainWindow::update() {
            buf->append((loader->getFiles()).back().getTitle().c_str());
            //textBox->setText(textBox->whatsThis() + loader->getFiles().back().getContent().c_str());
            textBox->append(loader->getFiles().back().getContent().c_str());
            progressBar->setValue((loader->getRL() * 1000 / loader->getNumOfResources()));
}
