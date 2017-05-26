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

double PID::CalculateSteering(double cte) {
    double diffCte = cte - lastCte;
    lastCte = cte;
    sum += cte;

    return -Kp * cte - Kd * diffCte - Ki * sum;

}

void PID::UpdateError(double cte) {
}

double PID::TotalError() {
}

