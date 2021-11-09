@rem コンパイル
g++ -c Main.cpp
g++ -c Object.cpp
g++ -c Destination.cpp
g++ -c Connecter.cpp
g++ -c Connected.cpp
g++ -c Power.cpp
g++ -c Nand.cpp

@rem リンク
g++ -o Main Main.o Object.o Destination.o Connecter.o Connected.o Power.o Nand.o

@rem 実行
PAUSE
CHCP 65001
cls
Main.exe