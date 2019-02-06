#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

float function_f(float x){return 2/(x+1)*x;} // change function here!

int main(int argc, char** argv){

    cout << "Please enter your step width dx: "<< endl;
    float dx;
    cin >> dx;
    float x_end = 10;
    float x_start = 0;
    int len = (x_end-x_start)/dx;
    float heights[len];
    float rect_start_x[len];
    float step_array[len];
    //float function_y_values[len];
    //cout << "len: " << len <<endl;
    float total_area = 0;

    string filename = "Integral_plot.csv";

    ofstream myfile;
    myfile.open(filename);
    for (int i = 0; i<len; i++){
        cout << "\nStep: "<< i<< endl;
        step_array[i] = dx;
        float xi = x_start+(i*dx);
        cout <<"X_Start: "<< xi<< " x_lenght: " << dx << endl;
        float height_l = function_f(xi);
        float height_r = function_f(xi+dx);
        float height;
        if (height_l > height_r){height= height_r;}
        else{height = height_l;}
        float yi = function_f(xi);
        cout << "Height: " << height << endl;
        rect_start_x[i] = xi;
        heights[i] = height;
        // Writing to myfile:  y, x_start, x_step_size, height
        myfile << yi << ","<< xi << "," << dx << "," << heights[i] << ",\n";
        // calc Area: 
        if (i < len-1){
        float area_i = dx * height;
        cout <<"Area: " <<area_i<<endl;
        
        total_area += area_i;}
    }
    myfile.close();
    cout << "Total Area is: " << total_area<<endl;

    string command = "python plot_rectangle.py";
    system(command.c_str());

    return 0;
}