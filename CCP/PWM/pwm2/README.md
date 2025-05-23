# PWM Motor Hız Kontrolü (PIC Mikrodenetleyici - CCS C)

Bu proje, **CCS C** dili kullanılarak **PIC mikrodenetleyici** üzerinde PWM (Pulse Width Modulation) tekniği ile bir motorun hızını kontrol etmeye yönelik geliştirilmiştir. Kullanıcı, A0 ve A1 pinlerine bağlı butonlar aracılığıyla motor hızını artırıp azaltabilir.

## Özellikler

- PWM sinyaliyle motor hız kontrolü
- A0 pininden hız artırımı
- A1 pininden hız azaltımı
- Duty cycle sınırlandırması (0 - 120)
- Debounce (zıplama önleme) gecikmesi

## Donanım Gereksinimleri

- PIC mikrodenetleyici (CCP2 modülüne sahip)
- 2 adet buton (hız artırma / azaltma için)
- PWM destekli motor sürücü
- DC motor
- Gerekli bağlantılar ve dirençler

## Pin Konfigürasyonu

| Pin   | Fonksiyon               |
|-------|-------------------------|
| A0    | Hız artırma butonu      |
| A1    | Hız azaltma butonu      |
| CCP2  | PWM çıkışı (motor kontrol) |
