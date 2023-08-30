#include "updateswindow.h"
#include "ui_updateswindow.h"

UpdatesWindow::UpdatesWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdatesWindow)
{
    //初始化
    ui->setupUi(this);
    setFixedSize(width(),height());
    setWindowFlags(Qt::Dialog);
}

UpdatesWindow::~UpdatesWindow()
{
    delete ui;
}
