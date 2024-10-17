#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<math.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    btnNums={{Qt::Key_0,ui->btnNum0},
               {Qt::Key_1,ui->btnNum1},
               {Qt::Key_2,ui->btnNum2},
               {Qt::Key_3,ui->btnNum3},
               {Qt::Key_4,ui->btnNum4},
               {Qt::Key_5,ui->btnNum5},
               {Qt::Key_6,ui->btnNum6},
               {Qt::Key_7,ui->btnNum7},
               {Qt::Key_8,ui->btnNum8},
               {Qt::Key_9,ui->btnNum9},
               };
    foreach(auto btn,btnNums)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));


    btnOpts={{Qt::Key_Asterisk,ui->btnMutiple},
               {Qt::Key_Plus,ui->btnPlus},
               {Qt::Key_Slash,ui->btnDivide},
               {Qt::Key_Minus,ui->btnSub},
               };
    foreach(auto btn,btnOpts)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnSqart,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnPeriod,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::btnNumClicked()
{
    QString dight=qobject_cast<QPushButton*>(sender())->text();
    if(operand=="0"&&dight=="0")
        dight="";
    if(operand=="0"&&dight!="0")
        operand="";
    operand+=dight;
    ui->display->setText(operand);
}

void MainWindow::on_btnPoint_clicked()
{
    if(!operand.contains("."))
        operand+=qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
}


void MainWindow::on_btnDelete_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}
QString MainWindow::calculation(bool *ok)
{
    QString result;
    QString opt;

    if(operands.size()==2&&opcodes.size()>0)
    {
        opt=opcodes.front();
        opcodes.pop_front();
        QString operand1=operands.front();
        operands.pop_front();
        QString operand2=operands.front();
        operands.pop_front();
        if(opt=="+"){
            result=QString::number(operand1.toDouble()+operand2.toDouble());
        }
        else if(opt=="-"){
            result=QString::number(operand1.toDouble()-operand2.toDouble());
        }
        else if(opt=="x"){
            result=QString::number(operand1.toDouble()*operand2.toDouble());
        }
        else if(opt=="/"){
            if(operand2=="0"){
                ui->display->setText("除数不能做分母");
            }
            result=QString::number(operand1.toDouble()/operand2.toDouble());
        }

        operand=result;
        operands.push_back(operand);
        operand="";
        //ui->statusbar->showMessage("operand="+operand+"opcode.size="+QString::number(opcodes.size()));
        ui->display->setText(operand);
    }
    return result;
}

void MainWindow::btnBinaryOperatorClicked()
{
    opcode=qobject_cast<QPushButton*>(sender())->text();
    if(operand!=""||operands.size()>0){
        if(operand!=""){
        operands.push_back(operand);
        operand="";//清空
        }
        opcodes.push_back(opcode);
    }
    QString result=calculation();
    if(result!=""){
        ui->display->setText(result);
    }
}


void MainWindow::on_btnEqual_clicked()
{
    if(operand!=""){
        operands.push_back(operand);
        operand=""; //清空
    }
    QString result=calculation();
    ui->display->setText(result);
}

void MainWindow::btnUnaryOperatorClicked()
{
    QString op=qobject_cast<QPushButton*>(sender())->text();
    if(operand!=""){
        double result=operand.toDouble();
        operand="";
        if(op=="%")
            result=result/100.0;
        else if(op=="1/x")
            result=1/result;
        else if(op=="x^2")
            result=result*result;
        else if(op=="√")
            result=sqrt(result);
        ui->display->setText(QString::number(result));
        operand=QString::number(result);
    }
}
void MainWindow::on_btnPlusOrSur_clicked()
{
    if(operand!=""){
        double dight=operand.toDouble();
        dight=-1*dight;
        operand=QString::number(dight);
        ui->display->setText(operand);
    }
}


void MainWindow::on_btnClear_clicked()
{
    operand="";
    while(!operands.empty()) operands.pop();
    opcode="";
    while(!opcodes.empty()) opcodes.pop();
    ui->display->setText(operand);
}


void MainWindow::on_btnClearE_clicked()
{
    operand="";
    ui->display->setText(operand);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(btnNums.contains(event->key()))
    {
        foreach(auto btnkey,btnNums.keys())
        {
            if(event->key()==btnkey)
                btnNums[btnkey]->animateClick(100);
        }
    }
    else if(btnOpts.contains(event->key()))
    {
        foreach(auto btnkey,btnOpts.keys())
        {
            if(event->key()==btnkey)
                btnOpts[btnkey]->animateClick(100);
        }
    }
    else if(event->key()==Qt::Key_Backspace){
        ui->btnDelete->animateClick(100);
    }
    else if(event->key()==Qt::Key_Period){
        ui->btnPoint->animateClick(100);
    }
    else if(event->key()==Qt::Key_Equal){
        ui->btnEqual->animateClick(100);
    }
}

