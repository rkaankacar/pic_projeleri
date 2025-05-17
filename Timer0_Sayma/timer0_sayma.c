#include <main.h>
int sayac=0;
#INT_TIMER0
void TIMER0_isr()
{ 
  set_timer0(251);
  sayac++;
  if(sayac>15)
  sayac=0;
  
  output_b(sayac);
}
void main()
{  
  set_tris_a(0xff);
  set_tris_b(0x00);
  output_b(0x00);
  
  setup_timer_1(T1_DISABLED);
  setup_timer_2(T2_DISABLED,0,1);
  
  setup_timer_0(RTCC_EXT_H_TO_L|RTCC_DIV_2|RTCC_8_bit);
  set_timer0(251);
  
  enable_interrupts(INT_TIMER0);
  enable_interrupts(GLOBAL);
  
   while(TRUE)
   {
     
     
   }

}