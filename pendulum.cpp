#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;

// Muhammed Ali Sarimese
const float Pi = 3.1415926535897931f;

float formul(float t, float aci, float T) //acisal yer degistirme
{
    //Basit Harmonik Hareket denklemi
    float res = aci * cos((2*Pi / T) * t); 
    return res;
}

void ekranabas(float x1, float y1,float l, float g, float angle, float T)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm, "");

  float ivme; 

  for(float t = 1.0; t < 100.0;) //dongu suresi
  {
     float yeni_aci = formul(t, angle, T);
     
     ivme = -(g/l) * sin(yeni_aci);

     //diger bitis koordinatlarini aliyoruz
     float base = l * cos(yeni_aci);
     float height = l * sin(yeni_aci);

     //bitis koordinatlari
     float y2 = y1 + base;
     float x2 = x1 + height;

     setlinestyle(DASHED_LINE,0,NORM_WIDTH); //cizgi
     setcolor(BLUE);
     line(x1-200, y1, x1+200, y1);

     setlinestyle(SOLID_LINE,0,THICK_WIDTH);//ip 
     setcolor(RED);
     line(x1, y1, x2, y2);

     setcolor(YELLOW); //daire
     circle(x2, y2, 10);
     floodfill(x2, y2, YELLOW);
	 setfillstyle(SOLID_FILL,YELLOW); //daire ici renk
     delay(100);
     t = t + 1.0;
  }
  delay(100);
}

int main()
{
   float x1 = 250, y1 = 100; //sarkacin baslama koordinatlari

   float l = 200; //SARKACIN UZUNLUGU
   float g = 7; //yerçekimi ivmesi

   float aci = Pi/2; //radyan acisi (ne kadar aciyla doncegini belirliyoruz)

   float T = (5 * Pi) * sqrt(l/g); //sallanma periyodu

   ekranabas(x1, y1, l, g, aci, T);
   
}
// Muhammed Ali Sarimese
