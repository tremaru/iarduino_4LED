//	Библиотека для работы с 4 разрядным LED индикатором: http://iarduino.ru/shop/Displei/chetyrehrazryadnyy-indikator-led-trema-modul.html
//  Версия: 1.0.0
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/266.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/chetyrehrazryadnyy-indikator-trema-modul/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел sajaem@narod.ru
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_4LED_h
#define iarduino_4LED_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

//      DEC     10
#define LEN1	11
#define LEN2	12
#define LEN3	13
#define LEN4	14

//      HEX     16
#define TIME	17
#define TEMP	18
#define LEFT	19
#define RIGHT	20
#define POS1	21
#define POS2	22
#define POS3	23
#define POS4	24

class iarduino_4LED{

	public:			iarduino_4LED(uint8_t,uint8_t);											//	подключение индикатора (CLK,DIO);
	/**	функции доступные пользователю **/
		void		begin(){FUN_printNumS(""); light(5);}									//	инициализация индикатора
		void		clear(){FUN_printNumS("");}												//	очистка всех разрядов
		void		light(    uint8_t i){LED_uintLIGHT=i; FUN_dispDATA();}					//	установка яркости от 0 до 7
		void		point(    uint8_t=255,bool=0);											//	установка точек
		void		setLED(   uint8_t=0,uint8_t=0,uint8_t=0,uint8_t=0,bool=0);				//	установка светодиодов по битам
		void		print(    int16_t i,          int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle('0',j1,j2,j3,j4,j5); if(VAR_uintTYP==TIME){FUN_printNumT(i,j1);}else{FUN_printNumI(i);}}
		void		print(    int16_t i, char j0, int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(    int16_t i,          int j1    , char j0, int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(    int16_t i,          int j1    ,          int j2    , char j0, int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(    int16_t i,          int j1    ,          int j2    ,          int j3    , char j0, int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(    int16_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    , char j0, int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(    int16_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    ,          int j5,    char j0){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(i);}
		void		print(   uint16_t i,          int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle('0',j1,j2,j3,j4,j5); if(VAR_uintTYP==TIME){FUN_printNumT(int16_t(i),j1);}else{FUN_printNumI(int16_t(i));}}
		void		print(   uint16_t i, char j0, int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint16_t i,          int j1    , char j0, int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint16_t i,          int j1    ,          int j2    , char j0, int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint16_t i,          int j1    ,          int j2    ,          int j3    , char j0, int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint16_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    , char j0, int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint16_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    ,          int j5,    char j0){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle('0',j1,j2,j3,j4,j5); if(VAR_uintTYP==TIME){FUN_printNumT(int16_t(i),j1);}else{FUN_printNumI(int16_t(i));}}
		void		print(    int32_t i, char j0, int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1    , char j0, int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1    ,          int j2    , char j0, int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1    ,          int j2    ,          int j3    , char j0, int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    , char j0, int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(    int32_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    ,          int j5,    char j0){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle('0',j1,j2,j3,j4,j5); if(VAR_uintTYP==TIME){FUN_printNumT(int16_t(i),j1);}else{FUN_printNumI(int16_t(i));}}
		void		print(   uint32_t i, char j0, int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1    , char j0, int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1    ,          int j2    , char j0, int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1    ,          int j2    ,          int j3    , char j0, int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    , char j0, int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(   uint32_t i,          int j1    ,          int j2    ,          int j3    ,          int j4    ,          int j5,    char j0){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumI(int16_t(i));}
		void		print(     double i,          int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle('0',j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i, char j0, int j1=255,          int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i,          int j1    , char j0, int j2=255,          int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i,          int j1    ,          int j2    , char j0, int j3=255,          int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i,          int j1    ,          int j2    ,          int j3    , char j0, int j4=255,          int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i,          int j1    ,          int j2    ,          int j3    ,          int j4    , char j0, int j5=255        ){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(     double i,          int j1    ,          int j2    ,          int j3    ,          int j4    ,          int j5,    char j0){FUN_sortStyle( j0,j1,j2,j3,j4,j5); FUN_printNumF(i);}
		void		print(      char *i){FUN_sortStyle(' ',255,255,255,255,255);                                                                                                             FUN_printNumS(i);}
		void		print(const char *i){FUN_sortStyle(' ',255,255,255,255,255); char j[10]; j[9]=0; for(uint8_t k=0; k<9; k++){j[k]=i[k]; if(i[k]==0){k=10;}}                               FUN_printNumS(j);}
		void		print(     String i){FUN_sortStyle(' ',255,255,255,255,255); char j[10]; j[9]=0; for(uint8_t k=0; k<9; k++){j[k]=i[k]; if(i[k]==0){k=10;}}                               FUN_printNumS(j);}
		void		print(      int i[]){FUN_sortStyle(' ',255,255,255,255,255);                                                                                                             FUN_printNumA(i);}
	private:
	/**	внутренние функции **/
		void		FUN_dispDATA	(uint8_t,uint8_t);			//	вывести значение uint8_t, в позицию uint8_t
		void		FUN_dispDATA	();							//	вывести массив VAR_massCH
		uint8_t		FUN_segmCODE	(char);						//	закодировать символ для его вывода
		void		FUN_busSTART	();							//	установка состояния START
		void		FUN_busSTOP		();							//	установка состояния STOP
		void		FUN_busWBIT		(bool);						//	передача одного бита
		void		FUN_busWBYTE	(uint8_t);					//	передача одного байта
		bool		FUN_busRACK		();							//	ожидание одного ответного бита ACK
		void		FUN_printNumI	(int16_t);					//	вывод целого числа
		void		FUN_printNumF	(double);					//	вывод числа с плавающей точкой
		void		FUN_printNumS	(char*);					//	вывод строки
		void		FUN_printNumA	(int i[]);					//	вывод массива
		void		FUN_printNumT	(uint8_t,uint8_t);			//	вывод времени
		void		FUN_sortStyle	(char,uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);	//	сортировка параметров вывода
		void		FUN_strnInsert	(char*,char,int,int);		//	вставить в строку char* символ char, int раз, начиная с int позиции
		void		FUN_strnDelete	(char*,int,int);			//	удалить из строки char* int символов, начиная с int позиции
	/**	внутренние переменные **/
		uint8_t		LED_pinsCLK;		//	0 - 255				номер вывода назначенного для линии тактирования (CLocK)
		uint8_t		LED_pinsDIO;		//	0 - 255				номер вывода назначенного для линии данных (Data Input Output)
		uint8_t		LED_uintLIGHT;		//	0 - 7				яркость
		uint8_t		VAR_uintLEN;		//	0,1,2,3,4,255		длинна (количество рязрядов) выводимого числа, 255-по размеру числа
		char		VAR_charSYM;		//	' '					символ заменяющий знаки 0 перед числом (если VAR_uintLEN больше разрядности числа)
		uint8_t		VAR_uintPOS;		//	POS1 - POS4			позиция (номер разряда) выводимого числа
		uint8_t		VAR_uintRUN;		//	LEFT / RIGHT		направление сдвига от указанной позиции
		uint8_t		VAR_uintTYP;		//	DEC/HEX/TIME/TEMP	тип выводимого числа
		uint8_t		VAR_uintDEC;		//	0,1,2,3,4,255		количество знаков после запятой, 255-не указано
		char		VAR_massCH[10];		//	"X.X.:X.X."			массив значений разрядов
		bool		VAR_massPT[5];		//	{*,*,:,*,*}			массив точек
};

#endif