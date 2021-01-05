#include<windows.h>
#include <stdlib.h>
#include<GL/glut.h>

void init(void);
void tampil(void);
void mouse (int button, int state, int x,int y);
void keyboard(unsigned char,int,int);
void ukuran(int,int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;
int w = 500, h = 500, d = 0;
int p1 = 0, q1 = 0, angle = 0, s1 = 0;
float scaleX = 1, scaleY = 1, scaleZ = 1;


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Agustinus Yoga Pangestu - 672018059");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
     glutKeyboardFunc(keyboard);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth =1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0, 0, d);
        glRotatef(angle, p1, q1, s1);
        glScalef(scaleX, scaleY, scaleZ);

        gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f); // untuk mengatur penglihatan mata/objek
        glRotatef(xrot, 1.0f,0.0f,0.0f);
        glRotatef(yrot, 0.0f, 1.0f,0.0f);
        glPushMatrix();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.631);
    glVertex3f(-20.0,-20.0,10.0);
    glVertex3f(-20.0,20.0,10.0);
    glVertex3f(30.0,20.0,10.0);
    glVertex3f(30.0,-20.0,10.0);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(0.0,-19.8,11.0);
    glVertex3f(-10.0,-19.8,11.0);
    glVertex3f(-10.0,3.0,11.0);
    glVertex3f(0.0,3.0,11.0);
    glEnd();

    //ganggang pintu
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-8.0,-8.0,12.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3f(0.078,0.875,0.8);
    glVertex3f(10.0,5.0,11.0);
    glVertex3f(20.0,5.0,11.0);
    glVertex3f(20.0,-9.0,11.0);
    glVertex3f(10.0,-9.0,11.0);
    glEnd();

    //teralis jendela
    glBegin(GL_LINE_LOOP);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(10.0,5.0,11.0);
    glVertex3f(20.0,5.0,11.0);
    glVertex3f(20.0,-9.0,11.0);
    glVertex3f(10.0,-9.0,11.0);
    glEnd();

    //teralis jendela horizontal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(20.0,-1.5,12.0);
    glVertex3f(9.5,-1.5,12.0);
    glEnd();

    //teralis jendela vertikal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(15.0,5.0,12.0);
    glVertex3f(15,-9.0,12.0);
    glEnd();

    //tembok belakang
    glBegin(GL_QUADS);
   glColor3f(0.0,1.0,0.631);
    glVertex3f(-20.0,-20.0,-20.0);
    glVertex3f(-20.0,20.0,-20.0);
    glVertex3f(30.0,20.0,-20.0);
    glVertex3f(30.0,-20.0,-20.0);
    glEnd();


    //jendela belakang 1
    glBegin(GL_QUADS);
    glColor3f(0.078,0.875,0.8);
    glVertex3f(10.0,5.0,-21.0);
    glVertex3f(20.0,5.0,-21.0);
    glVertex3f(20.0,-9.0,-21.0);
    glVertex3f(10.0,-9.0,-21.0);
    glEnd();

    //jendela belakang 2
    glBegin(GL_QUADS);
    glColor3f(0.078,0.875,0.8);
    glVertex3f(-13.0,5.0,-21.0);
    glVertex3f(-3.0,5.0,-21.0);
    glVertex3f(-3.0,-9.0,-21.0);
    glVertex3f(-13.0,-9.0,-21.0);
    glEnd();

    //teralis jendela 1 belakang
    glBegin(GL_LINE_LOOP);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(10.0,5.0,-21.0);
    glVertex3f(20.0,5.0,-21.0);
    glVertex3f(20.0,-9.0,-21.0);
    glVertex3f(10.0,-9.0,-21.0);
    glEnd();

    //teralis jendela 1 belakang horizontal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(20.0,-1.5,-22.0);
    glVertex3f(9.5,-1.5,-22.0);
    glEnd();

    //teralis jendela 1 belakang vertikal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(15.0,5.0,-22.0);
    glVertex3f(15,-9.0,-22.0);
    glEnd();

    //teralis jendela 2 belakang
    glBegin(GL_LINE_LOOP);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(-13.0,5.0,-21.0);
    glVertex3f(-3.0,5.0,-21.0);
    glVertex3f(-3.0,-9.0,-21.0);
    glVertex3f(-13.0,-9.0,-21.0);
    glEnd();

    //teralis jendela 2 belakang horizontal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(-13.0,-1.5,-22.0);
    glVertex3f(-2.5,-1.5,-22.0);
    glEnd();

    //teralis jendela 2 belakang vertikal
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(-8.0,5.0,-22.0);
    glVertex3f(-8,-9.0,-22.0);
    glEnd();

    //tembok kanan
    glBegin(GL_QUADS);
     glColor3f(0.239,0.745,0.557);
    glVertex3f(30.0,20.0,10.0);
    glVertex3f(30.0,-20.0,10.0);
    glVertex3f(30.0,-20.0,-20.0);
    glVertex3f(30.0,20.0,-20.0);
    glEnd();

    //tembok kiri
    glBegin(GL_QUADS);
     glColor3f(0.239,0.745,0.557);
    glVertex3f(-20.0,20.0,10.0);
    glVertex3f(-20.0,-20.0,10.0);
    glVertex3f(-20.0,-20.0,-20.0);
    glVertex3f(-20.0,20.0,-20.0);
    glEnd();

     //bawah lantai
    glBegin(GL_QUADS);
    glColor3f(0.0,1.5,0.0);
    glVertex3f(-20,-20.0,10.0);
    glVertex3f(30,-20.0,10.0);
    glVertex3f(30,-20.0,-20.0);
    glVertex3f(-20,-20.0,-20.0);
    glEnd();

    //atap segitiga depan
    glBegin(GL_TRIANGLES);
    glColor3f(0.894,0.341,0.018);
    glVertex3f(-20.0,20.0,10.0);
    glVertex3f(10.0,48.0,10.0);
    glVertex3f(30.0,20.0,10.0);
    glEnd();

    //atap segitiga belakang
    glBegin(GL_TRIANGLES);
     glColor3f(0.894,0.341,0.018);
    glVertex3f(-20.0,20.0,-20.0);
    glVertex3f(10.0,48.0,-20.0);
    glVertex3f(30.0,20.0,-20.0);
    glEnd();

    //atap kanan atas
    glBegin(GL_QUADS);
     glColor3f(0.82,0.318,0.173);
    glVertex3f(10, 15.0+33.0,10.0);
    glVertex3f(30, -10.0+30.0,10.0);
    glVertex3f(30, -10.0+30.0,-20.0);
    glVertex3f(10, 15.0+33.0,-20.0);
    glEnd();

    //atap kiri atas
    glBegin(GL_QUADS);
    glColor3f(0.82,0.318,0.173);
    glVertex3f(15.5, -10.0+63.3,10.0);
    glVertex3f(-20, -10.0+30.0,10.0);
    glVertex3f(-20, -10.0+30.0,-20.0);
    glVertex3f(15.5, -10.0+63,-20.0);
    glEnd();

    //jendela tembok kanan
    glBegin(GL_QUADS);
    glColor3f(0.078,0.875,0.8);
    glVertex3f(30.1,5.0,5.0);
    glVertex3f(30.1,-15.0,5.0);
    glVertex3f(30.1,-15.0,-10.0);
    glVertex3f(30.1,5.0,-10.0);
    glEnd();

    //teralis jendela tembok kanan
    glBegin(GL_LINE_LOOP);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(30.1,5.0,5.0);
    glVertex3f(30.1,-15.0,5.0);
    glVertex3f(30.1,-15.0,-10.0);
    glVertex3f(30.1,5.0,-10.0);
    glEnd();

    //jendela tembok kiri
    glBegin(GL_QUADS);
    glColor3f(0.078,0.875,0.8);
    glVertex3f(-20.1,5.0,5.0);
    glVertex3f(-20.1,-15.0,5.0);
    glVertex3f(-20.1,-15.0,-10.0);
    glVertex3f(-20.1,5.0,-10.0);
    glEnd();

    //teralis jendela tembok kiri
    glBegin(GL_LINE_LOOP);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(-20.1,5.0,5.0);
    glVertex3f(-20.1,-15.0,5.0);
    glVertex3f(-20.1,-15.0,-10.0);
    glVertex3f(-20.1,5.0,-10.0);
    glEnd();

    //FURNITURE
    //Meja
    glBegin(GL_QUADS);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(8,-10.0,-10.0);
    glVertex3f(30,-10.0,-10.0);
    glVertex3f(30,-10.0,-20.0);
    glVertex3f(8,-10.0,-20.0);
    glEnd();

    //kaki meja
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(9.0,-10,-11.0);
    glVertex3f(9.0,-20,-11.0);
    glEnd();

    //kaki meja
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(9.0,-10,-19.0);
    glVertex3f(9.0,-20,-19.0);
    glEnd();

    //kaki meja
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(29.0,-10,-19.0);
    glVertex3f(29.0,-20,-19.0);
    glEnd();

    //kaki meja
    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(29.0,-10,-11.0);
    glVertex3f(29.0,-20,-11.0);
    glEnd();

    //lemari
    glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(4, -16, -18);
	glScalef(60, 80, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(4, -8, -18);
	glScalef(60, 80,40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(4.0,-4,-16);
    glVertex3f(4.0,-20,-16);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(3.0,-12.0,-16.0);
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(5.0,-12.0,-16.0);
    glEnd();

    //kursi
     glBegin(GL_QUADS);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(17,-14.0,-9.0);
    glVertex3f(25,-14.0,-9.0);
    glVertex3f(25,-14.0,-2.0);
    glVertex3f(17,-14.0,-2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(17,-14.0,-2.0);
    glVertex3f(25,-14.0,-2.0);
    glVertex3f(25,-3.0,-1.0);
    glVertex3f(17,-3.0,-1.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(18.0,-14,-7.0);
    glVertex3f(18.0,-20,-7.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(24.0,-14,-7.0);
    glVertex3f(24.0,-20,-7.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(24.0,-14,-3.0);
    glVertex3f(24.0,-20,-3.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.545,0.271,0.075);
    glVertex3f(18.0,-14,-3.0);
    glVertex3f(18.0,-20,-3.0);
    glEnd();

    //Kasur, Bantal, dan Selimut
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.294, 0.042, 0.902);
	glTranslatef(-15.2, -17, -8);
	glScalef(90, 60, 240);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	glTranslatef(-15.2, -14, -16);
	glScalef(50, 3, 29);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.976, 0.584, 0.114);
	glTranslatef(-15.2, -14, -6);
	glScalef(58, 2, 140);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

     //AC
    glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.914, 0.984, 1);
	glTranslatef(4, 12, 8);
	glScalef(160, 80, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-2.5,10.0,6.0);
    glVertex3f(11,10.0,6.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-2.5,13.0,6.0);
    glVertex3f(11,13.0,6.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-2.5,14.0,6.0);
    glVertex3f(11,14.0,6.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-2.5,15.0,6.0);
    glVertex3f(11,15.0,6.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}


void mouseMotion(int x,int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y){
    if (key=='w')d +=5; //fungsi keyboard untuk maju
    else if(key=='s')d =-5; //fungsi keyboard untuk mundur
     switch (key)
    {
    case '5': //fungsi keyboard untuk melihat interior
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
        is_depth = 1;
        glEnable(GL_DEPTH_TEST);
        }

}
}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0)tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0,500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
