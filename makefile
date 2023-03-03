OUT = fluxpacker.exe
SRC = src/*.c

$(OUT): $(SRC)
	gcc $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)