## [EN]

## Project Overview

`so_long` is a project given by Ecole 42 and aims to create a simple 2D game. This project will help you understand and implement the fundamentals of game programming, graphical interfaces, and event handling. The project involves creating a game where the player navigates a maze to collect specific objectives.

## Requirements

- **Language**: C
- **Libraries**: Minilibx (42's graphics library)
- **Standard**: POSIX compliant
- **Dependencies**: Minilibx library must be used; other external libraries are prohibited.

## Features

The key features to be implemented in this project include:

- **Game Area**:
  - Creating the maze structure.
  - The game area must include walls, paths, and objectives.

- **Character Management**:
  - Moving the player’s character using the keyboard (up, down, left, right).
  - Collecting objectives with the character and completing the game.

- **Graphics and Interface**:
  - Rendering graphics and interfaces using Minilibx.
  - Providing appropriate graphics for the game area, character, and objectives.

- **Game State and Outcome**:
  - Managing the game's start and end states.
  - Displaying a message when the game is successfully completed.

## Installation and Usage

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/huseyinnatess/so_long.git

1. Navigate to the project directory:

   ```bash 
   cd so_long

2. Ensure Minilibx library is installed. You can find more information on how to install Minilibx [here](https://github.com/42Paris/minilibx).

3. Build the project:

   ```bash
   make

### Usage

1. Launch the game:

   ```bash
   ./so_long map.ber

2. Here, `map.ber` is a map file defining the game area. This file specifies the structure of the game field.

3. While playing, you can move your character using the arrow keys and collect objectives on the map.

4. The game will end when all objectives are collected or another termination condition is met.

## [TR]

## Proje Hakkında

`so_long`, Ecole 42 tarafından verilen bir projedir ve basit bir 2D oyunu oluşturmayı amaçlar. Bu proje, oyun programlama temellerini, grafik arayüzleri ve olay yönetimini anlamanızı ve uygulamanızı sağlar. Proje, oyuncunun karakteri bir labirent içinde hareket ettirerek belirli hedefleri toplamasını içeren bir oyunun gerçekleştirilmesini gerektirir.

## Gereksinimler

- **Dil**: C
- **Kütüphaneler**: Minilibx (42’nin grafik kütüphanesi)
- **Standart**: POSIX uyumlu
- **Bağımlılıklar**: Minilibx kütüphanesi kullanılmalıdır; diğer harici kütüphaneler yasaktır.

## Özellikler

Bu projede implemente edilmesi gereken temel özellikler şunlardır:

- **Oyun Alanı**:
  - Labirent yapısının oluşturulması.
  - Oyun alanında duvarlar, yollar ve hedefler yer almalıdır.

- **Karakter Yönetimi**:
  - Oyuncunun karakterini klavye ile hareket ettirme (yukarı, aşağı, sağ, sol).
  - Karakterin hedefleri toplaması ve oyunun tamamlanması.

- **Grafik ve Arayüz**:
  - Minilibx kullanarak grafiklerin ve arayüzlerin render edilmesi.
  - Oyun alanı, karakter ve hedefler için uygun grafiklerin sağlanması.

- **Oyun Durumu ve Sonuç**:
  - Oyunun başlangıç ve bitiş durumlarının yönetilmesi.
  - Oyun başarıyla tamamlandığında bir mesaj görüntülenmesi.

## Kurulum ve Kullanım

### Kurulum

1. Depoyu klonlayın:

   ```bash
   git clone https://github.com/huseyinnatess/so_long.git

2. Proje dizinine gidin:

    ```bash
   cd so_long

3. Minilibx kütüphanesinin kurulu olduğundan emin olun. Minilibx’in nasıl kurulacağı hakkında daha fazla bilgi [burada](https://github.com/42Paris/minilibx) bulunabilir.

4. Projeyi derleyin:

    ```bash
   make

### Kullanım

1. Oyunu başlatın:

    ```bash
   ./so_long map.ber

2. Burada, `map.ber` oyun alanını tanımlayan bir harita dosyasıdır. Bu dosya, oyun alanının yapısını belirler.

3. Oynarken, karakterinizi ok tuşlarıyla hareket ettirebilir ve harita üzerindeki hedefleri toplayabilirsiniz.

4. Oyun, tüm hedefler toplandığında veya başka bir sonlanma koşulu gerçekleştiğinde sona erecektir.

