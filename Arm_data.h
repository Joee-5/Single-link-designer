#ifndef ARM_DATA_H
#define ARM_DATA_H

using namespace std;
class arm_specs
{
    private:
        double length;
        double cross_area;
        double payload;
        double max_acc;
        double base;
        double height;
        double radius;
        double modified_base;
        double modified_height;
        double modified_radius;
        double mod_cross_area;
    public:
        arm_specs();
        arm_specs(double mass, double acc, double arm_length);
        double area_calc(string area_type);
        void set_area_dim(double b, double h, double r);
//getter functions to allow us to access the private variables values.
        double get_length();
        double get_mass();
        double get_acc();
        double get_area();
        double get_base();
        double get_height();
        double get_radius();
        double get_mod_base();
        double get_mod_height();
        double get_mod_radius();
        void set_mod_base( double b );
        void set_mod_height( double h );
        void set_mod_radius( double r );
        void output_mod_data(string area_t);
        double mod_area_calc(string area_type);
        double get_mod_area ();
};

#endif // Arm_data
