#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <algorithm>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    srand(static_cast<unsigned int>(time(nullptr)));

    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generateMatrix);
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortMatrix);
    connect(ui->obnulButton, &QPushButton::clicked, this, &MainWindow::obnulMatrix);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateMatrix() {
    int n = ui->sizeSpinBox->value();
    int size = 2 * n;

    matrix.resize(size);
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    ui->matrixTable->clear();
    ui->matrixTable->setRowCount(size);
    ui->matrixTable->setColumnCount(size);
    ui->matrixTable->horizontalHeader()->setDefaultSectionSize(50);
    ui->matrixTable->verticalHeader()->setDefaultSectionSize(50);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ui->matrixTable->setItem(i, j, new QTableWidgetItem(QString::number(matrix[i][j])));
        }
    }
}

void MainWindow::sortMatrix() {
    int n = ui->sizeSpinBox->value();
    int size = 2 * n;

    if (matrix.empty()) {
        QMessageBox::warning(this, "Ошибка", "Сначала сгенерируйте матрицу.");
        return;
    }

    if (matrix.size() != size) {
        QMessageBox::warning(this, "Ошибка", "Размер матрицы не соответствует ожиданиям. Сначала сгенерируйте матрицу нужного размера.");
        return;
    }

    for (int i = 0; i < size; ++i) {
        QVector<int> leftRow, rightRow;

        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                leftRow.append(matrix[i][j]);
            }
        }

        for (int j = n; j < size; ++j) {
            if (matrix[i][j] != 0) {
                rightRow.append(matrix[i][j]);
            }
        }

        std::sort(leftRow.begin(), leftRow.end());
        std::sort(rightRow.begin(), rightRow.end(), std::greater<int>());

        int leftIndex = 0, rightIndex = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = leftRow[leftIndex++];
            }
        }
        for (int j = n; j < size; ++j) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = rightRow[rightIndex++];
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ui->matrixTable->setItem(i, j, new QTableWidgetItem(QString::number(matrix[i][j])));
        }
    }
}

void MainWindow::obnulMatrix() {
    int n = ui->sizeSpinBox->value();
    int size = 2 * n;

    if (matrix.size() != size) {
        QMessageBox::warning(this, "Ошибка", "Размер матрицы не соответствует ожиданиям. Сначала сгенерируйте матрицу нужного размера.");
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j > i) && (j < (size - 1 - i))) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = n; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j < i) && (j > (size - 1 - i))) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ui->matrixTable->setItem(i, j, new QTableWidgetItem(QString::number(matrix[i][j])));
        }
    }
}


