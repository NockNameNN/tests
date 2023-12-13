#include "facadetest.h"

void FacadeTest::testGetLevels() {
    QDir tempDir;

    tempDir.mkpath("tempLevels");

    QFile level1("tempLevels/level1.txt");
    level1.open(QIODevice::WriteOnly | QIODevice::Text);
    level1.write("1\n2\nData");
    level1.close();

    QFile level2("tempLevels/level2.txt");
    level2.open(QIODevice::WriteOnly | QIODevice::Text);
    level2.write("1\n2\nData");
    level2.close();

    Facade facade;

    QVector<QString> levels = facade.getLevels();

    QCOMPARE(levels.size(), 2);
    QVERIFY(levels.contains("level1"));
    QVERIFY(levels.contains("level2"));

    tempDir.removeRecursively();
}

void FacadeTest::testGetLevelData() {
    QFile levelFile("tempLevel1.txt");
    levelFile.open(QIODevice::WriteOnly || QIODevice::Text);
    levelFile.write("3\n4\nData1\nData2\nData3");
    levelFile.close();

    Facade facade;

    Level level = facade.get_level_data("tempLevel");

    QCOMPARE(level.h, 3);
    QCOMPARE(level.w, 4);
    QCOMPARE(level.leveldata.size(), 3);
    QCOMPARE(level.leveldata[0], "Data1");
    QCOMPARE(level1.leveldata[1], "Data2");
    QCOMPARE(level.leveldata[2], "Data3");

    QFile::remove("tempLevel.txt");
}

QTEST_APPLESS_MAIN(FacadeTest)
