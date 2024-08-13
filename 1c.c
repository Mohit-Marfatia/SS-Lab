#include<fcntl.h>
int main() {
	mknod("./1c_fifo", 0744, 0);
}
