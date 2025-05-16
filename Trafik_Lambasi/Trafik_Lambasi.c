#include <main.h>
int8 x;
void main()
{
    set_tris_b(0xC0);  // RB0-RB5 çıkış, RB6-RB7 giriş

    while(TRUE)
    { 
        // B0 ve B5 aynı anda yanacak (1 << 0) | (1 << 5)
        x = (1 << 0) | (1 << 5); 
        output_b(x);
        delay_ms(30000);  // 30 saniye bekle
        output_b(0);      // Tüm lambaları söndür

        // B1 ve B4 aynı anda 3 kez yanıp sönecek
        x = (1 << 1) | (1 << 4);
        for(int i = 0; i < 3; i++) {
            output_b(x);
            delay_ms(5000);  // 5 saniye bekle
            output_b(0);
            delay_ms(5000);  // 5 saniye bekle
        }

        // B2 ve B3 aynı anda yanacak
        x = (1 << 2) | (1 << 3);
        output_b(x);
        delay_ms(30000);  // 30 saniye bekle
        output_b(0);
    }
}
