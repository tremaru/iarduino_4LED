#include <iarduino_4LED.h>                             //  подключаем библиотеку для работы с четырёхразрядным LED индикатором
iarduino_4LED dispLED(4,5);                            //  объявляем объект для работы с функциями библиотеки iarduino_4LED, с указанием выводов дисплея ( CLK , DIO ). Можно указывать любые выводы Arduino
int a[4]={0,3,6,9};                                    //  объявляем массив из 4 целых положительных чисел
int b=1000;                                            //  объявляем переменную с указанием задержки после вывода

void setup(){
  dispLED.begin();                                     //  инициируем LED дисплей
}

void loop(){
  dispLED.print(    1                  );    delay(b); // Вывод целого числа   1
  dispLED.print(   -1                  );    delay(b); // Вывод целого числа   -1
  dispLED.print(  0.1                  );    delay(b); // Вывод дробного числа 0.1
  dispLED.print( -0.1                  );    delay(b); // Вывод дробного числа -0.1
  
  dispLED.print(    1   , TEMP         );    delay(b); // Вывод целого числа   1     в качестве температуры
  dispLED.print(   -1   , TEMP         );    delay(b); // Вывод целого числа   -1    в качестве температуры
  dispLED.print(  0.1   , TEMP         );    delay(b); // Вывод дробного числа 0.1   в качестве температуры
  dispLED.print( -0.1   , TEMP         );    delay(b); // Вывод дробного числа -0.1  в качестве температуры
  
  dispLED.print(    a                  );    delay(b); // Вывод массива        а     состоящего из 4 положительный целых чисел
  
  dispLED.print(    1, 2, TIME         );    delay(b); // Вывод двух чисел     1,2   в качестве времени (01 минута : 02 секунды)
  dispLED.print(   34,56, TIME         );    delay(b); // Вывод двух чисел     34,56 в качестве времени (34 минуты : 56 секунд )
  
  dispLED.print(  250   , HEX          );    delay(b); // Вывод целого числа   250   в шестнадцатиричной системе счисления (FA)
  dispLED.print(   31   , HEX          );    delay(b); // Вывод целого числа   31    в шестнадцатиричной системе счисления (1F)
  
  dispLED.print("stop"                 );    delay(b); // Вывод текста
  
  dispLED.point(    1, 1               );    delay(b); // Установка точки            в 1 позиции
  dispLED.point(    2, 1               );    delay(b); // Установка точки            в 2 позиции
  dispLED.point(    3, 1               );    delay(b); // Установка точки            в 3 позиции
  dispLED.point(    4, 1               );    delay(b); // Установка точки            в 4 позиции
  dispLED.point(    1, 0               );    delay(b); // Сброс точки                из 1 позиции
  dispLED.point(    2, 0               );    delay(b); // Сброс точки                из 2 позиции
  dispLED.point(    3, 0               );    delay(b); // Сброс точки                из 3 позиции
  dispLED.point(    4, 0               );    delay(b); // Сброс точки                из 4 позиции
  dispLED.point(    0, 1               );    delay(b); // Установка двоеточия
  dispLED.point(    0, 0               );    delay(b); // Сброс двоеточия
  dispLED.point(    5, 1               );    delay(b); // Установка всех точек и двоеточия
  dispLED.point(    5, 0               );    delay(b); // Сброс всех точек и двоеточия

  dispLED.light(    4                  );    delay(b); // Установка яркости    4
  dispLED.light(    1                  );    delay(b); // Установка яркости    1
  dispLED.light(    0                  );    delay(b); // Установка яркости    0
  dispLED.light(    5                  );              // Установка яркости    5
  
  dispLED.print(    1                  );    delay(b); // Вывод целого числа   1
  dispLED.print(   12                  );    delay(b); // Вывод целого числа   12
  dispLED.print(  123                  );    delay(b); // Вывод целого числа   123
  dispLED.print( 1234                  );    delay(b); // Вывод целого числа   1234
  dispLED.print(  234   , RIGHT        );    delay(b); // Вывод целого числа   234   со сдвигом вправо от старшего разряда
  dispLED.print(   34   , RIGHT        );    delay(b); // Вывод целого числа   34    со сдвигом вправо от старшего разряда
  dispLED.print(    4   , RIGHT        );    delay(b); // Вывод целого числа   4     со сдвигом вправо от старшего разряда
  
  dispLED.print(   45   , POS1, RIGHT  );    delay(b); // Вывод целого числа   45    со сдвигом вправо от 1 позиции
  dispLED.print(   45   , POS2, RIGHT  );    delay(b); // Вывод целого числа   45    со сдвигом вправо от 2 позиции
  dispLED.print(   45   , POS3, RIGHT  );    delay(b); // Вывод целого числа   45    со сдвигом вправо от 3 позиции
  dispLED.print(   45   , POS4, RIGHT  );    delay(b); // Вывод целого числа   45    со сдвигом вправо от 4 позиции
  dispLED.print(   45   , POS4         );    delay(b); // Вывод целого числа   45    со сдвигом влево от 4 позиции
  dispLED.print(   45   , POS3         );    delay(b); // Вывод целого числа   45    со сдвигом влево от 3 позиции
  dispLED.print(   45   , POS2         );    delay(b); // Вывод целого числа   45    со сдвигом влево от 2 позиции
  dispLED.print(   45   , POS1         );    delay(b); // Вывод целого числа   45    со сдвигом влево от 1 позиции

  dispLED.print(    6, 1               );    delay(b); // Вывод целого числа   6     с 1 знаком  после запятой
  dispLED.print(    6, 2               );    delay(b); // Вывод целого числа   6     с 2 знаками после запятой
  dispLED.print(    6, 3               );    delay(b); // Вывод целого числа   6     с 3 знаками после запятой
  dispLED.print(    6, 2, RIGHT        );    delay(b); // Вывод целого числа   6     с 2 знаками после запятой и сдвигом вправо от старшего разряда
  dispLED.print(    6, 1, RIGHT        );    delay(b); // Вывод целого числа   6     с 1 знаком  после запятой и сдвигом вправо от старшего разряда
  dispLED.print(    6,    RIGHT        );    delay(b); // Вывод целого числа   6                               и сдвигом вправо от старшего разряда

  dispLED.print(7.89 , 0, RIGHT        );    delay(b); // Вывод дробного числа 7.89  без знаков  после запятой и сдвигом вправо от старшего разряда
  dispLED.print(7.89 , 1, RIGHT        );    delay(b); // Вывод дробного числа 7.89  с 1 знаком  после запятой и сдвигом вправо от старшего разряда
  dispLED.print(7.89 , 2, RIGHT        );    delay(b); // Вывод дробного числа 7.89  с 2 знаками после запятой и сдвигом вправо от старшего разряда
  dispLED.print(7.89 , 3, RIGHT        );    delay(b); // Вывод дробного числа 7.89  с 3 знаками после запятой и сдвигом вправо от старшего разряда
  dispLED.print(7.89 , 2               );    delay(b); // Вывод дробного числа 7.89  с 2 знаками после запятой
  dispLED.print(7.89 , 1               );    delay(b); // Вывод дробного числа 7.89  с 1 знаком  после запятой
  dispLED.print(7.89 , 0               );    delay(b); // Вывод дробного числа 7.89  без знаков  после запятой

  dispLED.print(    8   , LEN1         );    delay(b); // Вывод целого числа   8     в 1 разряде
  dispLED.print(    8   , LEN2         );    delay(b); // Вывод целого числа   8     в 2 разрядах (впереди добавляется 1 нуль)
  dispLED.print(    8   , LEN3         );    delay(b); // Вывод целого числа   8     в 3 разрядах (впереди добавляется 2 нуля)
  dispLED.print(    8   , LEN4         );    delay(b); // Вывод целого числа   8     в 4 разрядах (впереди добавляется 3 нуля)
  dispLED.print(    8   , LEN4, '_'    );    delay(b); // Вывод целого числа   8     в 4 разрядах (впереди добавляется 3 знака '_')
  dispLED.print(    8   , LEN3, '_'    );    delay(b); // Вывод целого числа   8     в 3 разрядах (впереди добавляется 2 знака '_')
  dispLED.print(    8   , LEN2, '_'    );    delay(b); // Вывод целого числа   8     в 2 разрядах (впереди добавляется 1 знак  '_')
  dispLED.print(    8   , LEN1, '_'    );    delay(b); // Вывод целого числа   8     в 1 разряде
  
  dispLED.print(6789    , LEN1         );    delay(b); // Вывод целого числа   6789  в 1 разряде  (срезаются 3 первых разряда)
  dispLED.print(6789    , LEN2         );    delay(b); // Вывод целого числа   6789  в 2 разрядах (срезаются 2 первых разряда)
  dispLED.print(6789    , LEN3         );    delay(b); // Вывод целого числа   6789  в 3 разрядах (срезается 1 первый разряд )
  dispLED.print(6789    , LEN4         );    delay(b); // Вывод целого числа   6789  в 4 разрядах (выводится всё число целиком)
  dispLED.print(6789    , LEN3, RIGHT  );    delay(b); // Вывод целого числа   6789  в 3 разрядах (срезается 1 первый разряд )
  dispLED.print(6789    , LEN2, RIGHT  );    delay(b); // Вывод целого числа   6789  в 2 разрядах (срезаются 2 первых разряда)
  dispLED.print(6789    , LEN1, RIGHT  );    delay(b); // Вывод целого числа   6789  в 1 разряде  (срезаются 3 первых разряда)

  dispLED.clear();                           delay(b); // Очистка экрана
}


