#include<fcntl.h>
int main() {
	mknod("./1c_fifo", S_IFIFO | 0744, 0);
}
