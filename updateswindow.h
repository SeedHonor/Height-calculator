#ifndef UPDATESWINDOW_H
#define UPDATESWINDOW_H

#include <QWidget>

namespace Ui {
class UpdatesWindow;
}

class UpdatesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UpdatesWindow(QWidget *parent = nullptr);
    ~UpdatesWindow();

private:
    Ui::UpdatesWindow *ui;
};

#endif // UPDATESWINDOW_H
