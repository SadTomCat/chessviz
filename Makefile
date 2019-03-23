main: ./src/main.c
	gcc -Wall -Werror -o ./bin/main ./src/main.c
	./bin/main

clean:
	rm ./bin/main 