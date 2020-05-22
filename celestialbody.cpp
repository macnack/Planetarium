#include "celestialbody.h"

/*CelestialBody::CelestialBody()
{

}
*/
CelestialBody::CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<int> rgb)
    : diameter_(diameter), distance_(distance), spin_time_(spin_time), orbit_time_(orbit_time_), rgb_(rgb){}
//CelestialBody::CelestialBody(planet obj){};
void CelestialBody::draw_body(){
    double radius = diameter_ / 2.0;
    //bottom
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius,  radius, -radius);
    glVertex3d( radius,  radius, -radius);
    glVertex3d( radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();
    //top
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON); // bottom
    glVertex3d(-radius,  radius, radius);
    glVertex3d( radius,  radius, radius);
    glVertex3d( radius, -radius, radius);
    glVertex3d(-radius, -radius, radius);
    glEnd();
    //left
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius,  radius);
    glVertex3d(-radius,  radius,  radius);
    glVertex3d(-radius,  radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();
    //right
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(radius, -radius,  radius);
    glVertex3d(radius,  radius,  radius);
    glVertex3d(radius,  radius, -radius);
    glVertex3d(radius, -radius, -radius);
    glEnd();
    //front
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius,  radius);
    glVertex3d( radius, -radius,  radius);
    glVertex3d( radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();
    //back
    glColor3d(1.0,0.0,0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, radius,  radius);
    glVertex3d( radius, radius,  radius);
    glVertex3d( radius, radius, -radius);
    glVertex3d(-radius, radius, -radius);
    glEnd();
}
