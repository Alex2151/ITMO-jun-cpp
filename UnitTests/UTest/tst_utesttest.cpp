#include <QString>
#include <QtTest>
#include <myclass.h>

class UTestTest : public QObject
{
    Q_OBJECT

public:
    UTestTest();

private Q_SLOTS:
    void testMin();
};

UTestTest::UTestTest()
{
}

void UTestTest::testMin()
{
    MyClass test_cl;
    QCOMPARE(test_cl.min(0, 43), 0);
}

QTEST_APPLESS_MAIN(UTestTest)

#include "tst_utesttest.moc"
