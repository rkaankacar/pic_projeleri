# PIC PWM Kontrolü

## Proje Açıklaması
Bu proje, PIC mikrodenetleyici üzerinde Timer2 ve CCP1 modülünü kullanarak PWM (Pulse Width Modulation) sinyali üretmektedir. PWM1 ve PWM2 çıkışlarının görev döngüleri belirlenmiştir.

## Donanım
- PIC mikrodenetleyici
- PWM çıkış pinleri (CCP1 ve CCP2)
- Timer2 ile zamanlama

## Özellikler
- Timer2, 2 ms periyodunda overflow ve kesme üretir
- CCP1 PWM modunda ayarlanır
- PWM1 duty cycle: 31 (belirlenen birimlerde)
- PWM2 duty cycle: 62 (belirlenen birimlerde)

## Kurulum
1. CCS C derleyici ile derleyin.
2. Mikrodenetleyiciye programı yükleyin.
3. PWM çıkış pinlerine uygun cihaz bağlayın (örneğin motor, LED).
4. Timer2 ve PWM otomatik çalışır.

## Kod Açıklaması
- `setup_timer_2(T2_DIV_BY_16,124,1)`: Timer2 16 bölücü ile çalışır, 124 sayısına kadar sayar, 2 ms overflow ve kesme üretir.
- `setup_ccp1(CCP_PWM)`: CCP1 PWM modu olarak ayarlanır.
- `set_pwm1_duty(31)`: PWM1 görev döngüsü % yaklaşık olarak ayarlanır.
- `set_pwm2_duty(62)`: PWM2 görev döngüsü % yaklaşık olarak ayarlanır.
- `while(TRUE)`: Sonsuz döngü, burada kullanıcı kodu eklenebilir.

## Notlar
- PWM duty cycle değerleri donanıma göre ayarlanabilir.
- Timer2 overflow süresi 2 ms olarak belirlenmiştir.
- PWM sinyalleri harici cihaz kontrolü için uygundur.

