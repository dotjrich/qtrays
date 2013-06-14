#ifndef RENDERWORKER_HPP
#define RENDERWORKER_HPP

#include <QImage>
#include <QObject>
#include <QString>

class RenderWorker : public QObject
{
    Q_OBJECT

public:
    explicit RenderWorker(QObject* parent = 0);
    ~RenderWorker();
    
signals:
    void render_started();
    void render_finished();//(QImage& img);
    //void render_update(QImage& img);
    //void error(QString& err);
    
public slots:
    void start_render();
};

#endif // RENDERWORKER_HPP
