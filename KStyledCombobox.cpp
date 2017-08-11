#include "stdafx.h"
#include "KStyledCombobox.h"

#include <QAbstractItemView>
#include <QStyledItemDelegate>

static QStyledItemDelegate    s_delegater_(nullptr);// = nullptr;

KStyledCombobox::KStyledCombobox(QWidget *parent)
    : QComboBox(parent)
{
    QComboBox::view()->setItemDelegate(&s_delegater_);
}

KStyledCombobox::~KStyledCombobox()
{
}

void KStyledCombobox::setModel(QAbstractItemModel *model)
{
    QComboBox::setModel(model);
}
