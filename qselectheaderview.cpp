#include "stdafx.h"
#include "qselectheaderview.h"
#include <QMouseEvent>

QSelectHeaderView::QSelectHeaderView(Qt::Orientation orientation, QWidget *parent)
  :QHeaderView(orientation, parent)
  , m_RightButMenu(new QMenu(this))
  , m_SortEnable(false)
{
	this->setSectionsMovable(true);
    connect(m_RightButMenu, &QMenu::triggered,
        this, &QSelectHeaderView::rightButMenuActionTriggered);
}

QSelectHeaderView::~QSelectHeaderView()
{
    delete m_RightButMenu;
}

void QSelectHeaderView::addRightButMenuActions(const QStringList & texts)
{
    foreach(QString text,texts)
    {
        m_RightButMenu->addAction(text);
    }
}

void QSelectHeaderView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        m_RightButMenu->move(event->globalPos());
        m_RightButMenu->show();
    }

    else if(event->button() == Qt::LeftButton)
    {
        if(m_SortEnable)
        {
            if(this->sortIndicatorOrder() == Qt::AscendingOrder)
            {
                this->setSortIndicator(this->logicalIndexAt(event->pos()),Qt::DescendingOrder);
            }
            else
            {
                this->setSortIndicator(this->logicalIndexAt(event->pos()),Qt::AscendingOrder);
            }
        }
    }
    QHeaderView::mousePressEvent(event);
}

void QSelectHeaderView::mouseDoubleClickEvent(QMouseEvent *event)
{
	emit hasDoubleClickedColumn(this->logicalIndexAt(event->pos()));
    m_SortEnable = !m_SortEnable;
    if(m_SortEnable)
    {
        this->setSortIndicatorShown(true);
        this->setSortIndicator(this->logicalIndexAt(event->pos()),Qt::DescendingOrder);
    }
    else
    {
        this->setSortIndicatorShown(false);
    }
    QHeaderView::mouseDoubleClickEvent(event);
}

