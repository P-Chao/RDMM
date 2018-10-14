/*
This file is part of UCHIYAMARKERS, a software for random dot markers.
Copyright (c) 2011 Hideaki Uchiyama

You can use, copy, modify and re-distribute this software
for non-profit purposes.
*/

#include "main.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// tracking initialization
void trackingInit()
{
    m_img.Load("../data/0.jpg");
	m_llah.Init(m_img.w, m_img.h);		// set image size

	// load markers
	char name[256];
	int nummarker = 10;

	for(int i=0;i<nummarker;i++){
		sprintf_s(name,sizeof(name),"../data/%d.txt",i);
		m_llah.AddPaper(name);
		std::cout << name << " loaded" << std::endl;
	}
}

void mainloop(const char *name)
{
    MyTimer::Push("Time");

    m_llah.SetPts();
    m_llah.CoordinateTransform(static_cast<double>(m_cam.h));

    //showimg();
    m_nextimg.Load(name);
    m_nextcamimg.Load(name);
    m_img.Swap(m_nextimg);
    m_camimg.Swap(m_nextcamimg);

#ifdef _OPENMP
#pragma omp parallel
    {
#pragma omp master
        {
            m_llah.RetrievebyTracking();
            m_viewmode = m_llah.FindPaper(4);
            m_llah.RetrievebyMatching();
            m_viewmode |= m_llah.FindPaper(8);
        }
#pragma omp single
        {
            getimg();
            m_llah.Extract(m_nextimg);
        }
    }
#else
    m_llah.RetrievebyTracking();
    m_viewmode = m_llah.FindPaper(4);
    m_llah.RetrievebyMatching();
    m_viewmode |= m_llah.FindPaper(8);
    if (m_viewmode) {
        cout << "get" << endl;
    }
    //getimg();
    m_llah.Extract(m_nextimg);
#endif
    MyTimer::Pop();
}

// main function
int main(int argc, char **argv)
{
	trackingInit();		// tracking initialization
    for (int i = 0; i < 10; ++i) {
        char name[32];
        sprintf(name, "../data/%d.jpg", i);
        printf("Processing: %s\n", name);
        mainloop(name);
    }
	return 0;
}





