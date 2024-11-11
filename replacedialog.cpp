#include "replacedialog.h"
#include "ui_replacedialog.h"
#include<QMessageBox>

ReplaceDialog::ReplaceDialog(QWidget *parent,QPlainTextEdit *textEdit)
    : QDialog(parent)
    , ui(new Ui::ReplaceDialog)
{
    ui->setupUi(this);
    pTextEdit =textEdit;
    ui->radioButton_down->setChecked(true);
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}
void ReplaceDialog::on_pushButton_Find_clicked()
{
    QString target=ui->searchText->text();
    QString text=pTextEdit->toPlainText();
    if(target==""||pTextEdit==nullptr)return;
    QTextCursor c=pTextEdit->textCursor();
    int index=-1;

    if(ui->radioButton_down->isChecked()){
        index=text.indexOf(target,c.position(),ui->checkBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index);
            c.setPosition(index+target.length(),QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    }
    else if(ui->radioButton_up->isChecked()){
        index=text.lastIndexOf(target,c.position()-1,ui->checkBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive);
        if(index>=0){
            c.setPosition(index+target.length());
            c.setPosition(index,QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    }
    if(index<0){
        QMessageBox msg(this);
        msg.setWindowTitle("...");
        msg.setText(QString("找不到")+target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}


void ReplaceDialog::on_pushButton_replace_clicked()
{
    QString target=ui->searchText->text();
    QString to=ui->replaceText->text();

    if(pTextEdit!=nullptr&&target!=""&&to!=""){
        QString selText=pTextEdit->textCursor().selectedText();
        if(selText==target)pTextEdit->insertPlainText(to);
        on_pushButton_Find_clicked();
    }
}


void ReplaceDialog::on_pushButton_allReplace_clicked()
{
    QString target=ui->searchText->text();
    QString to=ui->replaceText->text();

    if(pTextEdit!=nullptr&&target!=""&&to!=""){
        QString text=pTextEdit->toPlainText();
        text.replace(target,to,ui->checkBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive);
        pTextEdit->clear();
        pTextEdit->insertPlainText(text);
    }
}


void ReplaceDialog::on_pushButton_cancle_clicked()
{
    accept();
}

