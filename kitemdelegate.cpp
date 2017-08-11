#include "stdafx.h"
#include "kitemdelegate.h"
#include <QtGui>
#include <QDateTimeEdit>
#include <QLineEdit>
#include "KStyledCombobox.h"

//////////////////////////////////////////////////////////////////////////
void KCmbCustomDelegateWidget::SetCumtomData(QVariant v, const QModelIndex &)
{
    if (QComboBox* c = dynamic_cast<QComboBox*>(this))
    {
        c->setCurrentText(v.toString());
    }
}

QVariant KCmbCustomDelegateWidget::GetCumtomData(QAbstractItemModel *, const QModelIndex &)
{
    if (QComboBox* c = dynamic_cast<QComboBox*>(this))
    {
        return c->currentText();
    }
    return QVariant();
}
