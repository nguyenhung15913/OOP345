/*#include <string>
template<typename A, typename B>
class GeometricObject
{
public:
	GeometricObject();
	GeometricObject(const A& color, B filled);
	A getColor() const;
	void setColor(const A& color);
	B isFilled() const;
	void setFilled(B filled);
	A toString() const;
private:
	A color;
	B filled;
};
template<typename A, typename B>
class Rectangle : public GeometricObject<A, B>
{
public:
	Rectangle();
	Rectangle(double width, double height);
	Rectangle(double width, double height,
		const AS& color, B filled);
	double getWidth() const;
	void setWidth(double);
	double getHeight() const;
	void setHeight(double);
	double getArea() const;
	double getPerimeter() const;
	A toString() const;
private:
	double width;
	double height;
};*/