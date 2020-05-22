#include "celesialbody.h"
        //
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
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
planet pl;
bool read_file(std::string name){
    std::ifstream data(name);
    if(data.is_open()){
        std::stringstream input_data;
        std::string line;
        input_data << line << "\n";
        std::getline(data,line);
        while(std::getline(data,line)){
            input_data.str(line);
            std::string name_;
            std::string dis_;
            std::string dia_;
            std::string spi_;
            std::string orb_;
            std::string gra_;
            std::string moo_;
            std::vector<int> rgb;
            std::string r_;
            std::string g_;
            std::string b_;
            std::string end;
            input_data >> name_ >> dis_ >> dia_ >> spi_ >> orb_ >> gra_ >> moo_ >> r_ >> g_ >> b_ ;
            pl.name.push_back(name_);
            pl.distance.push_back(stoi(dis_));
            pl.diameter.push_back(stoi(dia_));
            pl.spin_time.push_back(stod(spi_));
            pl.orbit_time.push_back(stof(orb_));
            pl.gravity.push_back(stod(gra_));
            pl.moons.push_back(stoi(moo_));
            rgb.push_back(stoi(r_));
            rgb.push_back(stoi(g_));
            rgb.push_back(stoi(b_));
            pl.rgb.push_back(rgb);
        }
    }else{
        return 0;
    }
    return 1;
}
class CelestialBody{
public:
    CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<int> rgb)
        : diameter_(diameter), distance_(distance), spin_time_(spin_time), orbit_time_(orbit_time_), rgb_(rgb){}
    void show(){
        std::cout << diameter_ << " " << distance_ << " " << spin_time_ << " " << orbit_time_ << " ";
        for(auto &el : rgb_){
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
private:
    int diameter_ ;
    int distance_ ;
    double spin_time_;
    float orbit_time_;
    std::vector<int> rgb_;
};
