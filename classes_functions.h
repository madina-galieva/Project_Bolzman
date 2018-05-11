#include "classes.h"

//*************************Класс «Стенка»************************
void Wall::show (int ix,int iy)
    {
       /* setcolor(15);
        if( angle == 0)  // в зависимости от значения угла рисовать горизонтальную или вертикальную стенку
                  bar(ix-5,iy-5,ix+length,iy);
        else bar(ix-15,iy-5,ix,iy+length);
        setcolor(color); */
    }


//*************************Класс «Перегородка»**********************
void Barrier :: hide (int ix,int iy)
    {
        setcolor(color);
        line(ix,iy,ix,centre_y-hole_radius);
        line(ix,centre_y+hole_radius,ix,460);
        setcolor(15);
    }

void Barrier :: show(int ix,int iy)
    {
        setcolor(15);
        line(ix,iy,ix,centre_y-hole_radius);
        line(ix,centre_y+hole_radius,ix,460);
        setcolor(color);
    }

int Barrier::hole_scale(int dy)
    {
        hole_radius=hole_radius+dy;
        setcolor(color);
        line(centre_x,centre_y-hole_radius,centre_x,centre_y+hole_radius);
        setcolor(15);
        show(centre_x,10);
    }

void Barrier::move(int dx)
    {
        hide(centre_x,10);
        centre_x = centre_x+dx;
        show(centre_x,10);
    }


//************************************Класс «Молекула»*********************************
void Ball::show()
    {
        //нарисовать круг
    }

void Ball::hide()
    {
        //стереть круг
    }

int Ball::move()
    {
        hide();
        centreX = centreX + velo*1.0*cos(angl*Rad);//перемещение по оси Х
        centreY = centreY + velo*1.0*sin(angl*Rad); //перемещение по оси Y
        if(hit_on_wall()==1)                        // если есть удар о стенку – отскочить (изменяется угол движения)
                     { centreX = centreX + velo*1.0*cos(angl*Rad);
                       centreY = centreY + velo*1.0*sin(angl*Rad);}
        show();
    }

int Ball::hit(Ball b2)
    {
        if((abs(centreX-b2.centreX))<2.5*radius)              // если расстояние между центрами молекул по обеим осям
        if  ((abs(centreY-b2.centreY))<2.5*radius)        // меньше диаметра – изменить угол движения
            {
                if ((b2.angl==180)||(b2.angl==0))b2.angl=-angl;
                if((angl==180)||(angl==0))angl = -b2.angl;
                b2.angl=(angl+b2.angl)+b2.angl;
                angl=b2.angl+angl+angl;
            }
    }

int Ball::hit_on_wall()
    {
        // столкновение с вертикальными стенками
        if ((25 >= centreX) || (centreX >= 600))
            { angl= 180.0-(angl); return 1; }

        // столкновение с горизонтальными стенками
        if ((15 >= centreY)||(centreY >= 450))
            { angl = 0.0-angl;return 1; }
        return 0;
    }

void Ball::hit_on_barr(int x,int y,int d)
    {
        if((centreY-radius<(y-d))||(centreY+radius>(y+d)))  //попадает ли молекула в отверстие
        if (abs(x-centreX)<=velo+radius) angl= 180.0-angl;  // если не попадает, но находится у перегородки – отскочить
    }
