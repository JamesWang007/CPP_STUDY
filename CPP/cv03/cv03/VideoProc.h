//VideoProc.h  
  
#include"opencv2/core/core.hpp"  
#include"opencv2/highgui/highgui.hpp"  
#include "cv.h"  

using namespace std;  
using namespace cv;  
class VideoProc{  
    VideoCapture capture;//��Ƶ�ļ�ָ��  
    string InputWindow,OutputWindow;//�������������  
    void(*process)(Mat&,Mat&);//�ص�������ָ�룬ָ�򷵻�����Ϊvoid����Ϊ(Mat&,Mat&)�ĺ���  
    long Fnumber;//�Ѿ������֡���ϼ�  
    long FrameToStop;//��Ҫֹͣ��֡���  
    bool callIt;//�Ƿ���ûص���������־λ��true->call , false->donnt call  
    bool stop_flag;//�Ƿ�ֹͣ�����׼λ,true->stop , false->donnt stop  
    int delay;//��ʱ����  
public:  
    VideoProc():process(NULL),Fnumber(0),FrameToStop(-1),callIt(true),stop_flag(false),delay(0){}  
     
    /*******************��������/��ʼ������************************/  
    bool InputVideo(const string);//��ȡ��Ƶ  
    void setProcess(void (*)(Mat&,Mat&));//���ûص�����  
    void Window_ShowInput(const string);//����ԭʼ��Ƶ��ʾ����  
    void Window_ShowOutput(const string);//�������������Ƶ��ʾ����  
    void dontDisplay(void);//������ʾ������֡  
    long getNextFrame();//������һ֡�����  
  
    /********************������̿��ƺ���**************************/  
    void run(void);  
	void run1(void);
  
    double getFrameRate(){return capture.get(CV_CAP_PROP_FPS);}//����ÿ����ʾ��֡��  
    void setStopFlag(bool flag){stop_flag=flag;}//ֹͣ�����������б�־λ����  
    void setDelay(int d){delay=d;}//�����ӳٲ���  
    void setcallProcesss(bool flag){callIt=flag;}//�Ƿ���ûص������������ûص��������δ���������Ƶ�ļ�  
    void stopAtFrameNumber(long frame){FrameToStop=frame;}//ֹͣ���ض�֡����  
    bool readNextFrame(Mat& frame){return capture.read(frame);}//��ȡ��һ֡  
};  
bool VideoProc::InputVideo(const string filename)//����Ƶ�ļ�  
{  
    Fnumber=0;  
    capture.release();  
    return capture.open(filename);  
}  
void VideoProc::setProcess(void(*freamProccessingCallback)(Mat&,Mat&))//���ݻص�������ַ  
{  
    process=freamProccessingCallback;  
}  
void VideoProc::Window_ShowInput(const string filename)//����ԭʼ��Ƶ��ʾ����  
{  
    InputWindow=filename;  
    namedWindow(InputWindow,2);  
}  
void VideoProc::Window_ShowOutput(const string filename)//�������������Ƶ��ʾ����  
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
long VideoProc::getNextFrame()//������һ֡�����  
{  
    long fsquence=static_cast<long>(capture.get(CV_CAP_PROP_POS_FRAMES));  
    return fsquence;  
}  
void VideoProc::run(void)  
{  
	Mat CurrentFrame,OutputFrame;//�ֱ�Ϊ��ǰ֡�����֡  
	if(!capture.isOpened()) return;  
	long FrameCount=static_cast<long>(capture.get(CV_CAP_PROP_FRAME_COUNT))-1;//��Ƶ�ļ�֡����  
	int count = 0;
	while(!stop_flag)  
    {  
        if(!readNextFrame(CurrentFrame))//��ȡ��һ֡���ɹ�  
            break;  
		// resize each frame
		//resize(CurrentFrame, CurrentFrame, Size(640,480), 0, 0 , INTER_CUBIC);

        if(InputWindow.length()!=0)//�ַ����ĳ��Ȳ�Ϊ0�����Ѿ��д��ڴ���  
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
          // setStopFlag(true);//�����ⰴ��������ֹͣ�����������  

		if(FrameToStop>=0&&FrameToStop<=FrameCount&&getNextFrame()==FrameToStop)//�����趨��Ҫ��ͣ��֡��ʼ�յȴ���������  
            waitKey(0);  
    }  
}  

// this is a back-up of the run(void) function
void VideoProc::run1(void)  
{  
	Mat CurrentFrame,OutputFrame;//�ֱ�Ϊ��ǰ֡�����֡  
	if(!capture.isOpened()) return;  
	long FrameCount=static_cast<long>(capture.get(CV_CAP_PROP_FRAME_COUNT))-1;//��Ƶ�ļ�֡����  
	int count = 0;
	while(!stop_flag)  
    {  
        if(!readNextFrame(CurrentFrame))//��ȡ��һ֡���ɹ�  
            break;  
		// resize each frame
		//resize(CurrentFrame, CurrentFrame, Size(640,480), 0, 0 , INTER_CUBIC);

        if(InputWindow.length()!=0)//�ַ����ĳ��Ȳ�Ϊ0�����Ѿ��д��ڴ���  
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
           setStopFlag(true);//�����ⰴ��������ֹͣ�����������  
		if(FrameToStop>=0&&FrameToStop<=FrameCount&&getNextFrame()==FrameToStop)//�����趨��Ҫ��ͣ��֡��ʼ�յȴ���������  
            waitKey(0);  
    }  
}  
  