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
    int cNum, rNum, lNum, tNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
    Text *texts;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect *pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line *pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void setTexts(int tn, Text *pT)
    {
        tNum = tn;
        this->texts = pT;
    }

    void paint()
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }

        for (int i = 0; i < this->tNum; i++)
        {
            texts[i].draw();
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hola");
    int x, y;

    Picture myPic;


    // Center text in the top portion
Text t1 = Text("Ahmed", 250, 30, CYAN);          // Centered horizontally, near top
Text t2 = Text("Essam", 250, 80, LIGHTBLUE);     // Below first text
t1.setFontSize(5);
t2.setFontSize(5);

// Create a structured arrangement of shapes
Circle cArr[3] = {
    Circle(150, 200, 40, GREEN),    // Left circle
    Circle(300, 200, 40, BLUE),     // Center circle
    Circle(450, 200, 40, WHITE)     // Right circle
};

Rect rArr[2] = {
    Rect(100, 300, 250, 400, RED),      // Left rectangle
    Rect(350, 300, 500, 400, MAGENTA)   // Right rectangle
};

Line lArr[2] = {
    Line(100, 450, 300, 450, WHITE),    // Horizontal line
    Line(400, 450, 600, 450, YELLOW)    // Parallel horizontal line
};

Text tArr[2] = {t1, t2};

myPic.setCircles(3, cArr);
myPic.setRects(2, rArr);
myPic.setLines(2, lArr);
myPic.setTexts(2, tArr);


    myPic.paint();
    printf("%c\n", getch());

    return 0;
}