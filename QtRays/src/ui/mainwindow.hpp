#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:


private slots:
    void on_actionStart_triggered();
    void render_started();
    void render_finished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
