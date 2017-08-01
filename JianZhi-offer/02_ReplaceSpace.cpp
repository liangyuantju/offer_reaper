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