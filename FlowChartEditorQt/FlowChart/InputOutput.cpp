// InputOutput.cpp

/******************************************************************
* ���� �̸� : InputOutput.cpp
* ��� : �Է���±�ȣ�� ��ũ��Ʈ Ŭ����
* �ۼ��� : ����â
* �ۼ����� : 2016�� 2�� 22��
*******************************************************************/

#include "InputOutput.h"
#include "Painter.h"
#include "FlowChartVisitor.h"

#pragma warning (disable : 4996)

InputOutput::InputOutput(Long x, Long y, Long width, Long height, QColor backGroundColor,
	QPen borderLine, QColor borderColor, String contents)
	: Symbol(x, y, width, height, backGroundColor, borderLine, borderColor, contents) {

}

InputOutput::~InputOutput() {

}

InputOutput::InputOutput(const InputOutput& source) 
	: Symbol(source) {

}

InputOutput& InputOutput::operator=(const InputOutput& source) {
	Symbol::operator=(source);

	return *this;
}

bool InputOutput::IsEqual(const Shape& other) {
	bool retVo = false;
	if (dynamic_cast<InputOutput *>(const_cast<Shape *>(&other))) {
		retVo = Shape::IsEqual(other);
	}
	return retVo;
}

bool InputOutput::IsNotEqual(const Shape& other) {
	bool retVo = false;
	if (!dynamic_cast<InputOutput *>(const_cast<Shape*>(&other))) {
		retVo = Shape::IsNotEqual(other);
	}
	return retVo;
}

bool InputOutput::operator ==(const Shape& other) {
	bool retVo = false;
	if (dynamic_cast<InputOutput *>(const_cast<Shape *>(&other))) {
		retVo = Shape::IsEqual(other);
	}
	return retVo;
}

bool InputOutput::operator !=(const Shape& other) {
	bool retVo = false;
	if (!dynamic_cast<InputOutput *>(const_cast<Shape*>(&other))) {
		retVo = Shape::IsNotEqual(other);
	}
	return retVo;
}

void InputOutput::Accept(FlowChartVisitor *draw) {
	draw->Visit(this);
}

Shape* InputOutput::Clone() {
	return new InputOutput(*this);
}

void InputOutput::GetRegion(Painter *painter, QRegion *region) {
	Long halfWidth = (Long)this->width / 2;
	Long halfHeight = (Long)this->height / 2;

	QVector<QPoint> points(5);
	points.append(QPoint(this->x + halfHeight, this->y));
	points.append(QPoint(this->x + this->width, this->y));
	points.append(QPoint(this->x + this->width - halfHeight, this->y + this->height));
	points.append(QPoint(this->x, this->y + this->height));
	points.append(QPoint(this->x + halfHeight, this->y));
	QPolygon polygon(points);
	
	*region += QRegion(polygon);
}

void InputOutput::GetRegion(Painter *painter, Long thickness, QRegion *region) {
	Long x = this->x - thickness;
	Long y = this->y - thickness;
	Long width = this->width + thickness * 2;
	Long height = this->height + thickness * 2;
	Long halfWidth = this->width / 2;
	Long halfHeight = this->height / 2;

	QVector<QPoint> points(5);
	points.append(QPoint(this->x + halfHeight, this->y));
	points.append(QPoint(this->x + this->width, this->y));
	points.append(QPoint(this->x + this->width - halfHeight, this->y + this->height));
	points.append(QPoint(this->x, this->y + this->height));
	points.append(QPoint(this->x + halfHeight, this->y));
	QPolygon polygon(points);

	*region += QRegion(polygon);
}

bool InputOutput::IsIncluded(Painter *painter, QPoint point) {
	bool ret;
	Long halfWidth = (Long)this->width / 2;
	Long halfHeight = (Long)this->height / 2;

	QVector<QPoint> points(5);
	points.append(QPoint(this->x + halfHeight, this->y));
	points.append(QPoint(this->x + this->width, this->y));
	points.append(QPoint(this->x + this->width - halfHeight, this->y + this->height));
	points.append(QPoint(this->x, this->y + this->height));
	points.append(QPoint(this->x + halfHeight, this->y));
	QPolygon polygon(points);

	QRegion region(polygon);
	ret = region.contains(point);

	return ret;
}

bool InputOutput::IsIncluded(Painter *painter, const QRect& rect) {
	bool ret;
	Long halfWidth = (Long)this->width / 2;
	Long halfHeight = (Long)this->height / 2;

	QVector<QPoint> points(5);
	points.append(QPoint(this->x + halfHeight, this->y));
	points.append(QPoint(this->x + this->width, this->y));
	points.append(QPoint(this->x + this->width - halfHeight, this->y + this->height));
	points.append(QPoint(this->x, this->y + this->height));
	points.append(QPoint(this->x + halfHeight, this->y));
	QPolygon polygon(points);

	QRegion region(polygon);
	ret = region.contains(rect);

	return ret;
}

void InputOutput::GetAttribute(Attribute *attribute) {
	attribute->vertexIn = 'Y';
	attribute->vertexOut = 'Y';

	attribute->pointIn.setX(this->x + this->width / 2);
	attribute->pointIn.setY(this->y);

	attribute->pointOut.setX(this->x + this->width / 2);
	attribute->pointOut.setY(this->y + this->height);
}

void InputOutput::GetLine(char(*line)) {
	String saveContents(this->contents);
	saveContents.Replace('\n', '\r');

	sprintf(line, "%d\t%d\t%d\t%d\t%d\t\t\t%s\n", ID_INPUTOUTPUT, this->x, this->y, this->width, this->height, saveContents);
}

bool InputOutput::IsStyle(Long style) {
	bool ret = false;
	if (Shape::IsStyle(style) || Symbol::IsStyle(style) || (style >> 8) % 2) {
		ret = true;
	}
	return ret;
}
/*
void InputOutput::DrawSelectionMarkers(Painter* painter, ScrollController *scrollController) {
	Shape::DrawSelectionMarkers(painter, scrollController);
}
*/