#include "searchdialog.h"
#include "ui_searchdialog.h"
#include<QMessageBox>
SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit *textEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    pTextEdit =textEdit;
    ui->radioButton_down->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_pushButton_clicked()
{
    QString target=ui->searchText->text();
     if(target==""||pTextEdit==nullptr)return;
    QString text=pTextEdit->toPlainText();

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
void SearchDialog::on_pushButton_2_clicked()
{
    accept();
}

