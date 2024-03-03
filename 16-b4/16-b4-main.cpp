/* 2150792 计科 牛禄阳 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "16-b4.h"
using namespace std;

#if defined(__linux) || defined(__linux__) //Linux
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

#else //VS+Dev
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}
#endif

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动，也不需要提交，检查时会替换（细节可能有错，如果发现请及时提出）
***************************************************************************/
int main()
{
	if (1) {
		Date d1;
		Date d2(2023, 12, 1);

		cout << "测试初始化，完全正确的赋值" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2023.12.1，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2023, 11, 31); //2023.11.1

		cout << "测试初始化，年、月、日非法" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2023.11.1，实际为：";
		d4.show();

		/* 多个错，按年月日顺序处理 */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5应该是2000.2.29，实际为：";
		d5.show();
		cout << "d6应该是2000.2.1， 实际为：";
		d6.show();
		cout << "d7应该是2000.1.31，实际为：";
		d7.show();
		cout << "d8应该是2000.1.1， 实际为：";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 2, 29); //2023.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "测试初始化，闰年" << endl;

		cout << "d1应该是2023.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2020.2.29，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		d1.set(2023, 12, 10);	//2023.12.10
		d2.set(2023, 12);		//2023.12.1
		d3.set(2023);		    //2023.1.1

		cout << "d1应该是2023.12.10，实际为：";
		d1.show();
		cout << "d2应该是2023.12,1， 实际为：";
		d2.show();
		cout << "d3应该是2023.1.1，  实际为：";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 12, 1), d2(d1), d3(d1);

		cout << "测试set，部分不变" << endl;

		d1.set(2007, 0, 0); //2007.12.1
		d2.set(0, 10, 18);  //2023.10.18
		d3.set(0, 0, 28);   //2023.12.28

		cout << "d1应该是2007.12.1， 实际为：";
		d1.show();
		cout << "d2应该是2023.10.18，实际为：";
		d2.show();
		cout << "d3应该是2023.12.28，实际为：";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "测试set，年、月、日非法" << endl;

		d1.set(2112, 2, 29); //2000.2.29
		d2.set(2019, 2, 29); //2019.2.1
		d3.set(2023, 11, 32); //2023.11.1
		d4.set(2023, 13, 12); //2023.1.12

		cout << "d1应该是2000.2.29， 实际为：";
		d1.show();
		cout << "d2应该是2019.2.1，  实际为：";
		d2.show();
		cout << "d3应该是2023.11.1， 实际为：";
		d3.show();
		cout << "d4应该是2023.1.12， 实际为：";
		d4.show();

		/* 多个错+带缺省值，按年月日顺序处理 */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);//2000.1.31
		d11.set(1899, 13, 32);//2000.1.1
		cout << "d5应该是2000.2.29， 实际为：";
		d5.show();
		cout << "d6应该是2000.2.1，  实际为：";
		d6.show();
		cout << "d7应该是2000.2.1，  实际为：";
		d7.show();
		cout << "d8应该是2020.2.1，  实际为：";
		d8.show();
		cout << "d9应该是2020.1.1，  实际为：";
		d9.show();
		cout << "d10应该是2000.1.31，实际为：";
		d10.show();
		cout << "d11应该是2000.1.1， 实际为：";
		d11.show();

		Date d12(2020, 2, 29), d13(2023, 10, 31);

		d12.set(2023, 0, 0); //2023.2.1
		d13.set(0, 11, 0);   //2023.11.1

		cout << "d12应该是2023.2.1， 实际为：";
		d12.show();
		cout << "d13应该是2023.11.1，实际为：";
		d13.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 12, 1);
		int y, m, d;

		cout << "测试get" << endl;
		d1.get(y, m, d);

		cout << "应该y=2023,m=12,d=1，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 12, 1);
		Date d2;

		cout << "测试cout" << endl;
		cout << "d1应该是2023.12.1，实际为：" << d1 << endl;
		cout << "d2应该是2000.1.1， 实际为：" << d2 << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1;

		cout << "测试cin/cout" << endl;

		cout << "请输入2023 12 1" << endl;
		cin >> d1;
		cout << "d1应该是2023.12.1， 实际为：" << d1 << endl;

		cout << "请输入2020 2 29" << endl;
		cin >> d1;
		cout << "d1应该是2020.2.29， 实际为：" << d1 << endl;

		cout << "请输入2023 2 29" << endl;
		cin >> d1;
		cout << "d1应该是2023.2.1，  实际为：" << d1 << endl;

		cout << "请输入1899 4 10" << endl;
		cin >> d1;
		cout << "d1应该是2000.4.10， 实际为：" << d1 << endl;

		cout << "请输入2023 13 10" << endl;
		cin >> d1;
		cout << "d1应该是2023.1.10， 实际为：" << d1 << endl;

		cout << "请输入2023 11 31" << endl;
		cin >> d1;
		cout << "d1应该是2023.11.1， 实际为：" << d1 << endl;

		cout << "请输入2112 15 34" << endl;
		cin >> d1;
		cout << "d1应该是2000.1.1，  实际为：" << d1 << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31

		cout << "转换构造函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();

		d1 = 35000;
		cout << "d1应该是1995.10.29，实际为：";
		d1.show();

		d2 = 45260;
		cout << "d2应该是2023.12.1， 实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1900, 1, 1);
		Date d2(2099, 12, 31);
		Date d3(1995, 10, 29);
		Date d4(2023, 12, 1);

		cout << "类型转换函数测试，包括合法及非法值" << endl;

		cout << "d1应该是1，    实际为：" << int(d1) << endl;
		cout << "d2应该是73049，实际为：" << int(d2) << endl;
		cout << "d3应该是35000，实际为：" << int(d3) << endl;
		cout << "d4应该是45260，实际为：" << int(d4) << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 12, 1);
		Date d2;

		cout << "测试+/- n" << endl;

		d2 = d1 + 27;
		cout << "d2应该是2023.12.28，   实际为：" << d2 << endl;

		d2 = 27 + d1;
		cout << "d2应该是2023.12.28，   实际为：" << d2 << endl;

		d2 = d1 - 25;
		cout << "d2应该是2023.11.6，    实际为：" << d2 << endl;

		d1.set(2020, 2, 28);
		d2 = d1 + 3;
		cout << "d2应该是2020.3.2，     实际为：" << d2 << endl;

		d1.set(2023, 2, 28);
		d2 = d1 + 3;
		cout << "d2应该是2023.3.3，     实际为：" << d2 << endl;

		d1.set(2023, 12, 28);
		d2 = d1 + 5;
		cout << "d2应该是2024.1.2，     实际为：" << d2 << endl;

		d1.set(2023, 1, 1);
		d2 = d1 - 5;
		cout << "d2应该是2022.12.27，   实际为：" << d2 << endl;

		d1.set(2019, 12, 31);
		d2 = d1 + 367;
		cout << "d2应该是2021.1.1，     实际为：" << d2 << endl;

		d1.set(2022, 12, 31);
		d2 = d1 + 366;
		cout << "d2应该是2024.1.1，     实际为：" << d2 << endl;

		d1.set(2024, 1, 1);
		d2 = d1 - 366;
		cout << "d2应该是2022.12.31，   实际为：" << d2 << endl;

		d1.set(2021, 1, 1);
		d2 = d1 - 367;
		cout << "d2应该是2019.12.31，   实际为：" << d2 << endl;

		d1.set(1900, 1, 2);
		d2 = d1 - 10;
		cout << "d2应该是1900.1.1，     实际为：" << d2 << endl;

		d1.set(2099, 12, 30);
		d2 = d1 + 5;
		cout << "d2应该是2099.12.31，   实际为：" << d2 << endl;

		d1.set(2023, 12, 7);
		d2.set(2023, 11, 10);
		cout << "d1-d2应该是27，        实际为：" << d1 - d2 << endl;

		d1.set(2020, 11, 10);
		d2.set(2019, 11, 10);
		cout << "d1-d2应该是366，       实际为：" << d1 - d2 << endl;

		d1.set(2023, 12, 10);
		d2.set(2022, 12, 10);
		cout << "d1-d2应该是365，       实际为：" << d1 - d2 << endl;

		d1.set(2023, 12, 1);
		cout << "d1+27应该是2023.12.28，实际为：" << d1 + 27 << endl;
		cout << "27+d1应该是2023.12.28，实际为：" << 27 + d1 << endl;
		cout << "d1-25应该是2022.11.6， 实际为：" << d1 - 25 << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1(2023, 12, 1);
		Date d2(2023, 10, 13);

		cout << "测试-date" << endl;
		cout << "日期差值应为49， 实际为：" << d1 - d2 << endl;

		d2.set(2023, 12, 17);
		cout << "日期差值应为-16，实际为：" << d1 - d2 << endl;

		d1.set(2020, 3, 2);
		d2.set(2020, 2, 27);
		cout << "日期差值应为4，  实际为：" << d1 - d2 << endl;

		d1.set(2023, 3, 2);
		d2.set(2023, 2, 27);
		cout << "日期差值应为3，  实际为：" << d1 - d2 << endl;

		d1.set(2023, 1, 2);
		d2.set(2022, 12, 27);
		cout << "日期差值应为6，  实际为：" << d1 - d2 << endl;

		d1.set(2023, 1, 1);
		d2.set(2021, 12, 31);
		cout << "日期差值应为366，实际为：" << d1 - d2 << endl;

		d1.set(2021, 1, 1);
		d2.set(2019, 12, 31);
		cout << "日期差值应为367，实际为：" << d1 - d2 << endl;

		wait_for_enter();
	}

	if (1) {
		Date d1, d2;

		cout << "测试++/--" << endl;

		d1.set(2023, 12, 1);
		d2 = d1++;
		cout << "d1应该是2023.12.2， 实际为：" << d1 << endl;
		cout << "d2应该是2023.12.1， 实际为：" << d2 << endl;

		d1.set(2023, 12, 1);
		d2 = ++d1;
		cout << "d1应该是2023.12.2， 实际为：" << d1 << endl;
		cout << "d2应该是2023.12.2， 实际为：" << d2 << endl;

		d1.set(2023, 12, 1);
		d2 = d1--;
		cout << "d1应该是2023.11.30，实际为：" << d1 << endl;
		cout << "d2应该是2023.12.1， 实际为：" << d2 << endl;

		d1.set(2023, 12, 1);
		d2 = --d1;
		cout << "d1应该是2023.11.30，实际为：" << d1 << endl;
		cout << "d2应该是2023.11.30，实际为：" << d2 << endl;

		d1.set(2022, 12, 31);
		d2 = d1++;
		cout << "d1应该是2023.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是2022.12.31，实际为：" << d2 << endl;

		d1.set(2023, 1, 1);
		d2 = d1--;
		cout << "d1应该是2022.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2023.1.1，  实际为：" << d2 << endl;

		d1.set(2020, 2, 28);
		d2 = d1++;
		cout << "d1应该是2020.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2020.2.28， 实际为：" << d2 << endl;

		d1.set(2023, 2, 28);
		d2 = d1++;
		cout << "d1应该是2023.3.1，  实际为：" << d1 << endl;
		cout << "d2应该是2023.2.28， 实际为：" << d2 << endl;

		d1.set(2020, 3, 1);
		d2 = d1--;
		cout << "d1应该是2020.2.29， 实际为：" << d1 << endl;
		cout << "d2应该是2020.3.1，  实际为：" << d2 << endl;

		d1.set(2023, 3, 1);
		d2 = d1--;
		cout << "d1应该是2023.2.28， 实际为：" << d1 << endl;
		cout << "d2应该是2023.3.1，  实际为：" << d2 << endl;

		d1.set(2099, 12, 31);
		d2 = d1++;
		cout << "d1应该是2099.12.31，实际为：" << d1 << endl;
		cout << "d2应该是2099.12.31，实际为：" << d2 << endl;

		d1.set(1900, 1, 1);
		d2 = d1--;
		cout << "d1应该是1900.1.1，  实际为：" << d1 << endl;
		cout << "d2应该是1900.1.1，  实际为：" << d2 << endl;

		wait_for_enter();
	}

	if (1) {
		/* 测试比较运算符 */
		Date d1(2023, 12, 1);
		Date d2(2023, 12, 1);
		Date d3(2023, 11, 29);

		cout << "测试比较运算符" << endl;
		
		cout << "比较结果应为0，实际为：" << (d1 > d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 < d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 <= d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 == d2) << endl;
		cout << "比较结果应为0，实际为：" << (d1 != d2) << endl;
		cout << "比较结果应为1，实际为：" << (d1 > d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 >= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 < d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 <= d3) << endl;
		cout << "比较结果应为0，实际为：" << (d1 == d3) << endl;
		cout << "比较结果应为1，实际为：" << (d1 != d3) << endl;
		wait_for_enter();
	}

	return 0;
}
