# Step Motor Kontrol Projesi

Bu proje, PIC mikrodenetleyici kullanarak 8 adımlı bir step motorun sürülmesini sağlar. Butonlar yardımıyla step motorun dönüş yönü kontrol edilir ve motor adım adım döner.

---

## Donanım Bağlantıları

- **PORTC (RC0-RC7):** Step motor sargılarını kontrol eden çıkışlar (8 bitlik dizideki her bit bir sargıyı temsil eder).
- **PORTA PIN_A0 ve PIN_A1:** İki adet giriş butonu, step motorun dönüş yönünü belirlemek için.

---
## Yorum Satırındaki Alternatif Kodlar

Kodda ayrıca yorum satırı içinde şu alternatif yöntemler yer almaktadır:
Sonsuz döndürme için basit ileri adım döngüsü.