#ifndef MOUSE_QLABEL_H
#define MOUSE_QLABEL_H

#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>

class mouse_QLabel : public QLabel
{

    Q_OBJECT

public:
    mouse_QLabel(QWidget *parent);

    void mousePressEvent(QMouseEvent *ev);

signals:
    void MouseClicked();
};

#endif // MOUSE_QLABEL_H
