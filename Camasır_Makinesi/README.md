# Çamaşır Makinesi Simülasyonu - PIC Mikrodenetleyici Projesi

Bu proje, PIC mikrodenetleyici kullanarak basit bir **çamaşır makinesi çalışma simülasyonu** yapmaktadır.  
LCD ekran üzerinden işlemler takip edilir ve çıkış portları vasıtasıyla pompa, vana ve motor benzeri bileşenlerin durumları kontrol edilir.

---

## Proje Özeti

- **Giriş:** `PIN_A0` tuşu, çamaşır makinesini başlatmak için kullanılır.
- **Çıkış:** PORTB pinleri, su alma, boşaltma, durulama ve sıkma aşamalarını temsil eden röle veya motor sürücüleri için sinyal gönderir.
- **LCD:** İşlem aşamaları kullanıcıya metin olarak gösterilir.

---

## Çalışma Aşamaları

1. **Su Alma**  
   - `PIN_B3` set edilir (`0x08`) ve LCD'de "Su Alınıyor" mesajı gösterilir.
2. **Yıkama Döngüsü (3 defa)**  
   - Su alma ve boşaltma simüle edilir:  
     - `0x05` ve `0x06` değerleriyle sırayla çıkış sinyali verilir.  
     - LCD ekranda boş ekran gösterilerek süre kontrol edilir.
3. **Su Boşaltma**  
   - `0x10` çıkışı aktif edilir, LCD’de "Su Boşaltılıyor" mesajı gösterilir.
4. **Durulama**  
   - `0x05` ve `0x06` çıkışları sırayla aktif edilir, LCD’de durulama mesajları gösterilir.
5. **Sıkma**  
   - `0x20` çıkışı kullanılarak sıkma simüle edilir (bir süre yanıp sönme efekti).
6. **Bitti**  
   - LCD’de "Bitti" mesajı gösterilir, çıkışlar kapatılır.

---