#include <main.h>
int sayac,dizi[8] = {0b00000001,0b00000011,0b00000010,0b00000110,0b00000100,0b00001100,0b00001000,0b00001001};
void main()
{
   set_tris_c(0x00);
   set_tris_a(0xFF);
   
   while(TRUE)
   { 
     if(input(pin_A0)==1)
     {
         duz:
         output_c(dizi[sayac]);
         delay_ms(200);
         sayac++;
         if(sayac == 8)
         sayac=0;
         if(input(pin_A1)== 1)
         goto ters;
         goto duz;
     }
      if(input(pin_A1)==1)
     {
         ters:
         output_c(dizi[sayac]);
         delay_ms(200);
         sayac--;
         if(sayac == -1)
         sayac=7;
         if(input(pin_A0)== 1)
         goto duz;
         goto ters;
     }
     
   }
 }



// sonsuz döndürme
/*  for (sayac = 0; sayac<8; sayac++)
{
   output_c(dizi[sayac]);
   delay_ms(250);
}
-------------------------------------
   if(input(PIN_A0) == 1)
        {
         output_c(dizi[sayac]);
         delay_ms(100);
         sayac++;
         if(sayac ==8)
          sayac =0;
       
        }  
        
        if(input(PIN_A1) == 1)
        {
         output_c(dizi[sayac]);
         delay_ms(100);
         sayac--;
         if(sayac == -1)
             sayac = 7; 
  
        }
-----------------------------------------

*/