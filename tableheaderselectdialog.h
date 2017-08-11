#ifndef TABLEHEADERSELECTDIALOG_H
#define TABLEHEADERSELECTDIALOG_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class TableHeaderSelectDialog;
}

class TableHeaderSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableHeaderSelectDialog(QWidget *parent = 0);
    ~TableHeaderSelectDialog();

    void addCheckBox(QString name, bool checked);
    QList<bool> getCheckedState(void);

private:
    Ui::TableHeaderSelectDialog *ui;
    QList<QCheckBox*> m_CheckBoxnList;
};

#endif // TABLEHEADERSELECTDIALOG_H
