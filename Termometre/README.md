# PIC ADC ve LCD Gösterimi ile Termometre Projesi

Bu proje, PIC mikrodenetleyicide Analog-Dijital Dönüştürücü (ADC) kullanarak sıcaklık sensöründen okunan analog değeri dijitale çevirir, bunu sıcaklık değerine dönüştürür ve LCD ekranda gösterir. Ayrıca ADC kesme (interrupt) kullanılarak sinyal işleme yapılmaktadır.

---

## Donanım Bağlantıları

- **PORTA:** Analog giriş olarak kullanılır (özellikle AN5 kanalı sıcaklık sensörü için).
- **PORTB:** Dijital çıkış ve LCD veri yolları.
- **PORTC:** Dijital çıkış, örneğin C5 pini ADC kesme sırasında LED kontrolü için kullanılır.
- **LCD:** PORTB ve tanımlı portlarla bağlıdır.

---