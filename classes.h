#include <iostream.h>
#include <cmath>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QRect>

#define Rad  0.01745 // константа для перевода градусов в радианы
#define velo 6 // скорость молекулы



//*************************Класс «Ящик»************************
class Box : public QWidget // QObject ?
{
   Q_OBJECT
protected:
   int lux;
   int luy;
   int length;
   int height;
public: 
   Box (int x, int y, int l, int h) { lux = x; luy = y; length = l; height = h; } // конструктор по аналогии с таким же в Стенке
public slots:                                                                     // пока не знаю, что такое public slots, уточню 
   void paintEvent(QPaintEvent *box);                                             // функция, рисующая ящик
 signals:                                                                         // тоже пока не разобралась, увы
   
};                                                                                

//*************************Класс «Стенка»************************                 // не уверена, что нам нужен класс Стенка,
class Wall : public QWidget // QObject ?                                          // если у нас есть класс Ящик
{
   Q_OBJECT
protected:
    int length;
    int angle; //90 или 0 градусов
    int x,y;
public:
    Wall (int l, int a) { length = l; angle = a; } //конструктор
public slots:
  //  void Print_Walls();
    void show (int ix,int iy); // нарисовать стенку
signals:

};

//*************************Класс «Перегородка»**********************
class Barrier : public QWidget // QObject
{
    Q_OBJECT
protected:
//    int centre_x;  // координаты центра
//    int centre_y;
      int barr_x;    // т.к. перегородка полностью перекрывает сосуд и перпендикулярна длинным стенкам, 
                     // оставим только иксовую координату (игрековые координаты краев как у длинных стенок сосуда)
    int hole_radius; // радиус отверстия в перегородке
public:
    Barrier (int icx, int icy, int d)
       {centre_x = icx; centre_y = icy; hole_radius = d;}
public slots:
 //   void Print_Barrier(int icx, int icy, int d);
    void hide (int ix,int iy);                     // скрыть перегородку
    void show (int ix,int iy);                     // нарисовать  перегородку
    int hole_scale (int dy);                       // изменение радиуса отверстия в перегородке
    void move (int dx);                            // поменять положение перегородки
    int getcentre_x()  { return centre_x; }        // не знаю, нужны ли нам эти функции
    int getcentre_y()  { return centre_y; }        // не знаю, нужны ли нам эти функции
    int gethole_radius() { return hole_radius; }   // не знаю, нужны ли нам эти функции
signals:

};

//************************************Класс «Молекула»*********************************
class Ball : public QWidget // QObject
{
    Q_OBJECT
protected:
    int centreX;                                   //координаты центра
    int centreY;
    int radius;                                    //радиус молекулы
    double angl;                                   //угол, определяющий направление движения молекулы
public:
    Ball() {;}                                     //конструктор?
public slots:
 // void Print_Atom(int centreX,int centreY, int radius);
 //  void Print_Point(int centreX, int centreY);
    void show();                                   // рисование молекулы
    void hide();                                   // удаление молекулы
    int move();                                    // движение молекулы 
    int hit (Ball b2);                             //столкновение с другой молекулой
//  int hit_on_wall ();                            //столкновение со стенкой
//  void hit_on_barr (int x, int y, int d);        // столкновение с перегородкой
/*  void set (int m, int value)                    //функция инициализирующая поля класса (в зависимости от значения m)
     {
     if(m==1) centreX = value;
     if(m==2) centreY = value;
     if(m==3) radius = value;
     if(m==4) angl = 1.0*value;
     }
signals:
*/
};
