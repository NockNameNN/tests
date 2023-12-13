#ifndef FACADETEST_H
#define FACADETEST_H

#include <QtTest/QtTest>
#include "facade.h"

class FacadeTest: public QObject {
    Q_OBJECT

private slots:
    void testGetLevels();
    void testGetLevelData();
};

#endif // FACADETEST_H
