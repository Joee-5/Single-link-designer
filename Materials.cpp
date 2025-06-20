#include <iostream>
#include <string>
#include <vector>
#include "Materials.h"
#include "Global_functions.H"
Material::Material()
{
    name = "Steel";
    yieldStrength = 247;
    density = 7.58;
}
//constructor to store the characteristics of a new material entered by the user
Material::Material(string n, double ys, double d)
{
    name = n;
    yieldStrength = ys;
    density = d;
}


//material input function
Material getMaterialFromUser() //creating materials database
    {
    vector<Material> materials =
        {
        {"Cast Iron", 130, 7300},
        {"Copper Nickel", 130, 8940},
        {"Brass", 200, 8730},
        {"Aluminum", 241, 2700},
        {"Steel", 247, 7580},
        {"Acrylic", 72, 1160},
        {"Copper", 70, 8920},
        {"Stainless Steel", 275, 7860},
        {"Tungsten", 941, 19250}
        }; // initial materials in the database

    cout << "\nAvailable materials:\n\n";
    for (int i = 0; i < materials.size(); i++)
    {
        cout << i + 1 << ". " << materials[i].get_name() //printing material name
             << " (Yield Strength: " << materials[i].get_strength() //printing material yield strength
             << " MPa, Density: " << materials[i].get_density() << " kg/m^3)\n"; //printing material density
        cout<<"-----------------------------------------------------------\n";
    } //looping to print the materials database
    cout << materials.size() + 1 << ". Add a new material\n"; //an option to add a new material to the database
    cout << "\nChoose/add material: ";
    double choice;
    cin >> choice;
    input_errors(choice);
    if ((choice >= 1) && (choice <= materials.size())) //checking if the choice entered by the user is from the current database
    {
        return materials[choice - 1]; //printing the desired material and its specifications
    }
    else if (choice == materials.size() + 1) // if users chose to add a new material
        {
        string name;
        double ys, density;
        cin.ignore();
        cout << "Enter material name: ";
        cin>>name;

        while(cin.fail())
        {
            cout<<"\nPlease input as declared between the brackets!\n";
            cout<<"Cross section (rectangle) or (circle): ";
            cin.clear();
            cin.ignore();
            cin>>name;
        }

        cout << "Enter yield strength (MPa): ";
        cin >> ys;
        input_errors(ys);
        cout << "Enter density (kg/m^3): ";
        cin >> density;
        input_errors(density);
        Material new_material(name, ys, density); //assigning the new data to my class variables
        materials.push_back(new_material); //adding the new material to the database at the end

        return materials[materials.size() -1];
    }

    else
    {
        cout << "Invalid input! \nUsing default material (Steel).\n"; //in case of error in input, the application will restart
        return Material();
    }
}

string Material::get_name(){return name;}
double Material::get_strength(){return yieldStrength;}
double Material::get_density(){return density;}
