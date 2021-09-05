//
//  main.cpp
//  DSP HW2
//
//  Created by 何冠勳 on 2020/10/18.
//  Copyright © 2020 何冠勳. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int freq[3] = {100, 400, 3000};
    int sample[3] = {8000, 4000, 16000};
    int R = 1000;
    float pi = acos(-1);
    float C = 1/(2*pi*2*pi*400*400*1000);
    
    for(int i=0;i<3;i++)    // f = 100, 400, 3000Hz
    {
        for(int j=0;j<3;j++)    // tau = 1/8000, 1/4000, 1/16000
        {
            vector<complex<float>> x_n, y_n, y_t, diff;
            float tau = (float)1/sample[j];
            for(int k=0;k<sample[j];k++)    // Assume that signals are all within 1 sec.
            {
                float t = tau*k;
                complex<float> c(0, 2*pi*freq[i]*t);
                complex<float> sig = exp(c);      // Assume that max votage of x_n is 1V.
                //cout << t << ", " << c << ", " << sig << endl;
                x_n.push_back(sig);
            }
            
            complex<float> c(1,0);     // Initial votage of y_n is 1V. => cus |y(t)| -> 0, when t = 0.
            y_n.push_back(c);
            for(int k=1;k<sample[j];k++)    // Assume that signals are all within 1 sec.
            {
                complex<float> output;
                output = ((complex<float>)(R*C/(R*C+tau))*y_n[k-1]) + ((complex<float>)(tau/(tau+R*C))*x_n[k]);
                //cout << R*C/(R*C+tau) << ", " << y_n[k-1] << ", " << tau/(tau+R*C) << ", " << output << endl;
                y_n.push_back(output);
            }
            
            float sqr_err = 0;
            for(int k=0;k<sample[j];k++)    // Calculate y_t, the difference between y_n & y_t, and the square error.
            {
                float t = tau*k;
                complex<float> output;
                complex<float> c1(0, 2*pi*freq[i]*t);
                c1 = exp(c1);     // c1 = e^(jwt)
                complex<float> c2(0, 2*pi*freq[i]*R*C);
                complex<float> H = (complex<float>)1/((complex<float>)1+c2);
                output = (complex<float>)(H*c1);
                
                y_t.push_back(output);
                diff.push_back(output-y_n[k]);
                sqr_err = sqr_err + pow(abs(diff[k]),2);
            }
            
            cout.precision(5);    // set the precision (decimal point) to 5
            
            ofstream myfile;
            string filename = to_string(freq[i]) + "Hz_" + to_string(sample[j]) + "Hz_Voltage_Output.txt";
            cout << filename << endl;
            myfile.open(filename, ios::out);
            if(!myfile)
            {
                cout << "Can't open file" << endl;
                return 1;
            }
            
            myfile << "Iteration n, Sampletime t (sec), Signal x[n] (real, img), Output y[n] (real, img), Actual_Output y(t) (real, img), Difference y(t)-y[n] (real, img)" << endl << endl;
            myfile << "Square Error : " << sqr_err << endl << endl;
            
            for(int k=0;k<sample[j];k++)    // layout
            {
                float t = tau*k;
                myfile << "n: " << setw(4) << k;
                myfile << ", t: " << setw(8) << fixed << t;
                myfile << ", x[n]: " << setw(21) << x_n[k];
                myfile << ", y[n]: " << setw(21) << y_n[k];
                myfile << ", y(t): " << setw(21) << y_t[k];
                myfile << ", diff: " << setw(21) << diff[k] << endl;
            }
            
            myfile.close();
        }
    }
    
    return 0;
}
