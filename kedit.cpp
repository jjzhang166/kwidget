#include "stdafx.h"
#include "kedit.h"
#include <QPainter>
#include <QStyleOptionFrameV2>

KEdit::KEdit(QWidget *parent) 
	: QLineEdit(parent), 
	m_sSuffixText(""),
	m_nSuffixFixedWidth(0),
	m_nSuffixLeftMargin(4),
	m_nSuffixActualWidth(0),
	m_bSuffixCenterShow(true)
{
	m_oSuffixColor.setRgb(255, 255, 127);
}

/* 
	设置显示后缀 
*/
QString KEdit::suffixText() const
{
    return m_sSuffixText;
}
void KEdit::setSuffixText(const QString& value)
{
	if (m_sSuffixText != value)
	{
		m_sSuffixText = value;
		setTextRightMargin();
	}
}

/* 
	设置后缀固定显示宽度
*/
uint KEdit::suffixFixedWidth() const
{
	return m_nSuffixFixedWidth;
}
uint KEdit::suffixActualWidth() const
{
	return m_nSuffixActualWidth;
}
void KEdit::setSuffixFixedWidth(const uint value)
{
	if (m_nSuffixFixedWidth != value)
	{
		m_nSuffixFixedWidth = value;
		setTextRightMargin();	
	}
}

/* 
	后缀文字左边距
*/
uint KEdit::suffixLeftMargin() const
{
	return m_nSuffixLeftMargin;
}
void KEdit::setsuffixLeftMargin(const uint value)
{
	if (m_nSuffixLeftMargin != value)
	{
		m_nSuffixLeftMargin = value;
		setTextRightMargin();
	}
}

/* 
	后缀居中显示 
*/
bool KEdit::suffixCenterShow() const
{
	return m_bSuffixCenterShow;
}
void KEdit::setSuffixCenterShow(const bool value)
{
	if (m_bSuffixCenterShow != value)
	{
		m_bSuffixCenterShow = value;
		setTextRightMargin();
	}
}

/* 
	后缀背景颜色
*/
QColor KEdit::suffixColor() const
{
	return m_oSuffixColor;
}
void KEdit::setSuffixColor(const QColor& value)
{
	m_oSuffixColor = value;
	update();
}

/* 
	设置文本右边距
*/
void KEdit::setTextRightMargin()
{
	m_nSuffixActualWidth = calcSuffixWidth();

	QMargins mg = textMargins();
	mg.setRight(mg.left() + m_nSuffixActualWidth);
	setTextMargins(mg);
	update();
}

/* 
	根据m_sSuffixText计算显示宽度 
*/
uint KEdit::calcSuffixWidth()
{
	uint nWidth = 0;
	if (m_nSuffixFixedWidth)
	{
		nWidth = m_nSuffixFixedWidth;
	}
	else if (!m_sSuffixText.isEmpty())
	{
		// 根据m_sSuffixText计算显示宽度
		nWidth = fontMetrics().width(m_sSuffixText) + m_nSuffixLeftMargin;
		if (m_bSuffixCenterShow)
		{
			nWidth += m_nSuffixLeftMargin;
		}
	}
	return nWidth;
}

bool KEdit::event(QEvent * evt)
{
	if (evt->type() == QEvent::FontChange)
	{
		setTextRightMargin();
	}
	return QWidget::event(evt);
}

void KEdit::paintEvent(QPaintEvent* event)
{
	// 调用父类绘制过程绘制
	QLineEdit::paintEvent(event);

	if (!m_nSuffixActualWidth) return;

	// 绘制后缀信息
	QPainter painter(this);
	QPalette pal = palette();

	// 计算后缀绘制区域	
	QStyleOptionFrameV2 opt;
	opt.initFrom(this);
	opt.rect = contentsRect();
	opt.lineWidth = hasFrame() ? style()->pixelMetric(QStyle::PM_DefaultFrameWidth, &opt, this) : 0;
	QRect rt = style()->subElementRect(QStyle::SE_LineEditContents, &opt, this);
	rt.setLeft(rt.right() - m_nSuffixActualWidth);

	// 绘制后缀背景
	painter.fillRect(rt, m_oSuffixColor);

	// 竖直居中
	QFontMetrics fm = fontMetrics();
	rt.setTop(rt.top() + (rt.height() - fm.height()) / 2);

	// 水平居中
	if (m_bSuffixCenterShow)
	{
		uint nTextWidth = fm.width(m_sSuffixText) + 1;
		uint nDrawWidth = m_nSuffixActualWidth - m_nSuffixLeftMargin * 2;
		if (nTextWidth >= nDrawWidth)
		{
			rt.adjust(m_nSuffixLeftMargin, 0, -(int)m_nSuffixLeftMargin, 0);
		}
		else
		{
			int nOffset = m_nSuffixLeftMargin + (nDrawWidth - nTextWidth) / 2;
			rt.adjust(nOffset, 0, -nOffset, 0);
		}
	}
	else
	{
		rt.setLeft(rt.left() + m_nSuffixLeftMargin);
	}

	// 绘制后缀
	QString sDrawText = fm.elidedText(m_sSuffixText, Qt::ElideRight, rt.width());
	painter.drawText(rt, Qt::TextSingleLine, sDrawText);
}
