#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QVector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void generateMatrix();
    void sortMatrix();
    void obnulMatrix();

private:
    Ui::MainWindow *ui;
    QVector<QVector<int>> matrix;
};

#endif // MAINWINDOW_H
