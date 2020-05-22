#include "celestialbody.h"

CelestialBody::CelestialBody(int diameter, int distance, double spin_time, float orbit_time_, std::vector<float> rgb)
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
    float R = rgb_[0] * 1.f/255.f;
    float G = rgb_[1] * 1.f/255.f;
    float B = rgb_[2] * 1.f/255.f;
    //bottom
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON);
    glVertex3d(-radius,  radius, -radius);
    glVertex3d( radius,  radius, -radius);
    glVertex3d( radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();

    //top
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON); // bottom
    glVertex3d(-radius,  radius, radius);
    glVertex3d( radius,  radius, radius);
    glVertex3d( radius, -radius, radius);
    glVertex3d(-radius, -radius, radius);
    glEnd();

    //left
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius,  radius);
    glVertex3d(-radius,  radius,  radius);
    glVertex3d(-radius,  radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();

    //right
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON);
    glVertex3d(radius, -radius,  radius);
    glVertex3d(radius,  radius,  radius);
    glVertex3d(radius,  radius, -radius);
    glVertex3d(radius, -radius, -radius);
    glEnd();

    //front
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON);
    glVertex3d(-radius, -radius,  radius);
    glVertex3d( radius, -radius,  radius);
    glVertex3d( radius, -radius, -radius);
    glVertex3d(-radius, -radius, -radius);
    glEnd();
    
    //back
    //glColor3d(0.5, 0.5, 0.5);
    glColor3f( R , G , B );
    glBegin(GL_POLYGON);
    glVertex3d(-radius, radius,  radius);
    glVertex3d( radius, radius,  radius);
    glVertex3d( radius, radius, -radius);
    glVertex3d(-radius, radius, -radius);
    glEnd();
}

void CelestialBody::draw(float dir)
{
    double distance = distance_ / 100.0;
    double rot = dir * 360.0 * 1 / (spin_time_ * 864.00);
    float angle = dir * 360.0f * 1 / (orbit_time_ * 8640.00f);
    if (orbit_time_ == 0)
    {
        angle = 0.f;
    }
    glPushMatrix();                       // zapisuje pkt 0
    glTranslated(distance, 0.0, 0.0);     // distance    from Sun
    glRotated(rot, 0.0, 0.0, 1.0);        // spinn
    glScaled(0.01, 0.01, 0.01);           // sklala 1/100
    this->draw_body();                    // rysuj...
    glPopMatrix();                        // pobieram pkt 0
    glRotatef(angle, 0.0, 0.0, 1.0);        // circle move
}
