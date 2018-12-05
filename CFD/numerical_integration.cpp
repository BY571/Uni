#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


double function(double x){
    //Define your initial function
    double y = 1/(1+x);
    return y;
}

double integral(double(*f)(double x), double a, double b, double dx) {
    /*
    a- lower boundary
    b- upper boundary
    dx- step_widht 
    */
    int n = (b-a)/dx;       // how many rectangles need to be calc / added
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * dx) * dx; // sum up each small rectangle
    }
    return area;
}

int main(){
    // step 1: Define your function in the function: function
    // step 2: Define your Boundaries and step_width:
    double upper_boundary = 4;
    double lower_boundary = 0;
    double dx = 0.01;
    double Area = 0;
    // Calc the Integral / Area under the function:
    Area = integral(function,lower_boundary,upper_boundary, dx);
    cout << "Calculated Integral/Area under the initial function:\n"<< Area<< endl;


}