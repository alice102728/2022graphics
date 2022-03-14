#include <GL/glut.h>
#include <stdio.h>
int mouseX=0, mouseY=0, N=0;///N個點
int mx[100], my[100];///用來記錄,等一下要畫出來
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){///迴圈配陣列 mx[i] my[i]
            glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0 );
        }
    glEnd();
    glutSwapBuffers();///我們寫了一個會產生程式碼的工具
}
void mouse(int button, int state, int x, int y)
{
    mouseX=x; mouseY=y;///滑鼠可以printf()印出程式碼
    if(state==GLUT_DOWN){///按下去的(放開的那個不算數)
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x,y);
        N++;
        mx[N-1]=x; my[N-1]=y;///陣列 備份座標
    }
}
int main( int argc, char**argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///Display顯示
    glutMouseFunc(mouse);///Mouse滑鼠
    glutMainLoop();
}
