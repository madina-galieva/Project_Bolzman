#include<iostream.h>

#define Rad  0.01745 // константа для перевода градусов в радианы
#define velo 6 // скорость молекулы


//*************************Класс «Стенка»************************
class Wall
 {
  protected:
	   int length;
	   int angle; //90 или 0 градусов
	   int x,y;
  public:
	   Wall(int l, int a) //конструктор
     { length = l; angle = a; }

     void show (int ix,int iy); // нарисовать стенку
  };


  //*************************Класс «Перегородка»**********************
class Barrier
 {
	protected:
	   int centre_x;  // координаты центра
  	 int centre_y;
	   int hole_radius; // радиус отверстия в перегородке

	public:
	   Barrier(int icx, int icy, int d)
     {hole_radius = d; centre_x = icx; centre_y = icy;}

     void hide (int ix,int iy); //скрыть перегородку
  	 void show (int ix,int iy); //нарисовать  перегородку
  	 int hole_scale (int dy);  // изменение радиуса отверстия в перегородке
   	 void move (int dx); // поменять положение перегородки
  	 int getcentre_x()  { return centre_x; }
  	 int getcentre_y()  { return centre_y; }
  	 int gethole_radius() { return hole_radius; }
  };


  //************************************Класс «Молекула»*********************************
class Ball
 {
  protected:
  	 int centreX; //координаты центра
  	 int centreY;
  	 int radius;//радиус молекулы
  	 double angl; //угол определяющий направление движения молекулы

  public:
  	 Ball() {;}
  	 void show();
  	 void hide();
  	 int move();
  	 int hit (Ball b2); //столкновение с другой молекулой
  	 int hit_on_wall (); //столкновение со стенкой
  	 void hit_on_barr (int x, int y, int d); // столкновение с перегородкой

     void set (int bool, int value) //функция инициализирующая поля класса (в зависимости от значения bool)
     {
       if(bool==1) centreX = value;
       if(bool==2) centreY = value;
       if(bool==3) radius = value;
       if(bool==4) angl = 1.0*value;
     }
  };
