#include<iostream>
#include<vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

string Type2String(int type)
{
    string strType;
    uchar depth = type & CV_MAT_DEPTH_MASK;
    //uchar chans = 1 + (type >> CV_CN_SHIFT);
    switch (depth)
    {
    case CV_8U:
        strType = "CV_8U"; break;
    case CV_8S:
        strType = "CV_8S"; break;
    case CV_16U:
        strType = "CV_16U"; break;
    case CV_16S:
        strType = "CV_16S"; break;
    case CV_32S:
        strType = "CV_32S"; break;
    case CV_32F:
        strType = "CV_32F"; break;
    case CV_64F:
        strType = "CV_64F"; break;
    default:
        strType = "UNKNOWN_TYPE"; break;
    }
    //strType += "C";
    //strType += (chans + '0');

    return strType;
}
int main() 
{
	Mat img = imread("ͼƬ.bmp", IMREAD_UNCHANGED);
	int width = img.rows;
	int heidht = img.cols;
	//cout << img.size()/ width << " " << img.size()/heidht << endl;

	cout <<"��ڧܧ�֧ݧ�"<< img.size() << endl;


    cout <<" �ԧݧ�ҧڧߧ� ��ӧ֧��:" << img.type() << endl;
    cout << Type2String(img.type()) << endl;



    if (img.data != NULL)
    {
        vector<int>compression_params;
        compression_params.push_back(IMWRITE_JPEG_QUALITY);
        compression_params.push_back(90);     //ͼ��ѹ���������ò���ȡֵ��ΧΪ0-100����ֵԽ�ߣ�ͼ������Խ��

        bool bRet = imwrite("ͼƬ1.jpg", img, compression_params);
        if (bRet)
        {
            cout << "���٧�ҧ�ѧا֧ߧڧ� ����֧�ߧ� �����ѧߧ֧ߧ�" << endl;
        }
        else
        {
            cout << "���� ��էѧݧ��� �����ѧߧڧ�� �ڧ٧�ҧ�ѧا֧ߧڧ�" << endl;
        }
    }
    else
    {
        cout << "���ѧԧ��٧ܧ� �ڧ٧�ҧ�ѧا֧ߧڧ� �ߧ� ��էѧݧѧ��, ����ӧ֧����, ����֧��ӧ�֧� �ݧ� ��ѧۧ�!" << endl;
    }

    waitKey(0);
    getchar();


	system("pause");
	return 0;
}
