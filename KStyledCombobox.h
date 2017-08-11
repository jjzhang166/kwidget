#ifndef QSTYLEDCOMBOBOX_H
#define QSTYLEDCOMBOBOX_H

#include <QComboBox>
#include "kitemdelegate.h"

/**
 *		
 *  用于能够适应QSS的Combobox下拉列表
 *
**/
class QStyledItemDelegate;
class KStyledCombobox : 
    public QComboBox,
    public KCmbCustomDelegateWidget
{
    Q_OBJECT

public:
    KStyledCombobox(QWidget *parent);
    ~KStyledCombobox();

    void setModel(QAbstractItemModel *model);

};

#endif // QSTYLEDCOMBOBOX_H
