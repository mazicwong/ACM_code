/*
http://blog.csdn.net/dgq8211/article/details/7385718
http://blog.csdn.net/xiaofei_it/article/details/17042651
大概思路是开2个数组，c1[]保存当前得到的多项式各项系数，c2[]保存每次计算时的临时结果，
当每次计算完毕后，把它赋给c1，然后c2清零。
计算的时候，开3层for循环。
最外层，记录它正在与第几个多项式相乘。第二层，表示c1中的每一项，第三层表示后面被乘多项式中的每一项。

题目：  hdu 2082 母函数入门题
		hdu 1028 母函数整数划分，就是求完给出 C1[n]就行了


*/

memset(c1, 0, sizeof(c1));
memset(c2, 0, sizeof(c2));
c1[0] = 1;   //用x^0去乘以后面的多项式
for (int i = 1; i <= 26; i++) cin >> num[i];  //num[i]存放i重量的砝码有多少个
for (int i = 1; i <= 26; i++)
{//每一个多项式函数有26个乘积
	for (int j = 0; j <= 50; j++)
	{//c1各项系数的指数
		for (int k = 0; k <= num[i] && j + k*i <= 50; k++) //如果num[i]是无穷，这里的k<=num[i]舍去
		{//k*i表示被乘多项式各项的指数,(X^0*i + X^1*i + X^2*i + ……)
		 //指数相加得j+k*i,加多少只取决于c1[j]的系数，因为被乘多项式的各项系数均为1 
			c2[j + k*i] += c1[j];
		}
	}
	memcpy(c1, c2, sizeof(c2));
	memset(c2, 0, sizeof(c2));
}


/**********************模版二*************************/
//提高效率，用一个maxx变量记录目前最大的指数，这样只需要在0..last上进行计算。
/*
题目： hdu 1085 给1.2.5三种硬币个数，问最小不能表示的价值是多少
*/
a[0] = 1;
int maxx = 0;
memset(c1, 0, sizeof(c1));
memset(c2, 0, sizeof(c2));
c1[0] = 1;   //用x^0去乘以后面的多项式
maxx = 0;
for (int i = 1; i <= 3; i++) //每个的价值不是1.2.3了，而是1.2.5
{
	maxx += money[i] * num[i];
	for (int j = 0; j <= maxx; j++)
		for (int k = 0; k <= num[i] && j + k*money[i] <= maxx; k++)
			c2[j + k*val[i]] += c1[j];

	memcpy(c1, c2, sizeof(c2));
	memset(c2, 0, sizeof(c2));
}
