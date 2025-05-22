#include <main.h>
int sayac=0;
#INT_CCP1
void  CCP1_isr(void) 
{
 sayac++;
 if(sayac==4)
 sayac=0;
 output_b(sayac);
 set_timer1(0);
}

void main()
{
set_tris_b(0x00);
   setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1);      //65,5 ms overflow

   setup_ccp1(CCP_COMPARE_INT);

   enable_interrupts(INT_CCP1);
   enable_interrupts(GLOBAL);
   output_b(0x00);
   CCP_1_HIGH=0x00;
   CCP_1_LOW=0x08;
   set_timer1(0);

   while(TRUE)
   {


      //TODO: User Code
   }

}