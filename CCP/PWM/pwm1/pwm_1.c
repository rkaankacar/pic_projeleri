#include <main.h>

void main()
{
   setup_timer_2(T2_DIV_BY_16,124,1);      //2,0 ms overflow, 2,0 ms interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty(31);
   set_pwm2_duty(62);
   
   while(TRUE)
   {


      //TODO: User Code
   }

}