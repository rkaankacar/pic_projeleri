# PIC Timer0 Kesmesi ile Dış Kaynaklı Sayıcı Projesi

Bu proje, PIC mikrodenetleyicide Timer0’yı dış kaynaktan gelen sinyallerle sayıcı olarak kullanarak PORTB’ye sayım değerini yansıtır. Timer0, harici sinyalin düşen kenarlarıyla tetiklenir ve sayım işlemi kesme ile gerçekleştirilir.

---

## Donanım Bağlantıları

- **PORTA:** Tüm pinler giriş olarak ayarlanmıştır. (Özellikle Timer0 için kullanılan harici sinyal pinidir)
- **PORTB:** Tüm pinler çıkış olarak ayarlanmıştır ve sayacın değeri burada LED veya başka bir çıktı ile gösterilir.
- Harici bir sinyal kaynağı Timer0 giriş pinine bağlanmalıdır (düşen kenar tetiklemeli).

---