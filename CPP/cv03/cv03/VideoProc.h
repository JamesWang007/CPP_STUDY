//VideoProc.h  
  
#include"opencv2/core/core.hpp"  
#include"opencv2/highgui/highgui.hpp"  
#include "cv.h"  

using namespace std;  
using namespace cv;  
class VideoProc{  
    VideoCapture capture;//视频文件指针  
    string InputWindow,OutputWindow;//输入输出窗口名  
    void(*process)(Mat&,Mat&);//回调处理函数指针，指向返回类型为void参数为(Mat&,Mat&)的函数  
    long Fnumber;//已经处理的帧数合计  
    long FrameToStop;//需要停止的帧序号  
    bool callIt;//是否调用回调处理函数标志位，true->call , false->donnt call  
    bool stop_flag;//是否停止处理标准位,true->stop , false->donnt stop  
    int delay;//延时参数  
public:  
    VideoProc():process(NULL),Fnumber(0),FrameToStop(-1),callIt(true),stop_flag(false),delay(0){}  
     
    /*******************参数设置/初始化函数************************/  
    bool InputVideo(const string);//读取视频  
    void setProcess(void (*)(Mat&,Mat&));//设置回调函数  
    void Window_ShowInput(const string);//创建原始视频显示窗口  
    void Window_ShowOutput(const string);//创建处理过的视频显示窗口  
    void dontDisplay(void);//不再显示处理后的帧  
    long getNextFrame();//返回下一帧的序号  
  
    /********************处理过程控制函数**************************/  
    void run(void);  
	void run1(void);
  
    double getFrameRate(){return capture.get(CV_CAP_PROP_FPS);}//返回每秒显示的帧数  
    void setStopFlag(bool flag){stop_flag=flag;}//停止整个过程运行标志位设置  
    void setDelay(int d){delay=d;}//设置延迟参数  
    void setcallProcesss(bool flag){callIt=flag;}//是否调用回调函数，不调用回调函数输出未经处理的视频文件  
    void stopAtFrameNumber(long frame){FrameToStop=frame;}//停止在特定帧设置  
    bool readNextFrame(Mat& frame){return capture.read(frame);}//读取下一帧  
};  
bool VideoProc::InputVideo(const string filename)//打开视频文件  
{  
    Fnumber=0;  
    capture.release();  
    return capture.open(filename);  
}  
void VideoProc::setProcess(void(*freamProccessingCallback)(Mat&,Mat&))//传递回调函数地址  
{  
    process=freamProccessingCallback;  
}  
void VideoProc::Window_ShowInput(const string filename)//创建原始视频显示窗口  
{  
    InputWindow=filename;  
    namedWindow(InputWindow,2);  
}  
void VideoProc::Window_ShowOutput(const string filename)//创建处理过的视频显示窗口  
{  
    OutputWindow=filename;  
    namedWindow(OutputWindow,2);  
}  
void VideoProc::dontDisplay()  
{  
    destroyWindow(InputWindow);  
    destroyWindow(OutputWindow);  
    InputWindow.clear();  
    OutputWindow.clear();  
}  
long VideoProc::getNextFrame()//返回下一帧的序号  
{  
    long fsquence=static_cast<long>(capture.get(CV_CAP_PROP_POS_FRAMES));  
    return fsquence;  
}  
void VideoProc::run(void)  
{  
	Mat CurrentFrame,OutputFrame;//分别为当前帧和输出帧  
	if(!capture.isOpened()) return;  
	long FrameCount=static_cast<long>(capture.get(CV_CAP_PROP_FRAME_COUNT))-1;//视频文件帧总数  
	int count = 0;
	while(!stop_flag)  
    {  
        if(!readNextFrame(CurrentFrame))//读取下一帧不成功  
            break;  
		// resize each frame
		//resize(CurrentFrame, CurrentFrame, Size(640,480), 0, 0 , INTER_CUBIC);

        if(InputWindow.length()!=0)//字符串的长度不为0代表已经有窗口创建  
            imshow(InputWindow,CurrentFrame);  

		// start time: start to record
		clock_t startTime = clock();
		
		
		// the process() function
        if(callIt)  
        {
			//if((++count) % 5 == 0) // process every xxx frames
			//{	
			//	count = 0;
			//	process(CurrentFrame,OutputFrame);  
			//	Fnumber++;
			//}
			//else
			//{
			//	OutputFrame=CurrentFrame; 
			//}
			//cvtColor(CurrentFrame, CurrentFrame, cv::COLOR_RGB2GRAY);
			process(CurrentFrame,OutputFrame);  
            Fnumber++;
		}  
        else  
            OutputFrame=CurrentFrame;  

		// output the time span.
		clock_t endTime = clock();
		//cout << "time span: " << endTime - startTime / (double) CLOCKS_PER_SEC << endl;


		if(OutputWindow.length()!=0)  
            imshow(OutputWindow,OutputFrame);  

		waitKey(0);

		//if((delay>=0&&waitKey(delay)>=0))  
          // setStopFlag(true);//有任意按键按下则停止整个处理过程  

		if(FrameToStop>=0&&FrameToStop<=FrameCount&&getNextFrame()==FrameToStop)//到达设定需要暂停的帧，始终等待按键按下  
            waitKey(0);  
    }  
}  

// this is a back-up of the run(void) function
void VideoProc::run1(void)  
{  
	Mat CurrentFrame,OutputFrame;//分别为当前帧和输出帧  
	if(!capture.isOpened()) return;  
	long FrameCount=static_cast<long>(capture.get(CV_CAP_PROP_FRAME_COUNT))-1;//视频文件帧总数  
	int count = 0;
	while(!stop_flag)  
    {  
        if(!readNextFrame(CurrentFrame))//读取下一帧不成功  
            break;  
		// resize each frame
		//resize(CurrentFrame, CurrentFrame, Size(640,480), 0, 0 , INTER_CUBIC);

        if(InputWindow.length()!=0)//字符串的长度不为0代表已经有窗口创建  
            imshow(InputWindow,CurrentFrame);  

		// start time: start to record
		clock_t startTime = clock();		
		
		// the process() function
        if(callIt)  
        {
			//if((++count) % 5 == 0) // process every xxx frames
			//{	
			//	count = 0;
			//	process(CurrentFrame,OutputFrame);  
			//	Fnumber++;
			//}
			//else
			//{
			//	OutputFrame=CurrentFrame; 
			//}
			//cvtColor(CurrentFrame, CurrentFrame, cv::COLOR_RGB2GRAY);
			process(CurrentFrame,OutputFrame);  
            Fnumber++;
		}  
        else  
            OutputFrame=CurrentFrame;  

		// output the time span.
		clock_t endTime = clock();
		//cout << "time span: " << endTime - startTime / (double) CLOCKS_PER_SEC << endl;


		if(OutputWindow.length()!=0)  
            imshow(OutputWindow,OutputFrame);  
		if((delay>=0&&waitKey(delay)>=0))  
           setStopFlag(true);//有任意按键按下则停止整个处理过程  
		if(FrameToStop>=0&&FrameToStop<=FrameCount&&getNextFrame()==FrameToStop)//到达设定需要暂停的帧，始终等待按键按下  
            waitKey(0);  
    }  
}  
  