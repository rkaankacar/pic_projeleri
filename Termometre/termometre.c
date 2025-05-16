#include <main.h>
#define use_portb_lcd TRUE
#include <lcd.c>

#INT_AD
void AD_isr(void) //ADC KESMESİ
{
   output_high(pin_C5);
   delay_ms(100);
   output_low(pin_C5);
   delay_ms(200);
}

float sicaklik;
unsigned long int bilgi;


void main()
{  
   set_tris_c(0x00);
   set_tris_b(0x00);
   set_tris_a(0xff);
   output_b(0x00);
   setup_adc_ports(ALL_ANALOG);
   setup_adc(ADC_CLOCK_DIV_32);

   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   lcd_init();
   
   while(TRUE)
   {
     set_adc_channel(5);
     delay_ms(20);
     bilgi = read_adc();
     sicaklik = (bilgi*(5.0/1024))*0.10041; // dijital sıcaklığı dereceye çevirme
     printf(lcd_putc,"\fDijital: %lu",bilgi);
     printf(lcd_putc,"\nSicaklik:%.0f%cC",sicaklik,223);
   }

}