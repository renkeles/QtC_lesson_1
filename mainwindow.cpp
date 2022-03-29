#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString finderRoots(QString a, QString b, QString c)
{
    bool ok;

    double aD = a.toDouble(&ok);
    double bD = b.toDouble(&ok);
    double cD = c.toDouble(&ok);

    double pow = qPow(bD, 2);
    double Disk = pow - 4 * aD * cD;
    double eps = 0.0001;
    double result = 0.0;
    QString resultQ = "checker";

    if(fabs(aD) < eps)//Равен 0
    {
        if(bD > 0)
        {
            result = -cD;
            resultQ = "x = ";
            resultQ += QString::number(result);
            return resultQ;
        }else
        {
            result = cD;
            resultQ = "x = ";
            resultQ += QString::number(result);
            return resultQ;
        }
    }

    if(fabs(Disk) < eps)//Равен 0
    {
        result = -bD / 2 * aD;
        resultQ = "x = ";
        resultQ += QString::number(result);
        return resultQ;
    }else if(Disk > 0)
    {
        result = (-bD + qSqrt(Disk)) / 2 * aD;
        resultQ = "x1 = ";
        resultQ += QString::number(result);
        result = (-bD - qSqrt(Disk)) / 2 * aD;
        resultQ += ", x2 = ";
        resultQ += QString::number(result);
        return resultQ;
    }else
    {
        resultQ = "Нет корней";
        return resultQ;
    }

    return resultQ;
}

void MainWindow::on_pushButton_result_clicked()
{
    QString a = ui->input_a->text();
    QString b = ui->input_b->text();
    QString c = ui->input_c->text();

    QString resultQ = finderRoots(a, b, c);

    ui->output_result->setText(resultQ);
}


QString finderSide(QString a, QString b, QString angle)
{
    QString resultQ = "checker";

    bool ok;

    double aD = a.toDouble(&ok);
    double bD = b.toDouble(&ok);
    double angleD = angle.toDouble(&ok);


    if(angleD >= 0 & angleD <= 180)
    {
        double cosAngle = qCos(angleD * M_PI / 180);

        double result = qSqrt(qPow(aD,2) + qPow(bD,2) - 2 * aD * bD * cosAngle);

        resultQ = QString::number(result);

        return resultQ;
    }else
    {
        resultQ = "Неверный угол [0...180]";
        return resultQ;
    }


}

void MainWindow::on_pushButton_result_c_size_clicked()
{
    QString a = ui->input_a_side->text();
    QString b = ui->input_b_side->text();
    QString angle = ui->input_angle->text();

    QString resultQ = finderSide(a, b, angle);

    ui->output_result_c_side->setText(resultQ);

}


void MainWindow::on_pushButton_adder_clicked()
{

}


void MainWindow::on_pushButton_replace_clicked()
{

}

