#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DIFFHELL.h"
#include <cmath>
#include <QMessageBox>
#include <fstream>
#include <string>
#include "QValidator"
#include "QRegularExpression"
using namespace std;

int p = 97;
int g = 5;
DiffHell first(p, g);
DiffHell second(p, g);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression RegExp("([\\d]*)");
    QValidator *Validator = new QRegularExpressionValidator(RegExp, this);
    ui->keyword_1->setValidator(Validator);
    ui->keyword_2->setValidator(Validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_encrypt_clicked()
{
    QString text = ui->input_text->text();
    QString word_1 = ui->keyword_1->text();
    QString word_2 = ui->keyword_2->text();

    string str = text.toStdString(); //исходный текст
    int first_key = word_1.toInt(); //Ключевые слово 1
    int second_key = word_2.toInt(); //Ключевые слово 2

    if (str.empty() || word_1.length() == 0 || word_2.length() == 0)
        QMessageBox::information(this, "Ошибка!", "Необходимо заполнить все поля!");
    else
    {
     ui->output_text->clear();

    first.Set(first_key);
    second.Set(second_key);

    first.generate_public_key();
    second.generate_public_key();

    first.generate_secret_key(second.Get());
    second.generate_secret_key(first.Get());

    str = first.encrypt_message(str);

    QString code = QString::fromStdString(str);
    ui->output_text->insertPlainText(code);
    }

}


void MainWindow::on_decipher_clicked()
{
    QString text = ui->input_text->text();
    QString word_1 = ui->keyword_1->text();
    QString word_2 = ui->keyword_2->text();

    string str = text.toStdString(); //исходный текст
    int first_key = word_1.toInt(); //Ключевые слово 1
    int second_key = word_2.toInt(); //Ключевые слово 2

    if (str.empty() || word_1.length() == 0 || word_2.length() == 0)
        QMessageBox::information(this, "Ошибка!", "Необходимо заполнить все поля!");
    else
    {
      ui->output_text->clear();

    first.Set(first_key);
    second.Set(second_key);

    first.generate_public_key();
    second.generate_public_key();

    first.generate_secret_key(second.Get());
    second.generate_secret_key(first.Get());

    str = second.decrypt_message(str);

    QString code = QString::fromStdString(str);
    ui->output_text->insertPlainText(code);
    }


}

