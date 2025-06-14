#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
    Q_OBJECT  // Permet la gestion des signaux et slots

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();  // Slot pour gérer le clic du bouton

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
