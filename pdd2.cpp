#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int> > vec;

int isRight(int i, int j, int a, int b) {
    if(i==a && j==b)
        return 1;
    else if(i==b && a==j)
        return -1;
    else
        return 0;
}

bool cmd(vector<int>& v1, vector<int>& v2) {
    int flag=0;
    for(int i=0; i<6; i=i+2) {
        int tmp=isRight(v1[i],v1[i+1],v2[i],v2[i+1]);
        if(tmp)
            flag+=tmp;
        else
            return 0;
    }
    if(flag==1 || flag==-3)
        return 1;
    else
        return 0;
}

int cmd(vector<int>& v) {
    for(int i=0; i<30; ++i) {
        if(cmd(v,vec[i])) {
            return i;
        }
    }
    return -1;
}

/**
 * 
 * 1.编程语言可使用：C/C++, Java，时长150分钟。
2.请使用最新版chrome浏览器作答（72版本以上），考试需开启摄像头，请确保电脑带有摄像头。
3.编程题支持本地IDE编码后复制粘贴至考试页面，不做跳出限制。

4.每题100分，每个题会有多个数据，按数据独立给分。
5.系统首先会对您的程序进行编译。如果编译出错，会返回CE以及编译错误信息（常见的编译错误包括没有include正确的头文件等）。
6.如果编译成功，系统会用预先设定的若干组 (通常是5组或者10组) 数据对您的程序进行评测。
7.每道题目以最后那次提交结果为准。
8.如果您的程序全部输出正确，系统会反馈AC，您会得到满分；否则您会得到部分分数，和第一组出错的数据的反馈。例如5组数据，您的程序对于第1-3组数据输出结果正确，第4组输出结果错误(WA)，第5组运行时间超时(TLE)，系统会反馈WA，您会得到前3组数据的分数。

9.考试时允许使用草稿纸，请提前准备纸笔。考试过程中允许上厕所等短暂离开，但请控制离开时间。
10.考试期间如遇到断电、断网、死机等问题，可以关闭浏览器重新打开试卷链接即可继续做题。
11.测试时间结束程序提交即停止。而根据以往经验，测试结束前的10-15分钟系统会收到大量提交，可能会出现系统的反馈不够及时的情况。提醒大家合理安排时间，尽量避免在最后时段的集中提交。
12.遇到问题请即时反馈给考试主办方。
 * 
 * 
*/

int main() {
    int N=0;
    cin>>N;
    vec.push_back({1,2,3,4,5,6});
    vec.push_back({1,2,3,4,6,5});
    vec.push_back({1,2,3,5,4,6});
    vec.push_back({1,2,3,5,6,4});
    vec.push_back({1,2,3,6,4,5});
    vec.push_back({1,2,3,6,5,4});
    vec.push_back({1,3,2,4,5,6});
    vec.push_back({1,3,2,4,6,5});
    vec.push_back({1,3,2,5,4,6});
    vec.push_back({1,3,2,5,6,4});
    vec.push_back({1,3,2,6,4,5});
    vec.push_back({1,3,2,6,5,4});
    vec.push_back({1,4,2,3,5,6});
    vec.push_back({1,4,2,3,6,5});
    vec.push_back({1,4,2,5,3,6});
    vec.push_back({1,4,2,5,6,3});
    vec.push_back({1,4,2,6,3,5});
    vec.push_back({1,4,2,6,5,3});
    vec.push_back({1,5,2,4,3,6});
    vec.push_back({1,5,2,4,6,3});
    vec.push_back({1,5,2,3,4,6});
    vec.push_back({1,5,2,3,6,4});
    vec.push_back({1,5,2,6,4,3});
    vec.push_back({1,5,2,6,3,4});
    vec.push_back({1,6,2,4,5,3});
    vec.push_back({1,6,2,4,3,5});
    vec.push_back({1,6,2,5,4,3});
    vec.push_back({1,6,2,5,3,4});
    vec.push_back({1,6,2,3,4,5});
    vec.push_back({1,6,2,3,5,4});
    vector<int> vCount(30,0);
    int cnt=0;
    vector<int> item(6,0);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<6; ++j) {
            cin>>item[j];
        }
        int index=cmd(item);
        if(index>=0) {
            if(!vCount[index])
                ++cnt;
            ++vCount[index];
        }
    }
    sort(vCount.begin(),vCount.end());
    cout<<cnt<<endl;
    cout<<vCount[29];
    for(int i=28; i>=0; --i) {
        if(vCount[i]>0)
            cout<<" "<<vCount[i];
    }
    cout<<endl;
    return 0;
}