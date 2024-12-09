class GeoShape {

protected:
    float dim1;
    float dim2;

public: 
    GeoShape()
    {
        dim1 = 0 , dim2 = 0;
    }

    GeoShape(float dim)
    {
        dim1= dim ,dim2 = dim;
    }

    GeoShape(float dim1, float dim2)
    {
        this->dim1 = dim1;
        this->dim2 = dim2;
    }

    void set_dim1(float dim1)
    {
        this->dim1 = dim1;
    }
    float get_dim1()
    {
        return dim1;
    }
    void set_dim2(float dim2)
    {
        this->dim2 = dim2;
    }
    float get_dim2()
    {
        return dim2;
    }
    virtual float calculateArea() = 0;
};

class Triangle : public GeoShape
{
    public:
        Triangle(float base, float hieght): GeoShape(base, hieght){}
        float calculateArea(){
            return 0.5 * dim1 * dim2;
        }
};
class Rectangle : public GeoShape
{
    public:
        Rectangle(float width, float height): GeoShape(width, height){}
        float calculateArea(){
            return dim1 * dim2;
        }
};
class Square : private Rectangle
{
    public:
        Square(float length): Rectangle(length, length){}
        float calculateArea(){
            return this->dim1 * this->dim1;
        }
};
class Circle : private GeoShape
{
    public:
        Circle(float radius): GeoShape(radius){}
        float calculateArea(){
            return 22 / 7 * dim1 * dim1;
        }
};