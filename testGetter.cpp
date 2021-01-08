#include <stdio.h>
#include <iostream>
using namespace std;

class ClassSample{
private:
    float a, b;
public:
    //getter
    float getA(){
        return a;
    }
    float getB(){
        return b;
    }
    //setter
    void setA(float A){
        a = A;
    }
    void setB(float b){
        this -> b = b;
    }
    void output(){
        cout << a <<"/"<< b;
    }
    ClassSample();
    ClassSample(float a, float b){
        this -> a = a;
        this -> b = b;
    }
};

void operator-(ClassSample &C){
    C.setA(-C.getA());
};

int main(){
    ClassSample C(4, 5);
    -C;
    C.output(); // output = -4/5
    system("exit");
    return 0;
}
