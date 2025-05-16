#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>
void main()
{  
   set_tris_a(0xFF);
   set_tris_b(0x00);
   lcd_init();
   lcd_gotoxy(1,1);
   int sayac = 0;
   printf(lcd_putc,"\f %d",sayac);
   
   output_c(0b00000011);
   while(TRUE)
   {  
      
     if(input_state(PIN_A0)==0)
     { 
       delay_ms(50);
       sayac++;
       printf(lcd_putc,"\f %d",sayac);
       output_c(0b00001001);
       delay_ms(100);
       output_c(0b00000011);
       delay_ms(100);
        if(sayac==21)
       {
        printf(lcd_putc,"\f Otopark dolu");
        sayac = 20;
       }
    
       
       while(input_state(PIN_A0)==0);
     } 
      
     if(input_state(PIN_A1)==0)
     { 
       delay_ms(50);
       sayac--;
       printf(lcd_putc,"\f %d",sayac);
       output_c(0b00001001);
       delay_ms(100);
       output_c(0b00000011);
       delay_ms(100);
       if(sayac==-1)
       {
        printf(lcd_putc,"\f Arac Kalmadi");
        sayac = 0;
       }
     
       
       while(input_state(PIN_A1)==0);
     }

      
   }

}