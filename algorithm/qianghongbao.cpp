#include<iostream>
#include<time.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
//min   默认最小金额 1=0.01元
//max   默认最大金额 20000 = 200 元
//total 总钱数
//num   总人数
long long  CalcRandomValue(long long min, long long max, long long total, long long num)
{
	if (num == 1)
	{
		return total;
	}
	//跟新随机种子
	srand((unsigned int)time(NULL));

	//锁定本次随机范围
	long long low = (total - (num - 1)*max) < min ? min : (total - (num - 1)*max);
	long long high = (total - (num - 1)*min) > max ? max : (total - (num - 1)*min);


	long long ave = (total / num) > 1 ? (total / num) : 1;
	//调整上限
	if (high > 2 * ave)
	{
		high = 2 * ave;
	}

	//生成随机值
	long long ram = rand() % high;

	//防止溢出
	if (ram < low)
		ram = low;

	if (ram > high)
		ram = high;

	return abs(ram);
}



long long  qianghongbao(long long  total,long long num )
{
	if (total > 0)
	{
		if (num == 1)
		{
            cout << "发红包金额" << total << endl;
		}
		total *= 100;
		long long  low = 1;
		long long  max = 20000;
		cout << "红包总金额 " << total/100 << "元" << endl;
		cout << "抢红包总人数　" << num << endl;
		long long  ret = 0;
		int i = 1;
		float big = 0.0;
		int person = 0;
		while (num > 0)
		{
			ret = CalcRandomValue(low, max, total, num);
			float ram = ret / 100.0;
			cout << "第" << i << "个人抢到了" << ram << "元" << endl;
			if (ram > big)
			{
				big = ram;
				person = i;
			}
			total -= ret;
			--num;
			++i;
		}
		cout << "第" << person << "个人抢到了" << big << "元,手气最佳" << endl;
	}
	return -1;
}

int main()
{

	qianghongbao(11, 10);

	return 0;
}

