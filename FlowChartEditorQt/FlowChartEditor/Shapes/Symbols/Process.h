/******************************************************************
* 파일 이름 : Proess.h
* 기능 : 처리기호의 콘크리트 클래스
* 작성자 : 송윤창
* 작성일자 : 2015년 3월 30일 
*******************************************************************/

#ifndef _PROCESS_H
#define _PROCESS_H

#include "Symbol.h"

class Process : public Symbol{
public:
	Process(float x, float y, float width, float height,
		QColor backGroundColor = QColor(255, 255, 255), Qt::PenStyle borderLine = Qt::SolidLine,
		QColor borderColor = QColor(0, 0, 0), String contents = static_cast<String>(""));
	~Process();
	Process(const Process& source);
	Process& operator =(const Process& source);

	virtual bool IsEqual(const NShape& other);
	virtual bool IsNotEqual(const NShape& other);

	virtual bool operator ==(const NShape& other);
	virtual bool operator !=(const NShape& other);

	virtual void Accept( FlowChartVisitor *draw);

	virtual NShape* Clone();

	virtual QRegion GetRegion();
	virtual QRegion GetRegion(Long thickness);

	virtual bool IsIncluded(QPointF point);
	virtual bool IsIncluded(const QRectF& rect);

	void GetAttribute(Attribute *attribute);

	virtual void GetLine(char (*line));

	virtual bool Identify( SHAPE identify );
	virtual bool IsStyle(Long style);

	virtual void DrawSelectionMarkers(GObject *painter, ScrollController *scrollController);
};

inline bool Process::Identify( SHAPE identify ){
	return ( identify == SYMBOL || identify == PROCESS )?( true ):( false );
}

#endif// _PROCESS_H