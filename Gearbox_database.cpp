#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Gearbox_database.h"
#include "Global_functions.H"
Gear_Box::Gear_Box() {}

Gear_Box::Gear_Box(string n,string r,double e,double m,double d,double w,double msd)
{
    name = n;
    Gratio = r;
    efficiency = e;
    mass = m;
    diameter = d;
    width = w;
    max_shaft_diameter = msd;
}

string Gear_Box::get_name()
{
    return name;
}
string Gear_Box::get_gear_ratio()
{
    return Gratio;
}
double Gear_Box::get_efficiency()
{
    return efficiency;
}
double Gear_Box::get_mass()
{
    return mass;
}
double Gear_Box::get_diameter()
{
    return diameter;
}
double Gear_Box::get_width()
{
    return width;
}
double Gear_Box::get_max_shaft_diameter()
{
    return max_shaft_diameter;
}

std::vector<Gear_Box> gearBoxes;

void list_of_GearBoxes()
{
    gearBoxes =
    {
        {"110356", "19", 0.81, 48, 22, 31.25, 2},
        {"118655", "4592", 0.59, 73, 22, 42.05, 2},
        {"110357", "84", 0.73, 57, 22, 34.85, 2},
        {"144146", "370", 0.65, 65, 22, 38.45, 2},
        {"223091", "66", 0.75, 770, 52, 108, 10},
        {"701923", "5.2", 0.8, 950, 62, 110.7, 8},
        {"223098", "156", 0.75, 770, 52, 108, 8},
        {"701928", "100", 0.7, 1540, 62, 144.6, 8},
        {"223080", "3.5", 0.91, 460, 52, 49, 10},
        {"223081", "4.3", 0.91, 460, 52, 49, 10},
        {"223083", "12", 0.83, 620, 52, 65, 10},
        {"223084", "15", 0.83, 620, 52, 65, 10},
        {"223085", "19", 0.83, 620, 52, 65, 10},
        {"310308", "108", 0.66, 8, 12, 14, 1},
        {"310317", "4402", 0.48, 11, 12, 20, 1},
        {"327801", "1278", 0.48, 20, 16, 23.2, 1.5},
        {"424748", "157", 0.71, 65, 16, 30.95, 1.5},
        {"223089", "43", 0.75, 770, 52, 78.5, 10},
        {"223091", "66", 0.75, 770, 52, 78.5, 10},
        {"363867", "14", 0.67, 115, 22, 44.8, 4},
        {"363909", "33", 0.2, 331, 32, 57.7, 3},
        {"166164", "51", 0.7, 194, 32, 43.1, 6},
        {"166162", "28", 0.75, 162, 32, 36.4, 6},
        {"370776", "53", 0.59, 78, 22, 38.95, 4},
        {"370688", "16", 0.7, 64, 22, 32.3, 4},
        {"223086", "21", 0.83, 620, 52, 65, 10}
    };

    cout<<"\nAvailable gear heads:\n";
    cout<<"--------------------------------------------------------------------------------------------------\n";
    for (int i=0; i<gearBoxes.size(); i++)
    {
        cout<< i+1<<". \"" <<gearBoxes[i].get_name()
            <<"\"   Gear ratio: "<<gearBoxes[i].get_gear_ratio()
            <<", efficiency: "<<gearBoxes[i].get_efficiency()
            <<", mass(gm): "<<gearBoxes[i].get_mass()
            <<", diameter(mm): "<<gearBoxes[i].get_diameter()
            <<", width(mm): "<<gearBoxes[i].get_width()<<"\n";
        cout<<"--------------------------------------------------------------------------------------------------\n";
    }


    string new_gears;
    cout<<"\nDo you want to add new gear heads? (yes/no): ";
    cin>>new_gears;
    while (new_gears != "yes" && new_gears != "no")
    {
        cout<<"\nPlease input as declared between the brackets!\n";
        cout<<"\nDo you want to add new gears? (yes/no): ";
        cin.clear();
        cin.ignore();
        cin>>new_gears;
    }
    int Ngears;
    if(new_gears == "yes")
    {
        cout<<"\nEnter the number of new gear heads: ";
        cin >>Ngears;
        while(Ngears<0 || cin.fail())
        {
            cout<< "\nInvalid input, Enter a positive integer!\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>> Ngears;
        }

        for (int i=0; i<Ngears; i++)
        {
            string name, Gratio;
            double efficiency, mass, diameter, width, max_shaft_diameter;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<< "\nEnter the specs of gear head number "<< i+1<<" \n";
            cout<<"Name: ";
            getline(cin,name);

            cout<<"Gear ratio: ";
            cin>> Gratio;
            String_error(Gratio);

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"efficiency: ";
            cin>> efficiency;

            while(efficiency <= 0 || efficiency > 1 ||cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Invalid input, please enter a positive integer less than 1! \n";
                cin>>efficiency;
            }

            cout<<"Mass(gm): ";
            cin>> mass;
            input_errors(mass);

            cout<<"Diameter(mm): ";
            cin>> diameter;
            input_errors(diameter);

            cout<<"width(mm): ";
            cin>> width;
            input_errors(width);

            cout<<"Gearbox's max shaft diameter(mm): ";
            cin>> max_shaft_diameter;
            input_errors(max_shaft_diameter);

            Gear_Box new_Gear_Box(name,Gratio,efficiency,mass,diameter,width,max_shaft_diameter);
            gearBoxes.push_back(new_Gear_Box);
        }
    }


    if(Ngears >0)
    {
        cout<<"\nNew gear heads database:\n";
        cout<<"--------------------------------------------------------------------------------------------------\n";
        for (int i=0; i<gearBoxes.size(); i++)
        {
            cout<< i+1<<". \"" <<gearBoxes[i].get_name()
                <<"\"   Gear ratio: "<<gearBoxes[i].get_gear_ratio()
                <<", efficiency: "<<gearBoxes[i].get_efficiency()
                <<", mass(gm): "<<gearBoxes[i].get_mass()
                <<", diameter(mm): "<<gearBoxes[i].get_diameter()
                <<", width(mm): "<<gearBoxes[i].get_width()<<"\n";
            cout<<"--------------------------------------------------------------------------------------------------\n";
        }
    }
}
