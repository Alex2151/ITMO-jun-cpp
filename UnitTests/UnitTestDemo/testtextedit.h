#ifndef TESTTEXTEDIT_H
#define TESTTEXTEDIT_H

#include <QObject>
#include <QWidget>

class TestTextEdit : public QObject
{
    Q_OBJECT
public:
    TestTextEdit();

private slots: // должны быть приватными
    void edit();
};

#endif // TESTTEXTEDIT_H
