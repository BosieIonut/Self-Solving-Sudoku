EXEC = sudoku
FILES= *.c

build: $(FILES) $(HEADERS)
	gcc $(FILES) -o $(EXEC) -std=gnu99 -g

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)

pack:
	zip main-lab2.zip *.c *.h Makefile