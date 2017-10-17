#include "PID.h"
#include<iostream>
#include<math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    initialized = false;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double cte) {
    this->Kp = Kp;
    this->Kd = Kd;
    this->Ki = Ki;

    prev_cte = cte;
    integral_cte = 0.0;
    
    initialized = true;
}

void PID::UpdateError(double cte) {
    p_error = -Kp*cte;
    d_error = -Kd*(cte-prev_cte);
    i_error = -Ki*integral_cte;
    
    prev_cte = cte;
    integral_cte += cte;
}

double PID::TotalError() {
    cout << "p_error: " << p_error << " i_error: " << i_error << " d_error: " << d_error << endl;
    return p_error + d_error + i_error;
}



