linkedtest: linkedlist.c
	clang linkedlist.c -o linkedtest

clean:
	rm *~

run: linkedtest
	./linkedtest