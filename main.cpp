#include <iostream>
#include <math.h>
#include <stdio.h>
#include "capacitor.h"



int main()
{
    Capacitor cap;
    cap.C = 100e-12;
    cap.time = new double[50000];
    cap.voltage = new double[50000];
    cap.current = new double[50000];
    double dt = 1e-10;
    int steps = 50000;
    
    
    
    
    for (int count = 0; count < steps; count++){
        cap.time[count] = count * dt;
    }
    
    cap.voltage[0] = 0.0;
    cap.current[0] = 10.0/1000.0;
    
    for(int timeidk = 0; timeidk < steps - 1; timeidk++){
        cap.voltage[timeidk + 1] = cap.voltage[timeidk] + (cap.current[timeidk] * dt * 1 / cap.C);
        cap.current[timeidk + 1] = cap.current[timeidk];
        cap.time[timeidk + 1] = cap.time[timeidk] + dt;
        // printf("capacitor current or something  %.20lf\n", cap.voltage[timeidk]);
    }
    
 
    
    for(int timeidk = 0; timeidk < steps - 1; timeidk++){
        cap.current[timeidk + 1] = cap.current[timeidk] - ((cap.current[timeidk] / (1000 * cap.C)) * dt);
        cap.voltage[timeidk + 1] = cap.voltage[timeidk] + (cap.current[timeidk] * dt / cap.C);
    }
    
    for(int timeidk = 0; timeidk < steps; timeidk += 200){
        printf("time = %.10e | V = %.10e | I = %.10e\n", cap.time[timeidk], cap.voltage[timeidk], cap.current[timeidk]);
    }
    
    std::cout<<"Program End, clearing memory";

delete[] cap.time;
delete[] cap.voltage;
delete[] cap.current;

    return 0;
}
