# Ultrasonik Mesafe Ölçüm Uygulaması

## 📌 Projenin Amacı
Bu proje, HC-SR04 ultrasonik sensörü kullanarak cismin uzaklığını ölçer ve 16x2 LCD ekranda santimetre cinsinden gösterir. Ölçüm işlemi PIC mikrodenetleyici ile gerçekleştirilmiştir.

---

## 🧰 Kullanılan Donanımlar
- PIC mikrodenetleyici (örn: PIC16F877A)
- HC-SR04 Ultrasonik Mesafe Sensörü
- 16x2 LCD ekran
- CCS C derleyicisi (lcd.c kütüphanesi dahil)
- Proteus 

---

## ⚙️ Bağlantılar
| Eleman         | Bağlı Olduğu PIC Pin |
|----------------|----------------------|
| TRIG           | B0 (pin_B0)          |
| ECHO           | B4 (pin_B4)          |
| LCD            | Port D               |

---

## 🧠 Kodun İşleyişi
- `set_tris_b(0b00010000);` → B4 pini giriş, diğer B port pinleri çıkış yapılır.
- `setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);` → Timer1 başlatılır.
- LCD başlatılır ve “MESAFE UYGULAMASI” yazısı gösterilir.
- Sonsuz döngü içinde:
  - TRIG pinine 15ms boyunca HIGH sinyal gönderilir.
  - ECHO pini HIGH olduğunda süre ölçülmeye başlanır.
  - ECHO pini LOW olduğunda süre alınır.
  - Mesafe şu formülle hesaplanır:
    ```
    distance = time * 0.017;
    ```
    Bu çarpan, ses hızının sadece gidiş süresi için ayarlanmış halidir (340 m/s → 0.034 cm/µs, yarısı 0.017).
  - Ölçülen mesafe LCD'ye yazdırılır.

---
