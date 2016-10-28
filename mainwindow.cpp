#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "arbolavl.h"
#include "string.h"
#include "cstdlib"
#include "iostream"
#include "fstream"
#include "cstdlib"

using namespace std;

ArbolAVL* miarbol= (ArbolAVL*)malloc(sizeof(ArbolAVL));


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
