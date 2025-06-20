#ifndef MATERIALS_H
#define MATERIALS_H

using namespace std;

class Material {
    private:
        string name;
        double yieldStrength;
        double density;
    public:
        Material();
        Material(string n, double ys, double d);
//getter functions to allow us to access the private variables values.
        string get_name();
        double get_strength();
        double get_density();
};

Material getMaterialFromUser();
#endif
