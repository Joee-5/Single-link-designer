#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include "Materials.h"
#include "Arm_data.h"
class stress_calc
{
private:
    //making objects with the latest user inputs
    arm_specs &arm;
    Material material;
    double arm_mass;
    double mod_arm_mass;
    double mod_bending_M;
    double bending_M;
    double inertia;
    double max_stress;
    double opt_max_stress;
    double opt_inertia;
public:
    stress_calc(arm_specs& a, Material& m);
    //calculating the results
    double get_arm_mass();
    double get_bending_M();
    double calc_inertia(string area_type);
    double calc_max_stress(string area_type);
    double get_inertia();
    double get_max_stress();
    double get_opt_stress();
    double calc_opt_inertia(string area_type);
    double calc_opt_stress(string area_type);
    double get_opt_inertia();
    void set_opt_stress_initial();
    double get_mod_arm_mass();
    double get_mod_bending_M();
};

#endif // calculations
