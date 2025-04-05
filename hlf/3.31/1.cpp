#include<iostream>
using namespace std;

void func1() {
	int n;
	while (true) {
		cout << "请输入五以内的位数n" << endl;
		cin >> n;
		if (n >= 1 && n <= 5) {
			switch (n) {
			case 1:
				cout << "0到9" << endl;
				break;
			case 2:
				for (int i = 10;i <= 99;i++) {
					int a = 0, b = 0;
					a = i % 10;b = i / 10;
					if (a * a + b * b == i) {
						cout << i << endl;
					}

				}
				cout << "没有" << endl;
				break;
			case 3:
				for (int i = 100;i <= 999;i++) {
					int a = 0, b = 0, c = 0;
					a = i % 100;b = (i / 10) % 10;c = i / 100;
                    if(i==153)  cout<<a<<" "<<b<<" "<<c<<endl;
					if (a * a * a + b * b * b + c * c * c == i) {
						cout << i << endl;
					}
				}
				break;
			case 4:
				for (int i = 1000;i <= 9999;i++) {
					int a = 0, b = 0, c = 0, d = 0;
					a = i % 1000;b = i / 10 % 100;c = i / 100 % 10;d = i / 1000;
					if (a * a * a * a + b * b * b * b + c * c * c * c + d * d * d * d == i) {
						cout << i << endl;
					}
				}
				break;
			case 5:
				for (int i = 10000;i <= 99999;i++) {
					int a = 0, b = 0, c = 0, d = 0, e = 0;
					a = i % 10000;b = i / 10 % 1000;c = i / 100 % 100;d = i / 1000 % 10;e = i / 10000;
					if (a * a * a * a * a + b * b * b * b * b + c * c * c * c * c + d * d * d * d * d + e * e * e * e * e == i) {
						cout << i << endl;
					}
				}
				break;

			}
			break;

		}
		else {
			cout << "输入无效，请重新输入" << endl;
		}


	}

}
void func2() {
	int num = 0, sum = 0;
	cout << "请输入一个数字：" << endl;
	cin >> num;
	for (int i = 1;i <= num - 1;i++) {
		int a;
		a = num % i;
		if (a == 0) {
			sum += i;
		}
	}
	if (num == sum) {
		cout << num << "是完备数" << endl;
	}
	if (num != sum) {
		cout << num << "不是完备数" << endl;
	}
}
int main() {
	while (true) {
		cout << "请选择以下功能编号：" << endl;
		cout << "1、求自幂数" << endl;
		cout << "2、判断完备数" << endl;
		cout << "3、退出" << endl;
		int select = 0;
		cin >> select;


		switch (select) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			cout << "该程序已经退出" << endl;
			return 0;
        }
    }
}