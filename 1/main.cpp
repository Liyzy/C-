#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
struct StudentScore
{
    int serialNum;//序号
    int id;//学号
    string name;//姓名
    string major;//专业
    float regularScore;//平时成绩
    float midtermScore;//期中成绩
    float examScore;//期末成绩
    float finalScore;//总评成绩
};
void calculateMajor(StudentScore *s);  //统计班上各专业人数并写入文件
void parseScore(StudentScore *s, string str); //解析一行文本
void calculateFinalScore (StudentScore *s, int count)    //计算总评成绩
{
    s->finalScore=s->regularScore*0.1+s->midtermScore*0.3+s->examScore*0.6;
}
void printScore(StudentScore *stu)  //输出到屏幕
{
    cout<<setw(3)<<stu->serialNum;
    cout<<setw(12)<<stu->id;
    cout<<setw(5)<<stu->name;
    cout<<setw(10)<<stu->major;
    cout<<setw(4)<<stu->regularScore;
    cout<<setw(4)<<stu->midtermScore;
    cout<<setw(4)<<stu->examScore;
    cout<<setw(4)<<stu->finalScore;
}
bool readFromFile(StudentScore *s, int count,string  inputFileName)  //从文件读取
{
    int i;
    ifstream infile("score.txt",ios::in);
    if(!infile)
    {
        cerr<<"Error: unable to open score.txt\n";
        exit(1);
    }
    for(i=0; i<40; i++)  
        infile>>s[i].serialNum>>s[i].id>>s[i].name>>s[i].major>>s[i].regularScore>>s[i].midtermScore>>s[i].examScore>>s[i].finalScore;
    infile.close();
}
void sortScoreDesc(StudentScore *s, int count)   //排序函数，总成绩降序排
{
    int i,j,t;
    for(j=0; j<40; j++)
    {
        for(i=0; i<40-j; i++)    
        {
           if(s[i].finalScore<s[i+1].finalScore)
           {
              t=s[i].finalScore;
              s[i].finalScore=s[i+1].finalScore;
              s[i+1].finalScore=t;
           }
        }
    }
}
void writeToFile(StudentScore *s, int count,string outputFileName)  //输出到文件
{
    int i;
    cout<<"序号"<<'\t'<<"学号"<<'\t'<<"姓名"<<'\t'<<"班级"<<'\t'<<"平时成绩"<<'\t'<<"期中成绩"<<'\t'<<"期末成绩"<<'\t'<<"总评成绩"<<endl;
    ofstream outfile("score.txt",ios::out);
    if(!outfile)  
        {  
         cerr<<"open error!"<<endl;
                      
        }  
    for(i=0; i<40; i++)  
       {  
        outfile<<s[i].serialNum<<'\t'<<s[i].id<<'\t'<<s[i].name<<'\t'<<s[i].major<<'\t'<<s[i].regularScore<<'\t'<<s[i].midtermScore<<s[i].examScore<<s[i].finalScore<<endl;
        cout<<s[i].serialNum<<'\t'<<s[i].id<<'\t'<<s[i].name<<'\t'<<s[i].major<<'\t'<<s[i].regularScore<<'\t'<<s[i].midtermScore<<s[i].examScore<<s[i].finalScore<<endl;  
       }  
        outfile.close();
}
int main()
{
    StudentScore stus[40];
    readFromFile(stus,40,"score");
    sortScoreDesc(stus,40);
    writeToFile(stus,40,"statistic");
    return 0;
}
