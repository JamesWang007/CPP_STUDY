
#ifndef DETECTION_FUNCTIONS
#define DETECTION_FUNCTIONS



class CropRoi
// this class will do the cropping job
// input a non-empty image 
// use CropRoi::CropImg(cv::Mat) to crop the image
//		
// some configuration parameters are needed:
//		x: offset of the x axis of the original image
//		y: offset of the y axis of the original image
//		w: new width of the cropped image
//		h: new height
//		all the parameters will be passed into cv::Rect roi varialbe
//		
{
	public:
		// resize the roi, and limit the size within the image scale
		// it is used for corpping a image when there is a human detected,
		// then just scan and detect arround the human in the next frame
		// parameter: use increase_rate to modify the scale 
		void ReSizeRoi(cv::Rect& roi, cv::Mat & const img){
			const int x = roi.x;
			const int y = roi.y;
			const int w = roi.width;
			const int h = roi.height;

			int left_x = x;
			int right_x = x + w;
			int top_y = y;
			int bottom_y = y + h;

			double increase_rate = 0.2; // control the cropping size

			left_x	-= (int)(w * increase_rate);
			right_x += (int)(w * increase_rate);
			top_y	-= (int)(h * increase_rate);
			bottom_y += (int)(h * increase_rate); 

			roi.x = left_x > 0 ? left_x : 0;
			roi.y = top_y > 0 ? top_y : 0;
			roi.width = right_x - roi.x;	
			roi.height = bottom_y - top_y;	

			if(!img.empty())	//	limit the roi size within the input image
			{
				cv::Size s = img.size();
				if (roi.width + roi.x > s.width)
				{
					roi.width = s.width - roi.x;
				}
				if (roi.height + roi.y > s.height)
				{
					roi.height = s.height - roi.y;
				}
			}

		}
		
		// crop image to its center
		void ReSizeRoi2Center(cv::Mat & const img)
		{

			if (img.empty())
			{ 
				printf("empty image\n");
				return;
			}
			// - preserve the certer size (128 *128)
			const size_t PRESERVE_WIDTH = 256;
			const size_t PRESERVE_HEIGHT = 256;

			Rect roi;
			int x = 0;
			int y = 0;
			Size s = img.size();
			int w = s.width;
			int h = s.height;



			roi.x = x + w/2 - PRESERVE_WIDTH/2;
			roi.y = y + h/2 - PRESERVE_HEIGHT/2;

			roi.width = PRESERVE_WIDTH;
			roi.height = PRESERVE_WIDTH;

			// - adjust the roi properties
			if (roi.x < 0 || roi.x > s.width)
			{
				x = 0;
			}
			if (roi.y < 0 || roi.y > s.height)
			{
				y = 0;
			}
			if  (roi.width < 0 || roi.width > s.width || roi.x + roi.width > s.width)
			{
				roi.width = s.width - roi.x;
			}
			if (roi.height < 0 || roi.height > s.height || roi.y + roi.height > s.height)
			{
				roi.height = s.height - roi.y;
			}

			// - resize the img size to center
			img = img(roi);

		}
};

void canny(Mat& in,Mat& out)  
{  
    if(in.channels()==3) cvtColor(in,out,CV_BGR2GRAY);//转变为灰度图像，即3通道转变为1通道  
    Canny(out,out,100,200);//计算Canny边缘  
    threshold(out,out,128,255,THRESH_BINARY_INV);//反转图像  
}  

void pedstDetectHOG(Mat& in, Mat& out)
	//	basic detecting algorithm
	//	using hog + svm
{
	out = in;
	Mat& img = out;    

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    //namedWindow("people detector", 1);

	fflush(stdout);
	vector<Rect> found, found_filtered;
	double t = (double)getTickCount();
	// run the detector with default parameters. to get a higher hit-rate
	// (and more false alarms, respectively), decrease the hitThreshold and
	// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
	hog.detectMultiScale(img, found, 0, Size(16,16), Size(32,32), 1.05, 2);
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
	//imshow("people detector", img);
	 
}




// - some initialization of pedestDetectHOG_crop(...)
static vector<Rect> pre_found_rect;
static int SET_FRAME_NUMBERS_WHEN_NO_PEOPLE = 5;
static int no_people_frame_count = 0;	// in case no pedestrian found for 5 frames in a role, 
										// then, search in the center only. 



void pedstDetectHOG_crop(Mat& in, Mat& out)
// this is an rewrite func of the pedstDetectHOG(...) function.
// the new functionality is designed to apply cropping of the input image(from input vedio)
// this function will depend on  CropRoi class
//		- 
//		- 
// - customization: appled grayscale
{
	out = in;
	// out needs to be substantiate
	//cvtColor(in, out, cv::COLOR_RGB2GRAY);// convert RGB to gray

	Mat& img = out;
	CropRoi cropUtils; // CropRoi object will provide functionalities to crop next frame image 

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	//namedWindow("people detector", 1);

	fflush(stdout);
	vector<Rect> found, found_filtered;
	vector<double> foundWeights;

	if (no_people_frame_count <= 0)	// when there is a certain number of frame no people found, then crop the image into a small center
	{
		cropUtils.ReSizeRoi2Center(img);
	}

	double t = (double)getTickCount();
	// run the detector with default parameters. to get a higher hit-rate
	// (and more false alarms, respectively), decrease the hitThreshold and
	// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
	if ( pre_found_rect.size() != 0)
	{
		// if there are pre-found human, then do detecting on the cropped images
		for(vector<Rect>::iterator it = pre_found_rect.begin(); it < pre_found_rect.end(); it ++)
		{
			try{
				cv::Mat cropImg = img(*it);//cv::Mat img_temp = img(*it);	// crop the image with pre-stored rect objects
				hog.detectMultiScale(cropImg, found, foundWeights, 0, Size(8,8), Size(32,32), 1.05, 2);
				for(auto& it_r = found.begin(); it_r < found.end(); it_r ++ )
				{
					int offset_x = it->x;
					int offset_y = it->y;

					it_r->x += offset_x;
					it_r->y += offset_y;
				}
			}
			catch(char * ex)
			{
				cerr << ex << endl;
				break;
			}
			
		}
		pre_found_rect.clear();
	}
	else
	{	// no pre-found human, then run detector
		hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);
	}
	t = (double)getTickCount() - t;
	printf("tdetection time = %gms\n", t*1000./cv::getTickFrequency());

	//waitKey(0);
	// scores
	// - print all the foundWeights scores for found objects
	/*for (auto it = foundWeights.begin(); it < foundWeights.end(); it ++)
	{		
		printf("found # %d, foundWeights # %d, score: %lf\n", found.size(), foundWeights.size(), *it);
	}*/

	// scores
	// weight scores
	double score = 0;
	for ( size_t j = 0; j < foundWeights.size(); j ++)
	{
		if (score < foundWeights[j]) // max valuse as the value
		{
				score = foundWeights[j];
		}
	}
	
	if (!found.empty())
	{
		printf("\t\t\t\t\t\tScore is : %lf\n", score);
	}
	//printf("foundWeight size is %d -------- found size is %d\n", foundWeights.size(), found.size());
	//for( size_t i = 0; i < foundWeights.size(); i ++)
	//{
	//	printf("foundWeights[%d] Score is : %lf\n", foundWeights.size(), foundWeights[i]);
	//}
	
	// - after finding a person, then, set the value to initialize status(=5)
	if (found.empty())
	{
		if ( no_people_frame_count > 0)
		{
			no_people_frame_count --;
		}
	}
	else
	{
		no_people_frame_count = SET_FRAME_NUMBERS_WHEN_NO_PEOPLE; 
	}
	

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

		// - store the resized Rect object -- r
		cropUtils.ReSizeRoi(r, img);	// resize (crop) r
		pre_found_rect.push_back(r);  // record the position of previously found pedestrins
		// -

		// the HOG detector returns slightly larger rectangles than the real objects.
		// so we slightly shrink the rectangles to get a nicer output.
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.07);
		r.height = cvRound(r.height*0.8);
		rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
	}
	//imshow("people detector", img);	
}


// test function
void fun1()
{
	//calcOpticalFlowPyrLK();
	/*
		void calcOpticalFlowFarneback (InputArray prevImg, 
			InputArray nextImg, InputOutputArray flow, 
			double pyrScale, int levels, int winsize, 
			int iterations, int polyN, double polySigma, 
			int flags)
	*/

	/*
		Parameters:	
		prevImg – First 8-bit single-channel input image.
		nextImg – Second input image of the same size and the same type as prevImg .
		flow – Computed flow image that has the same size as prevImg and type CV_32FC2 .
		pyrScale – Parameter specifying the image scale (<1) to build pyramids for each image. pyrScale=0.5 means a classical pyramid, where each next layer is twice smaller than the previous one.
		levels – Number of pyramid layers including the initial image. levels=1 means that no extra layers are created and only the original images are used.
		winsize – Averaging window size. Larger values increase the algorithm robustness to image noise and give more chances for fast motion detection, but yield more blurred motion field.
		iterations – Number of iterations the algorithm does at each pyramid level.
		polyN – Size of the pixel neighborhood used to find polynomial expansion in each pixel. Larger values mean that the image will be approximated with smoother surfaces, yielding more robust algorithm and more blurred motion field. Typically, polyN =5 or 7.
		polySigma – Standard deviation of the Gaussian that is used to smooth derivatives used as a basis for the polynomial expansion. For polyN=5 , you can set polySigma=1.1 . For polyN=7 , a good value would be polySigma=1.5 .
		flags –
		Operation flags that can be a combination of the following:

		OPTFLOW_USE_INITIAL_FLOW Use the input flow as an initial flow approximation.
		OPTFLOW_FARNEBACK_GAUSSIAN Use the Gaussian  \texttt{winsize}\times\texttt{winsize} filter instead of a box filter of the same size for optical flow estimation. Usually, this option gives z more accurate flow than with a box filter, at the cost of lower speed. Normally, winsize for a Gaussian window should be set to a larger value to achieve the same level of robustness.
		The function finds an optical flow for each prevImg pixel using the [Farneback2003] alorithm so that

		\texttt{prevImg} (y,x)  \sim \texttt{nextImg} ( y + \texttt{flow} (y,x)[1],  x + \texttt{flow} (y,x)[0])	
	*/
}


#endif