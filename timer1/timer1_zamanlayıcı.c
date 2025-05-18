#include <main.h>
int sayac= 0;
#INT_TIMER1
void  TIMER1_isr(void) 
{  
  set_timer1(35);
  sayac++;
  if(sayac==61)
  {
    output_b(~input_b());
    sayac=0;
  }

}

void main()
{  set_tris_b(0x00);
   output_b(0x00);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      //65,5 ms overflow

   set_timer1(35);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {


      //TODO: User Code
   }

}