#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#include "LLAH.h"
LLAH m_llah;


void readPattern() {
    vector<string> patternlist;
    for (int i = 0; i < 10; ++i) {
        char patternname[32];
        sprintf(patternname, "../data/%d.txt", i);
        patternlist.push_back(patternname);
    }

    for (auto pattern : patternlist) {
        m_llah.AddPaper(pattern.c_str());
    }
}




int main(int argc, char *argv[]) {
    readPattern();
    int frames = 10;
    for (int frame = 0; frame < frames; ++frame) {
        char imagename[32];
        sprintf(imagename, "../data/%d.jpg", frame);
        printf("Processing: %s\n", imagename);

        Mat image = imread(imagename, IMREAD_GRAYSCALE);

    }


    return 0;
}