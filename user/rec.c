#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

void
rc(char *path)
{
    int res = rec(path);
    if(res == -1) {
        fprintf(2, "rec: wrong path\n");
        return;
    }
    if(res == -2) {
        fprintf(2, "rec: file was not found in this directory\n");
        return;
    }
    if(res == -3) {
        fprintf(2, "rec: inode has been reused\n");
        return;
    }
    if(res == -4) {
        fprintf(2, "rec: some of the blocks have been reused\n");
        return;
    }

    fprintf(2, "the recovery was successful\n");
}

int
main(int argc, char *argv[])
{
	if(argc < 2){
        fprintf(2, "rec: need to enter path name\n");
		exit();
	}
	rc(argv[1]);
	exit();
}
