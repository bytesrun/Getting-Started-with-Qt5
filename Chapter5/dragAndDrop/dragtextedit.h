#ifndef DRAGTEXTEDIT_H
#define DRAGTEXTEDIT_H
#include <QTextEdit>
#include <QMoveEvent>
#include <QMouseEvent>
#include <QMimeData>
#include <QMimeDatabase>
#include <QMimeType>

class DragTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit DragTextEdit(QWidget *parent = nullptr);
protected:
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dragMoveEvent(QDragMoveEvent *e) override;
    void dragLeaveEvent(QDragLeaveEvent *e) override;
    void dropEvent(QDropEvent *e) override;
};

#endif // DRAGTEXTEDIT_H
