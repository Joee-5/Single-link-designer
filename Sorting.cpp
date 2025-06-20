#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Sorting.h"
#include "Motor_database.h"
#include "Gearbox_database.h"
#include "Global_functions.H"
using namespace std;

void Sorting(double Treq)
{
    Motor selected_M;
    Gear_Box selected_G;
    double cost_min=std::numeric_limits<std::streamsize>::max();

    cout<< "\nEnter the desired angular speed (rad/s): ";

    double Wreq;
    cin>>Wreq;
    input_errors(Wreq);
    string Cost_type;
    cout<<"Determine cost priority: Minimize Mass(M) | Minimize Dimensions(D) | Minimize Mass & Dimensions(DM): ";
    cin>>Cost_type;
    while (Cost_type!="M"&&Cost_type!="D"&&Cost_type!="DM")
    {
        cout<<"\nPlease input as declared between the brackets!\n";
        cout<<"\nDetermine cost priority: Mass only (M) | Dimensions only (D) | Mass & Dimensions (DM): ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin>>Cost_type;
    }

    double To,Wo;
    int flag =0;
    for (int i=0; i<motors.size(); i++) //looping on all the motors of the vector motors
    {
        double Tm = motors[i].get_torque();
        double Wm = motors[i].get_speed();
        double required = Treq;
        for (int j=0; j<gearBoxes.size(); j++) //looping on all the gear boxes of the vector gear_Boxes with the motor in the index i only
        {
            string Gr = gearBoxes[j].get_gear_ratio();
            double doubleGr = String_error(Gr);
            double Geff = gearBoxes[j].get_efficiency();

            To = Tm*doubleGr*Geff; //calc the output torque
            Wo = Wm/doubleGr; //calc the output angular speed

            if (motors[i].get_shaft_diameter() > gearBoxes[j].get_diameter()) continue; //making sure that the motor at i is compatible with the gear box at j

            if ((To >= Treq) && (Wo >= Wreq))
            {
                if(Cost_type=="M")
                {
                    double current_cost= motors[i].get_mass()+gearBoxes[j].get_mass();
                    if(current_cost<cost_min)
                    {
                        cost_min=current_cost;
                        selected_M=motors[i];
                        selected_G=gearBoxes[j];
                        flag++;
                    }
                }
                else if (Cost_type=="D")
                {
                    double current_cost= (motors[i].get_diameter()+gearBoxes[j].get_diameter() +motors[i].get_width() +gearBoxes[j].get_width())/100;
                    if(current_cost<cost_min)
                    {
                        cost_min=current_cost;
                        selected_M=motors[i];
                        selected_G=gearBoxes[j];
                        flag++;
                    }
                }
                else if (Cost_type=="DM")
                {
                    double current_cost= motors[i].get_mass()+gearBoxes[j].get_mass() + (motors[i].get_diameter()+gearBoxes[j].get_diameter()+motors[i].get_width()+gearBoxes[j].get_width())/100;
                    if(current_cost<cost_min)
                    {
                        cost_min=current_cost;
                        selected_M=motors[i];
                        selected_G=gearBoxes[j];
                        flag++;
                    }
                }
            }
        }
    }
    if(flag == 0)
    {
        cout<<"\nNo pairs available fulfils these conditions :(\n";
    }
    else
    {
        cout<<"\nThe cheapest pair available:-\n";
        cout<<"\nMotor Code: "<<selected_M.get_name()<<"\n";
        cout<<"Gear box Code: "<<selected_G.get_name()<<"\n";
        cout<<"Cost: "<<cost_min<<endl;

    }
}
