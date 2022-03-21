#include <GL/glut.h>
float angle=0, oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotatef(angle, 0,0,1);///轉180度
        glColor3f( 1, 1, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{///按下mouse,放開mouse
    oldX = x;
}
void motion(int x, int y)
{///拖著它動
    angle += (x-oldX);
    oldX = x;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
