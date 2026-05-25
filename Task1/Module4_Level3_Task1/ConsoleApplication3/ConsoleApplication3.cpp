

#include <iostream>
#include <vector>

using namespace std;

// Абстрактний базовий клас
class Shape
{
protected:
    double x, y;
    double angle;
    double scale;

public:
    Shape(double startX, double startY)
    {
        x = startX;
        y = startY;
        angle = 0.0;
        scale = 1.0;
    }

    virtual ~Shape() {}


    virtual void funcDraw() = 0;
    virtual void funcHide() = 0;

    void funcRotate(double newAngle)
    {
        angle += newAngle;
        cout << "Rotated by " << newAngle << "Current angle " << angle << endl;
    }

    void funcMove(double dx, double dy)
    {
        x += dx;
        y += dy;
        cout << "Moved to new center " << x << ", " << y << endl;
    }
};

//Трикутник
class Triangle : public Shape 
{
public:
    Triangle(double startX, double startY) : Shape(startX, startY) {}

    void funcDraw() override 
    {
        cout << "Drawn at center " << x << ", " << y << " with scale " << scale << endl;
    }

    void funcHide() override
    {
        cout << " Hidden from screen." << endl;
    }
};

//Чотирикутник
class Quad : public Shape
{
public:
    Quad(double startX, double startY) : Shape(startX, startY) {}

    void funcDraw() override 
    {
        cout << " Drawn at center " << x << ", " << y << " with scale " << scale << endl;
    }

    void funcHide() override 
    {
        cout << "Hidden from screen" << endl;
    }
};

//Многокутник
class Polygon : public Shape
{
public:
    Polygon(double startX, double startY) : Shape(startX, startY) {}

    void funcDraw() override 
    {
        cout << " Drawn at center " << x << ", " << y << " with scale " << scale << endl;
    }

    void funcHide() override 
    {
        cout << " Hidden from screen." << endl;
    }
};


int main()
{
    Shape* shapes[3];

    shapes[0] = new Triangle(10.0, 20.0);
    shapes[1] = new Quad(30.0, 40.0);
    shapes[2] = new Polygon(50.0, 60.0);

    for (int i = 0; i < 3; i++) 
    {
        shapes[i]->funcDraw();
    }

    shapes[0]->funcMove(5.0, -5.0);
    shapes[1]->funcRotate(45.0);
    shapes[2]->funcHide();

    for (int i = 0; i < 3; i++) 
    {
        delete shapes[i];
    }

    return 0;
}