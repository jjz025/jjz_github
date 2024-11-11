#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QDialog>
#include<QPlainTextEdit>
namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr,QPlainTextEdit *textEdit=nullptr);
    ~ReplaceDialog();

private slots:


    void on_pushButton_Find_clicked();

    void on_pushButton_replace_clicked();

    void on_pushButton_allReplace_clicked();

    void on_pushButton_cancle_clicked();

private:
    Ui::ReplaceDialog *ui;
    QPlainTextEdit *pTextEdit;
};

#endif // REPLACEDIALOG_H
