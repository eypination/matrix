#ifndef MATRIXMANAGER_H
#define MATRIXMANAGER_H

#include <QObject>
#include <QVector>

const int RAZ = 60;
typedef int telem;
typedef QVector<QVector<telem>> tmas;

class MatrixManager : public QObject {
    Q_OBJECT
public:
    explicit MatrixManager(QObject *parent = nullptr);

    Q_INVOKABLE void inputArr(int n);
    Q_INVOKABLE QString outputArr(int n) const;
    Q_INVOKABLE void obnul(int n);
    Q_INVOKABLE void sortMatrix(int n);

private:
    void quickSort(telem dop[], int left, int right, bool yes);
    int partition(telem dop[], int left, int right, bool yes);

    tmas A;
};

#endif // MATRIXMANAGER_H
