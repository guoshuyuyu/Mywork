#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[]){
    QCoreApplication a(argc,argv);
    QVector<QString> number,name,score1,score2;
    number<<"1403130209"<<"1403140101"<<"1403140102"<<"1403140103";//学号
    name<<"鲁智深"<<"林冲"<<"宋江"<<"武松";//姓名
    score1<<"80"<<"82"<<"76"<<"88";//课程1成绩
    score2<<"72"<<"76"<<"85"<<"80";//课程2成绩
    qDebug()<<"原始数据："<<"\t\t"<<number<<"\t\t"<<name<<"\t\t"<<score1<<"\t"<<score2;//输出原始数据
    QVector<QVector<QString>>transcript;
    transcript<<number<<name<<score1<<score2;
    qDebug()<<"按姓名排序：";
    std::sort(name.begin(),name.end(),std::greater<QString>());
    int i,j;
    for(i=0;i<name.size();i++){
        for(j=0;j<name.size();j++)
            if(name.at(i)==transcript.at(1).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"课程1成绩排序：";
    std::sort(score1.begin(),score1.end(),std::greater<QString>());
    for(i=0;i<score1.size();i++){
        for(j=0;j<score1.size();j++)
            if(score1.at(i)==transcript.at(2).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    qDebug()<<"按课程2成绩排序：";
    std::sort(score2.begin(),score2.end(),std::greater<QString>());
    for(i=0;i<score2.size();i++){
        for(j=0;j<score2.size();j++)
            if(score2.at(i)==transcript.at(3).at(j))
                break;
        qDebug()<<transcript.at(0).at(j)<<transcript.at(1).at(j)<<transcript.at(2).at(j)<<transcript.at(3).at(j);
    }
    return a.exec();


}
