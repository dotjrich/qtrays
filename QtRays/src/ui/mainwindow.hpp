#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QImage>
#include <QLabel>
#include <QMainWindow>

#include "../renderer/renderer.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void on_actionStart_triggered();
    void render_started();
    void render_finished();

private:
    Ui::MainWindow* ui;
    QLabel* render_results;
    QImage* img;
    Renderer* renderer;
};

#endif // MAINWINDOW_HPP
