
[![](https://iarduino.ru/img/logo.svg)](https://iarduino.ru) [![](https://iarduino.ru/img/logo.svg)](https://iarduino.ru)



# iarduino_4LED
Библиотека iarduino_4LED для работы с четырёхразрядным индикатором

| Модель | Ссылка на магазин|
|--|--|
| Красная ![enter image description here](https://wiki.iarduino.ru/img/resources/702/702.svg) | https://iarduino.ru/shop/Displei/chetyrehrazryadnyy-indikator-led-trema-modul.html|
| Зеленый![enter image description here](https://wiki.iarduino.ru/img/resources/883/883.svg) | https://iarduino.ru/shop/Displei/chetyrehrazryadnyy-indikator-led-zelenyy-trema-modul.html |
| Синий ![enter image description here](https://wiki.iarduino.ru/img/resources/884/884.svg) | https://iarduino.ru/shop/Displei/chetyrehrazryadnyy-indikator-led-siniy-trema-modul.html |


## Описание библиотеки:
Библиотека позволяет регулировать яркость свечения LED индикатора, выводить на него числа (целые, дробные, положительные, отрицательные), символы ("abcdefghijlnopstu .,:;*-_"), массивы чисел, время и температуру.
**[  Подробное описание, подключение и примеры работы ](https://wiki.iarduino.ru/page/chetyrehrazryadnyy-indikator-trema-modul/)**

## Назначение функций и переменных:
Подробное описание работы с библиотекой, находится в разделе [Wiki Четырёхразрядный индикатор](https://wiki.iarduino.ru/page/chetyrehrazryadnyy-indikator-trema-modul/ "Wiki Четырёхразрядный индикатор").

**Подключаем библиотеку.**

    #include <iarduino_4LED.h> // Подключаем библиотеку.
    
**Создаём объект.** 

    iarduino_4LED ОБЪЕКТ ( ВЫВОД_CLK , ВЫВОД_DIO ); // Создаём объект.

**Инициализация работы с LED индикатором.**

    Функция begin(); // Инициализация работы с LED индикатором.
    
**Очистка индикатора (выключение всех сегментов).**

    Функция clear(); // Очистка индикатора (выключение всех сегментов).
    
**Установка яркости свечения индикатора, от 0 до 7.**

    Функция light( ЧИСЛО ); // Установка яркости свечения индикатора, от 0 до 7.
    
**Управление точками на индикаторе.**

    Функция point( ПОЗИЦИЯ , СОСТОЯНИЕ ); // Управление точками на индикаторе.
    
**Вывод значения на индикатор.**

    Функция print( ЗНАЧЕНИЕ [ , ПАРАМЕТРЫ_ВЫВОДА_ЧИСЛА ] ); // Вывод значения на индикатор.
    
**Устанавливает светодиоды (сегменты) индикатора по битам.**

    Функция setLED( [[[[[ БАЙТ_№1 ] , БАЙТ_№2 ] , БАЙТ_№3 ] , БАЙТ_№4 ] , ФЛАГ ] ); // Устанавливает светодиоды (сегменты) индикатора по битам.
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI5NjkwMzUwOCwtMjM4OTgxNzJdfQ==
-->