



Библиотека iarduino_Pressure_BMP позволяет считывать температуру окружающей среды и атмосферное давление с датчиков <a href="http://iarduino.ru/shop/Sensory-Datchiki/barometr-gy-68-datchik-atmosfernogo-davleniya-bmp180.html">BMP28/a> и <a href="](http://iarduino.ru/shop/Sensory-Datchiki/barometr-trema-modul.html">BMP280</a>, а так же рассчитывать высоту.</p>
<blockquote>
<p>Подробнее про установку библиотеки читайте в нашей <a href="https://wiki.iarduino.ru/page/Installing_libraries/">инструкции</a>.</p>
</blockquote>
<p>Пример подключения к <a href="https://iarduino.ru/shop/boards/arduino-uno-r3.html">Arduino</a>/<a href="https://iarduino.ru/shop/boards/piranha-uno-r3.html">Piranha UNO</a> с помощью <a href="dhttps://iarduino.ru/shop/Expansion-payments/trema-shield.html">Trema Shield</a><br>
Подробнее о <a href="https://wiki.iarduino.ru/page/trema-modul-pressure-meter">подключении модуля</a><br>
<img src="https://iarduino.ru/img/upload/ff71929a63d941fd58dc5a60860d0671.png" alt="enter image description here"></p>

<table>
<thead>
<tr>
<th>Модель</th>
<th>Ссылка на магазин</th>
</tr>
</thead>
<tbody>
<tr>
<td>BMP280 <img src="https://wiki.iarduino.ru/img/resources/840/840.svg" alt="enter image description here"></td>
<td><a href="https://iarduino.ru/shop/Sensory-Datchiki/barometr-trema-modul.htmlhttps://iarduino.ru/shop/Sensory-Datchiki/barometr-trema-modul.html</a></td>
</tr>
<tr>
<td>BMP180 <img src="https://wiki.iarduino.ru/img/resources/840/840.svg" alt="0 ![enter image description herehttps://iarduino.ru/img/resources/840/840.svg) | https://iarduino.ru/shop/Sensory-Datchiki/barometr-trema-modul.html|
| BMP18enter image description here"></td>
<td><a href="](https://wiki.iarduino.ru/shop/Sensory-Datchiki/barometr-gy-68-datchik-atmosfernogo-davleniya-bmp180.html">img/resources/840/840.svg) | https://iarduino.ru/shop/Sensory-Datchiki/barometr-gy-68-datchik-atmosfernogo-davleniya-bmp180.html</a></td>
</tr>
</tbody>
</table><h2 id="описание-библиотеки">Описание библиотеки:</h2>
<p>Данная библиотека может использовать как аппаратную, так и программную реализацию шины I2C.<br>
О том как выбрать тип шины I2C рассказано в статье <a href="https://wiki.iarduino.ru/page/i2c_connection/">[Wiki - расширенные возможности библиотек iarduino для шины I2C</a>.</p>
<p><strong><a href="](https://wiki.iarduino.ru/page/trema-modul-pressure-meter">  Подробное описание, подключение и примеры работы </a></strong></p>
<h2 id="назначение-функций-и-переменных">](https://wiki.iarduino.ru/page/trema-modul-pressure-meter)**

## Назначение функций и переменных:</h2>
<p>Подробное описание работы с библиотекой, находится в разделе <a href="https://wiki.iarduino.ru/page/chetyrehrazryadnyy-indikator-trema-modul/" title= "Wiki Четырёхразрядный индикатор">Wiki Четырёхразрядный индикатор</a>.</p>
<p><strong>Подключаем библиотеку.</strong></p>
<pre><code>#include  **&lt;<iarduino_Pressure_BMP.h&gt;>**  // Подключаем библиотеку.  
</code></pre>
<p><strong>
**Создаём объект (адрес по умолчанию 0x77).</strong></p>
<pre><code>**

    iarduino_Pressure_BMP  **ОБЪЕКТ (**  [ АДРЕС_I2C ]  **);**  // Создаём объект (адрес по умолчанию 0x77).
</code></pre>
<p><strong>
 **Инициализация работы BMP датчика (с указанием его начальной высоты).</strong></p>
<pre><code>Функция  **begin(**  [ ВЫСОТА ]  **);**  // Инициализация работы BMP датчика (с указанием его начальной высоты).
</code></pre>
<p><strong>
**Чтение показаний датчика (с выбором единицы измерения давления).</strong></p>
<pre><code>**

    Функция  **read(**  [ ЦИФРА ]  **);** // Чтение показаний датчика (с выбором единицы измерения давления).
</code></pre>
<p><strong>
**Выбор точности измерений (подавление шума).</strong></p>
<pre><code>**

    Функция  **measurement(**  ЦИФРА  **);**  // Выбор точности измерений (подавление шума).
</code></pre>
<p><strong>Возвращает температуру окружающей среды в °С.</strong></p>
<pre><code>Переменная  **temperature** // Возвращает температуру окружающей среды в °С.
</code></pre>
<p><strong>Возвращает атмосферное давление в мм.рт.ст. или Па.</strong></p>
<pre><code>Переменная  **pressure** // Возвращает атмосферное давление в мм.рт.ст. или Па.
</code></pre>
<p><strong>Возвращает высоту относительно начальной в м.</strong></p>
<pre><code>Переменная  **altitude** // Возвращает высоту относительно начальной в м.
</code></pre>
<p><strong>Возвращает тип датчика: 180 или 280.</strong></p>
<pre><code>Переменная  **type** // Возвращает тип датчика: 180 или 280.
</code></pre>
<p><strong>
**Возвращает версию прошивки датчика.</strong></p>
<pre><code>**

    Переменная  **version** // Возвращает версию прошивки датчика.
</code></pre>

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTQ1MDE3NjgxMCwtMTgzNjIzNjM1Nl19
-->
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE0NzQ3MTc4NzEsLTE3MzEzMzM1MTZdfQ
==
-->