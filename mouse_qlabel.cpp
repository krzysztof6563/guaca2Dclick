#include "mouse_qlabel.h"

mouse_QLabel::mouse_QLabel(QWidget* parent) : QLabel(parent)
{

}

void mouse_QLabel::mousePressEvent(QMouseEvent *ev)
{
    emit MouseClicked();
}
