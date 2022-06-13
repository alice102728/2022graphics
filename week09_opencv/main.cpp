#include <opencv/highgui.h>

int main()

{
    IplImage*img=cvLoadImage("檔名.png");///讀檔(程式碼放在哪 圖片就在哪)

    cvShowImage("week09",img);///秀圖

    cvWaitKey(0);///按任意鍵繼續
}
