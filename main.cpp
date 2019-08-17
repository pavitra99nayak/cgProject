#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<unistd.h>
#define PI 3.1415926535898

float yr=0.0;
float b2=0.0,b4=0.0;
float pr=0.0;
float x,y;
void font_g();
void font_f();
void font_s();
void font_p();
void circle(float ,float ,float );
void pulley_lines();
void floor_distinguish();
void lift_box();
void load();
void pulley();
void mykeyboard( unsigned char , int , int  );
void mydisplay();
void display_lift();
void display_mall();
void display_working();
void frontsreen();
void font_load();
 void font_mall();
void drawstring();
void setFont();
void helpscreen();
GLint flag=0;
void *currentfont;
void font_lift();

void setFont(void *font)
{
	currentfont=font;
}

void backg_lift()
{
 glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex2i(0,0);
    glColor3f(0,0,1);
    glVertex2i(1346,0);
    glColor3f(1,1,1);
    glVertex2i(1346,728);
    glColor3f(0,0,1);
    glVertex2i(0,728);
glEnd();
}

void backg_description()
{
 glBegin(GL_POLYGON);
    glColor3f(0.9,0.98,0.98);
    glVertex2i(0,0);
    glColor3f(1,0.2,0.3);
    glVertex2i(1346,0);
    glColor3f(0.9,0.98,0.98);
    glVertex2i(1346,728);
     glColor3f(1,0.2,0.3);
    glVertex2i(0,728);
glEnd();
}

void backg_front_navigation()
{
 glBegin(GL_POLYGON);
    glColor3f(0,0.2,0.5);
    glVertex2i(0,0);
    glColor3f(1,0.2,0.3);
    glVertex2i(1346,0);
    glColor3f(0,0.2,0.5);
    glVertex2i(1346,728);
     glColor3f(1,0.2,0.3);
    glVertex2i(0,728);
glEnd();
}

void boarder()
{

    glColor3f(0.2,0.4,0.6);
    glLineWidth(8.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0,0);
    glVertex2i(1346,0);
    glVertex2i(1346,728);
    glVertex2i(0,728);
    glEnd();
}
void boarder1()
{

    glColor3f(0,0,0.6);
    glLineWidth(8.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(0,0);
    glVertex2i(1346,0);
    glVertex2i(1346,728);
    glVertex2i(0,728);
    glEnd();
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{
        glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    backg_front_navigation();

    glColor3f(1,1,0);
    drawstring(310.0,696.0,0.0,"MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
    glColor3f(0.9,0,0.8);
    drawstring(330,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0,0.5);
    drawstring(550,580,0.0,"A MINI PROJECT ON");
    glColor3f(0,0.7,1);
    drawstring(470,530,0.0,"GRAPHICAL SIMULATION OF LIFT");
    drawstring(470,528,0.0,"_______________________________");
    glColor3f(1,0.5,0);
    drawstring(667,480,0.0,"BY");
    glColor3f(0.9,0,0.8);
    drawstring(350,430,0.0,"NAMITHA DSOUZA                                                4MT16CS047");
    drawstring(350,380,0.0,"PAVITRA NAYAK                                                    4MT16CS056");
    glColor3f(1, 0.5, 0);
    drawstring(540,320,0.0,"UNDER THE GUIDENCE OF ");
    glColor3f(0.8,0.8,0);
    drawstring(190,270,0.0,"MR PRASHANTH B S");
    drawstring(190,230,0.0,"ASSISTANT PROFESSOR");
    drawstring(190,190,0.0,"DEPARTMANET OF CS&E,");
    drawstring(190,150,0.0,"M.I.T.E, MOODABIDRI");
    drawstring(980,270.0,0,"MRS SARANYA BABU");
    drawstring(980,230,0.0,"ASSISTANT PROFESSOR");
    drawstring(980,190,0.0,"DEPARTMANET OF CS&E,");
    drawstring(980,150,0.0,"M.I.T.E, MOODABIDRI");

    glFlush();
}

void helpscreen()
{

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glClearColor(0,0,0,0);                                               /*background for cover page*/
    glClear(GL_COLOR_BUFFER_BIT);

    backg_front_navigation();
    //boarder1();
    glColor3f(1,1,1);
    drawstring(550.0,640.0,0.0,"NAVIGATIONS");
    drawstring(550.0,638.0,0.0,"_____________");
    glColor3f(1,1,1);
    drawstring(350.0,540.0,0.0,"FIRST FLOOR                                             PRESS '1'");
    drawstring(350.0,440.0,0.0,"SECOND FLOOR                                        PRESS '2'");
    drawstring(350.0,340.0,0.0,"GROUND FLOOR                                      PRESS 'g'");
    drawstring(350.0,240.0,0.0,"STOP AND EXIT                                       PRESS 'Esc'");
    drawstring(350.0,140.0,0.0,"NEXT SCENE                                            PRESS 'Enter'");

    glFlush();
}

void circle(float x,float y,float r)                         //to draw circle with filled color
{
    float theta;
    int i;
    glBegin(GL_POLYGON);
        for(i=0;i<360;i++)
        {
              theta=(i*PI)/180;
              glVertex2f(x+r*cos(theta),y+r*sin(theta));
        }
    glEnd();
}

void pulley_lines()
{
    glPushMatrix();
glColor3f(0.8, 0.5, 0.5);                                           //red for pulley strip
glBegin(GL_POLYGON);                                            //left pulley strip
    glVertex2i(395,710);
    glVertex2i(393,710);
    glVertex2i(393,420+b2);
    glVertex2i(395,420+b2);
glEnd();
glBegin(GL_POLYGON);                                            //right pulley strip
    glVertex2i(447,710);
    glVertex2i(449,710);
    glVertex2i(449,420+b4);
    glVertex2i(447,420+b4);
glEnd();
glPopMatrix();
}

void floor_distinguish()
{

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);                                      //boundary between first and ground floor
    glVertex2i(451,2);
    glVertex2i(1200,2);
glEnd();

glBegin(GL_LINES);                                      //boundary between first and second floor
    glVertex2i(451,230);
    glVertex2i(1200,230);
glEnd();

glBegin(GL_LINES);                                       //boundary between second and third floor
    glVertex2i(451,460);
    glVertex2i(1200,460);
glEnd();

glBegin(GL_LINES);                                        //upper boundary..i,e end of 3rd floor
    glVertex2i(451,690);
    glVertex2i(1200,690);
glEnd();
font_g();
font_f();
font_s();
}

void lift_box()
{
//glClear(GL_COLOR_BUFFER_BIT);

glColor3f(0.1,0.5,0.0);                                  //greenish color
glBegin(GL_POLYGON);                                    //for trapezoidal like structure above the lift
    glVertex2i(500,420+yr);
    glVertex2i(745,420+yr);
    glVertex2i(700,460+yr);
    glVertex2i(545,460+yr);
glEnd();
font_lift();
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);                                                 //for rectangle like structure
    glVertex2i(445,230+yr);
    glVertex2i(800,230+yr);
    glVertex2i(800,420+yr);
    glVertex2i(445,420+yr);
glEnd();

glColor3f(0.0,0.5,1.0);                                              //baby blue
glBegin(GL_POLYGON);                                                //left door
    glVertex2i(500,230+yr);
    glVertex2i(575+50,230+yr);
    glVertex2i(575+50,420+yr);
    glVertex2i(500,420+yr);
glEnd();
glBegin(GL_POLYGON);                                               //right door
    glVertex2i(576+50,230+yr);
    glVertex2i(745,230+yr);
    glVertex2i(745,420+yr);
    glVertex2i(576+50,420+yr);
glEnd();
glFlush();
}

void load()
{
    glPushMatrix();
glColor3f(0.5, 0.8, 0.5);                                               //brown
glBegin(GL_POLYGON);
    glVertex2i(250,230+pr);
    glVertex2i(400,230+pr);
    glVertex2i(400,420+pr);
    glVertex2i(250,420+pr);
glEnd();
glPopMatrix();
font_load();
}

void pulley()                                                       //function for pulley
{
glColor3f(0.0,1.0,0.0);
    circle(421,700,27);                                              //first call bigger pulley and then smaller one;
glColor3f(0.5,0.5,0.5);
    circle(421,700,10);
font_p();
}

void mykeyboard( unsigned char key, int x, int y )
{
    int i;
switch(key)
{
    case 13:
                if(flag==3)
                {
                    flag=4;
                    mydisplay();
                }
                if(flag==2)
                {
                    flag=3;
                    mydisplay();
                }
                if(flag==1)
                {
                    flag=2;
                    mydisplay();
                }
                    if(flag==0)
                {
                    flag=1;
                    mydisplay();
                }
            break;
    case  'g':    if(yr==0)                                      //if lift is there at first floor  //103==g
                    {
                        //for(i=0;i<230;i++)
                       // usleep(10000);
                         for(i=0;i<230;i++)
                         {
                             usleep(1000);
                             //lift_box();
                             yr--;
                             pr++;
                             b2++;
                             b4--;

                             glutPostRedisplay();
                         }
                   }
                   else if(yr==230||yr==229)                     //if lift is there at 2nd fllor
                     {
                         //for(i=0;i<230;i++)
                         //usleep(1000);
                          for(i=0;i<460;i++)
                          {
                              usleep(1000);
                             yr--;
                             pr++;
                             b2++;
                             b4--;

                             glutPostRedisplay();
                          }
                     }
                    else{
                             glutPostRedisplay();                   //you are already at your destination fl0or
                        }

                    break;
  case '1'      :     if(yr==-230||yr==-229)                          //if lift is at ground floor  //46==1
                     {
                         //for(i=0;i<230;i++)
                         //usleep(1000);
                         for(i=0;i<230;i++)
                         {
                             usleep(100);
                             yr++;
                             pr--;
                             b2--;
                             b4++;

                             glutPostRedisplay();
                         }
                     }
                      else if(yr==230||yr==229)                         //if lift is at 2nd ground floor
                     {
                         //for(i=0;i<230;i++)
                         //usleep(1000);
                         for(i=0;i<230;i++)
                          {
                              usleep(1000);
                              yr--;
                              pr++;
                              b2++;
                              b4--;

                              glutPostRedisplay();
                          }
                     }
                       else{                                    //if lift is already at the first floor
                            glutPostRedisplay();
                         }
                    break;
case    '2'       :   if(yr==-230||yr==-229)                     //if list is at ground floor
                     {
                         //for(i=0;i<230;i++)
                         //usleep(1000);
                         for(i=0;i<460;i++)
                          {
                              usleep(100);
                              yr++;
                              pr--;
                              b2--;
                              b4++;

                              glutPostRedisplay();
                          }
                     }
                    else if(yr==0)                              //if lift is at first fl0or
                     {
                         //for(i=0;i<230;i++)
                         //usleep(1000);
                         for(i=0;i<230;i++)
                          {
                              usleep(100);
                              yr++;
                              pr--;
                              b2--;
                              b4++;

                              glutPostRedisplay();
                          }
                     }
                     else{
                            glutPostRedisplay();
                        }
                       break;
case 27        :     exit(0);                                  //escape to come out of program
default        :    glutPostRedisplay() ;                      //if user enters any value <g or >2 because here we have only 3 floors<g,1,2>
}
}

void mydisplay()
{
//glClear(GL_COLOR_BUFFER_BIT);
if(flag==0)
    frontscreen();
if(flag==1)
	helpscreen();
if(flag==2)
    display_mall();
if(flag==3)
    display_working();
if(flag==4)
    display_lift();
glutSwapBuffers();
}

void font_f()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,330.0,0.0,"FIRST FLOOR");
}

void font_p()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(500.0,710.0,0.0,"PULLEY");
}

void font_mall()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(498.0,580.0,0.0,"MALL");
}

void font_g()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,120.0,0.0,"GROUND FLOOR");
}

void font_s()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,1,1);
    drawstring(1000.0,560.0,0.0,"SECOND FLOOR");
}

void font_load()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(300.0,320.0+pr,0.0,"LOAD");
}

void font_lift()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(605.0,432.0+yr,0.0,"LIFT");
}

void circle1(float x, float y, float r)
{
    float theta;
    //glColor3f(0.0, 0.0, 0.0 );
    glBegin(GL_LINE_LOOP);
    int i;
    for ( i=0 ; i< 360 ;i++)
    {
        theta=i*PI/180;
        glVertex2f(x+r*cos(theta),y+r*sin(theta));
    }
    glEnd();
}

void font1()
{


    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(1,1,1);
    //usleep(1000);
    drawstring(478.0,100.0,0.0,"PRESS ENTER FOR  VIEWING THE DESCRIPTION OF LIFT");
}
void font2()
{


    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0,0,0);
    drawstring(826.0,100.0,0.0,"PRESS ENTER FOR VIEWING THE WORKING OF LIFT");
}

void rectangle()
{

glColor3f(0.8,0.5,0.0);

  glBegin(GL_POLYGON);
  glVertex2f(150,150);
  glVertex2f(150,600);
  glVertex2f(900,600);
  glVertex2f(900,150);
  glVertex2f(50,200);
  glVertex2f(50,650);
  glVertex2f(800,650);
  glVertex2f(900,600);
glEnd();
font_mall();
}

void lines()
{
  glColor3f(1.0,1.0,0.0);
      glLineWidth(4);

  glBegin(GL_LINE_LOOP);

  glVertex2i(150,150);
  glVertex2i(50,200);
  glVertex2i(50,650);
  glVertex2i(150,600);
  glVertex2i(150,150);
  glVertex2i(900,150);
  glVertex2i(900,600);
  glVertex2i(800,650);
  glVertex2i(50,650);
  glVertex2i(150,600);
  glVertex2i(900,600);
  glVertex2i(900,150);
glEnd();
}

void road()
{

glColor3f(0.0,0.3,0.01);
    glBegin(GL_POLYGON);
    glVertex2i(0,50);
    glVertex2i(0,200);
    glVertex2i(1346,200);
    glVertex2i(1346,50);
    glEnd();
glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(0,50);
    glVertex2i(1346,50);
    glVertex2i(1346,0);
    glEnd();

}

void tree ()
{
    glColor3f(0.2,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(1160,150);
    glVertex2f(1160,380);
    glVertex2f(1195,380);
    glVertex2f(1195,150);
    glEnd();

    glColor3f(0.0,0.3,0.01);
    circle(1200,400,50);
    circle(1180,390,50);
    circle(1120,420,50);
    circle(1148,480,50);
    circle(1222,450,50);
    circle(1230,400,40);
}

void man1()
{
glColor3f(0.0, 0.0, 0.0 );
circle(435,124,14.3);
    glLineWidth(2.2);
    glBegin(GL_LINES);
    glVertex2f(435,80);
    glVertex2f(435,120);

    glVertex2f(435,80);
    glVertex2f(417,60);

    glVertex2f(435,80);
    glVertex2f(453,60);

    glVertex2f(435,92);
    glVertex2f(415,110);

    glVertex2f(435,92);
    glVertex2f(455,110);

    glEnd();
}

void man2()
{
glColor3f(0.0, 0.0, 0.0 );
circle(435-70,124,14.3);
    glLineWidth(2.2);
    glBegin(GL_LINES);
    glVertex2f(435-70,80);
    glVertex2f(435-70,120);

    glVertex2f(435-70,80);
    glVertex2f(417-70,60);

    glVertex2f(435-70,80);
    glVertex2f(453-70,60);

    glVertex2f(435-70,92);
    glVertex2f(415-70,110);

    glVertex2f(435-70,92);
    glVertex2f(455-70,110);

    glEnd();
glFlush();
}
void man3()
{
glColor3f(0.0, 0.0, 0.0 );
circle(435+700,124,14.3);
    glLineWidth(2.2);
    glBegin(GL_LINES);
    glVertex2f(435+700,80);
    glVertex2f(435+700,120);

    glVertex2f(435+700,80);
    glVertex2f(417+700,60);

    glVertex2f(435+700,80);
    glVertex2f(453+700,60);

    glVertex2f(435+700,92);
    glVertex2f(415+700,110);

    glVertex2f(435+700,92);
    glVertex2f(455+700,110);

    glEnd();


}

void pillor()
{
    glColor3f(1.0, 1.0, 0.0 );
    glLineWidth(3.2);
    glBegin(GL_LINES);
    glVertex2f(425,150);
    glVertex2f(425,600);
    glVertex2f(625,150);
    glVertex2f(625,600);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glLineWidth(3.2);
    glBegin(GL_LINES);
    glVertex2f(150,300);
    glVertex2f(900,300);
    glVertex2f(150,450);
    glVertex2f(900,450);
    glVertex2f(150,300);
    glVertex2f(50,350);
    glVertex2f(150,450);
    glVertex2f(50,500);
    glEnd();
}

void doors()
{
    //front door1
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(475,150);
    glVertex2f(475,270);
    glVertex2f(575,270);
    glVertex2f(575,150);
    glEnd();
    //front door2
    glBegin(GL_POLYGON);
    glVertex2f(475,300);
    glVertex2f(475,420);
    glVertex2f(575,420);
    glVertex2f(575,300);
    glEnd();
    //front door1
    glBegin(GL_POLYGON);
    glVertex2f(475,450);
    glVertex2f(475,570);
    glVertex2f(575,570);
    glVertex2f(575,450);
    glEnd();
    //left side door1
    glBegin(GL_POLYGON);
    glVertex2f(80,183);
    glVertex2f(80,300);
    glVertex2f(120,280);
    glVertex2f(120,163);
    glEnd();
    //left side door2
    glBegin(GL_POLYGON);
    glVertex2f(80,333);
    glVertex2f(80,450);
    glVertex2f(120,430);
    glVertex2f(120,317);
    glEnd();
    //left side door3
    glBegin(GL_POLYGON);
    glVertex2f(80,483);
    glVertex2f(80,600);
    glVertex2f(120,580);
    glVertex2f(120,467);
    glEnd();
}

void windows()
{
    //first floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(160,220);
    glVertex2f(160,270);
    glVertex2f(220,270);
    glVertex2f(220,220);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240,220);
    glVertex2f(240,270);
    glVertex2f(300,270);
    glVertex2f(300,220);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240+80,220);
    glVertex2f(240+80,270);
    glVertex2f(300+80,270);
    glVertex2f(300+80,220);
    glEnd();
    //second floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(160,370);
    glVertex2f(160,420);
    glVertex2f(220,420);
    glVertex2f(220,370);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240,370);
    glVertex2f(240,420);
    glVertex2f(300,420);
    glVertex2f(300,370);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240+80,370);
    glVertex2f(240+80,420);
    glVertex2f(300+80,420);
    glVertex2f(300+80,370);
    glEnd();
    //third floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(160,570);
    glVertex2f(160,520);
    glVertex2f(220,520);
    glVertex2f(220,570);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240,570);
    glVertex2f(240,520);
    glVertex2f(300,520);
    glVertex2f(300,570);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(240+80,570);
    glVertex2f(240+80,520);
    glVertex2f(300+80,520);
    glVertex2f(300+80,570);
    glEnd();
    //right side
    //first floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635,220);
    glVertex2f(635,270);
    glVertex2f(695,270);
    glVertex2f(695,220);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(635+80,220);
    glVertex2f(635+80,270);
    glVertex2f(695+80,270);
    glVertex2f(695+80,220);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(635+80+80,220);
    glVertex2f(635+80+80,270);
    glVertex2f(695+80+80,270);
    glVertex2f(695+80+80,220);
    glEnd();
    //second floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635,370);
    glVertex2f(635,420);
    glVertex2f(695,420);
    glVertex2f(695,370);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635+80,370);
    glVertex2f(635+80,420);
    glVertex2f(695+80,420);
    glVertex2f(695+80,370);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
     glBegin(GL_POLYGON);
    glVertex2f(635+80+80,370);
    glVertex2f(635+80+80,420);
    glVertex2f(695+80+80,420);
    glVertex2f(695+80+80,370);
    glEnd();
    //third floor
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635,570);
    glVertex2f(635,520);
    glVertex2f(695,520);
    glVertex2f(695,570);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635+80,570);
    glVertex2f(635+80,520);
    glVertex2f(695+80,520);
    glVertex2f(695+80,570);
    glEnd();
    glColor3f(1.0, 1.0, 0.0 );
    glBegin(GL_POLYGON);
    glVertex2f(635+80+80,570);
    glVertex2f(635+80+80,520);
    glVertex2f(695+80+80,520);
    glVertex2f(695+80+80,570);
    glEnd();


}

void scketch()
{
    backg_description();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(400,250);
    glVertex2f(400,600);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(360,200);
    glVertex2f(360,230);
    glVertex2f(440,230);
    glVertex2f(440,200);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(360,170);
    glVertex2f(360,180);
    glVertex2f(440,180);
    glVertex2f(440,170);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(360,180);
    glVertex2f(360,190);
    glVertex2f(440,190);
    glVertex2f(440,180);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(360,190);
    glVertex2f(360,200);
    glVertex2f(440,200);
    glVertex2f(440,190);
    glEnd();

     glBegin(GL_LINE_LOOP);
    glVertex2f(360,200);
    glVertex2f(360,210);
    glVertex2f(440,210);
    glVertex2f(440,200);
    glEnd();
     glBegin(GL_LINE_LOOP);
    glVertex2f(360,210);
    glVertex2f(360,220);
    glVertex2f(440,220);
    glVertex2f(440,210);
    glEnd();
     glBegin(GL_LINE_LOOP);
    glVertex2f(360,220);
    glVertex2f(360,230);
    glVertex2f(440,230);
    glVertex2f(440,220);
    glEnd();
     glBegin(GL_LINE_LOOP);
    glVertex2f(360,230);
    glVertex2f(360,240);
    glVertex2f(440,240);
    glVertex2f(440,230);
    glEnd();
     glBegin(GL_LINE_LOOP);
    glVertex2f(360,240);
    glVertex2f(360,250);
    glVertex2f(440,250);
    glVertex2f(440,240);
    glEnd();
     circle1(425,600,25);    //secondary pulley

     glBegin(GL_LINES);
     glVertex2f(425,600);
     glVertex2f(425,660);
     glEnd();

     glBegin(GL_LINES);
     glVertex2f(410,660);
     glVertex2f(440,660);
     glEnd();

     glBegin(GL_LINES);
     glVertex2f(450,600);
     glVertex2f(450,500);
     glEnd();

    circle1(470,498,20);  //bigger circle at the middle

    glBegin(GL_LINES);
     glVertex2f(490,498);
     glVertex2f(490,600);
     glEnd();

     circle1(525,600,35); //electric motor
     circle1(525,600,45);    //electric motor

     circle1(470,498,5);    //smallest circle at the middle


     glBegin(GL_LINES);
     glVertex2f(465,498);
     glVertex2f(460,460);

     glVertex2f(475,498);
     glVertex2f(480,460);

     glVertex2f(460,460);
     glVertex2f(480,460);

     glVertex2f(470,460);
     glVertex2f(470,430);
     glEnd();

    glBegin(GL_LINE_LOOP);
     glVertex2f(460,430);
     glVertex2f(480,430);
     glVertex2f(480,300);
     glVertex2f(460,300);
     glEnd();

     glBegin(GL_LINE_LOOP);
     glVertex2f(460,420);
     glVertex2f(430,420);
     glVertex2f(430,300);
     glVertex2f(460,300);
     glEnd();

     glBegin(GL_LINE_LOOP);
     glVertex2f(480,420);
     glVertex2f(510,420);
     glVertex2f(510,300);
     glVertex2f(480,300);
     glEnd();

     glBegin(GL_LINE_LOOP);
     glVertex2f(270,100);
     glVertex2f(270,700);
     glVertex2f(700,700);
     glVertex2f(700,100);
     glEnd();

      glFlush();

}

void desclift()
{
    setFont(GLUT_BITMAP_HELVETICA_12);
   // glClearColor(1.0,1.0,1.0,1);/*background for cover page*/
    glColor3f(0,0,1);
    drawstring(390.0,680.0,0.0,"LIFTING DRUM ARRANGEMENTS");
    drawstring(390.0,678.0,0.0,"____________________________");

    glColor3f(0,0,1);
    drawstring(276,600,0,"Secondary Pulley -> ");
    drawstring(276,200,0,"Counter ");
    drawstring(288,188,0,"Weight -> ");
    drawstring(513,350,0,"<--- Car");
    drawstring(513,300,0,"<--- Platform");
    drawstring(480,390,0,"<------ Sling");
    drawstring(470,440,0,"<---- Crosshead");
    drawstring(490,520,0,"<--- Cable");
    drawstring(570,600,0,"<-- Electric Motor");
//glFlush();
}

void principle()
{

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.1,0.3,0.8);
    drawstring(820.0,680.0,0.0,"Pulley:");
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.2,0.7,0.8);
    drawstring(820.0,656.0,0.0,"Pulley's are used to evenly balance the counterweight and the");
    drawstring(819.0,640,0.0,"elevator car.Pulley in elevators reduces the friction and which");
    drawstring(818.0,620.0,0.0," in turn reduces the strain on the electric motor.");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.1,0.3,0.8);
    drawstring(820.0,580.0,0.0,"Counter Weight:");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.2,0.7,0.8);
    drawstring(820.0,556.0,0.0,"A counterweight is a weight that, by exerting an opposite force,");
    drawstring(820.0,540,0.0,"provides balance and stability of a mechanical system.Its   ");
    drawstring(820.0,520.0,0.0,"purpose is to make lifting the load more efficient, which  ");
    drawstring(820.0,500.0,0.0,"saves energy and is less taxing on the lifting machine.");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.1,0.3,0.8);
    drawstring(820.0,460.0,0.0,"Electric Motor:");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.2,0.7,0.8);
    drawstring(820.0,436.0,0.0,"Electric motor is the device which converts Electrical energy to ");
    drawstring(820.0,418.0,0.0,"Mechanical energy. In simple way, we give electrical energy to");
    drawstring(820.0,400.0,0.0,"the system and extracts mechanical energy. The mechanical");
    drawstring(820.0,382.0,0.0,"energy output can be used for the movement of load.");
}

void display_working()
{
    int i;
    glClearColor(0.9,0.98,0.98,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    scketch();
 desclift();
 principle();
font2();
  glFlush();
}

void display_lift()
{
glClearColor(0.0,0.0,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
 backg_lift();
floor_distinguish();
usleep(1000);
pulley_lines();
lift_box();
load();
pulley();
pulley_lines();
glFlush();
}

void display_mall()
{
glClearColor(0.8,0.8,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
road();
rectangle();
lines();
pillor();
doors();
windows();
tree();
man1();
man2();
man3();
font1();
glFlush();
}


void myinit()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1346,728);
glutInitWindowPosition(0,0);
glutCreateWindow("GRAPHICAL SIMULATION OF LIFT");
glutFullScreen();
glutDisplayFunc(mydisplay);
glutKeyboardFunc(mykeyboard);
myinit();
glutMainLoop();
}

