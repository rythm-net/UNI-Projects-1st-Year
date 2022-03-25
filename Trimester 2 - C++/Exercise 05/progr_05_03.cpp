#include <iostream>
using namespace std;
#include <cmath>
double distance(double x1, double y1,
                double x2=0.0, double y2=0.0) {
    return sqrt( (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) );
}

int main() {
    double x1,y1,x2,y2;
    cout<<"Kоординати на 1-ата точка: ";
    cin>>x1>>y1;
    cout<<"Kоординати на 2-ата точка: ";
    cin>>x2>>y2;
    cout<<"Разстояние от 1-та точка до (0;0): "
        <<distance(x1,y1)<<endl;
    cout<<"Разстояние от 2-та точка до (0;0): "
        <<distance(x2,y2)<<endl;
    cout<<"Разстояние между двете точки: "
        <<distance(x1,y1,x2,y2)<<endl;
}