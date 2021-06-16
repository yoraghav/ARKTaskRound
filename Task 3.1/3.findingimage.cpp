

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;
using namespace std;
int main() {
    
    Mat img2 = imread("yo/search.png");
    Mat img = imread("yo/2.png");
    cout<<img.cols<<" "<<img.rows<<endl;
    int b=0;
    for(int x=0;x<1440;x++){
        for(int y=0;y<977;y++){
            b=0;
            
            Vec3b pixel1 = img.at<Vec3b>(Point(x,y));
            
            while(pixel1==img2.at<Vec3b>(Point(b%150,(int)b/150))){
                b++;
                pixel1 = img.at<Vec3b>(Point(x+b%150,y+(int)b/150));
            }
            
            if(b==30000){
                cout<<x<<" "<<y;
            }
            
        }
    }
    
    imshow(" ",img);
    imshow("",img2);
    waitKey(0);
    return 0;
}
//        94,6
