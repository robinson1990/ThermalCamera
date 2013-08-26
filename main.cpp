#include "main.h"

int main(int argc,char** argv)
{
	
	//Video Capture
	cv::VideoCapture cap(0);

	cap.set(CV_CAP_PROP_FRAME_WIDTH,640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT,480);

  if(!cap.isOpened()) 
  {
	  return -1;

  }

  while(1) {

	  cv::Mat frame;

	  cap >> frame; 

	  std::cout<<frame.rows<<std::endl;
	  std::cout<<frame.cols<<std::endl;

	  cv::imshow("Capture",frame);

	  int key=cv::waitKey(1);

	  keyCheck(frame,key);

  }
	return 0;
}

void keyCheck(cv::Mat src,int key)
{
	switch(key){
	case 'q':
		exit(0);
		break;
	case '\033':
		exit(0);
		break;
	case 's':
		char filename[30];
		sprintf(filename,"thermal.bmp");
		cv::imwrite(filename,src);
		break;
	}
}
