#include <opencv/highgui.h>

int main()

{
    IplImage*img=cvLoadImage("�ɦW.png");///Ū��(�{���X��b�� �Ϥ��N�b��)

    cvShowImage("week09",img);///�q��

    cvWaitKey(0);///�����N���~��
}
