#include <main.h>
int sayac =0;
#INT_CCP1
void  CCP1_isr(void) 
{
   sayac++;
   if(sayac==16)
   sayac=15;
   output_b(sayac);
}

#INT_CCP2
void  CCP2_isr(void) 
{
  sayac--;
  if(sayac==-1)
  sayac=0;
  output_b(sayac);
}

void main()
{  
   set_tris_b(0x00);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_1);      //65,5 ms overflow

   setup_ccp1(CCP_CAPTURE_DIV_4);
   setup_ccp2(CCP_CAPTURE_RE);

   enable_interrupts(INT_CCP1);
   enable_interrupts(INT_CCP2);
   enable_interrupts(GLOBAL);
   output_b(0x00);
   while(TRUE)
   {


      //TODO: User Code
   }

}