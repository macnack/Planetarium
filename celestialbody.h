#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <GL/glu.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
struct planet
{
    std::vector<std::string> name;
    std::vector<int> distance;
    std::vector<int> diameter;
    std::vector<double> spin_time;
    std::vector<float> orbit_time;
    std::vector<double> gravity;
    std::vector<int> moons;
    std::vector<std::vector<int>> rgb;
};
class CelestialBody
{
public:
    CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<int> rgb);
    CelestialBody(planet obj);
    void show();
    void draw_body();
    void draw(float dir);

private:
    int diameter_;
    int distance_;
    double spin_time_;
    float orbit_time_;
    std::vector<int> rgb_;
};
#endif // CELESTIALBODY_H
