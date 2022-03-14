#include <GL/glut.h>
void myTeapot(float x, float y)///自訂的函式
{
    glPushMatrix();///push備份矩陣
        glTranslatef( x, y, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///pop還原矩陣
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);///red
    myTeapot(+0.5, +0.5);
    myTeapot(+0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, +0.5);

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW2 bouns");

    glutDisplayFunc(display);
    glutMainLoop();
}
