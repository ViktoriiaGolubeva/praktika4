#include <8051.h> 
unsigned char* init()
{
	unsigned char array[6];
	array[0]=0x0; 
	array[1]=0x20;  //T=1s 
	array[2]=0x4;  //T=1s 
	array[3]=0x18; //T=3s 
	array[4]=0x42;  //T=5s 
	array[5]=0x81;  //T=7s 
	return array;
} 

void msec (int x)  
{
	while(x-->0) 
	{
		TH0 = (-10000)>> 8;  
		TL0= (-10000); 
		TR0=1; 
		do;
		while(TF0==0);  
		TF0=0; 
		TR0=0;  
	}
}

void main() 
{
	int i;
	unsigned char*array = init();
	TMOD=0x1;
	while(100)
	{
		P1=array[0]; 
		msec(1);//1 sec
		for(i=1;i<=17;i++) 
		{
			if(i<=1) P1=array[1];
			else if(i<=2 && i >1) P1=array[2];
			else if(i<=5 && i >2) P1=array[3];
			else if(i<=12 && i >5) P1=array[4];
			else P1=array[5];			 
			msec(100);//1 sec 
		}	
	}
}
