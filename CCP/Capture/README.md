# CCP ile Binary LED Sayaç Uygulaması

## 📌 Projenin Amacı  
Bu proje, PIC mikrodenetleyici üzerinde **CCP (Capture/Compare/PWM)** modülleri kullanılarak bir sayaç oluşturur. Sayaç değeri, **PORTB üzerinden LED'lerle ikili (binary) olarak** görselleştirilir.

---

## 🧰 Kullanılan Donanımlar
- PIC mikrodenetleyici (örn: PIC16F877)
- 8 adet LED (PORTB’ye bağlanır)
- 2 adet buton veya harici sinyal kaynağı (CCP1 ve CCP2 için)
- CCS C derleyicisi
- Proteus

---

## ⚙️ Bağlantılar
| Eleman      | PIC Pin         | Açıklama                       |
|-------------|------------------|-------------------------------|
| CCP1 Girişi | RC2 (pin CCP1)   | Sayacı artırır                |
| CCP2 Girişi | RC1 (pin CCP2)   | Sayacı azaltır                |
| LED'ler     | PORTB (RB0–RB7)  | Sayaç değerini binary gösterir|

---

## 🧠 Kodun İşleyişi
- Başlangıçta `sayac = 0` olarak ayarlanır.
- CCP1 kesmesi: Her tetiklendiğinde `sayac++` olur.
  - Eğer sayaç 15’e ulaştıysa sabitlenir.
- CCP2 kesmesi: Her tetiklendiğinde `sayac--` olur.
  - Eğer sayaç 0’a düşerse sabitlenir.
- Her değişiklikte `output_b(sayac);` komutu ile değer PORTB’ye aktarılır.
  - Bu sayede LED’ler **ikili sayı düzenine göre yanar**.

---

## ⚙️ Yapılandırmalar
- `setup_ccp1(CCP_CAPTURE_DIV_4);` → CCP1, her 4. yükselen kenarda kesme oluşturur.
- `setup_ccp2(CCP_CAPTURE_RE);` → CCP2, her yükselen kenarda kesme oluşturur.
- `setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);` → Zamanlama için Timer1 yapılandırılır.

---
