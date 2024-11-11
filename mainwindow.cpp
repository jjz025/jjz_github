#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QColorDialog>
#include<QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    textChanged=false;

    on_actionNew_triggered();

    ui->statusbar;
    statusLabel.setMaximumWidth(200);
    statusLabel.setText("length:"+QString::number(0)+"  lines:"+QString::number(1));

    ui->statusbar->addPermanentWidget(&statusLabel);
    statusCursorLabel.setMaximumWidth(200);
    statusCursorLabel.setText("Ln:"+QString::number(1)+"  Col:"+QString::number(1));
    ui->statusbar->addPermanentWidget(&statusCursorLabel);

    QLabel *author=new QLabel(ui->statusbar);
    author->setText("郑佳佳");
    ui->statusbar->addPermanentWidget(author);

    ui->actionCope->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    on_actionAutoWrap_triggered();
    ui->actionState->setChecked(true);
    ui->actionTool->setChecked(true);
    on_actionShowRowNumber_triggered(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{
    SearchDialog dlg(this,ui->TextEdit);
    dlg.exec();
}


void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog dlg(this,ui->TextEdit);
    dlg.exec();
}


void MainWindow::on_actionNew_triggered()
{
    if(!userEditConfirmed()){return;}
    filePath="";
    ui->TextEdit->clear();
    this->setWindowTitle(tr("新建文本文件 -- 编辑器"));
    textChanged=false;
}


void MainWindow::on_actionOpen_triggered()
{
    if(!userEditConfirmed()){return;}
    QString filename=QFileDialog::getOpenFileName(this,"打开文件",".",tr("Text files(*.txt);;All(*.*)"));
    QFile file(filename);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"..","打开文件失败");
        return;
    }

    filePath=filename;
    QTextStream in(&file);
    QString text=in.readAll();
    ui->TextEdit->insertPlainText(text);
    file.close();
    this->setWindowTitle(QFileInfo(filename).absoluteFilePath());
    textChanged=false;
}




void MainWindow::on_actionSave_triggered()
{
    QString filename;
    if (filePath.isEmpty()) {
        // 弹出保存文件对话框，让用户选择保存路径和文件名
        filename = QFileDialog::getSaveFileName(this, "保存文件", ".", tr("Text files(*.txt)"));
        if (filename.isEmpty()) {
            return; // 用户取消保存操作
        }
        filePath=filename;
    }
    else{
        filename = filePath;
    }

    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "打开文件失败");
        return;
    }

    QTextStream out(&file);
    QString text = ui->TextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
    this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
}


void MainWindow::on_actionAdd_triggered()
{
        QString filename = QFileDialog::getSaveFileName(this, "另存为", ".", tr("Text files(*.txt)"));
        if (filename.isEmpty()) {
            return; // 用户取消保存操作
        }

        // 打开文件进行写操作
        QFile file(filename);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "..", "打开文件失败");
            return;
        }

        // 获取文本编辑器中的内容并写入文件
        QTextStream out(&file);
        QString text = ui->TextEdit->toPlainText();
        out << text;
        file.flush();
        file.close();

        // 更新当前文件路径为新保存的文件路径
        filePath = filename;

        // 更新窗口标题为新保存的文件路径
        this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
}


void MainWindow::on_TextEdit_textChanged()
{
    if(!textChanged){
        this->setWindowTitle("*"+this->windowTitle());
        textChanged=true;
    }
    statusLabel.setText("length:"+QString::number(ui->TextEdit->toPlainText().length())+"  lines:"+QString::number(ui->TextEdit->document()->lineCount()));
}

bool MainWindow::userEditConfirmed()
{
    if(textChanged){
        QString path=(filePath!="")?filePath:"无标题.txt";
        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle("..");
        msg.setWindowFlag(Qt::Drawer);
        msg.setText(QString("是否将更改保存到\n")+"\""+path+"\" ?");
        msg.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        int r=msg.exec();
        switch(r){
        case QMessageBox::Yes:on_actionSave_triggered();break;
        case QMessageBox::No:textChanged=false;break;
        case QMessageBox::Cancel:return false;
        }
    }
    return true;
}


void MainWindow::on_actionCut_triggered()
{
    ui->TextEdit->cut();
    ui->actionPaste->setEnabled(true);
}


void MainWindow::on_actionUndo_triggered()
{
     ui->TextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->TextEdit->redo();
}


void MainWindow::on_actionCope_triggered()
{
    ui->TextEdit->copy();
    ui->actionPaste->setEnabled(true);
}


void MainWindow::on_actionPaste_triggered()
{
    ui->TextEdit->paste();
}


void MainWindow::on_actionSeleteAll_triggered()
{
    ui->TextEdit->selectAll();
}


void MainWindow::on_TextEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}


void MainWindow::on_TextEdit_copyAvailable(bool b)
{
    ui->actionCope->setEnabled(b);
    ui->actionCut->setEnabled(b);
}


void MainWindow::on_TextEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}


void MainWindow::on_actioFrontColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::black,this,"选择字体颜色");
    if(color.isValid()){
        ui->TextEdit->setStyleSheet(QString("QPlainTextEdit{color:%1}").arg(color.name()));
    }
}


void MainWindow::on_actionSetBackColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::black,this,"选择背景颜色");
    if(color.isValid()){
        ui->TextEdit->setStyleSheet(QString("QPlainTextEdit{background-color:%1}").arg(color.name()));
    }
}


void MainWindow::on_actionAutoWrap_triggered()
{
    // 获取当前文本编辑控件的自动换行模式
    bool isAutoWrap = ui->TextEdit->lineWrapMode() == QPlainTextEdit::WidgetWidth;

    // 如果当前是自动换行模式，则关闭它；否则，打开它
    if (isAutoWrap) {
        ui->TextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        ui->actionAutoWrap->setChecked(false);
    } else {
        ui->TextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
         ui->actionAutoWrap->setChecked(true);
    }
}


void MainWindow::on_actionFront_triggered()
{
    QFont font;
    font.setFamily("等线"); // 设置默认字体为宋体
    bool ok;
    QFont newFont = QFontDialog::getFont(&ok, font, this, "选择字体");
    if (ok) {
        ui->TextEdit->setFont(newFont);
    }
}



void MainWindow::on_actionTool_triggered()
{
    bool visible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!visible);
    ui->actionTool->setChecked(!visible);
}


void MainWindow::on_actionState_triggered()
{
    bool visible = ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
    ui->actionState->setChecked(!visible);
}


void MainWindow::on_actionClose_triggered()
{
    if(userEditConfirmed())
        exit(0);
}


void MainWindow::on_TextEdit_cursorPositionChanged()
{
    int pos=ui->TextEdit->textCursor().position();
    int col=0;
    int ln=0;
    int flg=-1;
    QString text=ui->TextEdit->toPlainText();
    for(int i=0;i<pos;i++){
        if(text[i]=='\n'){
            ln++;
            flg=i;
        }
    }
    flg++;
    col=pos-flg;
    statusCursorLabel.setText("Ln:"+QString::number(ln+1)+"  Col:"+QString::number(col+1));
}

void MainWindow::on_actionShowRowNumber_triggered(bool checked)
{
     ui->TextEdit->hideLineNmberArea(!checked);
}

