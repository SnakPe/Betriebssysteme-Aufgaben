
#include <stdio.h>
float p = 0.00001;

float heron(float x, float a){
	float newA = (a+x/a)/2;
	 printf("Adresse von newA ist %p\n", (void*)&newA);
	if(newA*newA-x<p)return newA;
	return heron(x,newA);
}

float sqrt2(float x){
	return heron(x,1);
	
}

int main(int argc, char **argv)
{
	int test = 5423;
	printf("Die Quadratwurzel von %d lautet %.4f",4376427654613674132765467,sqrt2(test));
	return 0;
}
