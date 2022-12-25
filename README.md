## Курсовая работа. API для Англо-Русского словаря
---
**Инструкция:**

1. Установите PostgreSQL, CMake, libpqxx
2. Создайте локальную базу данных в postgres, запустите ![этот](https://github.com/arazyan/uni/blob/main/coursework/source.sql) скрипт
3. Соберите приложение, находясь в корневой папке проекта (в одной с main.cpp).


Сборка
```cmake -S . -B ./out```

Получение бинарника
```cd ./out && make```

После этого можете запустить приложение в терминале из под папки out с помощью
```./main```
