//
// Created by madina on 11.05.18.
//


#include "classes.h"

//*************************Класс «Стенка»************************
void Wall::show (int ix,int iy) {
    QColor mycolor;
    mycolor.setRgb(250, 250, 250);   //пробуем добавить цвет

}

void Wall::paintEvent(QPaintEvent *event)                           // функция для рисования, обязательно должен быть
                                                                    // paintEvent. Попробуем к объекту привязать функцию show
                                                                    // возможно, нужно что-либо поменять как-либо функцию, пока работаю над этим


    {
        int k, m;                                                   // следующие 4 строчки и эта - для направления линии
        k = 0;
        m = 0;
        if ( angle == 90 ) { k = 1; }
        if ( angle == 0 ) { m = 1; }
        QColor mycolor;
        mycolor.setRgb(250, 250, 250);                              //пробуем добавить цвет
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);              // сглаживание
        // painter.translate(width() / 2, height() / 2);            // переносим точку отсчета в центр
        painter.scale(side / 500.0, side / 500.0);                  // теперь  используем шкалу в 500 условных единиц в ширину и высоту
        painter.drawLine(ix, iy, ix+length*k, iy+length*m);         // откладываем длину линии либо вверх, либо вправо ( смотри if выше )
                                                                    // думаю, как ix и iy привязать сюда правильно и куда

        /*
        Wall* board = new Wall;                                     // пытаюсь использовать show, как в примере
        board -> show();                                            //
        */

    }

    /* setcolor(15);
     if( angle == 0)  // в зависимости от значения угла рисовать горизонтальную или вертикальную стенку
               bar(ix-5,iy-5,ix+length,iy);
     else bar(ix-15,iy-5,ix,iy+length);
     setcolor(color); */
}


//*************************Класс «Перегородка»**********************
void Barrier :: paintEvent(QPaintEvent *event)
{
    QColor mycolor;
    mycolor.setRgb(250, 250, 250);                              //пробуем добавить цвет
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);              // сглаживание
                                                                // рисуем стенки с дырой (два отрезка)
    painter.drawLine(ix,iy,ix,centre_y-hole_radius);
    painter.drawLine(ix, centre_y+hole_radius, ix, centre_y+hole_radius+(centre_y-hole_radius-iy) );

    /*
        Barrier* barr = new Barrier;                                     // пытаюсь использовать show, как в примере
        barr -> show();
        barr -> hide();                                                  //hide работает по тому же принципу
        */
}
    /*
void Barrier :: show(int ix, int iy)
{
    QColor mycolor;
    mycolor.setRgb(250, 250, 250);                              //пробуем добавить цвет

    line(ix,iy,ix,centre_y-hole_radius);
    line(ix,centre_y+hole_radius,ix,460);
    setcolor(color);
}
    */
int Barrier :: hole_scale(int dy)
{
    barr -> hide();                                             // поскольку у на есть волшебные функции show и hide,
    hole_radius=hole_radius+dy;                                 // то достаточно поменять один параметр, как и в
    barr -> show();                                             // move на следующей
}

void Barrier :: move(int dx)
{
    barr -> hide();
    centre_x = centre_x+dx;
    barr -> show();
}


//************************************Класс «Молекула»*********************************
void Ball::paintEvent(QPaintEvent *event) {
    QColor mycolor;
    mycolor.setRgb(250, 250, 250);                              //пробуем добавить цвет
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);              // сглаживание


    /*
       Ball* atom = new Ball;                                     // пытаюсь использовать show, как в примере
       atom -> show();                                            //
       */

}
    /*
void Ball::hide()
{
    //стереть круг
}
    */

int Ball::move()
{
    atom -> hide();
    centreX = centreX + velo*1.0*cos(angl*Rad);//перемещение по оси Х
    centreY = centreY + velo*1.0*sin(angl*Rad); //перемещение по оси Y
    if(hit_on_wall()==1)                        // если есть удар о стенку – отскочить (изменяется угол движения)
    { centreX = centreX + velo*1.0*cos(angl*Rad);
        centreY = centreY + velo*1.0*sin(angl*Rad);}
    atom -> show();
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
