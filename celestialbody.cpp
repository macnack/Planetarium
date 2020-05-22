#include "celestialbody.h"

CelestialBody::CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<int> rgb)
    : diameter_(diameter), distance_(distance), spin_time_(spin_time), orbit_time_(orbit_time_), rgb_(rgb) {}

//CelestialBody::CelestialBody(planet obj){};

void CelestialBody::show()
{
    std::cerr << diameter_ << " | " << distance_ << " | " << spin_time_ << " | " << orbit_time_ << " | ";
    for (auto &el : rgb_)
    {
        std::cerr << el << " ";
    }
    std::cerr << " |" << std::endl;
}

void CelestialBody::draw_body()
{
    double radius = diameter_ / 2.0;
    //bottom
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, radius, -radius);
    glVertex3d(radius, radius, -radius);
    glVertex3d(radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();

    //top
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON); // bottom
    glVertex3d(-radius, radius, radius);
    glVertex3d(radius, radius, radius);
    glVertex3d(radius, -radius, radius);
    glVertex3d(-radius, -radius, radius);
    glEnd();

    //left
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius, radius);
    glVertex3d(-radius, radius, radius);
    glVertex3d(-radius, radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();

    //right
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(radius, -radius, radius);
    glVertex3d(radius, radius, radius);
    glVertex3d(radius, radius, -radius);
    glVertex3d(radius, -radius, -radius);
    glEnd();

    //front
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius, radius);
    glVertex3d(radius, -radius, radius);
    glVertex3d(radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();
    
    //back
    glColor3d(1.0, 0.0, 0.0);
    //glColor3i(rgb_[0],rgb_[1], rgb_[2]);
    glBegin(GL_POLYGON);
    glVertex3d(-radius, radius, radius);
    glVertex3d(radius, radius, radius);
    glVertex3d(radius, radius, -radius);
    glVertex3d(-radius, radius, -radius);
    glEnd();
}

void CelestialBody::draw(float dir)
{
    double distance = distance_ / 100.0;
    double rot = dir * 360.0 * 1 / (spin_time_ * 8.6400);
    float angle = dir * 360.0f * 1 / (orbit_time_ * 8.6400);
    if (orbit_time_ == 0)
    {
        angle = 0.f;
    }
    glPushMatrix();
    glTranslated(distance, 0.0, 0.0);     // location from Sun
    glRotatef(rot, 0.0, 0.0, 1.0);        // spinn
    glRotatef(angle, 0.0, 1.0, 0.0);      // orbit
    glTranslated(distance * 2, 0.0, 0.0); // okrag o promieniu dystans od slonca
    glScaled(0.01, 0.01, 0.01);
    this->draw_body();
    glPopMatrix();
}
