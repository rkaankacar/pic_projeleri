#include <main.h>
#define lcd_portd TRUE
#include <lcd.c>
#define TRIG pin_B0
#define ECHO pin_B4

float time,distance;
void main()
{  
   set_tris_b(0b00010000);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      //65,5 ms overflow
  
   lcd_init();
   printf(lcd_putc,"\fMESAFE\nUYGULAMASI");
   delay_ms(2000);
   
   while(TRUE)
   { 
     output_low(TRIG);
     delay_ms(20);
     output_high(TRIG);
     delay_ms(15);
     output_low(TRIG); //burst işareti oluştu.
     
     
     while(input(echo)!=1);
     set_timer1(0);
     while(input(echo)!=0);
     time = get_timer1();
     distance= time* 0.017; //normalde gidiş geliş 0.034 ama biz sadece geliş istiyoruz o yuzden 0.0017 kullanıyoruz
     
     lcd_init();
     printf(lcd_putc,"\fUzaklik:\n");
     printf(lcd_putc,"%.2fcm",distance);
     delay_ms(500);
     

      
   }

}