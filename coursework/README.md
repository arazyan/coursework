## Курсовая работа. API для Англо-Русского словаря
---
**Инструкция:**

1. Установите PostgreSQL, CMake, libpqxx
2. Переместите все csv-файлы из каталога *dict* в

    *Mac/Linux*: /tmp/
    
    *Windows*: C:\Users\Public\

3. Создайте локальную базу данных в postgres, используйте нужный скрипт для вашей ОС:

* ![mac/linux](https://github.com/arazyan/uni/blob/main/coursework/sourceUnix.sql)

* ![win](https://github.com/arazyan/uni/blob/main/coursework/sourceWin.sql)

4. Соберите приложение, находясь в корневой папке проекта (в одной с main.cpp)


Сборка
```cmake -S . -B ./out```

Получение бинарника
```cd ./out && make```

После этого можете запустить приложение в терминале из под папки out с помощью
```./main```
