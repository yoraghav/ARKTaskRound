


    #include <opencv2/imgcodecs.hpp>
    #include <opencv2/highgui.hpp>
    #include <opencv2/imgproc.hpp>
    #include <opencv2/objdetect.hpp>
    #include <iostream>

    using namespace cv;
    using namespace std;
    int main() {
        
        
        
        Mat img = imread("yo/1.png");
//        cout<<img.size();

        Mat image = img;
            for(int y=0;y<7;y++)
            {
                for(int x=0;x<img.cols;x++)
                {
                Vec3b color = image.at<Vec3b>(Point(x,y));
                    char a = (char)color[0];
                    cout<<a;
            }
            }
        
        
    }
        
        
        
     
