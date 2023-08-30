#include "dialog.h"
#include "ui_dialog.h"
#include "updateswindow.h"
#include <Windows.h>
#include <ctime>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    //初始化
    ui->setupUi(this);
    ui->caculating->setHidden(true);

    setFixedSize(width(),height());
    //按下按钮后的事件触发
    connect(ui->Button_confirm,SIGNAL(clicked(bool)),this,SLOT(whenButtonIsClicked()));
}

Dialog::~Dialog()
{
    delete ui;
}
time_t tick;
void wait(int n){
    tick = time(NULL);
    while(1){
        if(time(NULL)-n==tick)
            break;
    }
}
void Dialog::whenButtonIsClicked(){
    int i=0;
    QString heightn="你的身高大约为"+ui->height->text()+"厘米";

    //隐藏和显示各个控件
    ui->Button_confirm->setEnabled(false);

    //开始计算，设置进度条的进度变化
    ui->Button_confirm->setText("计算中...");
    for(;i<=99;i++){
        ui->progressBar->setValue(i);
        Sleep(25);
    }
    ui->Button_confirm->setText("处理中...");
    ui->progressBar->setValue(100);

    //显示计算成功
    Sleep(2000);
    ui->Button_confirm->setText("计算成功");
    ui->progressBar->setHidden(true);
    ui->caculating->setHidden(false);
    ui->caculating->setText(heightn);

}

void Dialog::on_updates_clicked()
{
    UpdatesWindow *configWindow = new UpdatesWindow;
    configWindow->show();
}
