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
}

void PID::UpdateError(double cte) {
    diffCte = cte - lastCte;
    lastCte = cte;
    sum += cte;
}

double PID::TotalError() {
	return -Kp * lastCte - Kd * diffCte - Ki * sum;
}

