
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int dist(Point a,Point b){
    Point diff = a-b;
    return sqrt(diff.x*diff.x + diff.y*diff.y);
}

Point nextpt(Point a,int sign1,int sign2){
    a.y+=sign1;
    a.x+=sign2;
    return a;
}

int polarity1(int sign,Point face,int faceradius,Point prev){
    int br =100;
    if(prev.y<br){
        return 5;
    }
    if(dist(prev,face)<br+faceradius){
        return -5;
    }
    return sign;
}

int polarity2(int sign,Point face,int faceradius,Point prev,int last){
    int br =100;
    if(prev.x<br){
        return 5;
    }
    if(last-prev.x<br){
        return -5;
    }
    if(dist(prev,face)<br+faceradius){
        return -1*sign;
    }
    return sign;
}

int main() {
    Mat img;
    VideoCapture cap(0);
    CascadeClassifier face;
    face.load("football/haarcascade_frontalface_default.xml");
    vector<Rect> faces;
    Point ballcentre(500,200);
    int sign1 = 5,sign2=4;
    Mat gameover;
    while(true){
        cap.read(img);
        face.detectMultiScale(img,faces,1.1,10);
        Point facecentre =(faces[0].tl()+faces[0].br())/2;
        int faceradius = dist(facecentre,faces[0].tl());
        circle(img,facecentre,faceradius,Scalar(0,0,255),10);
        sign1 = polarity1(sign1, facecentre, faceradius, ballcentre);
        sign2 = polarity2(sign2, facecentre, faceradius, ballcentre,img.cols);
        ballcentre = nextpt(ballcentre,sign1,sign2);
        circle(img,ballcentre,100,Scalar(0,255,0),10);
        imshow("hello",img);
        int i=img.rows,j=img.cols;
        if(img.rows-ballcentre.y<100){
            gameover = Mat(i,j,CV_8UC3,Scalar(0,0,0));
            break;
        }
        
        waitKey(1);
    }
    putText(gameover, "GAME  OVER",Point(150,400), FONT_HERSHEY_DUPLEX, 5, Scalar(0,0,255),10);
    imshow("",gameover);
    waitKey(0);
}
