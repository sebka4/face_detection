#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include "tesseract/baseapi.h"

using namespace cv;

CascadeClassifier face_cascade;
std::vector<Rect> faces;
Mat before, after;
const char *cascade_name = "";

tesseract::TessBaseAPI tess;
QString temp_data;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_tick()));

    face_cascade.load("/home/sebka4/haarcascades/haarcascade_frontalface_default.xml");
    namedWindow("before",1);
    namedWindow("after",1);
   // tess.Init(NULL, "/home/sebka4/Downloads/tesseract-ocr/tessdata/eng");
    timer->start(101);

}

void MainWindow::timer_tick()
{
        static VideoCapture cap(0);

        cap >> before;
        after = before.clone();

       // tess.SetImage((uchar*)before.data, before.size().width, before.size().height, before.channels(), before.step1());

        /*
        cvtColor(after, after, CV_BGR2GRAY);
        equalizeHist(after, after);

        face_cascade.detectMultiScale(after, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30,30));
        after = before.clone();
        for(int i=0; i<faces.size(); i++)
        {
           rectangle(after, faces[i], {255,255,255,0});
        }
        if(faces.size()>0)
            ui->label->setText("X: " + QString::number(faces.at(0).x)+ " Y: " + QString::number(faces.at(0).y));
        */
      //  tess.Recognize(0);
      //  temp_data.sprintf("%s", tess.GetUTF8Text());
      //  ui->label->setText(temp_data);
        imshow("before",before);
        imshow("after", after);


}

MainWindow::~MainWindow()
{
    delete ui;
}
