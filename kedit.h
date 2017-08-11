#ifndef KEDIT_H
#define KEDIT_H

#include <QEvent>
#include <QLineEdit>


class KEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit KEdit(QWidget *parent = 0);

	/* 后缀 */
    QString suffixText() const;
    void setSuffixText(const QString& value);

	/* 后缀宽度 */
	uint suffixFixedWidth() const;
	uint suffixActualWidth() const;
	void setSuffixFixedWidth(const uint value);

	/* 后缀文字左边距 */
	uint suffixLeftMargin() const;
	void setsuffixLeftMargin(const uint value);

	/* 后缀居中显示 */
	bool suffixCenterShow() const;
	void setSuffixCenterShow(const bool value);

	/* 后缀背景颜色 */
	QColor suffixColor() const;
	void setSuffixColor(const QColor& value);

protected:
	bool event(QEvent * evt);
    void paintEvent(QPaintEvent* event);

	/* 根据m_sSuffixText计算显示宽度 */
	virtual uint calcSuffixWidth();

	/* 设置文本右边距 */
	virtual void setTextRightMargin();
signals:

public slots:

private:
	QString m_sSuffixText;
	bool m_bSuffixCenterShow;
	uint m_nSuffixFixedWidth;
	uint m_nSuffixLeftMargin;
	uint m_nSuffixActualWidth;
	QColor m_oSuffixColor;
};

#endif // TESTEDIT_H
