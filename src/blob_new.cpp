#include <iostream>
#include <vector>

using namespace std;

struct Blob {
    int x;
    int y;
    int p;
};

struct Paper {
    int paper_id;
    vector<Blob> blogs;
    vector<vector<Blob>> neighbors;
};

struct PaperList {
    vector<Paper> papers;
};