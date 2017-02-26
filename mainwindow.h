#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int timeout;
    int hourtime;
public:
    explicit MainWindow(QWidget *parent = 0);
    void setTimeout (const int _timeout) { timeout = _timeout; }
    void sethourtime (const int _hourtime) { hourtime = _hourtime; }
    ~MainWindow();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_spinBox_valueChanged(int arg1);


    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
