#include <18F452.h>
#fuses NOWDT, HS, NOPUT, NOLVP, NODEBUG
#use delay(clock=20000000)  // Kristalin 20 MHz olduğunu varsayıyorum, farklıysa değiştir

#INT_EXT // interrups ı dahil eder.
void ext_Led(void) // interrups fonksiyonu
{
 for(int i = 0; i < 5; i++)   // 5 defa yakıp söndürür.
 {
   output_low(PIN_D0);
   delay_ms(500);
   output_high(PIN_D0);
   delay_ms(500);
 }
}

void main()
{
  set_tris_d(0x00);
  enable_interrups(INT_EXT); // ext interrupsı aktif eder
  enable_interrups(GLOBAL); // interrupsları aktif eder
  ext_int_edge(H_TO_L); // buton basılıp high olup low oldugunda interrups gerçekleşir.
  output_low(PIN_D0);
  While(TRUE)
  {
    output_high(PIN_D0);
  }
  
}