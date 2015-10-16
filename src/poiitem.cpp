#include <QPainter>
#include "config.h"
#include "poiitem.h"

#include <QDebug>

#define POINT_SIZE  8


POIItem::POIItem(const QString &text, QGraphicsItem *parent)
  : QGraphicsItem(parent)
{
	_text = text;
	updateBoundingRect();
}

void POIItem::updateBoundingRect()
{
	QFont font;
	font.setPixelSize(FONT_SIZE);
	font.setFamily(FONT_FAMILY);
	QFontMetrics fm(font);
	QRect ts = fm.tightBoundingRect(_text);

	_boundingRect = QRectF(0, 0, ts.width() + POINT_SIZE,
	  ts.height() + fm.descent() + POINT_SIZE);
}

void POIItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	  QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	QFont font;
	font.setPixelSize(FONT_SIZE);
	font.setFamily(FONT_FAMILY);
	QFontMetrics fm(font);
	QRect ts = fm.tightBoundingRect(_text);

	painter->setFont(font);
	painter->drawText(POINT_SIZE - qMax(ts.x(), 0), POINT_SIZE + ts.height(),
	  _text);
	painter->setBrush(Qt::SolidPattern);
	painter->drawEllipse(0, 0, POINT_SIZE, POINT_SIZE);

/*
	painter->setPen(Qt::red);
	painter->setBrush(Qt::NoBrush);
	painter->drawRect(boundingRect());
*/
}
