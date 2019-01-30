#define VARD 15
#define LIMITE_INFERIOR 50
#include<vector>
struct bala{  int x,y; };
#include<time.h>
#include <windows.h>
#include <C:\Program Files (x86)\freeglut\include\GL\glut.h>
#include<iostream>
#include <stdlib.h>
#include<cstring>
#include<unistd.h>
#include<stdbool.h>
#include <mmsystem.h.>
using namespace std;


//generales
 double ancho = 1000, altura = 630;

//alien Variables
 unsigned int MAX_ALIEN=33;
 GLfloat alien_pos[33][2];
 bool alien_present[33];
 unsigned int  alien_speed[33];
 int ALIEN_COUNT;

// juego
int game_state;
int nivel ;

int k;
// nave
bool nave_left,nave_right;
unsigned int ship_span = 20, FPS = 60 ;
int ship_x = (ancho/2), ship_y = LIMITE_INFERIOR, unidad_mov=20;
float v,w,y;
//explosion
bool explosion_present;
//balas
std::vector <struct bala> balas;
//score
 long long int curr_score;


void sonido_enter(){
    sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/enter.wav",SND_SYNC);
}
void sonido_esc(){
     sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/smb_gameover.wav",SND_SYNC);
}
void sonido_colision(){
     sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/invasorm.wav",SND_ASYNC);
}
void sonido_disparo(){
     sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/shoot.wav",SND_ASYNC);
}
void sonido_intro(){
    PlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/str.wav", NULL, SND_NOSTOP| SND_ASYNC);
}

void fondo_espacio(){
     for(int i=0;i<40;i++){
     v=rand()%(int)ancho;
     w=rand()%(int)altura;
    glPointSize(2);
    glBegin(GL_POINTS);

    if (nivel==1)
    glColor3f(1.,1.,0.);
    if (nivel==2)
    glColor3f(1.,0.,0.);
    if (nivel==3)
    glColor3f(0.,1.,1.);

    glVertex2f(v,w);
    //cout<<i+1<<"--> "<<v<<"  -  "<<w<<"---"<<endl;
    glEnd();
    }
}
void monstr1(){
     glBegin(GL_QUADS);
                glColor3f(1.0,1.0,0.0);

                glVertex2f(16,8);
                glVertex2f(-12,8);
                glVertex2f(-12,-8);
                glVertex2f(16,-8);
            glEnd();
  glBegin(GL_QUADS);
                                glVertex2f(16,-4);
                glVertex2f(16,4);
                glVertex2f(20,4);
                glVertex2f(20,-4);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-12,-4);
                glVertex2f(12,4);
                glVertex2f(-16,4);
                glVertex2f(-16,-4);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(20,0);
                glVertex2f(24,0);
                glVertex2f(24,-12);
                glVertex2f(20,-12);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-20,-12);
                glVertex2f(-20,0);
                glVertex2f(-16,0);
                glVertex2f(-16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(8,8);
                glVertex2f(8,12);
                glVertex2f(12,12);
                glVertex2f(12,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-4,8);
                glVertex2f(-4,12);
                glVertex2f(-8,12);
                glVertex2f(-8,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,12);
                glVertex2f(12,16);
                glVertex2f(16,16);
                glVertex2f(16,12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,12);
                glVertex2f(-12,16);
                glVertex2f(-8,16);
                glVertex2f(-8,12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(4,-16);
                glVertex2f(4,-12);
                glVertex2f(12,-12);
                glVertex2f(12,-16);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-8,-16);
                glVertex2f(-8,-12);
                glVertex2f(0,-12);
                glVertex2f(0,-16);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,-12);
                glVertex2f(12,-8);
                glVertex2f(16,-8);
                glVertex2f(16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,-12);
                glVertex2f(-12,-8);
                glVertex2f(-8,-8);
                glVertex2f(-8,-12);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(12,4);
                glVertex2f(12,0);
            glEnd();

  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
            glEnd();
}
void monstr0(){
     glBegin(GL_QUADS);
                glColor3f(1.0,1.0,1.0);

                glVertex2f(16,8);
                glVertex2f(-12,8);
                glVertex2f(-12,-8);
                glVertex2f(16,-8);
            glEnd();
  glBegin(GL_QUADS);
                                glVertex2f(16,-4);
                glVertex2f(16,4);
                glVertex2f(20,4);
                glVertex2f(20,-4);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-12,-4);
                glVertex2f(12,4);
                glVertex2f(-16,4);
                glVertex2f(-16,-4);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(20,0);
                glVertex2f(24,0);
                glVertex2f(24,-12);
                glVertex2f(20,-12);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-20,-12);
                glVertex2f(-20,0);
                glVertex2f(-16,0);
                glVertex2f(-16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(8,8);
                glVertex2f(8,12);
                glVertex2f(12,12);
                glVertex2f(12,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-4,8);
                glVertex2f(-4,12);
                glVertex2f(-8,12);
                glVertex2f(-8,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,12);
                glVertex2f(12,16);
                glVertex2f(16,16);
                glVertex2f(16,12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,12);
                glVertex2f(-12,16);
                glVertex2f(-8,16);
                glVertex2f(-8,12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(4,-16);
                glVertex2f(4,-12);
                glVertex2f(12,-12);
                glVertex2f(12,-16);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-8,-16);
                glVertex2f(-8,-12);
                glVertex2f(0,-12);
                glVertex2f(0,-16);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,-12);
                glVertex2f(12,-8);
                glVertex2f(16,-8);
                glVertex2f(16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,-12);
                glVertex2f(-12,-8);
                glVertex2f(-8,-8);
                glVertex2f(-8,-12);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(12,4);
                glVertex2f(12,0);
            glEnd();

  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
            glEnd();
}
void monstr2(){
     glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(-10,-14);
                glVertex2f(-10,12);
                glVertex2f(20,12);
                glVertex2f(20,-14);
            glEnd();

  glBegin(GL_QUADS);
                glColor3f(1.,1.,1.);
                glVertex2f(6,2);
                glVertex2f(6,10);
                glVertex2f(16,10);
                glVertex2f(16,2);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(1.,1.,1.);
                glVertex2f(8,10);
                glVertex2f(8,12);
                glVertex2f(14,12);
                glVertex2f(14,10);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(1.,1.,1.);
                glVertex2f(8,0);
                glVertex2f(8,2);
                glVertex2f(14,2);
                glVertex2f(14,0);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(0.,0.,0.);
                glVertex2f(6,10);
                glVertex2f(12,10);
                glVertex2f(12,4);
                glVertex2f(6,4);
       glEnd();

              glBegin(GL_QUADS);
                glColor3f(1.,1.,1.);
                glVertex2f(-10,2);
                glVertex2f(-10,10);
                glVertex2f(0,10);
                glVertex2f(0,2);
            glEnd();
              glBegin(GL_QUADS);
                glColor3f(1.,1.,1.);
                glVertex2f(-8,0);
                glVertex2f(-8,12);
                glVertex2f(-2,12);
                glVertex2f(-2,0);
            glEnd();
              glBegin(GL_QUADS);
                glColor3f(0.,0.,0.);
                glVertex2f(-10,10);
                glVertex2f(-10,4);
                glVertex2f(-4,4);
                glVertex2f(-4,10);
            glEnd();

              glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(-8,12);
                glVertex2f(-8,14);
                glVertex2f(18,14);
                glVertex2f(18,12);
            glEnd();

              glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(-6,14);
                glVertex2f(-6,18);
                glVertex2f(16,18);
                glVertex2f(16,14);
            glEnd();

              glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(12,20);
                glVertex2f(12,18);
                glVertex2f(-2,18);
                glVertex2f(-2,20);
            glEnd();
              glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(20,4);
                glVertex2f(20,-14);
                glVertex2f(22,-14);
                glVertex2f(22,4);
            glEnd();
             glBegin(GL_QUADS);
                glColor3f(1.,0.,0.);
                glVertex2f(-10,4);
                glVertex2f(-10,-14);
                glVertex2f(-12,-14);
                glVertex2f(-12,4);
            glEnd();


}
void monstr3(){

            glColor3f(1.,0.,1.);

     glBegin(GL_QUADS);
                glVertex2f(-16,-4);
                glVertex2f(16,-4);
                glVertex2f(16,4);
                glVertex2f(-16,4);
            glEnd();
  glBegin(GL_QUADS);
                glVertex2f(-12,4);
                glVertex2f(12,4);
                glVertex2f(12,8);
                glVertex2f(-12,8);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-8,8);
                glVertex2f(8,8);
                glVertex2f(8,12);
                glVertex2f(-8,12);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-4,12);
                glVertex2f(4,12);
                glVertex2f(4,16);
                glVertex2f(-4,16);
            glEnd();
  glBegin(GL_QUADS);

                glVertex2f(-8,-4);
                glVertex2f(-4,-4);
                glVertex2f(-4,-8);
                glVertex2f(-8,-8);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(4,-4);
                glVertex2f(8,-4);
                glVertex2f(8,-8);
                glVertex2f(4,-8);
                  glEnd();
              glBegin(GL_QUADS);
                glVertex2f(-16,-16);
                glVertex2f(-16,-12);
                glVertex2f(-12,-12);
                glVertex2f(-12,-16);
                glEnd();
              glBegin(GL_QUADS);
                 glVertex2f(16,-16);
                glVertex2f(16,-12);
                glVertex2f(12,-12);
                glVertex2f(12,-16);
              glEnd();
              glBegin(GL_QUADS);
                glVertex2f(-12,-12);
                glVertex2f(-12,-8);
                glVertex2f(-8,-8);
                glVertex2f(-8,-12);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(12,-12);
                glVertex2f(12,-8);
                glVertex2f(8,-8);
                glVertex2f(8,-12);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(-8,-16);
                glVertex2f(-8,-12);
                glVertex2f(-4,-12);
                glVertex2f(-4,-16);
            glEnd();
              glBegin(GL_QUADS);
           glVertex2f(8,-16);
                glVertex2f(8,-12);
                glVertex2f(4,-12);
                glVertex2f(4,-16);
            glEnd();
             glBegin(GL_QUADS);
           glVertex2f(-4,-12);
                glVertex2f(-4,-8);
                glVertex2f(4,-8);
                glVertex2f(4,-12);
            glEnd();

   glColor3f(0.,0.,0.);
     glBegin(GL_QUADS);

                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
glEnd();
glBegin(GL_QUADS);


                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(4,4);
                glVertex2f(4,0);
        glEnd();
         }
void monstr4(){
       glColor3f(0.0,1.0,0);
     glBegin(GL_QUADS);

                glVertex2f(16,8);
                glVertex2f(-12,8);
                glVertex2f(-12,-8);
                glVertex2f(16,-8);
            glEnd();
  glBegin(GL_QUADS);
                                glVertex2f(16,-8);
                glVertex2f(20,-8);
                glVertex2f(20,4);
                glVertex2f(16,4);
            glEnd();
  glBegin(GL_QUADS);
                  glVertex2f(-12,-8);
                glVertex2f(-16,-8);
                glVertex2f(-16,4);
                glVertex2f(-12,4);
           glEnd();
  glBegin(GL_QUADS);

                glVertex2f(20,-4);
                glVertex2f(24,-4);
                glVertex2f(24,12);
                glVertex2f(20,12);
            glEnd();
  glBegin(GL_QUADS);
        glVertex2f(-16,-4);
                glVertex2f(-20,-4);
                glVertex2f(-20,12);
                glVertex2f(-16,12);
            glEnd();
            //-------------------------------------
              glBegin(GL_QUADS);

                glVertex2f(8,8);
                glVertex2f(8,12);
                glVertex2f(12,12);
                glVertex2f(12,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-4,8);
                glVertex2f(-4,12);
                glVertex2f(-8,12);
                glVertex2f(-8,8);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,12);
                glVertex2f(12,16);
                glVertex2f(16,16);
                glVertex2f(16,12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,12);
                glVertex2f(-12,16);
                glVertex2f(-8,16);
                glVertex2f(-8,12);
            glEnd();
            //----------------------------
              glBegin(GL_QUADS);

                glVertex2f(-16,-16);
                glVertex2f(-16,-12);
                glVertex2f(-12,-12);
                glVertex2f(-12,-16);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(16,-16);
                glVertex2f(20,-16);
                glVertex2f(20,-12);
                glVertex2f(16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(12,-12);
                glVertex2f(12,-8);
                glVertex2f(16,-8);
                glVertex2f(16,-12);
            glEnd();
              glBegin(GL_QUADS);

                glVertex2f(-12,-12);
                glVertex2f(-12,-8);
                glVertex2f(-8,-8);
                glVertex2f(-8,-12);
            glEnd();
  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(12,4);
                glVertex2f(12,0);
            glEnd();

  glBegin(GL_QUADS);
                glColor3f(0,0,0);
                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
            glEnd();
}
void nave(){
       glColor3f(1.0,1.0,1.0);
     glBegin(GL_QUADS);
                glVertex2f(-20,-20);
                glVertex2f(-20,-4);
                glVertex2f(-16,-4);
                glVertex2f(-16,-20);
            glEnd();
      glBegin(GL_QUADS);
                glVertex2f(20,-20);
                glVertex2f(20,-4);
                glVertex2f(24,-4);
                glVertex2f(24,-20);
            glEnd();
    glBegin(GL_QUADS);
                glVertex2f(-16,-16);
                glVertex2f(-16,-8);
                glVertex2f(-12,-8);
                glVertex2f(-12,-16);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(16,-16);
                glVertex2f(16,-8);
                glVertex2f(20,-8);
                glVertex2f(20,-16);
            glEnd();
                glBegin(GL_QUADS);
                glVertex2f(-12,-12);
                glVertex2f(-12,12);
                glVertex2f(-8,12);
                glVertex2f(-8,-12);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(12,-12);
                glVertex2f(12,12);
                glVertex2f(16,12);
                glVertex2f(16,-12);
            glEnd();
            //-------------
       glBegin(GL_QUADS);
                glVertex2f(-8,-16);
                glVertex2f(-8,4);
                glVertex2f(12,4);
                glVertex2f(12,-16);
            glEnd();
    glBegin(GL_QUADS);
                glVertex2f(-4,4);
                glVertex2f(-4,12);
                glVertex2f(8,12);
                glVertex2f(8,4);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(0,12);
                glVertex2f(0,24);
                glVertex2f(4,24);
                glVertex2f(4,12);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(0,-20);
                glVertex2f(0,-16);
                glVertex2f(4,-16);
                glVertex2f(4,-20);
            glEnd();
  glColor3f(1.,0.,0.);
    glBegin(GL_QUADS);
                glVertex2f(-20,-4);
                glVertex2f(-20,0);
                glVertex2f(-16,0);
                glVertex2f(-16,-4);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(20,-4);
                glVertex2f(20,0);
                glVertex2f(24,0);
                glVertex2f(24,-4);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(-12,8);
                glVertex2f(-12,12);
                glVertex2f(-8,12);
                glVertex2f(-8,8);
            glEnd();


    glBegin(GL_QUADS);
                glVertex2f(12,8);
                glVertex2f(12,12);
                glVertex2f(16,12);
                glVertex2f(16,8);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(-8,-16);
                glVertex2f(-8,-12);
                glVertex2f(0,-12);
                glVertex2f(0,-16);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(4,-16);
                glVertex2f(4,-12);
                glVertex2f(12,-12);
                glVertex2f(12,-16);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(-4,-8);
                glVertex2f(-4,0);
                glVertex2f(0,0);
                glVertex2f(0,-8);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(4,-8);
                glVertex2f(4,0);
                glVertex2f(8,0);
                glVertex2f(8,-8);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(0,-4);
                glVertex2f(0,4);
                glVertex2f(4,4);
                glVertex2f(4,-4);
            glEnd();

    glColor3f(0.,1.,1.);
    glBegin(GL_QUADS);
                glVertex2f(-12,-4);
                glVertex2f(-12,0);
                glVertex2f(-8,0);
                glVertex2f(-8,-4);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(12,-4);
                glVertex2f(12,0);
                glVertex2f(16,0);
                glVertex2f(16,-4);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
            glEnd();

    glBegin(GL_QUADS);
                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(12,4);
                glVertex2f(12,0);
            glEnd();
}
void explosion(){
    glColor3f(1.0,0.0,0.0);
   glBegin(GL_QUADS);
                glVertex2f(12,-4);
                glVertex2f(12,0);
                glVertex2f(16,0);
                glVertex2f(16,-4);
            glEnd();
  glBegin(GL_QUADS);
                glVertex2f(-12,0);
                glVertex2f(-12,4);
                glVertex2f(-8,4);
                glVertex2f(-8,0);
            glEnd();
glBegin(GL_QUADS);
                glVertex2f(-4,0);
                glVertex2f(-4,4);
                glVertex2f(4,4);
                glVertex2f(4,0);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(4,4);
                glVertex2f(4,8);
                glVertex2f(8,8);
                glVertex2f(8,4);
            glEnd();
             glBegin(GL_QUADS);
                glVertex2f(12,4);
                glVertex2f(12,8);
                glVertex2f(16,8);
                glVertex2f(16,4);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(-28,8);
                glVertex2f(-28,12);
                glVertex2f(-24,12);
                glVertex2f(-24,8);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(-16,8);
                glVertex2f(-16,12);
                glVertex2f(-12,12);
                glVertex2f(-12,8);
            glEnd();
               glBegin(GL_QUADS);
                glVertex2f(20,8);
                glVertex2f(20,12);
                glVertex2f(24,12);
                glVertex2f(24,8);
            glEnd();
               glBegin(GL_QUADS);
                glVertex2f(-24,12);
                glVertex2f(-24,16);
                glVertex2f(-20,16);
                glVertex2f(-24,12);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(0,12);
                glVertex2f(0,16);
                glVertex2f(4,16);
                glVertex2f(4,12);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(24,12);
                glVertex2f(24,16);
                glVertex2f(28,16);
                glVertex2f(28,12);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(-8,16);
                glVertex2f(-8,20);
                glVertex2f(-4,20);
                glVertex2f(-4,16);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(0,16);
                glVertex2f(0,20);
                glVertex2f(8,20);
                glVertex2f(8,16);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(16,16);
                glVertex2f(16,20);
                glVertex2f(24,20);
                glVertex2f(24,16);
            glEnd();
              glBegin(GL_QUADS);
                glVertex2f(-12,36);
                glVertex2f(-12,40);
                glVertex2f(-8,40);
                glVertex2f(-8,36);
            glEnd();
            glColor3f(1,1,0);

              glBegin(GL_QUADS);
                glVertex2f(-16,-12);
                glVertex2f(-16,-8);
                glVertex2f(-12,-8);
                glVertex2f(-12,-12);
            glEnd();
             glBegin(GL_QUADS);
                glVertex2f(8,-12);
                glVertex2f(8,-8);
                glVertex2f(12,-8);
                glVertex2f(12,-12);
            glEnd();
             glBegin(GL_QUADS);
                glVertex2f(-8,0);
                glVertex2f(-8,4);
                glVertex2f(-4,4);
                glVertex2f(-4,0);
            glEnd();
                 glBegin(GL_QUADS);
                glVertex2f(8,0);
                glVertex2f(8,4);
                glVertex2f(12,4);
                glVertex2f(12,0);
            glEnd();
                 glBegin(GL_QUADS);
                glVertex2f(-16,4);
                glVertex2f(-16,8);
                glVertex2f(-12,8);
                glVertex2f(-12,4);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(-8,8);
                glVertex2f(-8,12);
                glVertex2f(-4,12);
                glVertex2f(-4,8);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(8,8);
                glVertex2f(8,12);
                glVertex2f(12,12);
                glVertex2f(12,8);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(28,8);
                glVertex2f(28,12);
                glVertex2f(32,12);
                glVertex2f(32,8);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(-16,12);
                glVertex2f(-16,16);
                glVertex2f(-12,16);
                glVertex2f(-12,12);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(4,12);
                glVertex2f(4,16);
                glVertex2f(8,16);
                glVertex2f(8,12);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(16,12);
                glVertex2f(16,16);
                glVertex2f(20,16);
                glVertex2f(20,12);
            glEnd();

                 glBegin(GL_QUADS);
                glVertex2f(-4,16);
                glVertex2f(-4,24);
                glVertex2f(0,24);
                glVertex2f(0,12);
            glEnd();
               glBegin(GL_QUADS);
                glVertex2f(8,20);
                glVertex2f(8,24);
                glVertex2f(12,24);
                glVertex2f(12,20);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(16,24);
                glVertex2f(16,28);
                glVertex2f(20,28);
                glVertex2f(20,24);
            glEnd();
                           glBegin(GL_QUADS);
                glVertex2f(-8,28);
                glVertex2f(-8,32);
                glVertex2f(-4,32);
                glVertex2f(-4,28);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(-4,-4);
                glVertex2f(0,0);
                glVertex2f(0,0);
                glVertex2f(-4,-4);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(-4,-16);
                glVertex2f(-4,-12);
                glVertex2f(0,-12);
                glVertex2f(0,-16);
            glEnd();
            glBegin(GL_QUADS);
                glVertex2f(-12,-24);
                glVertex2f(-12,-20);
                glVertex2f(-8,-20);
                glVertex2f(-8,-24);
            glEnd();
            glColor3f(1.,0.5,0.);
                glBegin(GL_QUADS);
                glVertex2f(-8,-20);
                glVertex2f(-8,-16);
                glVertex2f(-4,-16);
                glVertex2f(-4,-20);
            glEnd();




}
void fondo_aliens(){
for(int i=0;i<5;i++){
     v=rand()%(int)ancho;
     w=rand()%(int)altura;
       glPushMatrix();
        glTranslatef(v,w,0);
        glScalef(1.,1.,1);
        monstr0();
        glPopMatrix();
    }}

void draw_string(std::string str){
    for(unsigned int i=0;i<str.length();i++){
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *(str.begin()+i)); }
}

void dibujo_bienvenida(){
    fondo_aliens();
    glPushMatrix();
    glTranslatef(ancho/2.0-250,altura/2.0-160,0);
    glColor3f(0.,0.,0.);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();

     glLineWidth(8);
    glColor3f(255.,255.,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,-20);
        glVertex2f(500,-20);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();

        glLineWidth(7);
        glPushMatrix();
        glTranslatef(40,250,0);
        glScalef(0.3,0.3,0.3);
        glColor3f(255.0,0.0,255.0);
        draw_string("I n v a s o r e s");
        glPopMatrix();

    glPushMatrix();
          glColor3f(1.0, 0.0, 0.0);
          glBegin(GL_POLYGON);
             glVertex2f(80,80);
             glVertex2f(440,80);
             glVertex2f(440,180);
             glVertex2f(80,180);
          glEnd();

            glLineWidth(5);
            glColor3f(1.,1.0,1.0);
            glBegin(GL_LINE_LOOP);
             glVertex2f(80,80);
             glVertex2f(440,80);
             glVertex2f(440,180);
             glVertex2f(80,180);
            glEnd();

            glPushMatrix();
            glTranslatef(350,130,0);
            glScalef(1.5,1.5,0.);
            monstr0();
            glPopMatrix();


        glPopMatrix();

        glLineWidth(7);
        glPushMatrix();
        glTranslatef(140,120,0);
        glScalef(0.35,0.35,0.);
        glColor3f(1.,1.,1.0);
        draw_string("PLAY");
        glPopMatrix();
  glLineWidth(4);

        glPushMatrix();
        glTranslatef(260,120,0);
         glLineWidth(5);
            glColor3f(1.,1.0,1.0);
            glBegin(GL_LINES);
             glVertex2f(0.,0.);
             glVertex2f(20.,0);
             glVertex2f(0.,0.0);
             glVertex2f(8,5);

             glVertex2f(0.,0.0);
             glVertex2f(8,-5);

             glVertex2f(20.,0.0);
             glVertex2f(20.,25);
            glEnd();

        glPopMatrix();




    glPopMatrix();

}
void dibujo_nivel1(){
     glPushMatrix();
    glLineWidth(9);
    glColor3f(1.,1.,1.);
    glBegin(GL_LINE_LOOP);
        glVertex2f(ancho-198,1);
        glVertex2f(ancho-3,1);
        glVertex2f(ancho-3,27);
        glVertex2f(ancho-198,27);
    glEnd();
    glLineWidth(5);
    glColor3f(1.,1.,0.);
    glBegin(GL_POLYGON);
        glVertex2f(ancho-195,3);
        glVertex2f(ancho-5,3);
        glVertex2f(ancho-5,26);
        glVertex2f(ancho-195,26);
    glEnd();

       glLineWidth(2);
        glColor3f(1.,1.,1.0);
        glPushMatrix();
        glTranslatef(ancho-160,10,0);
        glScalef(0.1,0.1,0.);
        draw_string("NIVEL 1");
        glPopMatrix();

glPopMatrix();

}
void dibujo_nivel2(){
    glPushMatrix();
    glLineWidth(9);
    glColor3f(1.,1.,1.);
    glBegin(GL_LINE_LOOP);
        glVertex2f(ancho-198,1);
        glVertex2f(ancho-3,1);
        glVertex2f(ancho-3,27);
        glVertex2f(ancho-198,27);
    glEnd();
    glLineWidth(5);
    glColor3f(1.,0.,0.);
    glBegin(GL_POLYGON);
        glVertex2f(ancho-195,3);
        glVertex2f(ancho-5,3);
        glVertex2f(ancho-5,26);
        glVertex2f(ancho-195,26);
    glEnd();

       glLineWidth(2);
        glColor3f(1.,1.,1.0);
        glPushMatrix();
        glTranslatef(ancho-160,10,0);
        glScalef(0.1,0.1,0.);
        draw_string("NIVEL 2");
        glPopMatrix();





    glPopMatrix();

}
void dibujo_nivel3(){
     glPushMatrix();
    glLineWidth(9);
    glColor3f(1.,1.,1.);
    glBegin(GL_LINE_LOOP);
        glVertex2f(ancho-198,1);
        glVertex2f(ancho-3,1);
        glVertex2f(ancho-3,27);
        glVertex2f(ancho-198,27);
    glEnd();
    glLineWidth(5);
    glColor3f(0.,1.,1.);
    glBegin(GL_POLYGON);
        glVertex2f(ancho-195,3);
        glVertex2f(ancho-5,3);
        glVertex2f(ancho-5,26);
        glVertex2f(ancho-195,26);
    glEnd();

       glLineWidth(2);
        glColor3f(1.,1.,1.0);
        glPushMatrix();
        glTranslatef(ancho-160,10,0);
        glScalef(0.1,0.1,0.);
        draw_string("NIVEL 3");
        glPopMatrix();





    glPopMatrix();

}
void dibujar_valor_puntaje(long long int curr_score){
    long long int tempsc = curr_score;
    int stk[20],sp=0;

    while(tempsc>0)
    {
        stk[sp++] = (tempsc%10);
        tempsc /= 10;
    }
    sp--;
    while(sp>=0)
    {

        glutStrokeCharacter(GLUT_STROKE_ROMAN, stk[sp--]+'0');
    }
    if(curr_score == 0)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
}
void dibujo_score(){
    glPushMatrix();

    glLineWidth(3);
    glPushMatrix();
    glTranslatef(17,12,0);
    glScalef(0.7,-0.7,0.);
    monstr1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(47,12,0);
    glScalef(0.7,-0.7,0.);
    monstr3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(77,12,0);
    glScalef(0.7,-0.7,0.);
    monstr4();
    glPopMatrix();

    glLineWidth(2);
    glColor3f(1.,1.,1.);
    glPushMatrix();
    glTranslatef(90,4,0);
    glScalef(0.2,0.2,1);
    draw_string(" score: ");
    dibujar_valor_puntaje(curr_score);
    glPopMatrix();

    glLineWidth(5);
    glColor3f(1,0.98,0);
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex2f(2,29);
    glVertex2f(ancho-200,29);
    glEnd();
    glPopMatrix();

    glPopMatrix();

}
void dibujo_gracias(){
    glPushMatrix();
    glTranslatef(ancho/2.0-250,altura/2.0-160,0);
    glColor3f(0.,0.,0.);
    glBegin(GL_POLYGON);
        glVertex2f(0,-20);
        glVertex2f(500,-20);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();

    glLineWidth(8);
    glColor3f(255.,255.,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,-20);
        glVertex2f(500,-20);
        glVertex2f(500,320);
        glVertex2f(0,320);
    glEnd();

        glLineWidth(7);
        glPushMatrix();
        glTranslatef(40,250,0);
        glScalef(0.3,0.3,0.3);
        glColor3f(255.0,0.0,255.0);
        draw_string("I n v a s o r e s");
        glPopMatrix();

        glPushMatrix();
          glColor3f(1.0, 0.0, 0.0);
          glBegin(GL_POLYGON);
             glVertex2f(80,80);
             glVertex2f(440,80);
             glVertex2f(440,180);
             glVertex2f(80,180);
          glEnd();

            glLineWidth(5);
            glColor3f(1.,1.0,1.0);
            glBegin(GL_LINE_LOOP);
             glVertex2f(80,80);
             glVertex2f(440,80);
             glVertex2f(440,180);
             glVertex2f(80,180);
            glEnd();

            glPushMatrix();
            glColor3f(1.,1.,1.);
            glTranslatef(400,130,0);
            glScalef(1.5,-1.5,0.);
            monstr0();
            glPopMatrix();


        glPopMatrix();

        glLineWidth(5);
        glPushMatrix();
        glTranslatef(100,120,0);
        glScalef(0.3,0.3,0.);
        glColor3f(1.,1.,1.0);
        draw_string("GAME OVER");
        glPopMatrix();

        glLineWidth(3);
        glPushMatrix();
        glTranslatef(300,20,0);
        glScalef(0.2,0.2,0.);
        glColor3f(255.,255.,0.0);
        draw_string("Score : ");
        dibujar_valor_puntaje(curr_score);
        glPopMatrix();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    Sleep(4000);
 exit(0);
}


void dibujo_aliens(){
     unsigned int i;
    for(i=0;i<MAX_ALIEN;i++)
    {
        int p=i/11;

    if(ALIEN_COUNT%33==0){
         alien_present[i]=true;
          }

    if (alien_present[i]==true){
        glPushMatrix();
        glTranslatef(alien_pos[i][0],alien_pos[i][1],0);
        if(p==0){ monstr3();}
        if(p==1){ monstr1();}
        if(p==2){ monstr4();}
        glPopMatrix();
         }
    if(explosion_present==true && alien_present[i]==false){
    glPushMatrix();
    glTranslatef(alien_pos[i][0],alien_pos[i][1],0);
    explosion();
    glPopMatrix();
}

     }

explosion_present=false;
}
void movimiento_aliens(){
    unsigned int i;

    for(i=0;i<MAX_ALIEN;i++)
    {
       //velocidad por niveles
       if (nivel==1) alien_pos[i][0] += (alien_speed[i]);
       if (nivel==2) alien_pos[i][0] += (alien_speed[i]+3);
       if (nivel==3) alien_pos[i][0] += (alien_speed[i]+6);
       //tope y pos inicial del movimiento
        if(alien_pos[i][0]>=ancho-20){
           alien_pos[i][0] = 20;
        }
     }
  }

void dibujo_balas(){
    unsigned int i;
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(4);
    glBegin(GL_POINTS);
    for(i=0;i<balas.size();i++){
        glVertex2i(balas[i].x,balas[i].y);
    }
    glEnd();
}
void movimiento_bala(){
    unsigned int i;
   for(i = 0;i < balas.size(); i++)
    {
        balas[i].y += 15;
        if(balas[i].y>=altura)
balas.erase(balas.begin() + i),i--;

    }
}
void agregar_bala(){
    struct bala tp;
    tp.x = ship_x  ;
    tp.y = ship_y ;
    balas.push_back(tp);
}


void movimiento_nave(){
 if(nave_left)
    {
         if(ship_x>(int)unidad_mov){
            ship_x -= unidad_mov;}
         else if(ship_x<=unidad_mov){
            ship_x=ship_span/2;}
    }
    if(nave_right)
    {
        if(ship_x<=(ancho-ship_span-unidad_mov)){
            ship_x += unidad_mov;}
        else if(ship_x<=(ancho-ship_span)){
            ship_x = ancho-ship_span;}
    }
}
void dibujo_nave(int x, int y){
    glPushMatrix();
    glTranslatef(ship_x,ship_y,0);
    nave();
    glPopMatrix();
    glFlush();
}


void TeclaPresionada(int key, int x, int y){
         switch(key)
    {
        case GLUT_KEY_LEFT:
            //sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/move.wav",SND_ASYNC);
            nave_left = true, nave_right = false;
                            break;
        case GLUT_KEY_RIGHT:
            //sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/move.wav",SND_ASYNC);
            nave_right = true,nave_left = false;
                             break;
    }
    }
void TeclasUp(int key, int x, int y) {
 switch(key)
    {
        case GLUT_KEY_LEFT: nave_left = false;
                            break;
        case GLUT_KEY_RIGHT:nave_right = false;
                            break;
    }
}
void Tecla_normal(unsigned char key, int x, int y){
     if (key == 13){
        sonido_enter();
       if(game_state == 1)
         game_state = 2;
    }
    if (key == 27){
   sonido_esc();
        if(game_state == 2 || game_state==1)
                game_state=3;
                    }

}
void Tecla_normal_up(unsigned char key, int x, int y){
    switch(key)
    {
        case 32:
            glutIgnoreKeyRepeat(1);
            sonido_disparo();
                    if(game_state == 2)
                        agregar_bala();
                    break;
    }
}


void myinit(){

   cout<<endl<<"inicio ..reinicio"<<endl;
   unsigned int i;
   curr_score = 0;
   k = 0;
   nivel=1;
   nave_left = false, nave_right = false, game_state = 1;
   ALIEN_COUNT = 0;
    for(i=0;i<MAX_ALIEN;i++){
      int p=i/11;
      if (p==0) {
       alien_pos[i][0] = 60+ship_span+80*i;
        alien_pos[i][1] = altura-(3*VARD);}
       if (p ==1){
       alien_pos[i][0] = 60+ship_span+80*(i-11);
       alien_pos[i][1] = altura-(3*VARD)-40;}
       if (p==2){
       alien_pos[i][0] = 60+ship_span+80*(i-22);
        alien_pos[i][1] = altura-(3*VARD)-80;}
        alien_speed[i] = 8;
        alien_present[i]=true;}
}


bool colision_bala_alien(struct bala bull, int bomb_ind){
    if(alien_present[bomb_ind]==false) return false;
    if(bull.y<(alien_pos[bomb_ind][1]-VARD)) return false;
    if(bull.y>(alien_pos[bomb_ind][1]+VARD)) return false;
    if(bull.x<(alien_pos[bomb_ind][0]-VARD)) return false;
    if(bull.x>(alien_pos[bomb_ind][0]+VARD)) return false;
    return true;
}
void detectar_colision(){
    unsigned int i,j;
    for(i = 0; i < balas.size(); i++){
        for(j = 0;j < MAX_ALIEN; j++){
            if(alien_present[j] && colision_bala_alien(balas[i], j))
            {
                 sonido_colision();
                 int p=j/11;
                 if(p==0){
                    if (nivel==1) curr_score =curr_score+300;
                    if (nivel==2) curr_score =curr_score+200;
                    if (nivel==3)curr_score =curr_score+100;}
                 if(p==1){
                     if (nivel==1) curr_score =curr_score+220;
                     if (nivel==2) curr_score =curr_score+120;
                     if (nivel==3) curr_score =curr_score+80;}
                 if(p==2){
                  if (nivel==1) curr_score =curr_score+100;
                  if (nivel==2) curr_score =curr_score+80;
                  if (nivel==3) curr_score =curr_score+25;}

                alien_present[j]=false;
                explosion_present=true;
                ALIEN_COUNT++;
                balas.erase(balas.begin() + i);
                i--;

            }}}
}

void mover(int v){
 if(game_state == 2){
    movimiento_nave();
    movimiento_aliens();
    movimiento_bala();
    detectar_colision();
}
glutTimerFunc(60,mover,v);
glutPostRedisplay();

}


void PintarEscena(){
    glClearColor(0, 0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    fondo_espacio();

    if(game_state == 1){dibujo_bienvenida();}
    if(game_state == 2){
     dibujo_nivel1();
     if(curr_score>=6820 ){
//sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/Level-complete.wav",SND_NOSTOP| SND_ASYNC);
        nivel=2;
        dibujo_nivel2();
    }
//      if(curr_score==11220 ){
//  //   sndPlaySound("C:/Users/MEL/Documents/computacion grafica/lab/verjuego/Level-complete.wav",SND_SYNC);
//   }
       if(curr_score>=11220){
       nivel=3;
       dibujo_nivel3();

        if (ALIEN_COUNT==99)
            dibujo_gracias();
        }

       dibujo_nave(ship_x,ship_y);
       dibujo_balas();
       dibujo_aliens();
       dibujo_score();

    }
    if(game_state == 3){

        dibujo_gracias();
   }

    glFlush();
    glutSwapBuffers();
}
void reshape(int w, int h){
    ship_x = (ship_x*w)/ancho;
    ancho = (GLdouble) w;
    altura = (GLdouble) h;
   glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, ancho, 0.0, altura);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA );

    glutInitWindowPosition(30,30); //Posicion de la ventana
    glutInitWindowSize((int)ancho,(int)altura);
    glutCreateWindow(" ---------- "); //TITULO DE LA VENTANA
    myinit();
    glutReshapeFunc(reshape);
    glutDisplayFunc(PintarEscena);//Funcion de dibujado
    glutKeyboardFunc(Tecla_normal);
    glutKeyboardUpFunc(Tecla_normal_up);
    glutSpecialFunc(TeclaPresionada);
    glutSpecialUpFunc(TeclasUp);
    glutTimerFunc(100,mover,0);
    sonido_intro();
    glutMainLoop();
    return 0;
}
