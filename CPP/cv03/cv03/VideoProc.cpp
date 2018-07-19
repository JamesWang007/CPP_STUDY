
//VideoProc.cpp  
#include"iostream"  
#include"VideoProc.h"  
#include "detectionFunctions.h"

int main()  
{  
    VideoProc sv;//定义对象  
    sv.InputVideo("D:\\windows\\data\\video\\3.mp4");//视频读取  
	//D:\\windows\\data\\video\\seg1.mp4
	//D:\\windows\\data\\video\\seg2.mp4
	//D:\\windows\\data\\video\\seg3_two.mp4
	//D:\\windows\\data\\video\\seg4_two.mp4
	//D:\\windows\\data\\video\\1.mp4
	//D:\\windows\\data\\video\\2.mp4
	//D:\\windows\\data\\video\\3.mp4
	//D:\\windows\\data\\video\\4.mp4


    sv.Window_ShowInput("inputWindow");//创建原始视频显示窗口  
    sv.Window_ShowOutput("outputWindow");//创建处理过的视频显示窗口  
    sv.setDelay(1000./sv.getFrameRate());//设置延迟参数,设置为"0"表示每帧均需要用户按键,  
                                       //1000./sv.getFrameRate()表示此时的播放速率和原始视频的频率相同  
    //sv.setProcess(canny);//帧处理函数调用接口  
	sv.setProcess(pedstDetectHOG_crop); // pedstDetectHOG, pedstDetectHOG_crop
    sv.stopAtFrameNumber(-1);//在25帧处暂停
    sv.setcallProcesss(true);//不调用处理函数  
    sv.run();//视频处理过程控制函数  

	return 0;  
}  