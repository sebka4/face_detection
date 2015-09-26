#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;

CascadeClassifier face_cascade;
std::vector<Rect> faces;
Mat before, after;
const char *cascade_name = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_tick()));

    face_cascade.load("/home/sebka4/haarcascades/haarcascade_eye.xml");
    namedWindow("before",1);
    namedWindow("after",1);

    timer->start(10);

}

void MainWindow::timer_tick()
{

        static VideoCapture cap(0);
        cap >> before;
        after = before.clone();

        cvtColor(after, after, CV_BGR2GRAY);
        equalizeHist(after, after);


        face_cascade.detectMultiScale(after, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30,30));
        after = before.clone();
        for(int i=0; i<faces.size(); i++)
        {
            rectangle(after, faces[i], {255,255,255,0});
        }

        imshow("before",before);
        imshow("after", after);


}

MainWindow::~MainWindow()
{
    delete ui;
}
