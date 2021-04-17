#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"


#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace cv;
using namespace std;

void help()
{
	printf(
			"\nDemonstrate the use of the HoG descriptor using\n"
			"  HOGDescriptor::hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());\n"
			"Usage:\n"
			"./peopledetect (<image_filename> | <image_list>.txt)\n\n");
}

int MyVideoCapture(char* path)  
{  
	try
	{
		VideoCapture capture(path);  
		if(!capture.isOpened())  
			return true;  
		double rate=capture.get(CV_CAP_PROP_FPS);  
		int delay=1000/rate;  
		bool stop=false;  
		Mat cframe;  
		namedWindow("视频获取框",2);  
		while(!stop)  
		{  
			if(!capture.read(cframe))  
				break;  
			imshow("视频获取框",cframe);  
			if(waitKey(delay)>=0)  
				stop=true;  
		}  
		capture.release();  
	} 
	catch(char * ex)
	{
		printf("Function: MyVideoCapture:: %s\n", ex);
	}
    return 0;  
}  

int detectHuman()
{
	return 0;
}

int main3()
{
	MyVideoCapture("D:\\windows\\data\\video\\seg1.mp4");
	return 0;
}

int main1()
{
    Mat img;
    FILE* f = 0;
    char _filename[1024];

    //if( argc == 1 )
    //{
    //    printf("Usage: peopledetect (<image_filename> | <image_list>.txt)\n");
    //    return 0;
    //}
	//if(argv[1] == NULL)
	//{
	//	*argv = new char[20];
	//	strcpy(*argv, "01.jpg");
	//}

	char* path = "D:\\windows\\data\\img\\01.jpg";
	
	img = imread(path);

    if( img.data )
    {
	    strcpy(_filename, path);
    }
    else
    {        
		fprintf( stderr, "ERROR: the specified file could not be loaded\n");
		return -1;
    }

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    namedWindow("people detector", 1);

    for(;;)
    {
	    char* filename = _filename;
	    if(f)
	    {
		    if(!fgets(filename, (int)sizeof(_filename)-2, f))
			    break;
		    //while(*filename && isspace(*filename))
		    //	++filename;
		    if(filename[0] == '#')
			    continue;
		    int l = strlen(filename);
		    while(l > 0 && isspace(filename[l-1]))
			    --l;
		    filename[l] = '\0';
		    img = imread(filename);
	    }
	    printf("%s:\n", filename);
	    if(!img.data)
		    continue;
		
	    fflush(stdout);
	    vector<Rect> found, found_filtered;
	    double t = (double)getTickCount();
	    // run the detector with default parameters. to get a higher hit-rate
	    // (and more false alarms, respectively), decrease the hitThreshold and
	    // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
	    hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);
	    t = (double)getTickCount() - t;
	    printf("tdetection time = %gms\n", t*1000./cv::getTickFrequency());
	    size_t i, j;
	    for( i = 0; i < found.size(); i++ )
	    {
		    Rect r = found[i];
		    for( j = 0; j < found.size(); j++ )
			    if( j != i && (r & found[j]) == r)
				    break;
		    if( j == found.size() )
			    found_filtered.push_back(r);
	    }
	    for( i = 0; i < found_filtered.size(); i++ )
	    {
		    Rect r = found_filtered[i];
		    // the HOG detector returns slightly larger rectangles than the real objects.
		    // so we slightly shrink the rectangles to get a nicer output.
		    r.x += cvRound(r.width*0.1);
		    r.width = cvRound(r.width*0.8);
		    r.y += cvRound(r.height*0.07);
		    r.height = cvRound(r.height*0.8);
		    rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
	    }
	    imshow("people detector", img);
	    int c = waitKey(0) & 255;
	    if( c == 'q' || c == 'Q' || !f)
            break;
    }
    if(f)
        fclose(f);
    return 0;
}
