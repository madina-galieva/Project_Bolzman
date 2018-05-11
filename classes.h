#include <iostream.h>
#include <cmath>
#include <QObject>

#define Rad  0.01745 // константа для перевода градусов в радианы
#define velo 6 // скорость молекулы


//*************************Класс «Стенка»************************
class Wall : public QObject
{
   Q_OBJECT
protected:
    int length;
    int angle; //90 или 0 градусов
    int x,y;
public:
    Wall (int l, int a) { length = l; angle = a; } //конструктор
public slots:
    void Print_Walls();
    void show (int ix,int iy); // нарисовать стенку
signals:

};

//*************************Класс «Перегородка»**********************
class Barrier : public QObject
{
    Q_OBJECT
protected:
    int centre_x;  // координаты центра
    int centre_y;
    int hole_radius; // радиус отверстия в перегородке
public:
    Barrier (int icx, int icy, int d)
       {centre_x = icx; centre_y = icy; hole_radius = d;}
public slots:
    void Print_Barrier(int icx, int icy, int d);
 // void hide (int ix,int iy); //скрыть перегородку
 // void show (int ix,int iy); //нарисовать  перегородку
    int hole_scale (int dy);  // изменение радиуса отверстия в перегородке
 // void move (int dx); // поменять положение перегородки
    int getcentre_x()  { return centre_x; }
    int getcentre_y()  { return centre_y; }
    int gethole_radius() { return hole_radius; }
signals:

};

//************************************Класс «Молекула»*********************************
class Ball : public QObject
{
    Q_OBJECT
protected:
    int centreX; //координаты центра
    int centreY;
    int radius;//радиус молекулы
    double angl; //угол определяющий направление движения молекулы
public:
    Ball() {;}
public slots:
    void Print_Atom(int centreX,int centreY, int radius);
    void Print_Point(int centreX, int centreY);
  //  void show();
  //  void hide();
  //  int move();
  // int hit (Ball b2); //столкновение с другой молекулой
  //  int hit_on_wall (); //столкновение со стенкой
  //  void hit_on_barr (int x, int y, int d); // столкновение с перегородкой
  /*  void set (int m, int value) //функция инициализирующая поля класса (в зависимости от значения m)
     {
     if(m==1) centreX = value;
     if(m==2) centreY = value;
     if(m==3) radius = value;
     if(m==4) angl = 1.0*value;
     }
signals:
*/
};
