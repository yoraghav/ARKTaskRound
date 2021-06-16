


    #include <opencv2/imgcodecs.hpp>
    #include <opencv2/highgui.hpp>
    #include <opencv2/imgproc.hpp>
    #include <opencv2/objdetect.hpp>
    #include <iostream>

    using namespace cv;
    using namespace std;
    int main() {
        
        Mat img = imread("yo/1.png");
        Mat final(200,150,CV_8UC3);
//        cout<<img.size();
            for(int x=0;x<30000;x++)
            {
                int y =x+1333-177;
                Vec3b color1 = img.at<Vec3b>(Point(y%177,(int)y/177));
                final.at<Vec3b>(Point(x%150,(int)x/150))=color1;
            }
        cout<<img.cols;
        imwrite("yo/search.png",final);
        imshow("",final);
        waitKey(0);
        
    }
//        94,6
        
//     177 177   31329
//    177x7 + 93 = 1332

//Congrats on solving the first level of this task! You were able to figure out the ASCII text from the image, but wait! Your journey is not yet over. After the end of the text you will find a (200, 150, 3) coloured image. This image is a part of the bigger image called "zucky_elon.png". Find the top left coordinate (Image convention) from where this image was taken. The x coordinate represents the colour of a monochrome maze hidden in an image with coloured noise. Find the maze and solve the maze using any algothrim like dfs but better. Try comparing them and seeing how they perform like A*, RRT, RRT* for example. Once the maze is solved you will see a word. This word is a password to a password protected zip file which contains a png. Note that the password is case sensitive and all the aplhabets in the password will be capital letters This is your treasure. To open the treasure you need to convert the image in to an audio file in a simple way like you did for this ASCII text. Once converted, open the .mp3 file and enjoy your treasure, you deserved it! A part of the image "zucky_elon.png" will begin immediatly after the colon, image-lv2 :
