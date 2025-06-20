#ifndef GEARBOX_DATABASE_H
#define GEARBOX_DATABASE_H
#include <vector>
using namespace std;
class Gear_Box
{
private:
    string name, Gratio;
    double efficiency, mass, diameter, width, max_shaft_diameter;

public:
    Gear_Box();
    Gear_Box(string n,string ratioo ,double eff,double masss,double dia ,double wid, double msd);
    string get_name();
    string get_gear_ratio();
    double get_efficiency();
    double get_mass();
    double get_diameter();
    double get_width();
    double get_max_shaft_diameter();
};
extern vector<Gear_Box> gearBoxes ;
void list_of_GearBoxes();

#endif // Gearbox_database
