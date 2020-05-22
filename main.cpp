//
//  main.cpp
//  sfml_opengl
//
//  Created by Jakub Tomczyński on 27/02/2019.
//  Copyright © 2019 Jakub Tomczyński. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#include <celestialbody.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <celestialbody.h>
#ifdef __APPLE__
#include <OpenGL/glu.h> // macOS
#else
#include <GL/glu.h> // Windows/Linux
#endif

void draw_cube(double size) {
    double half_cube_size = size / 2.0;
    // bottom //140 177 222
    glBegin(GL_POLYGON);
    glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
    glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    glEnd();

    // top
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
    glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    glEnd();

    // left
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
    glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    glEnd();

    // right
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
    glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    glEnd();

    // front
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
    glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
    glEnd();

    // back
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, half_cube_size);
    glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
    glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
    glEnd();
}
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
GLdouble eyez = 3;
GLdouble view_pos_x;
GLdouble view_pos_y;
void set_viewport(int width, int height) {
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    gluLookAt(-3, 20, 60, 0, 0, 0, 0, 0, 1);
    //gluLookAt(0, 0, 0, 60, 0, 0, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//void move_cam(){
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//        eyez -= 0.1;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//        eyez += 0.1;
//    }
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluLookAt(0, -5, eyez, 0, 0, 0, 2, 0, 10);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
int main() {
    // create the window
    if(!read_file("/home/maciek/work/Planetarium/solar/solar_system.txt")){return 1;};
    std::vector<CelestialBody> CelestialBodies;
    for(unsigned int i = 0; i < pl.name.size(); i++){
        CelestialBodies.emplace_back(CelestialBody(pl.diameter[i], pl.distance[i], pl.spin_time[i], pl.orbit_time[i], pl.rgb[i]));
    }
    sf::Window window(sf::VideoMode(1024, 768), "SFML OpenGL Template", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // activate the window
    window.setActive(true);

    // set viewport according to current window size
    view_pos_x = window.getSize().x;
    view_pos_y = window.getSize().y;
    set_viewport(view_pos_x, view_pos_y);

    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);

    // setup lights

    GLfloat light_position[] = { 2.0, 0.0, 2.0, 1.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat light_specular[] = { 0.0, 0.0, 0.0, 1.0 };

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );

    GLfloat global_ambient[] = {0.3, 0.3, 0.3, 0.1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_NORMALIZE) ;

    // load resources, initialize the OpenGL states, ...

    // run the main loop
    bool running = true;

    sf::Clock clk;

    while (running) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            } else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                set_viewport(event.size.width, event.size.height);
            } else if (event.type == sf::Event::KeyPressed){
                set_viewport(event.size.width, event.size.height);
                //std::cerr << "x: " <<view_pos_x << "y:" << view_pos_y << "\n";
            }
        }
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE) ;
        glEnable (GL_COLOR_MATERIAL);

        set_viewport(view_pos_x, view_pos_y );
        //float rot = clk.getElapsedTime().asSeconds() * 90;
        float dir = clk.getElapsedTime().asSeconds();
        // draw stuff
        for( auto &CelestialBodie : CelestialBodies){
            CelestialBodie.draw(dir);
        }


        //camera move
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            view_pos_y -= 1.5 * dir;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            view_pos_y += 1.5 * dir;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            view_pos_x -= 2.5 * dir;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            view_pos_x += 2.5 * dir;
        }

        // TODO
        // test functions below (glTranslated, glRotated, glColor3d)
        // what happens when you change their arguments?
        // does their order change the result?


        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;
}
