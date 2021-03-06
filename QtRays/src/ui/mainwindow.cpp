#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QColor>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QString>
#include <QThread>

#include "../renderer/renderer.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), render_results(0), img(0), renderer(0)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(tr("Ready"));
    ui->imagelayout->setAlignment(Qt::AlignCenter);
}

// -----------------------------------------------------------------------

MainWindow::~MainWindow()
{
    if (img != 0) {
        delete img;
    }

    if (render_results != 0) {
        ui->imagelayout->removeWidget(render_results);
        delete render_results;
    }

    delete ui;
}

// -----------------------------------------------------------------------

void
MainWindow::on_actionSave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "", "", tr("Images (*.png)"));

    if (!file_name.isEmpty() && img) {
        img->save(file_name);
    }
}

// -----------------------------------------------------------------------

void
MainWindow::on_actionStart_triggered()
{
    if (img != 0) {
        delete img;
        img = 0;
    }

    QThread* thread = new QThread();
    renderer = new Renderer(&img);
    renderer->moveToThread(thread);
    connect(thread, SIGNAL(started()), renderer, SLOT(start_render()));
    connect(renderer, SIGNAL(render_started()), this, SLOT(render_started()));
    connect(renderer, SIGNAL(render_finished()), thread, SLOT(quit()));
    connect(renderer, SIGNAL(render_finished()), renderer, SLOT(deleteLater()));
    connect(renderer, SIGNAL(render_finished()), this, SLOT(render_finished()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

// -----------------------------------------------------------------------

void
MainWindow::render_started()
{
    ui->statusbar->showMessage(tr("Rendering"));
}

// -----------------------------------------------------------------------

void MainWindow::render_finished()
{
    if (render_results != 0) {
        ui->imagelayout->removeWidget(render_results);
        delete render_results;
        render_results = 0;
    }

    int w = img->width();
    int h = img->height();

    render_results = new QLabel();
    render_results->setPixmap(QPixmap::fromImage(*img));
    render_results->setMinimumSize(w, h);
    render_results->resize(w, h);
    render_results->setAlignment(Qt::AlignCenter);
    render_results->show();
    ui->imagelayout->addWidget(render_results);

    ui->actionSave->setEnabled(true);
    ui->statusbar->showMessage(tr("Rendering Complete"));
}
