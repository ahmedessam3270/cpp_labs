#include <iostream>

// we try to make inheritance and test the cases that will face us


// BASE class
class Person {
    // private:
    //     int age;
    //     char * name;
    //     float height;
    protected:
        int age;
        char * name;
        float height;
    public:

        Person (): age(18) , name("unknown"), height(1.7f) {
            std::cout << "Person Initialized!"<<std::endl;
        }

        ~Person ()
        {
            std::cout << "Person destroyed!"<<std::endl;
        }

        void getName ()
        {
          std::cout << name <<std::endl;
        }

        void getAge ()
        {
          std::cout << age <<std::endl;
        }

        void getHeight ()
        {
          std::cout << height <<std::endl;
        }
};

// sub class
class Employee : public Person {
    private:
        int salary;
        float workingHours;
    
    public:
        Employee()
        {
            // we can't access the private members of the partent Person
            // I mean by access here is to mutate it directly without APIs
           // age =2; // BUG error 
            //member "Person::age" (declared at line 9) is inaccessibleC/C++(265)int Person::age

            // to over come this we can make it protected

            std::cout << "Employee Initialized" << std::endl;
            salary = 0;
            workingHours = 0;
        }

        ~Employee ()
        {
             std::cout << "Employee destroyed!"<<std::endl;

        }
    
};

// sub sub class
class Manager : public Employee {
    private:
        char * managingDepartment;
        int EmployeesNumbersUnderHisSupervision;
    
    public:
        Manager () {
            std::cout << "Manager Initialized!"<<std::endl;
        }

        ~Manager ()
        {
            std::cout << "Manager destroyed!"<<std::endl;
        }

        void setName( char * mgName)
        {
            name = mgName;
        }

        void getName()
        {
            std::cout << "MR " << name << std::endl;
        }

        void getManagingDepartment ()
        {
            std::cout << managingDepartment<<std::endl;
        }
        void getNumberOfEmployessHeManage ()
        {
            std::cout << EmployeesNumbersUnderHisSupervision<<std::endl;
        }
};

int main ()
{
    Person p1;
    p1.getName();
    p1.getAge();
    p1.getHeight();

    Employee e1;
    e1.getAge();

    Manager m1;
    m1.setName("Ahmed Essam");
    m1.getName();
    m1.getHeight();


    std::cin.get();
}