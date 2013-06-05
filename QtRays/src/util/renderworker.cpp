#include "renderworker.hpp"

#include <QObject>

RenderWorker::RenderWorker(QObject *parent)
    : QObject(parent)
{
}

// -----------------------------------------------------------------------

RenderWorker::~RenderWorker()
{
}

// -----------------------------------------------------------------------

void
RenderWorker::start_render()
{
    emit render_started();
    qDebug("Rendering...");
    emit render_finished();
    qDebug("Rendering Complete...");
}
