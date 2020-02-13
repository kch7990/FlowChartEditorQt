/******************************************************************
* ���� �̸� : Decision.h
* ��� : �Ǵܱ�ȣ�� ��ũ��Ʈ Ŭ����
* �ۼ��� : ����â
* �ۼ����� : 2015�� 3�� 30��
*******************************************************************/

#ifndef _DECISION_H
#define _DECISION_H

#include "Symbol.h"

class Decision : public Symbol {
public:
	Decision(Long x, Long y, Long width, Long height, QColor backGroundColor,
		QPen borderLine, QColor borderColor, String contents = static_cast<String>(""));
	~Decision();
	Decision(const Decision& source);
	Decision& operator =(const Decision& source);

	virtual bool IsEqual(const Shape& other);
	virtual bool IsNotEqual(const Shape& other);

	virtual bool operator ==(const Shape& other);
	virtual bool operator !=(const Shape& other);

	virtual void Accept(FlowChartVisitor *draw);

	virtual Shape* Clone();

	virtual void GetRegion(Painter *painter, QRegion *region);
	virtual void GetRegion(Painter *painter, Long thickness, QRegion *region);

	virtual bool IsIncluded(Painter *painter, QPoint point);
	virtual bool IsIncluded(Painter *painter, const QRect& rect);

	void GetAttribute(Attribute *attribute);

	virtual void GetLine(char(*line));

	virtual bool Identify(SHAPE identify);
	virtual bool IsStyle(Long style);

	//virtual void DrawSelectionMarkers(Painter* painter, ScrollController *scrollController);
};

inline bool Decision::Identify(SHAPE identify) {
	return (identify == DECISION || identify == SYMBOL) ? (true) : (false);
}

#endif// _DECISION_H