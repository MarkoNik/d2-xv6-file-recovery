#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

void
lsd(char *path)
{
    char result[64*(DIRSIZ+1)];
    int n = lsdel(path, result);
    if(n == -1) {
        fprintf(2, "lsdel: wrong path\n");
        return;
    }
    if(n == 0) {
        fprintf(2, "lsdel: no deleted files\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", result + i*13);
    }
}

int
main(int argc, char *argv[])
{
	if(argc < 2){
		lsd(".");
		exit();
	}
	lsd(argv[1]);
	exit();
}
