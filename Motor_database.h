#ifndef MOTOR_DATABASE_H
#define MOTOR_DATABASE_H
#include <vector>
using namespace std;
class Motor
{
private:
    string name;
    double torque, speed, mass, diameter, width, shaft_diameter;

public:
    Motor();
    Motor(string n,double t ,double s,double m,double d ,double w,double sd);
    string get_name();
    double get_torque();
    double get_speed();
    double get_mass();
    double get_diameter();
    double get_width();
    double get_shaft_diameter();
};
extern vector <Motor> motors;
void list_of_motors();


#endif // Motor_database
