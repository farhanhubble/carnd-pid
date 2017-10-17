#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    prev_cte = 0.0;
    integral_cte = 0.0;
}

void PID::UpdateError(double cte) {
    p_error = -Kp*cte;
    
    d_error = -Kd*(cte-prev_cte);
    prev_cte = cte;

    i_error = -Ki*integral_cte;
    integral_cte += cte;
}

double PID::TotalError() {
    return p_error + d_error + i_error;
}

