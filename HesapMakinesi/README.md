# PIC Mikrodenetleyici ve LCD Destekli Hesap Makinesi Projesi (Keypad Girişli)

Bu proje, PIC mikrodenetleyici ve fiziksel keypad kullanarak temel matematiksel işlemleri yapan bir hesap makinesi uygulamasıdır.  
Kullanıcı, keypad üzerindeki tuşlarla sayıları ve operatörleri girer, ifade LCD ekranda görüntülenir ve hesaplama sonucu yine LCD’de gösterilir.

---

## Donanım

- **Keypad:** Sayı ve operatör girişleri için kullanılır. PORTD'den okunur.
- **LCD Ekran:** İşlemler ve sonuçlar görüntülenir. PORTB çıkış olarak ayarlanmıştır.
- **Mikrodenetleyici:** PIC ailesinden bir mikrodenetleyici kullanılır.

---

## Yazılım Detayları

- Keypad'den gelen tuş kodları PORTD üzerinden okunur ve ilgili karaktere dönüştürülür.
- Girilen infix ifade bir diziye kaydedilir ve LCD ekranında gösterilir.
- `=` tuşuna basıldığında, infix ifade postfix formata dönüştürülür ve hesaplanır.
- Hesap sonucu LCD üzerinde görüntülenir.
- `Clear` tuşu ekranı ve girişleri sıfırlar.

---

## Keypad Tuş Kodları ve Karakter Karşılıkları

| Keypad Okuma Değeri (PORTD) | Karakter  |
|-----------------------------|-----------|
| 0b01111000                  | '0'       |
| 0b00101000                  | '1'       |
| 0b01101000                  | '2'       |
| 0b10101000                  | '3'       |
| 0b00011000                  | '4'       |
| 0b01011000                  | '5'       |
| 0b10011000                  | '6'       |
| 0b00001000                  | '7'       |
| 0b01001000                  | '8'       |
| 0b10001000                  | '9'       |
| 0b11001000                  | '/'       |
| 0b11011000                  | '*'       |
| 0b11101000                  | '-'       |
| 0b11111000                  | '+'       |
| 0b10111000                  | '=' (Hesapla) |
| 0b00111000                  | Clear (Temizle) |

---