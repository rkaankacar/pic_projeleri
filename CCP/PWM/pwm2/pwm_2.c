#include <main.h>
int dutyscasle=62;
void main()
{  

   set_tris_a(0xff);
   setup_timer_2(T2_DIV_BY_16,124,1);      //2,0 ms overflow, 2,0 ms interrupt

   
   setup_ccp2(CCP_PWM);
   
   set_pwm2_duty(dutyscasle);

   while(TRUE)
   {
     if(input(pin_A0)==1)
     {  
       delay_ms(20);
       
       dutyscasle = dutyscasle+4;
       if(dutyscasle > 120)
       dutyscasle = 120;
       
       set_pwm2_duty(dutyscasle);
       while(input(pin_A0)==1);
       
     
     }
     
     if(input(pin_A1)==1)
     {
       delay_ms(20);
       
       if(dutyscasle >= 4)
       {
         dutyscasle = dutyscasle-4;
       }
       else
       {
         dutyscasle = 0;  
       }

       set_pwm2_duty(dutyscasle);
       
       while(input(pin_A1)==1);
      
     }
      
   }

}