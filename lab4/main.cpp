#include <iostream>
#include <graphics.h>

using namespace std;



class Shape {
    protected: 
        int color;

    public:
        Shape(int c = CYAN)
        {
            std::cout << "The Shape instance has been created!"<< std::endl;
            color = c;
            setcolor(c);
        }   
        ~Shape ()
        {
            std::cout << "The Shape instance has been destroyed!"<< std::endl;
        } 

        virtual void draw() = 0;

        int getColor() {return color; }  
};

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Line : public Shape
{
private:
    Point start;
    Point end;

public:
    Line() :Shape(RED),  start(), end() {}
    Line(int x1, int y1, int x2, int y2, int c = RED) :Shape(c) , start(x1, y1), end(x2, y2) {}

    void draw() override
    {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rect() : Shape(GREEN), ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2, int c) : Shape(c), ul(x1, y1), lr(x2, y2) {}

    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Text : public Shape
{
private:
    char *value;
    Point position;
    int fontSize;

public:
    Text(char *value, int x, int y,int c = GREEN)
    {
        this->value = value;
        this->fontSize = 12;
        this->position = Point(x, y);
        this->color = c;
    }
    void draw()
    {
        settextstyle(DEFAULT_FONT, 0, this->fontSize);
        outtextxy(this->position.getX(), this->position.getY(), this->value);
        setcolor(color);
    }

    void setFontSize(int fs){
        this->fontSize = fs;
    }
};

class Circle : public Shape
{
private:
    Point center;
    int radius;

public:
    Circle() :Shape(YELLOW) ,center(), radius(0) {}
    Circle(int m, int n, int r, int c = WHITE) :Shape(c), center(m, n), radius(r) {}

    void draw() override
    {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    Shape ** shapes;
    int size;
    int top;

public:
    Picture(int size)  {
        shapes = new Shape*[size];
        this->size = size;
        top = 0;
    }

    void addShape(Shape * s){
        if (top >= size){
            return;
        }
        shapes[top] = s;
        top++;
    }


    void paint()
    {
        for (int i = 0; i < top; i++)
        {
            shapes[i]->draw();
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hola");
    int x, y;

    Picture myPic(10);

    Text * t1 = new Text("Ahmed", 250, 10, CYAN); 
    Text * t2 =  new Text("Essam", 250, 80, LIGHTBLUE);  
    myPic.addShape(t1);
    myPic.addShape(t2);

    Circle * cArr[3] = {
        new Circle(150, 200, 40, GREEN),    // Left circle
        new Circle(300, 200, 40, BLUE),     // Center circle
        new Circle(450, 200, 40, WHITE)     // Right circle
    };

    for (int i = 0; i < 3; i++)
    {
        myPic.addShape(cArr[i]);
    }

    Rect * rArr[2] = {
        new Rect(100, 300, 250, 400, RED),      // Left rectangle
        new Rect(350, 300, 500, 400, MAGENTA)   // Right rectangle
    };

    for (int i = 0; i < 2; i++)
    {
        myPic.addShape(rArr[i]);
    }

    Line * lArr[2] = {
        new Line(100, 450, 300, 450, WHITE),    // Horizontal line
        new Line(400, 450, 600, 450, YELLOW)    // Parallel horizontal line
    };

    for (int i = 0; i < 2; i++)
    {
        myPic.addShape(lArr[i]);
    }


    myPic.paint();
    printf("%c\n", getch());

    return 0;
}