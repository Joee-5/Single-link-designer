#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Motor_database.h"
#include "Global_functions.H"
Motor::Motor() {}

Motor::Motor(string n,double t,double s,double m,double d,double w,double sd)
{
    name = n;
    torque = t;
    speed = s;
    mass = m;
    diameter = d;
    width = w;
    shaft_diameter = sd;
}

string Motor::get_name()
{
    return name;
}
double Motor::get_torque()
{
    return torque;
}
double Motor::get_speed()
{
    return speed;
}
double Motor::get_mass()
{
    return mass;
}
double Motor::get_diameter()
{
    return diameter;
}
double Motor::get_width()
{
    return width;
}
double Motor::get_shaft_diameter()
{
    return shaft_diameter;
}

std::vector<Motor> motors;

void list_of_motors()
{
    motors=
    {
        {"110153", 6.86, 6420, 54, 22, 38.4, 2},
        {"110165", 6.97, 5270, 54, 22, 38.4, 2},
        {"110167", 6.95, 5840, 54, 22, 38.4, 2},
        {"267423", 6.03, 8100, 54, 22, 38.4, 2},
        {"578296", 405, 5680, 1100, 50, 140.2, 8},
        {"618573", 442, 2480, 1100, 50, 140.2, 8},
        {"618572", 404, 4630, 1100, 50, 140.2, 8},
        {"578298", 420, 4620, 1100, 50, 140.2, 8},
        {"574740", 399, 4360, 823, 52, 80, 8},
        {"574741", 438, 4210, 823, 52, 80, 8},
        {"579164", 448, 4370, 823, 52, 80, 8},
        {"579165", 423, 4470, 823, 52, 80, 8},
        {"596099", 655, 3300, 1150, 52, 110, 8},
        {"606793", 646, 2970, 1150, 52, 110, 8},
        {"110182", 5.03, 8670, 117, 26, 44.7, 2},
        {"353029", 6.86, 9630, 54, 22, 31.9, 2},
        {"236661", 44, 4670, 240, 32, 67.9, 4},
        {"236664", 45.4, 5860, 240, 32, 62.9, 4},
        {"311537", 54, 17800, 175, 22, 66, 2},
        {"118557", 1.27, 11600, 7, 10, 17, 1.5},
        {"625857", 381, 3760, 350, 60, 36, 8},
        {"118517", 2.94, 6630, 24, 13, 33.8, 1.5},
        {"268193", 50.6, 8440, 260, 30, 68, 5},
        {"268213", 73.7, 8870, 260, 30, 68, 5},
        {"397800", 804, 4670, 860, 32, 142, 8},
        {"236660", 43.1, 5000, 240, 32, 62.9, 4}
    };

    cout<<"\nAvailable motors:\n";
    cout<<"-----------------------------------------------------------------------------------------------------\n";
    for (int i=0; i<motors.size(); i++)
    {
        cout<< i+1<<". \"" <<motors[i].get_name()
            <<"\"   torque(mN.m): "<<motors[i].get_torque()
            <<", speed(RPM): "<<motors[i].get_speed()
            <<", mass(gm): "<<motors[i].get_mass()
            <<", diameter(mm): "<<motors[i].get_diameter()
            <<", width(mm): "<<motors[i].get_width()<<"\n";
        cout<<"-----------------------------------------------------------------------------------------------------\n";
    }
    string new_motors;
    cout<<"\nDo you want to add new motors? (yes/no): ";
    cin>>new_motors;
    while (new_motors != "yes" && new_motors != "no")
    {
        cout<<"\nPlease input as declared between the brackets!\n";
        cout<<"\nDo you want to add new motors? (yes/no): ";
        cin.clear();
        cin.ignore();
        cin>>new_motors;
    }
    int Nmotors;
    if(new_motors == "yes")
    {
        cout<<"\nEnter the number of new motors: ";
        cin >>Nmotors;
        while(Nmotors<0 || cin.fail())
        {
            cout<< "\nInvalid input, Enter a positive integer!\n";
            cout<<"\nEnter the number of new motors: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>> Nmotors;
        }

        for (int i=0; i<Nmotors; i++)
        {
            cout<< "\nEnter the specs of motor number "<< i+1<<" \n";
            string name;
            double torque, speed, mass, diameter, width, shaft_diameter;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Name: ";
            getline(cin,name);

            cout<<"\nTorque (mN.m): ";
            cin>> torque;
            input_errors(torque);

            cout<<"speed (rpm): ";
            cin>> speed;
            input_errors(speed);

            cout<<"Mass (gm): ";
            cin>> mass;
            input_errors(mass);

            cout<<"Diameter (mm): ";
            cin>> diameter;
            input_errors(diameter);

            cout<<"width (mm): ";
            cin>> width;
            input_errors(width);

            cout<<"motor's shaft diameter (gm): ";
            cin>> shaft_diameter;
            input_errors(shaft_diameter);

            Motor new_motor(name,torque,speed,mass,diameter,width, shaft_diameter);
            motors.push_back(new_motor);
        }

        cout<<"\nNew motors list:\n";
        cout<<"-----------------------------------------------------------------------------------------\n";
        for (int i=0; i<motors.size(); i++)
        {
            cout<< i+1<<". \"" <<motors[i].get_name()
                <<"\"   torque(mN.m): "<<motors[i].get_torque()
                <<", speed(RPM): "<<motors[i].get_speed()
                <<", mass(gm): "<<motors[i].get_mass()
                <<", diameter(mm): "<<motors[i].get_diameter()
                <<", width(mm): "<<motors[i].get_width()<<"\n";
            cout<<"-----------------------------------------------------------------------------------------\n";
        }
    }

}
