#include <main.h>
#include <lcd.c>
#define use_portd_lcd TRUE
void main()
{
lcd_init();
   while(TRUE)
   {
    if(input_state(pin_A0)==1)
    {
     delay_ms(10);
     while(input_State(pin_A0)==1);
     delay_ms(10);
     output_b(0x08); //0000|0000
     lcd_gotoxy(1,1);
     printf(lcd_putc,"\f Su Aliniyor");
     delay_ms(2500);
     for(int i=0;i<3;i++)
     {
     output_b(0x05);
     printf(lcd_putc,"\f");
     delay_ms(5000);
     output_b(0x06);
     delay_ms(5000);
     }
     //Su boşaltıp - Su alma
     output_b(0x10);
     printf(lcd_putc,"\f Su Bosaltiliyor");
     delay_ms(2500);
     output_b(0x08);
     printf(lcd_putc,"\f Su Aliniyor");
     delay_ms(2500);
     // Durulama
     output_b(0x05);
     printf(lcd_putc,"\f Durulaniyor");
     delay_ms(5000);
     output_b(0x06);
     delay_ms(5000);
     printf(lcd_putc,"\f Durulama bitti\nSu Bosaltiliyor");
     output_b(0x10);
     delay_ms(2500);
     output_b(0x05);
     printf(lcd_putc,"\f SIKTIRMA islemi");
     delay_ms(3000);
     printf(lcd_putc,"\f Bitti");
     while(TRUE)
     {
      output_b(0x20);
      delay_ms(1000);
      output_b(0x00);
      delay_ms(1000);
     }
    }

      //TODO: User Code
   }

}