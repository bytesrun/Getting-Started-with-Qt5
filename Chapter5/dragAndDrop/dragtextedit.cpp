#include "dragtextedit.h"
#include <QDebug>
DragTextEdit::DragTextEdit(QWidget* parent) : QTextEdit(parent)
{
    setAcceptDrops(true);
}

void DragTextEdit::dragMoveEvent(QDragMoveEvent *e)
{
    e->acceptProposedAction();
}

void DragTextEdit::dragLeaveEvent(QDragLeaveEvent *e)
{
    e->accept();
}

void DragTextEdit::dragEnterEvent(QDragEnterEvent *e)
{
    e->acceptProposedAction();
}

void DragTextEdit::dropEvent(QDropEvent *e)
{
    const QMimeData *mimeData = e->mimeData();
    if (mimeData->hasText())
    {
        QTextStream out(stdout);
        qDebug() << "Path: " << mimeData->urls().at(0).path().mid(1);
        QFile file(mimeData->urls().at(0).path().mid(1));
        file.open(QFile::ReadOnly | QFile::Text);
        QString contents = file.readAll();
        setText(contents);
        //e->acceptProposedAction();
        return;
    }
    else
    {
        e->ignore();
    }
}
