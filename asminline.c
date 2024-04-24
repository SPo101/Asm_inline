int int_to_char(char *str, int x){
	int n = x;
	int len = 0;
	while(x>1){
		x /= 10;
		len++;
	}
	int prev_digit=0;
	int digit;
	int tens;
	for(int i=0; i<len; i++){
		tens = 1;
		for(int j=0; j<len-1-i; j++)
			tens *= 10;
		digit = (n/tens)-prev_digit;
		*(str+i) = (char) digit+0x30;
		prev_digit = n/tens*10;
	}
	return 0;
}


int main() {
	char s[6];
	int_to_char(s, 43512);
	s[5] = '\n';
	write(1, s, 6);

	int add1 = 1;
	int add2 = 2;
	int add3 = 3;
	int res;

	asm (	"add %%ebx, %%eax;"
		"add %%ecx, %%eax;"
    		: "=a" (res)
   		: "a" (add1), "b" (add2), "c" (add3)
	);

	char *buff1 = "hello1\n";
	char *buff2 = "hello2\n";
	write(1, buff1, 7);
	int ret;
	asm (
		"syscall"
		: "=a" (ret)
		: "a" (1), "D" (1), "S" (buff2), "d" (7)
		:
	);

	asm ( 
		"syscall"
		: 
		: "a" (60), "d" (1)
		:
	);

	write(1, "wont see this", 13);
}
