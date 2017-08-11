#ifndef QSELECTHEADERVIEW_H
#define QSELECTHEADERVIEW_H

#include <QWidget>
#include <QMenu>
#include <QHeaderView>

class QSelectHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit QSelectHeaderView(Qt::Orientation orientation, QWidget *parent = 0);
    ~QSelectHeaderView();
    void addRightButMenuActions(const QStringList & texts);
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

signals:
    void rightButMenuActionTriggered(QAction *action);
	void hasDoubleClickedColumn(int column);

public slots:

private:
    QMenu *m_RightButMenu;
    bool m_SortEnable;
};

#endif // QSELECTHEADERVIEW_H
