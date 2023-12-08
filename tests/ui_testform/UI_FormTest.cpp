#include "UI_FormTest.h"
#include <QTest>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <../../src/form.h>

void UI_FormTest::testUI() {
    Form form;

    mainWidget = new Form();
    textLineEdit = form.getTextLineEdit();
    subStringLineEdit = form.getSubStringLineEdit();
    searchButton = form.getSearchButton();
    resultLabel = form.getResultLabel();

    mainWidget->show();
    QTest::keyClicks(textLineEdit, "hello my name Ruslan mm");
    QTest::keyClicks(subStringLineEdit, "m");
    QTest::mouseClick(searchButton, Qt::LeftButton);
    QCOMPARE(resultLabel->text(), QString("6 11 21 22 "));
}

void UI_FormTest::cleanupTestCase() {
    delete mainWidget;
}

QTEST_MAIN(UI_FormTest)

