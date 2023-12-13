#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void start();

private:
    Ui::Form *ui;
};

QVector<int> boyerMooreSearch(const QString &text, const QString &pattern);

#endif // FORM_H
