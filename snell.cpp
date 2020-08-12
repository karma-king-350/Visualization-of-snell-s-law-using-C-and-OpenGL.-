#include<iostream>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
using namespace std;
int dashLength=10;
int f=0;
float g=0.5;
void myInit()
{
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0,1600,0,800);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
}
float counter=0.0f;
float counter1=0.0f;
float line1_move=0.0f;
float sun_move=0.0f;
float fish_move=0.0f;
float fish_move1=0.0f;
float fish_move2=0.0f;
float i=0.0f;
float j=0.0f;
float x_move=0.0f;
float y_move=0.0f;
float x1_move=0.0f;
float y1_move=0.0f;
float cloud_move=0.0f;
float cloud_move1=0.0f;
float cloud_move2=0.0f;
int ox;
int oy;
void circle(float x,float y,double r)
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1=x+((r-.07)*cos(A));
        float y1=y+((r)*sin(A));
        glVertex2f(x1,y1);
    }
    glEnd();
}
void Sun()
{
    glColor3f(1.000,0.843,0.000);
    circle(-0.75,0.75,0.18);
}
void sky()
{


    glColor3f(.011,g,.98);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,0.0);
    glEnd();
}
void river()
{
    glColor3f(0.225,0.412,0.882);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(1.0f,0.0f);
    glVertex2f(-1.0f,0.0f);
    glEnd();
}
void normal()
{
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x7733);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.0,0.75);
    glVertex2f(-0.0,-0.80);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
void line1()
{
    counter+=.003;
{
    if(counter>0.8)
    {
        counter=-.75;
    }
}
    glColor3f(1.0,0.0,0.0);
    glLineWidth(3);
    glBegin(GL_LINES);
  glVertex2f(0.0f, 0.0f);
  glVertex2f(-0.75+counter, 0.75f);
  glBegin(GL_LINES);
  glVertex2f(-0.132f, 0.0f);
  glVertex2f(-0.75+counter, 0.588f);
  glVertex2f(-0.04f, 0.0f);
  glVertex2f(-0.73+counter, 0.631f);

  glEnd();
}

void line2()
{
    counter1-=.0015;
{
    if(counter1<-.4)
    {
        counter1=0.36;
    }
}
    glColor3f(1.0,0.0,0.0);
    glLineWidth(3);
    glBegin(GL_LINES);
  glVertex2f(-0.0f,0.0f);
  glVertex2f(0.36+ counter1, -0.96f);
  glEnd();
    glBegin(GL_LINES);
  glVertex2f(-0.132f, 0.0f);
  glVertex2f(0.208+ counter1,-0.917f);

  glEnd();
   glBegin(GL_LINES);
  glVertex2f(-0.04f, 0.0f);
  glVertex2f(0.29+ counter1,-0.95f);

  glEnd();
}
void Cloud1()
{
    glColor3f(0.80,0.80,0.80);
    circle(-0.85,0.77,0.15);
    circle(-0.79,0.70,0.15);
    circle(-0.70,0.70,0.15);
    circle(-0.75,0.77,0.15);
}
void Cloud2()
{
    glColor3f(0.80,0.80,0.80);
    circle(0.35,0.77,0.15);
    circle(0.45,0.70,0.15);
    circle(0.55,0.75,0.15);
    circle(0.45,0.80,0.15);
}
void Cloud3()
{
    glColor3f(0.80,0.80,0.80);
    circle(-0.07,0.85,0.15);
    circle(-0.01,0.80,0.15);
    circle(0.08,0.83,0.15);
    circle(0.02,0.85,0.15);
}
void arrow(){
    glColor3f(1,0,0);
  glBegin(GL_TRIANGLES);
   glVertex2f(-0.56f, 0.53f);
  glVertex2f(-0.57f,0.56f);
  glVertex2f(-0.6f, 0.5f);
  //glVertex2f(-0.633f,0.605f);
  glEnd();
}

void arrow2()
{
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);

        glVertex2f(0.01136f,- 0.06f);
        glVertex2f(0.03f,-0.019f);
        glVertex2f(0.03f,-0.0857f);
        //glVertex2f(-0.633f,0.605f);
    glEnd();

}
void fish1()
{
    glColor3f(0,0,0);
	//circle(.52,-.52,.01);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2d(-.1,-.408);
    glEnd();
   glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.130,-0.434);
	glVertex2f(-0.071,-0.326);
	glVertex2f(-0.071,-0.545);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.015,-0.44);
	glVertex2f(-0.071,-0.326);
	glVertex2f(-0.071,-0.545);
	glEnd();
	glColor3f(1.0,0.0,0.0);
    //glTranslatef(0.0,-0.46,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.015,-0.44);
	glVertex2f(0.030,-0.35);
	glVertex2f(0.030,-0.5);
	glEnd();


}


void tree2Code(float x){
    glPushMatrix();
    glScalef(0.2f, 0.3f, 0.0f);
    glTranslated(x,-3.55,0.0);
    glColor3f(0.3, 0.0, 0.0);
//timber
    glBegin(GL_POLYGON);
    glVertex3f(0.2, 0.0, 0.0);
    glVertex3f(0.3, 0.0, 0.0);
    glVertex3f(0.3, 0.35, 0.0);
    glVertex3f(0.2, 0.35, 0.0);
    glVertex3f(0.2, 0.0, 0.0);
    glEnd();
//lowest
    glColor3f(0.7,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.35, 0.0);
    glVertex3f(0.5, 0.35, 0.0);
    glVertex3f(0.40, 0.55, 0.0);
    glVertex3f(0.10, 0.55, 0.0);
    glVertex3f(0.0, 0.35, 0.0);
    glEnd();
//middle
    glBegin(GL_POLYGON);
    glVertex3f(0.05, 0.55, 0.0);
    glVertex3f(0.45, 0.55, 0.0);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.30, 0.75, 0.0);
    glVertex3f(0.20, 0.75, 0.0);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.05, 0.55, 0.0);
    glEnd();
//top
    glBegin(GL_POLYGON);
    glVertex3f(0.19, 0.75, 0.0);
    glVertex3f(0.40, 0.75, 0.0);
    glColor3f(0.4,1.0,0.0);
    glVertex3f(0.27, 0.95, 0.0);
    glVertex3f(0.10, 0.75, 0.0);
    glEnd();
    glPopMatrix();
}

void DrawTree2(){
    glPushMatrix();
    for(float f=-5;f<6;f+=1){
        tree2Code(f);
    }
    glPopMatrix();
}



void fish2()
{
    glColor3f(0,0,0);
	//circle(.52,-.52,.01);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2d(-.5538,-.2228);
    glEnd();

    glColor3f(0.0,1.0,.0);
	glBegin(GL_QUADS);
    glVertex2f(-0.7,-0.285);
	glVertex2f(-0.6,-0.385);
	glVertex2f(-0.5,-0.265);
    glVertex2f(-0.60,-0.128);
	glEnd();

    glColor3f(0.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.75,-0.237);
	glVertex2f(-0.7,-0.285);
	glVertex2f(-0.75,-0.42);
glEnd();
//circle(-.207,-.394,.001);

}

void DrawFish()
{
    glColor3f(0,0,0);
	//circle(.52,-.52,.01);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2d(.52,-.42);
    glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.47,-0.47);
	glVertex2f(0.56,-0.36);
	glVertex2f(0.56,-0.57);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.64,-0.47);
    glVertex2f(0.7,-0.4);
	glVertex2f(0.7,-0.56);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.64,-0.47);
	glVertex2f(0.56,-0.57);
	glVertex2f(0.56,-0.36);
	glEnd();


}
void bitmap(int x, int y, char *string,void *font)
 {
   int len, i;

   glRasterPos2f(x, y);
   len = (int) strlen(string);
   for (i = 0; i < len; i++) {
     glutBitmapCharacter(font, string[i]);
   }
 }
void *fonts[]=
 {
 GLUT_BITMAP_9_BY_15,
 GLUT_BITMAP_TIMES_ROMAN_10,
 GLUT_BITMAP_TIMES_ROMAN_24,
 GLUT_BITMAP_HELVETICA_18,
 GLUT_BITMAP_HELVETICA_12
 };
 void front()
 {
         glColor3f( 0.87,0.58,0.98);
         bitmap(365,130," DAYANANDA SAGAR ACADEMY OF TECHNOLOGY",fonts[2]);
         glColor3f(1,1,1);
         bitmap(375,100,"DEPT. OF COMPUTER SCIENCE & ENGG.",fonts[0]);
         glColor3f(0.5,1.0,0.5);
         bitmap(300,600,"SNELL'S LAW DEMONSTRATION",fonts[2]);
         glColor3f(0,1.0,0);
         bitmap(450,500,"SUBMITTED BY :",fonts[0]);
         glColor3f(1,1,1);
         bitmap(225,450,"Rubiya jugal",fonts[3]);
         bitmap(670,450,"Gnanesh M R",fonts[3]);
         bitmap(180,300,"",fonts[3]);
         bitmap(220,400,"(1DT18CS411)",fonts[0]);
         bitmap(680,400,"(1DT17CS034)",fonts[0]);
         glColor3f(0.5,1.0,0.5);
         bitmap(380,200,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
 }
 void menu()
 {
         glColor3f(0.5,1.0,0.0);
         bitmap(170,480,"SNELL'S LAW DEMONSTRATION",fonts[2]);
         glColor3f(0.0,0.6,0.3);
         bitmap(300,400,"SELECT AN OPTION",fonts[2]);
         bitmap(300,380,"-----------------",fonts[2]);
         glColor3f(0.3,0.5,0.8);
         bitmap(300,300,"[1] DESCRIPTION",fonts[3]);
         bitmap(300,260,"[2] INCIDENT A RAY OF LIGHT",fonts[3]);
         bitmap(300,220,"[3] SEE THE REFRACTION",fonts[3]);
         bitmap(300,180,"[q] QUIT",fonts[3]);
         bitmap(300,100,"PRESS 'I' TO INCIDENT",fonts[3]);
         bitmap(300,60,"PRESS 'R' TO REFRACT",fonts[3]);
         glColor3f(0.5,0.2,0.6);
 }
 void discription()
 {
  glColor3f(0.5,1.0,0.0);
  bitmap(100,480,"SNELL'S LAW: The ratio of the sine of the angle of incidence to the sine of the angle of refraction is a constant, for the light",fonts[2]);
  glColor3f(0.5,1.0,0.0);
  bitmap(100,440,"of a given colour and for the given pair of media",fonts[2]);
  glColor3f(0.3,0.5,0.8);
  bitmap(300,300,"(sin i)/(sin r)",fonts[3]);
  glColor3f(0.5,1.0,0.0);
  bitmap(100,360,"LET 'i' BE THE ANGLE OF INCIDENCE AND 'r' BE THE ANGLE OF REFRACTION",fonts[2]);

 }
void incident_Display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
   // Sun();

glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud1();
glPopMatrix();

glPushMatrix();
glTranslatef(fish_move,0.0,0.0);
DrawFish();
glPopMatrix();

glPushMatrix();
glTranslatef(fish_move1,0.0,0.0);
fish1();
glPopMatrix();

glPushMatrix();
glTranslatef(fish_move2,0.0,0.0);
fish2();
glPopMatrix();

 glPushMatrix();
    DrawTree2();
    glPopMatrix();
glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud2();
glPopMatrix();
glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud3();
glPopMatrix();
cloud_move+=.002;
{
  if(cloud_move>1.9)
    {
        cloud_move=-1.0;
    }
}
cloud_move1+=.003;
{
    if(cloud_move>1.0)
    {
        cloud_move=-1.7;
    }
}
cloud_move2+=.003;
{

    if(cloud_move>1.5)
    {
        cloud_move=-1.2;
    }
}
sun_move+=.003;
{
    if(sun_move>0.8)
    {
        sun_move=-.75;
        g=.5;
    }
}

//glPushMatrix();
//glTranslatef(x_move,y_move,0.0);
//arrow();
//glPopMatrix();
glPushMatrix();
glTranslatef(sun_move,0.0,0.0);
Sun();
glPopMatrix();

//glPushMatrix();
//glTranslatef(counter,0.0,0.0);
line1();
//glPopMatrix();

g+=.002;
//Sleep(100);
//    if(g>=1.0)
//    {
//        g=.5;
//   }
y_move-=.003;
{
    if(y_move>.54)
    {
        for(i=345;i>160;i--)
        y_move=0.4755*i;
    }
}
x_move+=.003;
{
    if(x_move>.54)
    {
        for(j=288;j<683;j++)
            x_move=2.103*j;
    }

}
fish_move-=.005;
{
  if(fish_move<-2.5)
    {
        fish_move=1.5;
    }
}
fish_move1-=.005;
{
  if(fish_move1<-2.5)
    {
        fish_move1=1.5;
    }
}
fish_move2+=.005;
{
  if(fish_move2>1.5)
    {
        fish_move2=.1;
    }
}
      glPushMatrix();
      glPopMatrix();
      glFlush();
      glEnable(GL_LIGHT0);
  //    sun_move+=0.005;
      normal();
//line12();

sky();

river();
glutSwapBuffers();
}
void refraction_Display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    //Sun();
glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud1();
glPopMatrix();
glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud2();
glPopMatrix();
glPushMatrix();
glTranslatef(cloud_move,0.0,0.0);
Cloud3();
glPopMatrix();

 glPushMatrix();
    DrawTree2();
    glPopMatrix();
glPushMatrix();
glTranslatef(fish_move,0.0,0.0);
DrawFish();
glPopMatrix();

glPushMatrix();
glTranslatef(fish_move1,0.0,0.0);
fish1();
glPopMatrix();

glPushMatrix();
glTranslatef(fish_move2,0.0,0.0);
fish2();
glPopMatrix();
cloud_move+=.002;
{
  if(cloud_move>1.9)
    {
        cloud_move=-1.0;
    }
}
cloud_move1+=.003;
{
    if(cloud_move>1.0)
    {
        cloud_move=-1.7;
    }
}
cloud_move2+=.003;
{

    if(cloud_move>1.5)
    {
        cloud_move=-1.2;
    }
}



sun_move+=.003;
{
    if(sun_move>0.8)
    {
        sun_move=-.75;
        g=.5;
    }
}
//glPushMatrix();
//glTranslatef(x_move,y_move,0.0);
//arrow();
//glPopMatrix();

glPushMatrix();
glTranslatef(sun_move,0.0,0.0);
Sun();
glPopMatrix();

//glPushMatrix();
//    glTranslatef(x1_move,y1_move,0.0);
//    arrow2();
//    glPopMatrix();

x1_move+=.003;

	y1_move=-2.667*x1_move;

y_move-=.0003;
{
    if(y_move>.54)
    {
        for(i=345;i>160;i--)
        y_move=0.4755*i;
    }
}
x_move+=.0003;
{
    if(x_move>.54)
    {
        for(j=288;j<683;j++)
            x_move=2.103*j;
    }

}
fish_move-=.005;
{
  if(fish_move<-2.5)
    {
        fish_move=1.5;
    }
}
fish_move1-=.007;
{
  if(fish_move1<-2.5)
    {
        fish_move1=1.5;
    }
}
fish_move2+=.005;
{
  if(fish_move2>1.5)
    {
        fish_move2=.1;
    }
}
      glPushMatrix();
      glPopMatrix();
      glFlush();
      glEnable(GL_LIGHT0);
      //sun_move+=0.005;
      normal();
line1();
line2();
g+=.002;
sky();
river();
glutSwapBuffers();
}
void menuset()
 {
         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         glOrtho(-1, 1, -1, 1, -1, 1);
         glMatrixMode(GL_MODELVIEW);
         glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
 }
void Display()
{
 if(f==0)
         {
             glClearColor(0.7,0.7,1.0,0.0);
                 menuset();
                 front();
                 glutSwapBuffers();
         }
         else if(f==1)
         {
             menuset();
                 menu();
                 glutSwapBuffers();
         }
         else if(f==2)
         {
             menuset();
                 discription();
                 glutSwapBuffers();
         }

         else if(f==3)
         {
                 incident_Display();
         }
         else if(f==4)
         {
           refraction_Display();
         }
         else
         {
           refraction_Display();
         }
}
void keyboardFunc( unsigned char key, int x, int y )
 {
         if(f==0)
                 f=1;
         else if(f==1)
         {
                switch(key)
                {
                case 'd':
                case 'D':f=2;break;
                case 'q':
                case 'Q':exit(0);
                }
         }
         else if(f==2)
         {

                 switch(key)
                 {
                 case 'i':
                 case 'I':f=3;break;
                 case 'q':
                 case 'Q':exit(0);
                 }
         }
         else if(f==3)
         {
                switch(key)
                 {
                 case 'r':
                 case 'R':f=4;break;
                 case 'q':
                 case 'Q':exit(0);
                 }
         }

          else
         {
                switch(key)
                 {
                 case 'r':
                 case 'R':f=4;break;
                 case 'q':
                 case 'Q':exit(0);
                 }
         }
   glutPostRedisplay( );
 }
 void mouse(int btn, int state, int x, int y){
    float mx = x ;
    float my = y ;
    ox = (mx/700) -1.0;
    oy = -((my/350) -1.0);
    switch(btn){
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN){
                printf("x %f\n",mx);
                printf("y %f\n",my);
            }
            break;
    }

};
void TimeEvent(int values)
{
    glutPostRedisplay();
    glutTimerFunc(25,TimeEvent,0);
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1400,700);
    glutCreateWindow("sneel's law");
    myInit();
    glutDisplayFunc(Display);
    glutTimerFunc(200,TimeEvent,0);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();
    return 0;
}
