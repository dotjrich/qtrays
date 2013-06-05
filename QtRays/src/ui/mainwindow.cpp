#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QThread>

#include "../util/renderworker.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(tr("Ready"));
}

// -----------------------------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

// -----------------------------------------------------------------------

void
MainWindow::on_actionStart_triggered()
{
    QThread* thread = new QThread();
    RenderWorker* render_worker = new RenderWorker();
    render_worker->moveToThread(thread);
    connect(thread, SIGNAL(started()), render_worker, SLOT(start_render()));
    connect(render_worker, SIGNAL(render_started()), this, SLOT(render_started()));
    connect(render_worker, SIGNAL(render_finished()), thread, SLOT(quit()));
    connect(render_worker, SIGNAL(render_finished()), render_worker, SLOT(deleteLater()));
    connect(render_worker, SIGNAL(render_finished()), this, SLOT(render_finished()));
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
    ui->statusbar->showMessage(tr("Rendering Complete"));
}
