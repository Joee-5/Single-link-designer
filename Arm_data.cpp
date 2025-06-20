
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Arm_data.h"
#include "Global_functions.H"
arm_specs::arm_specs()
{
    base = 0.02; //m
    height = 0.02; //m
    radius = 0;
    cross_area = 0.0004; //m^2
    length = 0.5; //m
    payload = 40; //kg
    max_acc = 12; //rad/sec^2
}
arm_specs::arm_specs(double mass, double acc, double arm_length) //this constructor stores the input values from the user
{
    payload = mass;
    max_acc = acc;
    length = arm_length;
}

void arm_specs::set_area_dim(double b, double h, double r) // this function is used to initialize the cross-section area dimensions
{
    base = b;
    height = h;
    radius = r;
}

double arm_specs::area_calc(string area_type) // used to check if area is circle or rectangle, and calculate area
{
    if(area_type == "circle")
    {
        double r;
        cout<<"Please enter the radius(m): ";
        cin>>r;
        input_errors(r);
        set_area_dim(0,0,r);
        cross_area=M_PI*r*r;// used to initialize cross-section area ( if area is circle )
        return cross_area;
    }
    else if (area_type == "rectangle")
    {
        double b,h;
        cout <<"Please enter the base(m): ";
        cin>>b;
        input_errors(b);
        cout<<"Please enter the height(m): ";
        cin>>h;
        input_errors(h);
        set_area_dim(b,h,0);
        cross_area=b*h; // used to initialize cross-section area ( if area is rectangle )
        return cross_area;
    }
}

double arm_specs::mod_area_calc(string area_type) // used to calculate area using modified dimensions during the optimization
{

    if(area_type == "circle")
    {
        mod_cross_area=M_PI*modified_radius*modified_radius;
        return mod_cross_area;
    }
    else if (area_type == "rectangle")
    {
       mod_cross_area=modified_base*modified_height;
        return mod_cross_area;
    }
}

double arm_specs::get_length(){return length;}
double arm_specs::get_mass(){return payload;}
double arm_specs::get_acc(){return max_acc;}
double arm_specs::get_area(){return cross_area;}
double arm_specs::get_base(){return base;}
double arm_specs::get_height(){return height;}
double arm_specs::get_radius(){return radius;}
double arm_specs::get_mod_base(){return modified_base;}
double arm_specs::get_mod_height(){return modified_height;}
double arm_specs::get_mod_radius(){return modified_radius;}

void arm_specs::set_mod_base( double b ) {modified_base =b;}
void arm_specs::set_mod_height( double h ) {modified_height =h;}
void arm_specs::set_mod_radius( double r ) {modified_radius = r;}

double arm_specs::get_mod_area () {return mod_cross_area;}

void arm_specs :: output_mod_data(string area_t) // used to output the new dimensions and the area after the optimization
{
    if ( area_t == "rectangle" )
    {
    cout << "\nmodified base:" << get_mod_base() << " m\n";
    cout << "modified height:" << get_mod_height() << " m\n";
    }
    if ( area_t == "circle" )
    {
        cout << "modified radius:" << get_mod_radius() << " m\n";
    }
     cout << "modified Area:" << get_mod_area() << " m^2\n";
}

