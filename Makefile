CC = g++ -pedantic-errors -std=c++11

Level1.o: Level1.cpp ActualGame.h
	$(CC) -c $<

Level2.o: Level2.cpp ActualGame.h
	$(CC) -c $<

Level3.o: Level3.cpp ActualGame.h
	$(CC) -c $<

loadfunc.o: loadfunc.cpp
	$(CC) -c $<

main: loadfunc.o Level1.o Level2.o Level3.o main.cpp
	$(CC) -o main $^

clean:
	rm -f Level1.o Level2.o Level3.o loadfunc.o main

.PHONY: clean