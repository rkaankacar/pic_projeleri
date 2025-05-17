#include <main.h>

void main()
{ 
  int sayac = 0;
  int dizi[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
  output_c(0x3F);
  
 while(true)
  {
     if(input_state(pin_A0)==1)
    {
      delay_ms(10);
      sayac++;
      if(sayac==10)
      sayac=0;
      output_c(dizi[sayac]);
      while(input_state(pin_A0)==1);
    }
 
     if (input_state(PIN_A1) == 1) 
    {   
     delay_ms(10);
     sayac--;
     if (sayac == -1) 
     sayac = 9;
     output_c(dizi[sayac]);
     while (input_state(PIN_A1) == 1); 
    }

    
  }
}

