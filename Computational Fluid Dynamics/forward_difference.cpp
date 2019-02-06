#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


float func_g(float x){
    float y;
    return 1/(sqrt(2*M_PI*pow(1.2,2)))*exp(-pow(x-0.3,2)/(2*pow(1.2,2)));
}

int main(int argc, char** argv){

    float step = 0.25;
    int xstart = -5;
    int xend = 5;
    float xi;
    int len = (xend-xstart)/step +1;
    float array_[len]; 
    float array_xi[len];
    //cout << (xend-xstart)/step << endl;
    string filename = "data_ue6.csv";
    ofstream myfile;
    myfile.open (filename);
    for (int i = 0; i<len; i++){
        
        xi =xstart+i*step;
        array_xi[i]= xi;
        cout<< "Calculating y for xi: " << xi<< endl;
        float y = func_g(xi);
        cout << "y = "<< y << endl;
        myfile << xi<< "," <<y<<",\n";
        array_[i] = y;
        
    }
    myfile.close();
    string command = "python plotting.py -d data_ue6 -t .csv";
    system(command.c_str());

    // calculating the first deriviative with the forward difference
    float dx = 0.5;
    float dy_array[len];
    float gradients[len];
    filename = "Gradientplot.csv";
    ofstream myfile1;
    myfile1.open(filename);

    for (int i = 0; i<len;i++){
        // dy = f(x+dx)-f(x)
        dy_array[i] = func_g(array_xi[i]+dx)- func_g(array_xi[i]);
        // gradien = dy/dx
        gradients[i] = dy_array[i]/dx;
        cout <<"Gradient at xi = "<<array_xi[i]<<" : "<< gradients[i]<< endl;
        myfile1 << array_xi[i]<<","<< gradients[i]<<",\n";
        }
    myfile1.close();
    command = "python plotting.py -d Gradientplot -t .csv";
    system(command.c_str());


        // calculating the second deriviative with the forward difference
    float dy_array_2[len];
    float gradients_2[len];

    filename = "Second_Deriviative.csv";
    ofstream myfile2;
    myfile2.open(filename);
    for (int i = 0; i<len; i++){
        // f``(x) = d/dx(f(x+h)-f(x))  =  f(x+2h) - 2f(x+h) + f(x)
        dy_array_2[i] = func_g(array_xi[i]+2*dx)-2*func_g(array_xi[i]+dx)+func_g(array_xi[i]);
        // gradient= d^2y/d^2x
        gradients_2[i] = dy_array_2[i]/pow(dx,2);
        myfile2 << array_xi[i] <<","<< gradients_2[i]<<",\n";
        
    }
    myfile2.close();
    command = "python plotting.py -d Second_Deriviative -t .csv";
    system(command.c_str());


    return 0;


}
