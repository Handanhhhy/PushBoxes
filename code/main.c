#include"function.h"



int main()
{
	init();
	initmap();
	interf(1);
	interf(2);
	while (1)
	{
		update();
		render();
	}
	return 0;
}