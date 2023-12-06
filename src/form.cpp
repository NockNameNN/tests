#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    int index = str.indexOf(sub_str);

    QString result;
    while (index != -1) {
        result.append(QString::number(index) + " ");
        index = str.indexOf(sub_str, index + 1);
    }

    ui->result->setText(result.isEmpty() ? "Substring not found" : result);
}
