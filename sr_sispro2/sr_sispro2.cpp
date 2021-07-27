#include <iostream>

using namespace std;

int main()
{
	short N, K, res_asm = 0;
	int res_cpp = 0;
	cin >> N >> K;
	__asm {
		mov ax, N; ax = N
		mov bx, 0; bx = 0
		xor cx, cx;
		mov cx, 2; cx = 2
	begin_loop:
		cwd; расширяем word для деления
		idiv сx; ax/cx
		cmp bx, dx; сравним bx и остаток от деления
		jg loop_; 
		mov bx, dx; bx = остатку от деления
	loop_:
		inc cx;
		cmp cx, K; сравним ax и K
		jg begin_loop; если 1 операнд > 2
		jmp END;
	END:
		mov bx, cx; результат из cx
	}
}