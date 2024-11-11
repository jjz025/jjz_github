#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<aboutdialog.h>
#include<searchdialog.h>
#include<replacedialog.h>
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

private slots:
    void on_actionAbout_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAdd_triggered();

    void on_TextEdit_textChanged();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCope_triggered();

    void on_actionPaste_triggered();

    void on_actionSeleteAll_triggered();

    void on_TextEdit_undoAvailable(bool b);

    void on_TextEdit_copyAvailable(bool b);

    void on_TextEdit_redoAvailable(bool b);

    void on_actioFrontColor_triggered();

    void on_actionSetBackColor_triggered();

    void on_actionAutoWrap_triggered();

    void on_actionFront_triggered();

    void on_actionTool_triggered();

    void on_actionState_triggered();

    void on_actionClose_triggered();

    void on_TextEdit_cursorPositionChanged();


    void on_actionShowRowNumber_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    QLabel statusCursorLabel;
    QLabel statusLabel;
    QString filePath;
    bool textChanged;
    bool userEditConfirmed();
};
#endif // MAINWINDOW_H
