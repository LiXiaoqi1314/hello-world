#include <cstdio>
#include "RoundQueue.hpp"

int main()
{
	RoundQueue<> rq;
	
	char buf[300];
	for(int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 300; j ++)
			buf[j] = i;
		rq.enqueue(buf, 300);
	}

	while(rq.dequeue(buf, 300))
	{
		for(int i = 0 ; i < 300 ; i++)
		{
			printf("%d", buf[i]);
		}
		putchar(10);
	}

	return 0;
}