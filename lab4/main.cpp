#include <iostream>
#include <graphics.h>

using namespace std;

// Base Shape class
class Shape {
protected:
    int color;
public:
    Shape(int c = WHITE) : color(c) {
        setcolor(color);
    }
    virtual void draw() = 0;  // Pure virtual function
    
    void setShapeColor(int c) {
        color = c;
        setcolor(color);
    }
    
    int getColor() const { return color; }
};

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}
    
    int getX() const { return x; }
    int getY() const { return y; }
};

class Line : public Shape {
private:
    Point start;
    Point end;

public:
    Line() : Shape(BLUE), start(), end() {}
    Line(int x1, int y1, int x2, int y2, int c = BLUE) 
        : Shape(c), start(x1, y1), end(x2, y2) {}

    void draw() override {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect : public Shape {
private:
    Point ul;
    Point lr;
public:
    Rect() : Shape(RED), ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2, int c = RED) 
        : Shape(c), ul(x1, y1), lr(x2, y2) {}

    void draw() override {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Text : public Shape {
private:
    char* value;
    Point position;
    int fontSize;

public:
    Text(char* value, int x, int y, int c = GREEN) 
        : Shape(c), position(x, y), fontSize(12) {
        this->value = value;
    }
    
    void draw() override {
        setcolor(color);
        settextstyle(DEFAULT_FONT, 0, fontSize);
        outtextxy(position.getX(), position.getY(), value);
    }

    void setFontSize(int fs) {
        fontSize = fs;
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius;

public:
    Circle() : Shape(YELLOW), center(), radius(0) {}
    Circle(int m, int n, int r, int c = YELLOW) 
        : Shape(c), center(m, n), radius(r) {}

    void draw() override {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture {
private:
    int cNum, rNum, lNum, tNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;
    Text* texts;

public:
    Picture() : cNum(0), rNum(0), lNum(0), tNum(0),
                pCircles(nullptr), pRects(nullptr), 
                pLines(nullptr), texts(nullptr) {}

    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }

    void setTexts(int tn, Text* pT) {
        tNum = tn;
        texts = pT;
    }

    void paint() {
        // Draw each type of shape with its color
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
        for (int i = 0; i < tNum; i++) {
            texts[i].draw();
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Picture myPic;

    // Create shapes with different colors
    Text t1 = Text("Hello", 30, 30, GREEN);
    Text t2 = Text("World", 30, 120, LIGHTGREEN);
    t1.setFontSize(5);
    t2.setFontSize(5);

    Circle cArr[3] = {
        Circle(50, 50, 50, YELLOW),
        Circle(200, 100, 100, LIGHTRED),
        Circle(420, 50, 30, LIGHTCYAN)
    };

    Rect rArr[2] = {
        Rect(30, 40, 170, 100, RED),
        Rect(420, 50, 500, 300, LIGHTRED)
    };

    Line lArr[2] = {
        Line(420, 50, 300, 300, BLUE),
        Line(40, 500, 500, 400, LIGHTBLUE)
    };

    Text tArr[2] = {t1, t2};

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);
    myPic.setTexts(2, tArr);

    myPic.paint();
    
    getch();
    closegraph();
    return 0;
}