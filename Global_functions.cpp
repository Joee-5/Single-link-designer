#include <limits>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include "Global_functions.h"
void check ( Material &a, arm_specs &ar,  stress_calc &cal, string area_t)
{

    cal.set_opt_stress_initial();
    ar.set_mod_radius(ar.get_radius());
    ar.set_mod_base(ar.get_base());
    ar.set_mod_height(ar.get_height());
    ar.mod_area_calc(area_t);


    if (0.9*a.get_strength()< cal.get_opt_stress())
    {
        while (0.9*a.get_strength()< cal.get_opt_stress( ))
        {
            if (area_t == "rectangle")
            {
                ar.set_mod_base( 1.01*ar.get_mod_base()); // increasing base
                ar.set_mod_height( 1.01*ar.get_mod_height()); // increasing height
                ar.mod_area_calc( area_t );
                cal.calc_opt_inertia( area_t );
                cal.calc_opt_stress ( area_t );
            }
            else if (area_t == "circle")
            {
                ar.set_mod_radius( 1.01*ar.get_mod_radius()); // increasing radius
                ar.mod_area_calc( area_t );
                cal.calc_opt_inertia( area_t );
                cal.calc_opt_stress ( area_t );
            }
        }
    }

    else if (0.9*a.get_strength()> cal.get_opt_stress( ))
    {
        while (0.9*a.get_strength()> cal.get_opt_stress( ))
        {

            if (area_t == "rectangle")
            {
                ar.set_mod_base( 0.99*ar.get_mod_base()); // base reduction
                ar.set_mod_height( 0.99*ar.get_mod_height()); // height reduction
                ar.mod_area_calc(area_t);
                cal.get_mod_arm_mass();
                cal.get_mod_bending_M();
                cal.calc_opt_inertia( area_t );
                cal.calc_opt_stress ( area_t );
            }
            else if (area_t == "circle")
            {
                ar.set_mod_radius( 0.99*ar.get_mod_radius()); // radius reduction
                ar.mod_area_calc(area_t);
                cal.get_mod_arm_mass();
                cal.get_mod_bending_M();
                cal.calc_opt_inertia( area_t );
                cal.calc_opt_stress ( area_t );
            }
        }
    }
}

void input_errors(double &input)
{
    while(input <= 0 || cin.fail())
    {
        cin.clear();
        //This clears any error state from cin (like failbit) after wrong input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //to clear all the buffer storage inputs by deleting all characters untill ('\n')
        cout<<"Invalid input, please enter a positive value! \n";
        cin>>input;
    }
}

double String_error(string &r)
{
    while (true)
    {
        vector <char> Vr(r.begin(),r.end());
        vector <char> New;
        int dot = 0;
        string number_str;
        double number;

        for(int i=0; i<Vr.size(); i++)
        {
            if (
                Vr[i] == '1' ||
                Vr[i] == '2' ||
                Vr[i] == '3' ||
                Vr[i] == '4' ||
                Vr[i] == '5' ||
                Vr[i] == '6' ||
                Vr[i] == '7' ||
                Vr[i] == '8' ||
                Vr[i] == '9' ||
                Vr[i] == '0'
            )
            {
                New.push_back(Vr[i]);
            }

            else if (Vr[i]== '.')
            {
                dot++;
                if (dot == 1)
                {
                    New.push_back(Vr[i]);
                }

                else
                {
                    cout << "\ninvalid input, re-enter.\n";
                    cin >> r;
                    goto jump_here;
                    // when the compiler reads goto it jumps automatically to jump_here: statement ignoring all the statements in between
                }
            }

            else
            {
                cout << "\ninvalid input, re-enter.\n";
                cin >> r;
                goto jump_here;
            }


        }
        number_str= string(New.begin(), New.end());
        number = stod(number_str);
        return number;

        jump_here:;
    }
}


void input_data(double &l,double &mass, double &acc)
{
    cout<<"\nPlease enter the arm length (m): ";
    cin>>l;
    input_errors(l);
    cout<<"Please enter the payload mass (kg): ";
    cin>>mass;
    input_errors(mass);
    cout<<"Please enter the max angular acc (rad/sec^2): ";
    cin>>acc;
    input_errors(acc);
}

void default_dim(arm_specs def)
{
    cout<<"\nBase ="<<def.get_base()<<" m\n";
    cout<<"Height ="<<def.get_height()<<" m\n";
    cout<<"Arm length ="<<def.get_length()<<" m\n";
    cout<<"Payload mass ="<<def.get_mass()<<" kg\n";
    cout<<"Max angular acc ="<<def.get_acc()<<" rad/sec^2\n";
}

/*
this function is used to combine the classes ( Material / arm_specs / stress_calc ) together to optimize the dimensions of the arm
there are 2 cases
case 1: the max stress is higher than the material's strength therefore the stress of the arm must be reduced to less than the material's strength
case 2: the max stress is much lower than the material's strength therefore dimensions are reduced to reduce the cost
*/

