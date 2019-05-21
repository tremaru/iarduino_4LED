#include "iarduino_4LED.h"

//		ИНТЕРФЕЙС ПЕРЕДАЧИ ДАННЫХ:
//		    ────┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌──┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌┐┌─────
//		CLK   : │^│^│^│^│^│^│^│^│^││::│^│^│^│^│^│^│^│^│^││:
//			  : └┘└┘└┘└┘└┘└┘└┘└┘└┘└┘::└┘└┘└┘└┘└┘└┘└┘└┘└┘└┘:
//			  :                  :  ::                 :  :           УСЛОВИЯ:       CLK DIO
//		    ──┐ ┌─┐ ┌─┐       ┌─┐:  ┌┐  ┌─┐ ┌─┐ ┌─┐ ┌─┐:  ┌────       S - старт       1  1>0
//		DIO   │ │ │ │ │       │ │:  ││  │ │ │ │ │ │ │ │:  │           P - стоп        1  0>1
//			  └─┘ └─┘ └───────┘ └───┘└──┘ └─┘ └─┘ └─┘ └───┘           B - байт        1  0/1
//			  :                  :  ::                 :  :           A - пдтв        1   0
//		    │ S │1│0│1│0│0│0│0│1│A│ RS│0│1│0│1│0│1│0│1│A│ P │         изменения       0  изменения
//
//		ОБЩИЙ ВИД КОМАНДНОГО БАЙТА:
//			┌─┬─┬─┬─┬─┬─┬─┬─┐   тип команды:
//			│7│6│5│4│3│2│1│0│   00 - нет такого типа
//			├─┴─┼─┴─┼─┴─┴─┴─┤   01 - установка передачи данных
//			│тип│ 0 │команда│   10 - управление дисплеем
//			└───┴───┴───────┘   11 - выбор адреса(разряда) регистра сегментов LED:
//
//		ТИПЫ КОМАНДНЫХ БАЙТОВ:
//		01 - установка передачи данных:
//			┌─┬─┬─┬─┬─┬─┬─┬─┐   A - режим тестирования: 1-вкл/0-выкл
//			│7│6│5│4│3│2│1│0│   B - режим передачи адреса регистров: 1-фиксированный/0-инкрементируемый
//			├─┼─┼─┴─┼─┼─┼─┴─┤   С - направление передачи данных: 00-запись данных,10-чтение данных
//			│0│1│ 0 │A│B│ C │
//			└─┴─┴───┴─┴─┴───┘
//		10 - управление дисплеем:
//			┌─┬─┬─┬─┬─┬─┬─┬─┐   A - включение дисплея: 1-вкл/0-выкл
//			│7│6│5│4│3│2│1│0│   B - настройка яркости: 0-мин/7-макс
//			├─┼─┼─┴─┼─┼─┴─┴─┤
//			│1│0│ 0 │A│  B  │
//			└─┴─┴───┴─┴─────┘
//		11 - выбор адреса(разряда) регистра сегментов LED:
//			┌─┬─┬─┬─┬─┬─┬─┬─┐   A - адрес(разряд)
//			│7│6│5│4│3│2│1│0│   0000 = 0 => GRID1
//			├─┼─┼─┴─┼─┴─┴─┴─┤   ....
//			│1│1│ 0 │   A   │   0101 = 5 => GRID6
//			└─┴─┴───┴───────┘   указание более высокого адреса будет проигнорировано, по умолчанию устанавливается адрес 0000
//		БАЙТ ДАННЫХ:               a
//			┌─┬─┬─┬─┬─┬─┬─┬─┐     ───         
//			│7│6│5│4│3│2│1│0│   f│ g │b       вид байта данных:
//			├─┼─┼─┼─┼─┼─┼─┼─┤     ───         
//			│h│g│f│e│d│c│b│a│   e│   │c
//			└─┴─┴─┴─┴─┴─┴─┴─┘     ───  • h
//			                       d

		iarduino_4LED::iarduino_4LED(uint8_t i, uint8_t j){
			LED_pinsCLK=i;							//	номер вывода назначенного для линии тактирования (CLocK)
			LED_pinsDIO=j;							//	номер вывода назначенного для линии данных (Data Input Output)
			pinMode(LED_pinsCLK,OUTPUT);			//	переводим вывод LED_pinsCLK в режим выхода
			pinMode(LED_pinsDIO,OUTPUT);			//	переводим вывод LED_pinsDIO в режим выхода
			digitalWrite(LED_pinsCLK,HIGH);
			digitalWrite(LED_pinsDIO,HIGH);
}

//		установка состояния START
void	iarduino_4LED::FUN_busSTART(){
			digitalWrite(LED_pinsCLK,HIGH);			//	CLK	─ ─ ┬───────┐
			digitalWrite(LED_pinsDIO,HIGH);			//		─ ─ ┘   :   └ - -
			delayMicroseconds(10);					//		    :   :   :
			digitalWrite(LED_pinsDIO,LOW);			//	DIO	─ ─ ┬───┐   :
			delayMicroseconds(10);					//		─ ─ ┘   └──── - -
			digitalWrite(LED_pinsCLK,LOW);			//		  ? : d : d :
} 

//		установка состояния STOP
void	iarduino_4LED::FUN_busSTOP(){
			digitalWrite(LED_pinsCLK,LOW);			//	CLK	─ ─ ┐   ┌──── - -
			digitalWrite(LED_pinsDIO,LOW);			//		─ ─ ┴───┘   :
			delayMicroseconds(10);					//		    :   :   :
			digitalWrite(LED_pinsCLK,HIGH);			//	DIO	─ ─ ┐   :   ┌ - -
			delayMicroseconds(10);					//		─ ─ ┴───────┘
			digitalWrite(LED_pinsDIO,HIGH);			//		  ? : d : d :
}

//		передача одного бита
void	iarduino_4LED::FUN_busWBIT(bool i){
			digitalWrite(LED_pinsCLK,LOW);			//	CLK	─ ─ ┐   ┌──── ─ ─		─ ─ ┐   ┌──── ─ ─
			digitalWrite(LED_pinsDIO,i);			//		─ ─ ┴───┘   :			    └───┘   
			delayMicroseconds(10);					//		    :   :   :
			digitalWrite(LED_pinsCLK,HIGH);			//	DIO	─ ─ ┬──────── ─ ─		─ ─ ┬──────── ─ ─
			delayMicroseconds(10);					//		─ ─ ┴──────── ─ ─		─ ─ ┴──────── ─ ─
}													//		  ? : d : d :
//		ожидание одного ответного бита ACK
bool	iarduino_4LED::FUN_busRACK(){
			uint8_t f=0;
			digitalWrite(LED_pinsCLK,LOW);			//	CLK	─ ─ ┐   ┌──────────── ─ ─
			digitalWrite(LED_pinsDIO,HIGH);			//		─ ─ ┴───┘       :   :
			pinMode(LED_pinsDIO,INPUT);				//		    :   :       :   :
			delayMicroseconds(10);					//	DIO	─ ─ ┬ ─ ─ ─ ─ ─ ─ ─ ┬
			digitalWrite(LED_pinsCLK,HIGH);			//		─ ─ ┘   : ─ ─ ─ ─ ─ ┴─ ─ ─
			while(digitalRead(LED_pinsDIO)&&f<10){	//		  ? : d : while : d :
				delayMicroseconds(5); f++;
			}	delayMicroseconds(10);
			pinMode(LED_pinsDIO,OUTPUT);
			digitalWrite(LED_pinsDIO,LOW);
			return f<10?1:0;
}

//		передача одного байта
void	iarduino_4LED::FUN_busWBYTE(uint8_t i){
//			передаём байт младшим битом вперёд
			for(uint8_t j=0; j<8; j++){
				FUN_busWBIT(i&0x01); i>>=1;
			}	FUN_busRACK();
}

//		вывод одного разряда на дисплей
void	iarduino_4LED::FUN_dispDATA(uint8_t i, uint8_t j){	//	вывести значение i, в позицию j
			FUN_busSTART();							//	устанавливаем состояние START
			FUN_busWBYTE(0x44);						//	передаём командный байт: установка передачи данных с фиксированным адресом)
			FUN_busSTOP ();							//	устанавливаем состояние STOP
			FUN_busSTART();							//	устанавливаем состояние START
			FUN_busWBYTE(0xc0|j);					//	передаём командный байт: выбор адреса(разряда) регистра LED = j, где j значение от 0 до 7
			FUN_busWBYTE(i);						//	передаём байт данных для записи в указанный выше регистр
			FUN_busSTOP ();							//	устанавливаем состояние STOP
			FUN_busSTART();							//	устанавливаем состояние START
			FUN_busWBYTE(0x88|LED_uintLIGHT);		//	передаём командный байт: включение дисплея с указанием яркости = LED_uintLIGHT, где LED_uintLIGHT значение от 0 до 7	
			FUN_busSTOP ();							//	устанавливаем состояние STOP
}

//		вывод всех разрядов на дисплей
void	iarduino_4LED::FUN_dispDATA(){				//	вывести массив VAR_massCH
			FUN_dispDATA(                             (VAR_massCH[4]==' '?0x00:0x02) , 1);
			FUN_dispDATA((FUN_segmCODE(VAR_massCH[0])|(VAR_massCH[1]==' '?0x00:0x80)), 2);
			FUN_dispDATA((FUN_segmCODE(VAR_massCH[2])|(VAR_massCH[3]==' '?0x00:0x80)), 3);
			FUN_dispDATA((FUN_segmCODE(VAR_massCH[5])|(VAR_massCH[6]==' '?0x00:0x80)), 4);
			FUN_dispDATA((FUN_segmCODE(VAR_massCH[7])|(VAR_massCH[8]==' '?0x00:0x80)), 5);
}

//		кодирование символа в семисегментный вид
uint8_t	iarduino_4LED::FUN_segmCODE(char i){
			switch(i){
				case 'o': case 'O': case '0':	return 0x3F;	break;
				case 'i': case 'I': case '1':	return 0x06;	break;
									case '2':	return 0x5B;	break;
									case '3':	return 0x4F;	break;
									case '4':	return 0x66;	break;
				case 's': case 'S':	case '5':	return 0x6D;	break;
									case '6':	return 0x7D;	break;
									case '7':	return 0x07;	break;
									case '8':	return 0x7F;	break;
									case '9':	return 0x6F;	break;
				case 'a': case 'A':				return 0x77;	break;
				case 'b': case 'B':				return 0x7C;	break;
				case 'c': case 'C':				return 0x39;	break;
				case 'd': case 'D':				return 0x5E;	break;
				case 'e': case 'E':				return 0x79;	break;
				case 'f': case 'F':				return 0x71;	break;
				case 'g': case 'G':				return 0x3D;	break;
				case 'h': case 'H':				return 0x76;	break;
				case 'j': case 'J':				return 0x1E;	break;
				case 'l': case 'L':				return 0x38;	break;
				case 'n': case 'N':				return 0x54;	break;
				case 'p': case 'P':				return 0x73;	break;
				case 't': case 'T':				return 0x78;	break;
				case 'u': case 'U':				return 0x3E;	break;
				case '-':						return 0x40;	break;
				case '_':						return 0x08;	break;
				case '*':						return 0x63;	break;
				case '"': case '\'':			return 0x22;	break;
				default :						return 0x00;	break;
			}
}

//		установка точек
void	iarduino_4LED::point(uint8_t i,bool j){
			if(i==0||i>4){VAR_massCH[4]=j?':':' ';}
			if(i==1||i>4){VAR_massCH[1]=j?'.':' ';}
			if(i==2||i>4){VAR_massCH[3]=j?'.':' ';}
			if(i==3||i>4){VAR_massCH[6]=j?'.':' ';}
			if(i==4||i>4){VAR_massCH[8]=j?'.':' ';}
			FUN_dispDATA();
}

//	установка светодиодов по битам
void	iarduino_4LED::setLED(uint8_t j1, uint8_t j2, uint8_t j3, uint8_t j4, bool j0){
			FUN_dispDATA(j0?0x02:0x00,1);
			FUN_dispDATA(j1,2);
			FUN_dispDATA(j2,3);
			FUN_dispDATA(j3,4);
			FUN_dispDATA(j4,5);
}

//		сортировка параметров вывода
void	iarduino_4LED::FUN_sortStyle(char j0, uint8_t j1, uint8_t j2, uint8_t j3, uint8_t j4, uint8_t j5){
		uint8_t j[5]={j1,j2,j3,j4,j5};
		VAR_charSYM=j0;
		VAR_uintLEN=255;
		VAR_uintPOS=255;
		VAR_uintRUN=LEFT;
		VAR_uintTYP=DEC;
		VAR_uintDEC=255;
		VAR_massCH[0]=0;
		for(uint8_t i=0; i<5; i++){
			if(j[i]==DEC  || j[i]==HEX  || j[i]==TIME || j[i]==TEMP){VAR_uintTYP=j[i];}
		}
		for(uint8_t i=VAR_uintTYP==TIME?1:0; i<5; i++){
			if(j[i]==LEN1 || j[i]==LEN2 || j[i]==LEN3 || j[i]==LEN4){VAR_uintLEN=j[i];}
			if(j[i]==POS1 || j[i]==POS2 || j[i]==POS3 || j[i]==POS4){VAR_uintPOS=j[i];}
			if(j[i]==LEFT || j[i]==RIGHT                           ){VAR_uintRUN=j[i];}
		}	if(j1<5)												{VAR_uintDEC=j1;  }
		if(VAR_uintPOS==255){VAR_uintPOS=VAR_uintRUN==LEFT?POS4:POS1;}
}

//		вывод целого числа
void	iarduino_4LED::FUN_printNumI(int16_t i){
//			перенапраяляем вывод на число с плавающей точкой
			if(VAR_uintDEC>0 && VAR_uintDEC!=255){FUN_printNumF(double(i)); return;}
//			создаём временные переменные
			char l[10]; l[0]=0; uint8_t len=0; bool neg=0, fneg=0;
//			сохраняем знак и получаем модуль числа i
			if(i<0){neg=1; fneg=1; i*=-1;}
//			преобразуем число i в строку l и определяем её длину len
			itoa(i,l,(VAR_uintTYP==HEX?HEX:DEC)); if(VAR_uintTYP==TEMP){strcat(l,"*");} len=strlen(l);
//			удаляем из начала строки l лишние символы, если таковые есть
			if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1+1)<len){FUN_strnDelete(l,(len-(VAR_uintLEN-LEN1+1)),0);} len=strlen(l);
//			добавляем в начало строки l недостающие символы '0' и знак числа, если таковые необходимы
			if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1+1)>len){FUN_strnInsert(l,VAR_charSYM,((VAR_uintLEN-LEN1)-len),0); FUN_strnInsert(l,(neg?'-':VAR_charSYM),1,0); fneg=0;} len=strlen(l);
//			если в предыдущем условии знак не добавлен, то добавляем его сейчас
			if(fneg){if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1)<len){FUN_strnDelete(l,1,0);} FUN_strnInsert(l,'-',1,0); fneg=0;} len=strlen(l);
//			сдвигаем строку l вправо на указанную в VAR_uintPOS позицию
			if(VAR_uintPOS>POS1){FUN_strnInsert(l,' ',(VAR_uintPOS-POS1),0);}
//			сдвигаем строку влево если указано смещение VAR_uintRUN==LEFT
			if(VAR_uintRUN==LEFT){FUN_strnDelete(l,len-1,0);} len=strlen(l);
//			срезаем символы за пределами индикатора
			l[4]=0;
//			выводим строку
			FUN_printNumS(l);
}

//		вывод числа с плавающей точкой
void	iarduino_4LED::FUN_printNumF(double i){
//			перенапраяляем вывод на число без запятой
			if(VAR_uintDEC==0){FUN_printNumI(int16_t(i)); return;} if(VAR_uintDEC==255){VAR_uintDEC=1;} if(VAR_uintDEC>4){VAR_uintDEC=4;}
//			создаём временные переменные
			char l[10]; l[0]=0; uint8_t len=0; bool neg=0, fneg=0, fneg1=0;
//			сохраняем знак и получаем модуль числа i
			if(i<0){neg=1; fneg=1; fneg1=1; i*=-1;}
//			разбиваем число на челое и дробное
			int16_t i1 = int16_t(i);
			int16_t i2 = int32_t(i*10000)%10000;
//			собираем целое i1 и дробное i2 в строку l и определяем её длину len
			itoa(i1,l,(VAR_uintTYP==HEX?HEX:DEC)); strcat(l,"."); len=strlen(l); if(i2<1000){strcat(l,"0");} if(i2<100){strcat(l,"0");} if(i2<10){strcat(l,"0");} itoa(i2,&l[strlen(l)],(VAR_uintTYP==HEX?HEX:DEC)); l[len+VAR_uintDEC]=0; if(VAR_uintTYP==TEMP){strcat(l,"*");} len=strlen(l);
//			удаляем из начала строки l лишние символы, если таковые есть
			if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1+2)<len){FUN_strnDelete(l,(len-(VAR_uintLEN-LEN1+2)),0);} len=strlen(l);
//			добавляем в начало строки l недостающие символы '0' и знак числа, если таковые необходимы
			if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1+2)>len){FUN_strnInsert(l,VAR_charSYM,((VAR_uintLEN-LEN1+1)-len),0); FUN_strnInsert(l,(neg?'-':VAR_charSYM),1,0); fneg=0;} len=strlen(l);
//			если в предыдущем условии знак не добавлен, то добавляем его сейчас
			if(fneg){if(VAR_uintLEN<255 && (VAR_uintLEN-LEN1+1)<len){FUN_strnDelete(l,1,0);} FUN_strnInsert(l,'-',1,0); fneg=0;} len=strlen(l);
//			сдвигаем строку l вправо на указанную в VAR_uintPOS позицию
			if(VAR_uintPOS>POS1){FUN_strnInsert(l,' ',(VAR_uintPOS-POS1),0);}
//			сдвигаем строку влево если указано смещение VAR_uintRUN==LEFT
			if(VAR_uintRUN==LEFT){FUN_strnDelete(l,len-2,0);} len=strlen(l);
//			проверка наличия запятых и знаков
			if(l[0]=='.'){FUN_strnDelete(l,1,0);}
			fneg=1; if(l[1]=='.'){fneg=0;} if(l[2]=='.'){fneg=0;} if(l[3]=='.'){fneg=0;} if(l[4]=='.'){fneg=0;} if(fneg){FUN_strnDelete(l,1,0);} if(l[0]=='.'){FUN_strnDelete(l,1,0);}
			fneg=1; if(l[0]=='-'){fneg=0;} if(l[1]=='-'){fneg=0;} if(l[2]=='-'){fneg=0;} if(l[3]=='-'){fneg=0;} if(l[4]=='-'){fneg=0;} if(fneg && fneg1){l[0]='-';}
			fneg=0; if(l[1]=='.'){fneg=1;} if(l[2]=='.'){fneg=1;} if(l[3]=='.'){fneg=1;} if(l[4]=='.'){fneg=1;} l[4+fneg]=0;
//			выводим строку
			FUN_printNumS(l);
}
//		вывод времени
void	iarduino_4LED::FUN_printNumT(uint8_t i, uint8_t j){
			char l[10]; l[0]=0;
			if(i>59){i=59;} if(j>59){j=59;}
			if(i<10){strcat(l,"0");}					//	добавляем символ 0 перед часами, если таковой нужен
			itoa(i,&l[strlen(l)],DEC);					//	добавляем в строку часы
			strcat(l,":");								//	добавляем в строку разделитель
			if(j<10){strcat(l,"0");}					//	добавляем символ 0 перед минутами, если таковой нужен
			itoa(j,&l[strlen(l)],DEC);					//	добавляем в строку часы
//			выводим строку
			FUN_printNumS(l);
}

//		вывод строки
void	iarduino_4LED::FUN_printNumS(char *i){
			uint8_t f=0;
			VAR_massCH[0]=0;
			for(uint8_t j=0, k=1; j<10; j++, k++){
				if(strlen(i)>j){
					if(i[j]==':'||i[j]==';'||i[j]=='='){f=k; k--;}else
					{
						if(i[j]=='.' || i[j]==',')	{if(k%2==1){if(k<10){VAR_massCH[k-1]=' ';} k++;}}//	если требуется вывести "." или ":"
						else						{if(k%2==0){if(k<10){VAR_massCH[k-1]=' ';} k++;}}//	если требуется вывести число
						if(k<10){VAR_massCH[k-1]=i[j];}	//	дополняем строку указанным символом
					}
				}else{	if(k<10){VAR_massCH[k-1]=' ';}}	//	дополняем недостающие символы
			}	VAR_massCH[9]=0;
			if(f==1)		{VAR_massCH[5]=0;	FUN_strnInsert(VAR_massCH,' ',4,0);}
			if(f==2 || f==3){VAR_massCH[7]=0;	FUN_strnInsert(VAR_massCH,' ',2,0);}
			if(f==6 || f==7){					FUN_strnDelete(VAR_massCH,    2,0);}
			if(f==8 || f==9){					FUN_strnDelete(VAR_massCH,    4,0);}
												FUN_strnInsert(VAR_massCH,(f>0?':':' '),1,4);
			for(uint8_t j=0; j<9; j++){if(VAR_massCH[j]==0){VAR_massCH[j]=' ';}} VAR_massCH[9]=0;
			FUN_dispDATA();
}

//		вывод массива
void	iarduino_4LED::FUN_printNumA(int i[]){
			for(uint8_t j=0; j<9; j++){VAR_massCH[j]=' ';} VAR_massCH[9]=0;
			if(i[0]<=16){itoa(i[0], &VAR_massCH[0], HEX);}else{VAR_massCH[0]=' ';} VAR_massCH[1]=' ';
			if(i[1]<=16){itoa(i[1], &VAR_massCH[2], HEX);}else{VAR_massCH[2]=' ';} VAR_massCH[3]=' '; VAR_massCH[4]=' ';
			if(i[2]<=16){itoa(i[2], &VAR_massCH[5], HEX);}else{VAR_massCH[5]=' ';} VAR_massCH[6]=' ';
			if(i[3]<=16){itoa(i[3], &VAR_massCH[7], HEX);}else{VAR_massCH[7]=' ';} VAR_massCH[8]=' '; VAR_massCH[9]=0;
			FUN_dispDATA();
}

//		функции обработки строк
void	iarduino_4LED::FUN_strnInsert(char *i, char j, int n, int k){	//	вставить символ j в строку i, n раз, начиная с позиции k
			if(n<0 || k<0){return;} for(uint8_t l=0; l<n; l++){for(uint8_t m=strlen(i)+1; m>k; m--){i[m]=i[m-1];} i[k]=j;}
}
void	iarduino_4LED::FUN_strnDelete(char *i, int n, int k){			//	удалить n символов из строки i начиная с позиции k
			if(n<0 || k<0){return;} for(uint8_t l=0; l<n; l++){for(uint8_t m=k; m<=strlen(i); m++){i[m]=i[m+1];}}
}
