#include <stdio.h>
int main ()
{
     int temp,i;
     double a=2.4568;
    unsigned char b[5];
	 for(i=0;i<5;i++)
	 {
			 temp=(int)a;    
			 b[i]=temp+'0';
			  a=(a-temp)*10;
			  printf("%.20f %d\n",a,(int)a);
	 }
			 b[5]='\0';
			 puts(b);
	 getchar();
}