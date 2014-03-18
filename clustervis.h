#ifndef CLUSTERVIS_H
#define CLUSTERVIS_H

#include "timelinevis.h"

class ClusterVis : public TimelineVis
{
    Q_OBJECT
public:
    ClusterVis(QWidget* parent = 0, VisOptions *_options = new VisOptions());
    ~ClusterVis() {}
    void setTrace(Trace * t);

    void mouseMoveEvent(QMouseEvent * event);
    void wheelEvent(QWheelEvent * event);

signals:
    void focusGnome(Gnome * gnome);

public slots:
    void setSteps(float start, float stop, bool jump = false);

protected:
    void qtPaint(QPainter *painter);
    void drawNativeGL();
    void paintEvents(QPainter *painter);
    void prepaint();
    //void drawLine(QPainter * painter, QPointF * p1, QPointF * p2, int effectiveHeight);
    //void setupMetric();
    void mouseDoubleClickEvent(QMouseEvent * event);

    QMap<Gnome *, QRect> drawnGnomes;

};

#endif // CLUSTERVIS_H
