// Operator overloading code
//  defination : when a single opeartor is overloaded with different jobs it is called opeartor overloading
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class comple
{
private:
    int a, b;

public:
    void setvalue(int x, int y)
    {
        a = x;
        b = y;
    }
    void show_value()
    {
        cout << a << "+" << b << "i";
    }
    comple operator+(comple c2) // here we can see that + is used as a function name and to use the predefine keyword as an function name we have to use operator word here
    {
        comple temp;
        temp.a = a + c2.a;
        temp.b = b + c2.b;
        return temp;
    }
};
int main()
{
    comple c1, c2, c3;
    c1.setvalue(3, 4);
    c2.setvalue(4, 5);
    c3 = c1 + c2;
    c3.show_value();
    return 0;
}

// Friend function
// friend function are not a member of the class it is declared in the class but is defined outside the class
// friend function cannot directly access the members of the class and it has no caller object
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class comple
{

private:
    int a, b;

public:
    void set_data(int x, int y)
    {
        a = x;
        b = y;
    }
    void get_data()
    {
        cout << a << " " << b << endl;
    }
    friend void fun(comple);
};
void fun(comple c)
{
    cout << c.a << " " << c.b << endl;
}
int main()
{
    comple c1;
    c1.set_data(3, 4);
    fun(c1);

    return 0;
}

// Benefit of friend function
// One important point is we can made friend function and declare it anywhere in public or private because it is not a memberof the class so kya farak padega
// Important use of friend function is shown below where we can see that the fun member function can be accesible by both the classes but if we have created a non friend function than they are accesible by the class only in which they are declared;
// Friend function is using more than one private members of the classes at a time;
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class B; // forward decleration
class A
{
private:
    int a;

public:
    void set_data(int x)
    {
        a = x;
    }
    friend void fun(A, B);
};
class B
{
private:
    int b;

public:
    void set_data(int x)
    {
        b = x;
    }
    friend void fun(A, B);
};
void fun(A a1, B b1)
{
    cout << "Sum of this terms are" << a1.a + b1.b;
}
int main()
{
    A obj1;
    B obj2;
    obj1.set_data(3);
    obj2.set_data(4);
    fun(obj1, obj2);

    return 0;
}

// Operator overloading using friend function
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class comple
{
private:
    int a, b;

public:
    void set_data(int x, int y)
    {
        a = x;
        b = y;
    }
    void get_data()
    {
        cout << a << " " << b << endl;
    }
    friend comple opeartor + (comple, comple);
};
comple operator+(comple c1, comple c2)
{
    comple temp;
    temp.a = c1.a + c2.a;
    temp.b = c1.b + c2.b;
    return temp;
}
int main()
{
    comple c1, c2, c3;
    c1.set_data(3, 4);
    c2.set_data(4, 5);
    c3 = c1 + c2; // c3=operator +(c1,c2);

    return 0;
}

// Using function declared in a class as a friend function in different class
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class A
{
public:
    void fun() {}
    void foo() {}
};
class B
{
    friend class A; // if we want every member of class A
    friend void A::fun();
} int main()
{

    return 0;
}

// Availability and Accesibility
// It means that when we create a class which contains both public and private members so when the class is created no memory is allocated to this class but when the object is created memory is allocated to the class with both public and private members so we can say that we have the availability of both public and private members but we have the accesibility of only the public members of the class in the main function

// Inheritence
// With the different visibility modes
// If we are inheriting from the parent class through private access modifier than all the protected and public members of the parent class is accesible in the child class private part,if through protected class than all the member of the protected class and public class are present in the protected class and for public mode all the members of the protected mode are present in the protected mode and public in the public mode;

// Is-a relationship stablishment example bannana is a fruit,sports-car is a vehicle
// where their is Is-a relationship than we have to inherit the parent class through private members only
// Take the example of gear shift in car which is a member of parent class if it is not publicly inherited in the child class sports-car then we can't shift the gear in the main function directly.

// Where we can use protected and private mode of inheritence
// We can use that in making a stack in the parent class we have made a function called insert(position,value) which from the child class is sent value and postion as top but if we made them publicly inherited than the user can randomly insert and value at any position in the stack which will be incorrect.

// Inheritence ke case mai constructore ke chalne ka order hota hai from parent to child and call hone ka order hota hai from child to parent

// this keyword is a special pointer in c++ which is used as a current instance object pointer inside a member function ,it helps to overcome ambiguity when the parameters passed to the member function variable has the same name as the class members so this.a this tye of terminologies is used in context of this

// Function overloading and function overridding and function hiding
// Function overriding is a feature in C++ that allows a derived class to provide a specific implementation of a member function that is already defined in its base class. When a member function in the derived class has the same name, return type, and parameters as the one in the base class, it overrides the base class function, and the derived class version of the function will be called when the function is invoked through a pointer or reference to the base class. example of car and sportscar when sportscar want to shift gear in some different way than that of normal car
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class A
{
public:
    void f1();
    void f2();
};
class B : public A
{
public:
    void f1();   // function overridding when derived class has the same name,return type and parameters of the function as the base class
    void f2(int) // Method hiding is a situation in which the member function in the derived class has the same name as that of a member function in the base class but the signature is different. So their arises a conflict and error message is shown
};
int main()
{

    return 0;
}

// Parent class object pointer can contain the address of object of the derived class
// Virtual Function:In C++ object-oriented programming, a virtual function is a member function declared in the base class with the keyword virtual. It allows dynamic dispatch (late binding) of the function call based on the actual (runtime) type of the object, rather than the static (compile-time) type of the pointer or reference used to call the function. Virtual functions enable runtime polymorphism, making it possible to achieve different behavior for derived classes while working with objects through a common base class interface.
//  Virtual function :Early binding and late bindig concept are here
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class A
{
public:
    void f1();
};
class B : public A
{
public:
    void f1();
    void f2();
};
int main()
{
    A *p, obj1;
    B obj2;
    p = &obj2;
    p->f1(); // It will call class a function f1() because of early binding because it will early bind based on the type of p (beacuse it is done during the complie time)rather than assigning it to the class B object ie obj2 that is why it is the demerit of overiding ;

    return 0;
}

// To overcome early binding we have to do late binding wit the use of virtual keyword
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class A
{
public:
    virtual void f1(); // This will help in late binding which is done during runtime and therfore the f1 function inside class B will be called
};
class B : public A
{
public:
    void f1();
    void f2();
};
int main()
{
    A *p, obj1;
    B obj2;
    p = &obj2;
    p->f1();
    return 0;
}

// Real world example of virtual function
#include <iostream>

class Shape
{
public:
    virtual void calculateArea()
    {
        std::cout << "Generic shape area calculation method." << std::endl;
    }
};

class Circle : public Shape
{
public:
    void calculateArea() override
    {
        std::cout << "Area of Circle." << std::endl;
    }
};

class Rectangle : public Shape
{
public:
    void calculateArea() override
    {
        std::cout << "Area of Rectangle." << std::endl;
    }
};

class Triangle : public Shape
{
public:
    void calculateArea() override
    {
        std::cout << "Area of Triangle." << std::endl;
    }
};

int main()
{
    Shape shape;
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
    // If the term virtual is not used for late binding in the parent class then here the output of every function call will be the statement written in the parent class only
    Shape *pShape = &circle;
    pShape->calculateArea(); // Output: Area of Circle.

    pShape = &rectangle;
    pShape->calculateArea(); // Output: Area of Rectangle.

    pShape = &triangle;
    pShape->calculateArea(); // Output: Area of Triangle.

    return 0;
}

// Abstract class
// In this we will learn about pure virtual function
// Pure virtual function are the function having no defination it means that it has only the decleration but no defination or body

// Abstract class : The class which contains atleast one pure virtual function is called abstract class
//object of abstract class cannot be created
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
class A
{
public:
    virtual void f1() = 0;
};
class B : public A
{
public:
    void f1();
    void f2();
};
int main()
{
    
}