#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * arm = NULL;
GLMmodel * hand = NULL;
GLMmodel * rm = NULL;
GLMmodel * hnd = NULL;
GLMmodel * leg = NULL;
GLMmodel * lg = NULL;


GLMmodel * myReadOne( char * filename ){
    GLMmodel * one = NULL;
    one = glmReadOBJ( filename );
    glmUnitize(one);
    glmFacetNormals(one);
    glmVertexNormals(one, 90);
    return one;
}
float dx=0, dy=0, dz=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y)
{
    oldX=x;
    oldY=y;
}
float angle[20]={};
int angleID=0;
void motion(int x, int y)
{
    dx += (x-oldX)/250.0;
    dy -= (y-oldY)/250.0;
    angle[angleID]+=(x-oldX);
    oldX=x;
    oldY=y;
    printf("glTranslatef(%.2f, %.2f, %.2f);\n", dx, dy, dz);
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
    if(key=='9') angleID=9;
    if(key=='0') angleID=0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glColor3f(1,0,0);
    //glutSolidTeapot(0.05);
    //glColor3f(1,1,1);

    glmDraw(body, GLM_SMOOTH);

    glPushMatrix();
        glTranslatef(0.00, 0.46, 0.00);
        glmDraw(head, GLM_SMOOTH);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.22, 0.29, 0.00);
        glRotatef(angle[1], 1, 0, 0);
        glRotatef(angle[2], 0, 0, 1);
        glTranslatef(-0.06, -0.15, 0.00);
        glmDraw(arm, GLM_SMOOTH);

        glPushMatrix();
            glTranslatef(-0.00, -0.05, 0.00);///glTranslatef(dx, dy, dz);
            glRotatef(angle[3], 1, 0, 0);
            glRotatef(angle[4], 0, 0, 1);///glRotatef(dx*100, 0, 0, 1);
            glTranslatef(-0.09, -0.20, 0.00);
            glmDraw(hand, GLM_SMOOTH);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
            glTranslatef(0.22, 0.29, 0.00);
            glRotatef(angle[5], 1, 0, 0);
            glRotatef(angle[6], 0, 0, 1);
            glTranslatef(0.06, -0.15, 0.00);
            glmDraw(rm, GLM_SMOOTH);
        glPushMatrix();
            glTranslatef(0.01, -0.06, 0.00);
            glRotatef(angle[7], 1, 0, 0);
            glRotatef(angle[8], 0, 0, 1);
            glTranslatef(0.09, -0.19, 0.00);
            glmDraw(hnd, GLM_SMOOTH);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.16, -0.30, 0.00);
        glRotatef(angle[9], 0, 0, 1);
        glTranslatef(0.00, -0.30, 0.00);
        glmDraw(leg, GLM_SMOOTH);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.16, -0.41, 0.00);
        glRotatef(angle[0], 0, 0, 1);
        glTranslatef(0.00, -0.19, 0.00);
        glmDraw(lg, GLM_SMOOTH);
    glPopMatrix();

    glutSwapBuffers();
}
void myLighting()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week");
    head = myReadOne("data/head.obj");
    body = myReadOne("data/body.obj");
    arm = myReadOne("data/arm.obj");
    hand = myReadOne("data/hand.obj");
    rm = myReadOne("data/rm.obj");
    hnd = myReadOne("data/hnd.obj");
    leg = myReadOne("data/leg.obj");
    lg = myReadOne("data/lg.obj");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    myLighting();
    glutMainLoop();
}
