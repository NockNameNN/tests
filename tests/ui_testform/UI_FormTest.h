#ifndef UI_FORMTEST_H
#define UI_FORMTEST_H

#include <QtTest/QtTest>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../../src/form.h"

class UI_FormTest : public QObject
{
    Q_OBJECT

private slots:
    void cleanupTestCase();
    void testUI();

private:
    Form* mainWidget;
    QLineEdit* textLineEdit;
    QLineEdit* subStringLineEdit;
    QPushButton* searchButton;
    QLabel* resultLabel;
};
#endif // UI_FORMTEST_H
