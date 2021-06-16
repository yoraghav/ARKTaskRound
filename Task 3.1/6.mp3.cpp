


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>
#include <fstream>

using namespace cv;
using namespace std;
int main() {
    
    
    
    Mat img = imread("yo/treasure_mp3.png");
//        cout<<img.size();
    string ans;
    Mat image = img;
        for(int y=0;y<img.rows;y++)
        {
            for(int x=0;x<img.cols;x++)
            {
            Vec3b color = image.at<Vec3b>(Point(x,y));
                char a = (char)color[0]%256;
                ans=ans+a;
        }
        }
    
    cout<<ans;
    ofstream out("output.mp3");
    out<<ans;
    out.close();
}
