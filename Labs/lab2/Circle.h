class Circle
{
private:
	int X;
	int Y;
	double radius;

public:
	Circle();
	Circle(int x, int y, double r);
	void move(int horiz, int vert);
	void setRadius(double r);
	int getX() const;
	int getY() const;
	double getRadius() const;
	double getArea() const;
	void displayCircle() const;
	bool intersect(Circle c);
};