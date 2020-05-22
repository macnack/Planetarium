#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

#include <GL/glu.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
struct planet{
    std::vector<std::string> name;
    std::vector<int> distance;
    std::vector<int> diameter;
    std::vector<double> spin_time;
    std::vector<float> orbit_time;
    std::vector<double> gravity;
    std::vector<int> moons;
    std::vector<std::vector<int>> rgb;
};
class CelestialBody{
public:
    CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<int> rgb);
    CelestialBody(planet obj);
    void show(){
        std::cerr << diameter_ << " | " << distance_ << " | " << spin_time_ << " | " << orbit_time_ << " | ";
        for(auto &el : rgb_){
            std::cerr << el << " ";
        }
        std::cerr << " |" << std::endl;
    }
    void draw_body();
    void draw(float dir){
        double distance = distance_ / 100;
        double rot = dir * 360 * 1/ (spin_time_ * 8.6400);
        float angle = dir * 360 * 1/ (orbit_time_ * 8.6400);
        if( orbit_time_ == 0 ){
            angle = 0;
        }
        glPushMatrix();
        glTranslated(distance, 0.0, 0.0);       // location from Sun
        glRotatef(rot, 0.0, 0.0, 1.0);          // spinn
        glRotatef(angle, 0.0, 1.0, 0.0);        // orbit
        glTranslated(distance * 2, 0.0, 0.0);   // okrag o promieniu dystans od slonca
        glScaled(0.01, 0.01, 0.01);
        this->draw_body();
        glPopMatrix();
    }
private:
    int diameter_ ;
    int distance_ ;
    double spin_time_;
    float orbit_time_;
    std::vector<int> rgb_;
};
#endif // CELESTIALBODY_H
