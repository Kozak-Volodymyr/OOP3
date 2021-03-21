#include<iostream>
#include<cmath>
#include<Windows.h>
using namespace std;
int M = 1;
class Kvadrat2D {
private:
	 int x, x1, y, y1;
public:
	 Kvadrat2D(int a) { x = a; x1 = a; y = a; y1 = a; }
	 Kvadrat2D() {
		  cout << " вадрат є"<<M << endl;
		  cout << "¬вед≥ть x:";
		  cin >> x;
		  cout << "¬вед≥ть x1:";
		  cin >> x1;
		  cout << "¬вед≥ть y:";
		  cin >> y;
		  cout << "¬вед≥ть y1:";
		  cin >> y1;
		  M++;
	 }
	 ~Kvadrat2D() {}
	 int GetX() { return x; }
	 int GetX1() { return x1; }
	 int GetY() { return y; }
	 int GetY1() { return y1; }
	 double Distance() {
		  double Distance;
		  Distance = sqrt((pow(GetX() - GetX1(), 2) + pow(GetY() - GetY1(), 2)));
		  return Distance;
	 }
	 friend Kvadrat2D operator>>(Kvadrat2D &p1, int a) {
		  p1.x = p1.x >> a;
		  p1.x1 = p1.x1 >> a;
		  p1.y = p1.y >> a;
		  p1.y1 = p1.y1 >> a;
		  return p1;
	 }
	 friend Kvadrat2D operator<<(Kvadrat2D &p1, int a) {
		  p1.x = p1.x << a;
		  p1.x1 = p1.x1 << a;
		  p1.y = p1.y << a;
		  p1.y1 = p1.y1 << a;
		  return p1;
	 }
};
	 int operator>(Kvadrat2D &obj,Kvadrat2D &obj1) {
		  if (obj.Distance() > obj1.Distance()) {
				return 1;
		  }
		  else
				return 0;
	 }
	 double operator-(Kvadrat2D &p1,double a) {
		  double b;
		  b=p1.Distance()-a;
		  return b;
	 }
	 int main() {
		  SetConsoleOutputCP(1251);
		  SetConsoleCP(1251);
		  int n;
		  cout << "¬вед≥ть к≥льк≥сть квадрат≥в:";
		  cin >> n;
		  Kvadrat2D *DATA = new Kvadrat2D[n];
		  int l = 0;
		  for (int i = 0; i < n; i++) {
				Kvadrat2D obj1(0);
				if ((i + 1)== n)
					 break;
				if ((DATA[i] > DATA[i + 1]) == 0) {
					 l = i;
					 while ((DATA[l] > DATA[l + 1]) == 0) {
						  obj1 = DATA[l];
						  DATA[l] = DATA[l + 1];
						  DATA[l + 1] = obj1;
						  l--;
					 }
				}
		  }
		  double a;
		  cout << "¬вед≥ть a:";
		  cin >> a;
		  for (int i = 0; i < n; i++) {
				double b=0;
				b= DATA[i] - a;
				cout << "–езультати:" << endl;
				cout << " вадратє" << i + 1 << endl;
				cout << "x:" << DATA[i].GetX() << endl; 
				cout << "x1:" << DATA[i].GetX1() << endl; 
				cout << "y:" << DATA[i].GetY() << endl; 
				cout << "y1:" << DATA[i].GetY1() << endl;
				cout<<"—торона:" << b << endl;
		  }
		  delete[]DATA;
	 }
