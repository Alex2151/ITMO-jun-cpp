#include <QString>
#include <QtTest>
#include <QLineEdit>

#include "../compare.h"
#include "../testtextedit.h"

class TestsTest : public QObject
{
    Q_OBJECT

public:
    TestsTest();

private Q_SLOTS:
    void testCase1();
    void testCase2();
};

TestsTest::TestsTest()
{
}

void TestsTest::testCase1()
{

    Compare cm;
    QCOMPARE(cm.max(1, 0), 1);
}



void TestsTest::testCase2()
{

//    TestTextEdit cm;

    QLineEdit a;
    QTest::keyClicks(&a, "abCDEf123-");

    QCOMPARE(a.text(), QString("abCDEf123-"));
    QVERIFY(a.isModified());
}

QTEST_APPLESS_MAIN(TestsTest)

#include "tst_teststest.moc"
