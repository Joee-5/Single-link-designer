#ifndef GLOBAL_FUNCTIONS_H
#define GLOBAL_FUNCTIONS_H
#include "Materials.h"
#include "Arm_data.h"
#include "Calculations .h"
#include "Gearbox_database.h"
#include "Motor_database.h"

void check ( Material &a, arm_specs &ar,  stress_calc &cal, string area);
void input_errors(double &input);
double String_error(string &r);
void input_data(double &l,double &mass, double &acc);
void default_dim(arm_specs def);
#endif // Global_functions

