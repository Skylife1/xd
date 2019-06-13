#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
     int fd = open("/2019-SO-Electronica-1825221/2019_06_06/text.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | O_EXCL, S_IRUSR);
	if (fd<0){
           printf("The file exist \n");
}
	else{
	    printf("The file doesn't exist \n");
		
}

//    assert(fd >= 0);
//    char buffer[20];
//    sprintf(buffer, "hello world\n");
//    int rc = write(fd, buffer, strlen(buffer));
//    assert(rc == (strlen(buffer)));
//    fsync(fd);
    close(fd);
    return 0;
}
