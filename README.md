# So_Long Projesi
Bu, 42 Okulunun çekirdek müfredatının bir parçası olan so_long projesinin çözümüdür. Bu projenin amacı, farklı boyutlara ve içeriklere sahip bir haritanızın olduğu kendi 2D oyununuzu oluşturmaktır.

## Gereksinimler
- Sadece macOS Catalina (Sürüm 10.15.7) üzerinde test edilmiştir.
- Oyunu çalıştırmak için OpenGL ve AppKit gereklidir.
- Linux’ta çalıştırmak isterseniz, bu rehber size yardımcı olabilir.

## Harita Yapısı
* Geçerli bir harita aşağıdaki gibi yapılandırılmalıdır:
- En az 1 oyuncu (P)
- En az 1 çıkış (E)
- En az 1 toplanabilir nesne ©
- Harita dikdörtgen şeklinde olmalıdır.
- Haritanın dış sınırı duvarlarla (1) çevrili olmalıdır.
- Boş alanlar 0 ile doldurulmalıdır.
- Harita dosyasının uzantısı .ber olmalıdır.
- Harita dosyasında sadece şu karakterler bulunmalıdır: P, E, C, 1, 0.

Örnek bir harita:

```
1111111111111
10010000000C1
1000011111001
1P0011E000011
1111111111111
```

## Nasıl Çalıştırılır?
- Terminalde proje dizinine gidin. -
- make all komutuyla projeyi derleyin.
- ./so_long maps/map1.ber komutuyla oyunu çalıştırın.

## Oyun İçi Kontroller
- Oyuncu sadece WASD tuşlarıyla hareket edebilir.
- Oyuncu duvarlara çarpamaz.
- Oyuncu tüm toplanabilir nesneleri topladığında çıkışa ulaşabilir.
