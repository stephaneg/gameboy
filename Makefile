all: gameboy tests 

gameboy: gameboy.o
	gcc -o gameboy build/gameboy.o build/cpu.o build/memory.o


memory.o: include/memory.h src/memory.c
	gcc -c src/memory.c -o build/memory.o

gameboy.o: src/gameboy.c cpu.o memory.o 
	gcc -c src/gameboy.c -o build/gameboy.o

cpu.o: include/cpu.h src/cpu.c memory.o
	gcc -c src/cpu.c -o build/cpu.o

tests: test/test_memory.c memory.o cpu.o
	gcc -c test/test_memory.c -o build/test_memory.o
	gcc -c test/test_cpu_instructions.c -o build/test_cpu_instructions.o
	gcc -o test_memory build/test_memory.o build/memory.o
	gcc -o test_cpu_instructions build/memory.o build/cpu.o build/test_cpu_instructions.o

clean: 
		rm build/*.o ./gameboy ./test_memory

