#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Calculations .h"
stress_calc::stress_calc(arm_specs& a, Material& m) : arm(a), material(m) {}

double stress_calc::get_arm_mass() //using the density * volume equation to calculate the mass of the arm
{
    arm_mass = material.get_density()*arm.get_area()*arm.get_length();
    return arm_mass;
}

double stress_calc::get_bending_M() // used to calculated the bending moment due to the arm  mass  and the load mass
{
    double mp = arm.get_mass(); // arm mass
    double ml = get_arm_mass(); // load mass
    double L = arm.get_length(); // arm length
    double amax = arm.get_acc(); // angular acceleration
    double g = 9.81;
    return bending_M = ml*g*(L/2)+L*g*mp+ml*pow((L/2),2)*amax+mp*pow(L,2)*amax;
}

double stress_calc::calc_inertia(string area_type) // used to check the area type and calculate the inerita depending on the area type
{
    if (area_type == "rectangle")
    {
        return inertia = (arm.get_base()* pow(arm.get_height(), 3)) / 12.0; // initializing inertia
    }
    else if (area_type == "circle")
    {
        return inertia = (M_PI * pow(arm.get_radius(), 4)) / 64.0; // initializing inertia
    }
}

double stress_calc::calc_max_stress(string area_type) // used to calculate and initialize the max stress on the arm
{
    if (area_type == "rectangle")
    {
        return max_stress = pow(10,-6)*(get_bending_M() * arm.get_height()) / (2.0 * get_inertia());
    }
    else if (area_type == "circle")
    {
        return max_stress = (pow(10,-6)*get_bending_M() * arm.get_radius()) / get_inertia();
    }
}

double stress_calc::get_inertia(){return inertia;}
double stress_calc::get_max_stress(){return max_stress;}
double stress_calc::get_opt_stress(){return opt_max_stress;}
double stress_calc::get_opt_inertia(){return opt_inertia;}
void stress_calc::set_opt_stress_initial() {opt_max_stress = max_stress;}

double stress_calc::get_mod_arm_mass() //using the density * length * modified area equation to calculate the modified mass of the arm during optimization
{
    arm.get_mod_area();
    mod_arm_mass = material.get_density()*arm.get_mod_area()*arm.get_length();
    return mod_arm_mass;
}

double stress_calc::get_mod_bending_M() // used to calculated the bending moment due to the modified arm  mass  and the load mass during optimization
{
    double mp = arm.get_mass();
    double ml = get_mod_arm_mass();
    double L = arm.get_length();
    double amax = arm.get_acc();
    double g = 9.81;
    return mod_bending_M = ml*g*(L/2)+L*g*mp+ml*pow((L/2),2)*amax+mp*pow(L,2)*amax;
}

double stress_calc::calc_opt_inertia(string area_type) // used to re-calculate the inertia using the modified dimensions during optimization
{
    if (area_type == "rectangle")
    {
        return opt_inertia = (arm.get_mod_base()* pow(arm.get_mod_height(), 3)) / 12.0;
    }
    else if (area_type == "circle")
    {
        return opt_inertia = (M_PI * pow(arm.get_mod_radius(), 4)) / 64.0;
    }

}

double stress_calc::calc_opt_stress(string area_type) // calculates the modified stress on the arm after dimension optimization
{
    while(get_opt_stress() > 0 )
    {
      if (area_type == "rectangle")
    {

        return opt_max_stress = pow(10,-6)*(get_mod_bending_M() * arm.get_mod_height()) / (2.0 * get_opt_inertia());
    }
    else if (area_type == "circle")
    {
        return opt_max_stress = pow(10,-6)*(get_mod_bending_M() * arm.get_mod_radius()) / get_opt_inertia();
    }
    }
}
