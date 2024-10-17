#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include<QStack>
#include<QKeyEvent>
#include<QMap>
#include<QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString operand;
    QStack<QString> operands;
    QString opcode;
    QStack<QString> opcodes;
    QString calculation(bool *ok=NULL);
    QMap<int,QPushButton*> btnNums;
    QMap<int,QPushButton*> btnOpts;

private:
    Ui::MainWindow *ui;
private slots:
    void btnNumClicked();
    void on_btnPoint_clicked();
    void on_btnDelete_clicked();
    void btnBinaryOperatorClicked();
    void btnUnaryOperatorClicked();
    void on_btnEqual_clicked();
    void on_btnPlusOrSur_clicked();
    void on_btnClear_clicked();
    void on_btnClearE_clicked();
    virtual void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
