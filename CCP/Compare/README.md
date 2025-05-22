# PIC CCP1 Kesme Sayacı

## Proje Açıklaması
Bu proje PIC mikrodenetleyici üzerinde CCP1 modülünün karşılaştırma kesmesini kullanarak sayaç artışı yapar. Sayaç 0'dan 3'e kadar sayar ve PORTB çıkışına yazar.

## Donanım
- PIC mikrodenetleyici
- PORTB çıkışı (LED bağlanabilir)
- Timer1 harici tetikleme

## Özellikler
- CCP1 karşılaştırma kesmesi ile sayaç artışı
- Sayaç 4'e ulaşınca sıfırlanır
- PORTB çıkışına sayaç değeri yazılır

## Kurulum
1. CCS C derleyicisi ile derleyin.
2. Mikrodenetleyiciye programı yükleyin.
3. PORTB pinlerine LED veya benzeri çıkış bağlayın.
4. Timer1 dış kaynaktan tetikleyin.

## Kod Açıklaması
- `sayac`: Sayaç değeri, ISR içinde artırılır.
- `CCP1_isr()`: CCP1 kesmesi olduğunda sayaç artırılır, 4'te sıfırlanır, PORTB'ye yazılır.
- `main()`: Donanım ayarlarını yapar ve sonsuz döngüde bekler.

## Dikkat Edilmesi Gerekenler
- Timer1 dış kaynaktan tetiklenmelidir.
- `CCP_1_HIGH` ve `CCP_1_LOW` karşılaştırma değeri olarak 0x0008 ayarlanmıştır.
- PORTB çıkış olarak ayarlanmıştır.

