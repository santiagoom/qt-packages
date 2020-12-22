#include <QCoreApplication>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    cout << "aa" << endl;

    std::string image_path = "C:\\Users\\admin\\CLionProjects\\pach\\temp.jpg";
    cv::Mat img = imread(image_path, cv::IMREAD_COLOR);

    if (img.empty()) {
        std::cout << "Could not read the image: " << image_path << std::endl;
    }
    std::cout << "Could not r " << image_path << std::endl;
    imshow("Display window", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    if (k == 's') {
        imwrite("starry_night.png", img);
    }

    return a.exec();
}
