//请实现一个函数，将一个字符串中的空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == NULL || length < 0)
            return;
        //记录原来字符的长度
        int oldNumber = 0;
        //记录空格的数量
        int replaceNumber = 0;
        int i = 0;
        while (str[i] != '\0') {
            oldNumber++;
            if(str[i] == ' ')
                replaceNumber++;
            i++;
        }
        int newNumber = oldNumber + replaceNumber*2;
        //判断替换之后的长度与字符数组长度的大小
        if (newNumber > length)
            return;
        while (oldNumber >= 0 && newNumber > oldNumber) {
            //碰到空格就替换
            if (str[oldNumber] == ' ') {
                str[newNumber--] = '0';
                str[newNumber--] = '2';
                str[newNumber--] = '%';
            } else {
                str[newNumber--] = str[oldNumber];
            }
            oldNumber--;
        }
    }
};

int main()
{
    char *str = new char[100];
    str[0] = 'a';
    str[1] = 'b';
    str[2] = ' ';
    str[3] = 'c';
    Solution t;
    t.replaceSpace(str,100);
    cout<<str<<endl;
    return 0;
}



//public class Solution_java {
//    public String replaceSpace(StringBuffer str) {
//        int spacenum = 0;//spacenum为计算空格数
//        for(int i=0;i<str.length();i++){
//            if(str.charAt(i)==' ')
//                spacenum++;
//        }
//        int indexold = str.length()-1; //indexold为为替换前的str下标
//        int newlength = str.length() + spacenum*2;//计算空格转换成%20之后的str长度
//        int indexnew = newlength-1;//indexold为为把空格替换为%20后的str下标
//        str.setLength(newlength);//使str的长度扩大到转换成%20之后的长度,防止下标越界
//        for(;indexold>=0 && indexold<newlength;--indexold){ 
//                if(str.charAt(indexold) == ' '){  //
//                str.setCharAt(indexnew--, '0');
//                str.setCharAt(indexnew--, '2');
//                str.setCharAt(indexnew--, '%');
//                }else{
//                    str.setCharAt(indexnew--, str.charAt(indexold));
//                }
//        }
//        return str.toString();
//    }
//}
//
//
//
//class Solution_Cpp {
//public:
//  void replaceSpace(char *str,int length) {
//      //遍历一边字符串找出空格的数量
//          if(str==NULL||length<0)
//              return ;
//          int i=0;
//          int oldnumber=0;//记录以前的长度
//          int replacenumber=0;//记录空格的数量
//          while(str[i]!='\0')
//              {
//                 oldnumber++;
//                 if(str[i]==' ')
//                     {
//                       replacenumber++;
//                     }
//                    i++; 
//              }
//          int newlength=oldnumber+replacenumber*2;//插入后的长度
//          if(newlength>length)//如果计算后的长度大于总长度就无法插入
//              return ;
//          int pOldlength=oldnumber; //注意不要减一因为隐藏个‘\0’也要算里
//          int pNewlength=newlength;
//         
//  while(pOldlength>=0&&pNewlength>pOldlength)//放字符
//              {
//                if(str[pOldlength]==' ') //碰到空格就替换
//                    {
//                       str[pNewlength--]='0';
//                       str[pNewlength--]='2';
//                       str[pNewlength--]='%';
//                       
//                    }
//                 else //不是空格就把pOldlength指向的字符装入pNewlength指向的位置
//                 {
//                      str[pNewlength--]=str[pOldlength];
//                     
//                 }
//               pOldlength--; //不管是if还是elsr都要把pOldlength前移
//               
//             }
//          
//
//
//
//
//  }
//  };