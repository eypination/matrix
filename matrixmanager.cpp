#include "MatrixManager.h"
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <cstdlib>
#include <ctime>

MatrixManager::MatrixManager(QObject *parent) : QObject(parent) {
    A.resize(RAZ);
    for (auto &row : A)
        row.resize(RAZ);
}

void MatrixManager::inputArr(int n) {
    srand(time(0));
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            A[i][j] = rand() % 100;
        }
    }
}

QString MatrixManager::outputArr(int n) const {
    QString result;
    QTextStream out(&result);
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            out << A[i][j] << " ";
        }
        out << "\n";
    }
    return result;
}

void MatrixManager::obnul(int n) {
    int size = 2 * n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j > i) && j < (size - 1 - i)) {
                A[i][j] = 0;
            }
        }
    }
    for (int i = n; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j < i) && j > (size - 1 - i)) {
                A[i][j] = 0;
            }
        }
    }
}

void MatrixManager::sortMatrix(int n) {
    int size = 2 * n;
    for (int i = 0; i < size; ++i) {
        int leftCount = 0, rightCount = 0;
        QVector<telem> leftRow(RAZ), rightRow(RAZ);

        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                leftRow[leftCount++] = A[i][j];
            }
        }
        for (int j = n; j < size; ++j) {
            if (A[i][j] != 0) {
                rightRow[rightCount++] = A[i][j];
            }
        }

        quickSort(leftRow.data(), 0, leftCount - 1, false);
        quickSort(rightRow.data(), 0, rightCount - 1, true);

        int leftIndex = 0, rightIndex = 0;
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != 0) {
                A[i][j] = leftRow[leftIndex++];
            }
        }
        for (int j = n; j < size; ++j) {
            if (A[i][j] != 0) {
                A[i][j] = rightRow[rightIndex++];
            }
        }
    }
}

void MatrixManager::quickSort(telem dop[], int left, int right, bool yes) {
    if (left < right) {
        int index = partition(dop, left, right, yes);
        quickSort(dop, left, index - 1, yes);
        quickSort(dop, index + 1, right, yes);
    }
}

int MatrixManager::partition(telem dop[], int left, int right, bool yes) {
    telem osn = dop[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if ((yes && dop[j] < osn) || (!yes && dop[j] > osn)) {
            ++i;
            std::swap(dop[i], dop[j]);
        }
    }
    std::swap(dop[i + 1], dop[right]);
    return i + 1;
}
