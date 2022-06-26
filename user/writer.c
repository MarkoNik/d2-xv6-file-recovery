#include "kernel/fcntl.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Usage: writer [filename] [size]\n");
		exit();
	}

	int fd;
	if ((fd = open(argv[1], O_CREATE|O_WRONLY)) < 0) {
        exit();
    }

	char buf[atoi(argv[2])];
	char a = 'a' - 1;
	for (int i = 0; i < atoi(argv[2]); i++) {
		if (i % 512 == 0) {
			a++;
		}
		buf[i] = a;
	}

	write(fd, buf, atoi(argv[2]));
	close(fd);
	exit();
}
