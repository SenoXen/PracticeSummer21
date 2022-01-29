## Магазин на потоках

Есть 5 магазинов. В магазинах находятся товары числом в диапозоне 950-1050. Есть 3 покупателя (3 потока) с потребностью от 9500 до 10500 и один грузчик (1 поток), который отгружает в один из магазинов по 200 единиц товара и засыпает на 2 секунды. Покупатель заходит в магазин и забирает весь товар (задача засинхронизировать покупателей и погрузчика с помощью мьютексов). Ходит покупатель до тех пор, пока не удовлетворит свою потребность (после того как покупатель сделал покупку - засыпает на 1 сек). Подробно залогировать.

_Дополнение_:
    Потребность покупателей снижена до диапозона 4500-5500, а величина погрузчика повышена до 500 для ускорения ожидания окончания программы.

---

## Makefile

make - Скомпилировать и выполнить бинарный файл. Удалить бинарный файл по завершению программы;

make bin_exe - Скомпилировать и выполнить бинарный файл. Без удаления по завершению;

make bin - Скомпилировать бинарный файл без выполнения;

make debug - Скомпилировать и выполнить для отладки через gdb. Удалить бинарный файл по завершению программы;

make clean - Удалить скомпилированный бинарный файл.