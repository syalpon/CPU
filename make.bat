cls 

REM ##コンパイル
gcc -c main.c
gcc -c memory.c
gcc -c cpu.c


REM ##リンク
gcc memory.o cpu.o main.o
