#ifndef kitemdelegate_h__
#define kitemdelegate_h__

#include <functional>
#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QComboBox>



//////////////////////////////////////////////////////////////////////////
// 自定义的
class  ICustomDelegateWidget
{
public:
    virtual void SetCumtomData(QVariant v, const QModelIndex &index) = 0;
    virtual QVariant GetCumtomData(QAbstractItemModel *model, const QModelIndex &index) = 0;
};

class KCmbCustomDelegateWidget : public ICustomDelegateWidget
{
public:
    virtual void SetCumtomData(QVariant v, const QModelIndex &index);

    virtual QVariant GetCumtomData(QAbstractItemModel *model, const QModelIndex &index);
};


#endif // kitemdelegate_h__
