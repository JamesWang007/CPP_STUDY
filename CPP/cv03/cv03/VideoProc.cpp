
//VideoProc.cpp  
#include"iostream"  
#include"VideoProc.h"  
#include "detectionFunctions.h"

int main()  
{  
    VideoProc sv;//�������  
    sv.InputVideo("D:\\windows\\data\\video\\3.mp4");//��Ƶ��ȡ  
	//D:\\windows\\data\\video\\seg1.mp4
	//D:\\windows\\data\\video\\seg2.mp4
	//D:\\windows\\data\\video\\seg3_two.mp4
	//D:\\windows\\data\\video\\seg4_two.mp4
	//D:\\windows\\data\\video\\1.mp4
	//D:\\windows\\data\\video\\2.mp4
	//D:\\windows\\data\\video\\3.mp4
	//D:\\windows\\data\\video\\4.mp4


    sv.Window_ShowInput("inputWindow");//����ԭʼ��Ƶ��ʾ����  
    sv.Window_ShowOutput("outputWindow");//�������������Ƶ��ʾ����  
    sv.setDelay(1000./sv.getFrameRate());//�����ӳٲ���,����Ϊ"0"��ʾÿ֡����Ҫ�û�����,  
                                       //1000./sv.getFrameRate()��ʾ��ʱ�Ĳ������ʺ�ԭʼ��Ƶ��Ƶ����ͬ  
    //sv.setProcess(canny);//֡���������ýӿ�  
	sv.setProcess(pedstDetectHOG_crop); // pedstDetectHOG, pedstDetectHOG_crop
    sv.stopAtFrameNumber(-1);//��25֡����ͣ
    sv.setcallProcesss(true);//�����ô�����  
    sv.run();//��Ƶ������̿��ƺ���  

	return 0;  
}  