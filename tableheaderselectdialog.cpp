#include "stdafx.h"
#include "tableheaderselectdialog.h"
#include "ui_tableheaderselectdialog.h"


TableHeaderSelectDialog::TableHeaderSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableHeaderSelectDialog)
{
    ui->setupUi(this);
}

TableHeaderSelectDialog::~TableHeaderSelectDialog()
{
    delete ui;
}

void TableHeaderSelectDialog::addCheckBox(QString name,bool checked)
{
    m_CheckBoxnList.append(new QCheckBox(name, this));
    m_CheckBoxnList.last()->setChecked(checked);
    ui->gridLayout->addWidget(m_CheckBoxnList.last());
}

QList<bool> TableHeaderSelectDialog::getCheckedState()
{
    QList<bool> checked_state;

    foreach (QCheckBox *checkbox, m_CheckBoxnList)
    {
       checked_state.append( checkbox->isChecked());
    }

    return checked_state;
}
