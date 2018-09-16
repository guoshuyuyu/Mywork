#include<qDebug>
#define str(s) #s
typedef quint32 word;
typedef quint8 byte;
#define llo(x) ((byte)((word)(x)&0xFF))//低低位
#define hlo(x) ((byte)(((word)(x)>>8)&0xFF))//低高位
#define lhi(x) ((byte)(((word)(x)>>16)&0xFF))//高低位
#define hhi(x) ((byte)(((word)(x)>>24)&0xFF))//高高位
#define max(x,y) (((x)>(y))?(x):(y))//最大值
#define min(x,y) (((x)<(y))?(x):(y))//最小值
int main(int argc,char *argv[])
{
    int i=0x12345678;
    QList<qint8> values;
    values.append(llo(i));//将取值结果先存入对象values中
    values.append(hlo(i));
    values.append(lhi(i));
    values.append(hhi(i));
    int N_i;
    N_i=(values.at(0)<<16)+(values.at(1)<<8)+(values.at(2))+(values.at(3)<<24);
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",i,i,values.at(3),values.at(3),values.at(2),values.at(2),values.at(1),values.at(1),values.at(0),values.at(0));//原始值 低低位 低高位 高低位 高高位的值
    qDebug("0x%x(%d) 0x%x(%d)",max(values.at(0),values.at(1)),max(values.at(0),values.at(0)),min(values.at(2),values.at(3)),min(values.at(2),values.at(3)));//分别求高高位与低高位的最大值 高低位与低低位的最小值
    qDebug("0x%x(%d)",N_i,N_i);//0x56127834
    std::sort(values.begin(),values.end(),std::greater<qint8>());//从大到小排序
    qDebug()<<"排序后:"<<values;
}
