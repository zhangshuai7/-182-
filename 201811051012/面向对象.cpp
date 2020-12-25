#include<iostream.h>
class vehicle // ����������
{
protected:
int wheels; // ������
float weight; // ����
public:
vehicle(int wheels,float weight);
int get_wheels();
float get_weight();
float wheel_load();
void show();
};
class car:public vehicle // ����С����
{
int passenger_load; // ������
public:
car(int wheels,float weight,int passengers=4);
int get_passengers();
void show();
};
class truck:public vehicle // ���忨����
{
int passenger_load; // ������
float payload; // ������
public:
truck(int wheels,float weight,int passengers=2,float max_load=24000.00);
int get_passengers();
float efficiency();
void show();
};
vehicle::vehicle(int wheels,float weight)
{
vehicle::wheels=wheels;
vehicle::weight=weight;
}
int vehicle::get_wheels()
{
return wheels;
}
float vehicle::get_weight()
{
return weight/wheels;
}
void vehicle::show()
{
cout << "����:" << wheels << "��" << endl;
cout << "����:" << weight << "����" << endl;
}
car::car(int wheels, float weight,
int passengers) :vehicle (wheels, weight)
{
passenger_load=passengers;
}
int car::get_passengers ()
{
return passenger_load;
}
void car::show()
{
cout <<" ����:С��" << endl;
vehicle::show();
cout << "����:" << passenger_load << "��" << endl;
cout << endl;
}
truck:: truck(int wheels, float weight,int passengers, float max_load):vehicle(wheels,weight)
{
passenger_load=passengers;
payload=max_load;
}
int truck::get_passengers()
{
return passenger_load;
}
float truck::efficiency()
{
return payload/(payload+weight);
}
void truck::show()
{
cout <<"����:����" << endl;
vehicle:: show ();
cout << "����:" << passenger_load << "��" << endl;
cout << "Ч��:" << efficiency() << endl;
cout << endl;
}
void main ()
{
car car1(4,2000,5);
truck tru1(10,8000,3,340000);
cout << "������" << endl;
car1. show ();
tru1. show ();
}