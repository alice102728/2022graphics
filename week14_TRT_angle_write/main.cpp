///week13 rect many TRT
#include <GL/glut.h>
#include <stdio.h> ///為了printf, fprintf, fopen, fclose...
float angle[20], oldX=0;
int angleID=0;///0:第0個關節,1:第1個關節,2:第2個關節,3:第3個關節
FILE * fout = NULL;
void myWrite(){
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20 ;i++){
            printf( "%.2f ", angle[i] );
        fprintf(fout, "%.2f ",angle[i] );
    }
    printf("\n");
    fprintf(fout, "\n");
}
void keyboard( unsigned char key, int x, int y){
    if( key=='0' ) angleID=0;///預設是這一個
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}///用keyboard的按鍵,來決定等一下motion()裡要改
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion(int x, int y){
    angle[angleID] += (x-oldX);
    myWrite();
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色的
    glRectf(0.3, 0.5, -0.3, -0.2);///身體,瘦身

    glPushMatrix(); ///右半邊
        glTranslatef(0.3, 0.5, 0);///(3)等下要掛在0.5,0.5
        glRotatef(angle[0], 0, 0, 1);///(2)旋轉
        glTranslatef(-0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1, 0, 0);///紅色的
        glRectf(0.3, 0.5, 0.8, 0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);///(2)旋轉
            glTranslatef(-0.8, -0.4, 0);///(1)把下手肘的旋轉中心,放在正中心
            glColor3f(0,1,0);///綠色的
            glRectf(0.8, 0.5, 1.1, 0.3);///在畫右下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半邊
        glTranslatef(-0.3, 0.5, 0);///(3)等下要掛在0.5,0.5
        glRotatef(angle[2], 0, 0, 1);///(2)旋轉
        glTranslatef(0.3, -0.4, 0);///(1)先把旋轉中心放正中心
        glColor3f(1, 0, 0);///紅色的
        glRectf(-0.3, 0.5, -0.8, 0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);///(2)旋轉
            glTranslatef(0.8, -0.4, 0);///(1)把下手肘的旋轉中心,放在正中心
            glColor3f(0,1,0);///綠色的
            glRectf(-0.8, 0.5, -1.1, 0.3);///在畫左下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main( int argc, char**argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    ///glutInitWindowSize(600, 600);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///不放Idle
    glutMainLoop();
}
