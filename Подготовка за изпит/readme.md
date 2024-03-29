# Подготовка за изпит

## Задача 01
Напишете функция, която по подаден масив от числа с плаваща запетая, намира такова число `k`, че всички елементи в масива, които се намират на разстояние `k` позиции едно от друго, имат една и съща разлика по модул. Ако функцията успешно намира такова число, да го изведе на стандартния изход, в противен случай да изведе `"No solution"`. Ако има няколко такива числа, да се изведе най-голямото.

### Пример:
```
Вход:                     Изход:
1.6 2.3 3 3.7 4.4         3
```

## Задача 02
Напишете функция, която приема два символни низа и проверява дали двата низа са анаграми. Два низа са анаграми, ако съдържат същите знаци, но в различен ред.

### Пример:
```
Вход:                  Изход:
listen                 true
silent
```

## Задача 03
Дадена е следната структура описваща масив в динамичната памет:
```c++
struct UnsignedArray {
  unsigned* data;
  std::size_t size;
};
```

Напишете функция, която по подаден масив от естествени числа в динамичната памет връща масив само с тези числа, които имат по-малък брой цифри от броя на единиците в двоичния им запис.

### Пример:
```
Вход:                       Изход:
2 7 16 34 19 336 21         7 19 21
```

## Задача 04
Напишете функция, която по подадена матрица от естествени числа и естествено число `k` намира най-големия брой съседни елементи в матрицата, които имат един и същ най-голям общ делител с `k`.

### Пример:
```
Вход:                       Изход:
k: 54                       5
24 36 32 72
68 18 44 126
92 78 90 144
84 21 36 0
```