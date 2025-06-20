#include <iostream>
#include <limits>
#include "Global_functions.h"
#include "Calculations .h"
#include "Motor_database.h"
#include "Gearbox_database.h"
#include "Sorting.h"

using namespace std;

int main()
{
    double l, mass, acc;
    cout << "Welcome to the robotic arm designer!\n\n";
    string user;
    cout << "Enter (new) or use default specs (def): ";
    cin >> user;

    while (user != "def" && user != "new")
    {
        cout << "\nPlease input as declared between the brackets!\n";
        cout << "Enter (new) or use default values (def): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> user;
    }

    if (user == "new")
    {
        // taking arm specs from user.
        input_data(l, mass, acc);
        arm_specs arm1(mass, acc, l);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This line is used to clear input buffer (new line character)
        string type;
        cout << "Cross section (rectangle) or (circle): ";
        cin >> type;
        while (type != "rectangle" && type != "circle")
        {
            cout << "\nPlease input as declared between the brackets!\n";
            cout << "Cross section (rectangle) or (circle): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> type;
        }
        arm1.area_calc(type); // function to calculate area
        Material new_material = getMaterialFromUser(); // material selection function
        stress_calc arm_calculations(arm1, new_material); // object from stress calculation class
        arm_calculations.calc_inertia(type);
        arm_calculations.calc_max_stress(type);
        check(new_material, arm1, arm_calculations, type);
        list_of_motors();
        list_of_GearBoxes();
        Sorting(arm_calculations.get_mod_bending_M());

        arm1.output_mod_data(type); // to output the new modified data for the user
        cout << "Arm Mass = " << arm_calculations.get_mod_arm_mass() << " Kg\n"; // to output the new modified mass after the optimization
        cout << "Max stress = " << arm_calculations.calc_opt_stress(type) << " MPa\n";
    }

    else if (user == "def") // if the user chooses to use default dimensions and angular acceleration
    {
        // Showing the default values used to the user.
        arm_specs def;
        string area_type = "rectangle";
        default_dim(def);

        Material new_material = getMaterialFromUser();
        stress_calc arm_calculations(def, new_material);
        arm_calculations.calc_inertia(area_type);
        arm_calculations.calc_max_stress(area_type);
        check(new_material, def, arm_calculations, area_type);
        list_of_motors();
        list_of_GearBoxes();
        Sorting(arm_calculations.get_mod_bending_M());

        def.output_mod_data(area_type);
        cout << "Arm Mass = " << arm_calculations.get_mod_arm_mass() << " Kg\n";
        cout << "Max stress = " << arm_calculations.calc_opt_stress(area_type) << " MPa\n";
    }

    return 0;
}
