all: serv cli
runnables := cli serv
temp_dirs := cli.dSYM*/ serv.dSYM*/
serv: server/main.c
	gcc -g ./server/main.c -o serv

cli: client/main.c
	gcc -g ./client/main.c -o cli 


clean:
	rm -f $(runnables) 
	rm -rf $(temp_dirs)
