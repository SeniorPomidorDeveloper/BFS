# Задание VK BFS

## Сборка моей версии BFS

```
mkdir ./myVersion/build
cd ./myVersion/build
cdmake ..
make
```

## Сборка верссии с использованием библиотеки boost

Для сборки потребуется пакетный менаджер [Conan](https://conan.io/).
[Инструкция по установки](https://docs.conan.io/2/installation.html)

```
cd boostVersion
conan install .
cd ./build/re*/g*  
cmake ../../.. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```
