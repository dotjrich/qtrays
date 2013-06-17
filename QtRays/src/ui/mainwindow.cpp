#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QColor>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
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
    if (render_results != 0) {
        ui->imagelayout->removeWidget(render_results);
        delete render_results;
    }

    delete ui;
}

// -----------------------------------------------------------------------

void
MainWindow::on_actionStart_triggered()
{
    QThread* thread = new QThread();
    renderer = new Renderer(img);
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
    // Junk to test QImage stuff...
    QImage img(200, 200, QImage::Format_ARGB32);
    img.fill(qRgba(0, 0, 0, 255));
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; j += 2) {
            img.setPixel(i, j, QColor::fromRgbF(0.0f, 1.0f, 0.0f, 1.0f).rgba());
        }
    }
    render_results = new QLabel();
    render_results->setPixmap(QPixmap::fromImage(img));
    render_results->setMinimumSize(200, 200);
    render_results->resize(200, 200);
    render_results->setAlignment(Qt::AlignCenter);
    render_results->show();
    ui->imagelayout->addWidget(render_results);
    //img.save("/Users/jrichards/output_asdf.jpg");

    ui->statusbar->showMessage(tr("Rendering Complete"));
}
