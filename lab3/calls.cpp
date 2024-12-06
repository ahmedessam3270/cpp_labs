#include <iostream>
using namespace std;



class Stack{
private:
    int top;
    int n;
    int *arr;
    static int counter;

public:
    Stack(int arr_size=10){
        top = -1;
        this->n = arr_size;
        arr = new int[n];
        counter++;
        cout<<"creating stack object number: " <<counter<<endl;
    }
    ~Stack(){
    delete []arr;
    cout<<"deleting stack object number: " << counter<<endl;
    counter--;
    }

    //copy constructor
    Stack(const Stack &source){ 
    this->top = source.top;
    this->n = source.n;
    this->arr = new int[n];
    for(int i =0; i < n ; i++){
        this->arr[i] = source.arr[i];
    }
    cout<<"Copy Constructor called"<<endl;

    }

    int push(int val){
        if(top == n){ //Stack is full.
            return 0;
        }
        top++;
        arr[top] = val;
        return 1;
    }

    int pop(int & popped){
        if(top == -1){
            return 0;
        }
        top--;
        popped = arr[top];
        return 1;
    }

    int getTop(){
        return top;
    }

    int * getArr(){
        return arr;
    }

    void displayStack(){
        if(top == -1){
         cout<<"Stack is empty"<<endl;
        }
        else{
        for(int i=0; i <= top; i++){
            cout<<arr[i]<<endl;
        }
        }
    }




};

void viewContent_ref(Stack &s){
        int top = s.getTop();
        int * arr = s.getArr();
        if(top == -1){
         cout<<"Stack is empty"<<endl;
        }
        else{
        for(int i=0; i <= top; i++){
            cout<<arr[i]<<endl;
        }
        }
}

void viewContent_val(Stack s){
        int top = s.getTop();
        int * arr = s.getArr();
        if(top == -1){
         cout<<"Stack is empty"<<endl;
        }
        else{
        for(int i=0; i <= top; i++){
            cout<<arr[i]<<endl;
        }
        }
}

// initializing the static member
int Stack::counter =0;

int main()
{
    Stack s1;
    int data;
    s1.push(5);
    s1.push(3);
    s1.push(2);
    s1.push(10);
    int *arr = s1.getArr();

    /* for(int i = 0; i <= s1.getTop(); i++){
        cout<<arr[i]<<endl;
    }*/
    //Stack s2(s1); //copying s1 into s2

    viewContent_ref(s1); //pass by reference, no new object is created.
    //viewContent_val(s1); //pass by value, bitwise copying if no copy constructor.


//assuming no existing copy constructor, this will be garbage values because arr is now a dangling pointer.
//in this the case of a valid copy constructor, this will still print the values of the new array.
//with pass by reference,only the alias will be deleted and not the actual object's contents. So it will print correctly.
    for(int i = 0; i <= s1.getTop(); i++){
        cout<<arr[i]<<endl;
    }
    //s.pop(data);
    //s.pop(data);
    //viewContent_ref(s);
    //viewContent_ref(s);

    return 0;
}