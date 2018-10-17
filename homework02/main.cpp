#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{
    QString num;
    QString name;
    QVector<int> score;
    QStringList stud;
} studData;

QDebug operator<< (QDebug d, const studData &data) {
    QDebugStateSaver saver(d);
    d.nospace()<<data.num<<" "<<data.name<<" "<<data.score;
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
        bool operator()(const studData & d1,const studData & d2) ;
    private:
        int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:
        if(d1.name>=d2.name)
            result = false;
        else
            result = true;
        break;
    case SK::col02:
        if(d1.num>=d2.num)
            result = false;
        else
            result = true;
        break;
    default:
        result=(d1.score.at(currentColumn-3)<(d2.score.at(currentColumn-3)));
    }
    return result;
}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void doSort();
    void readFile();
    QByteArray line;
private:
    QString tempFile;
    QVector<studData> student;
    void writeFile(quint8 lie);
    studData list;
};

 ScoreSorter::ScoreSorter(QString dataFile)
{
    tempFile=dataFile;
}
void ScoreSorter::doSort(){
    for(int i=1;i<this->list.stud.size();i++){
    myCmp cmp(i-1);
    std::sort(this->dataFile.begin(),this->dataFile.end(),cmp );
    qDebug()<<"排序后输出，当前排序第"<<i+1<<"列";
    qDebug() << ""<< (this->list)<<"\t";
    for(int i=0;i<this->dataFile.size();i++)
    qDebug() << this->dataFile.at(i)<<"\t";
    qDebug()<<"-------------------------------------\n";
    this->writeFile(i+1);
    }
}

void ScoreSorter::readFile(){
    QFile file(tempFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<QString("文件打开失败").arg(tempFile);
    return -1;
    }
    while(!file.atEnd()){
        QString line=file.readLine();
        qDebug()<<line;
    }
                  file.close();
        qDebug().noquote().nospace()<<"文件读取完成："<<tempFile;
    }
    void ScoreSorter::writeFile(quint8 lie){
        QFile file("sorted_"+this->tempFile);
        file.open(QIODevice::ReadWrite | QIODevice::Append);
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream<<QString("排序后输出，当前排序第")<<lie <<QString("列")<<"\r\n";
        stream<<"\t";
        for(int j=0;j<this->list.s.size();j++)
            stream<<this->list.s.at(j)<<"\t";
        stream<<"\r\n";
        for(int i=0;i<this->data.size();i++)
        {
            for(int j=0;j<this->list.s.size();j++)
                stream<<this->data.at(i).s.at(j)<<"\t";
            stream<<"\r\n";
        }
        stream<<"--------------------------------------------------------------"<<"\r\n";
        file.close();
    }
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile *gFileLog=NULL;
    QMessageLogger *gMlog=NULL;
    char *msgHead[]={
        "Debug",
        "Warning",
        "Critical",
        "Fatal",
        "Info",
    };
    QByteArray localMsg = msg.toLocal8Bit();
    if(gFileLog){
        QTextStream tWrite(gFileLog);
        QString msgText="%1 | %6 | %2:%3, %4 | %5\n";
        msgText=msgText.arg(msgHead[type]).arg(context.file).arg(context.function).arg(localMsg.constData());
        tWrite<<msgText;
    }else{
        fprintf(stderr,"%s | %s | %s:%u, %s | %s\n",msgHead[type],context.line,context.function,localMsg.constData());
    }
}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "C:/Users/舒雨/Desktop/data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
}
