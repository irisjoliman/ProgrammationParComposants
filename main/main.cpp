
#include <iostream>
/*#include "Composant1.h"
#include "Composant2.h"*/
#include <dlfcn.h>
int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;
	void *  hndl1;
	void *  hndl2;
	int (*fptr)(int );
	int (*fptr2)(int );

	hndl1 = dlopen("./lib/libComposant1.so",RTLD_LAZY);
	hndl2 = dlopen("./lib/libComposant2.so",RTLD_LAZY);

	fptr = dlsym(hndl1,"composant1(data1,data2)");
        fptr2 = dlsym(hndl2,"composant2(data1,data2)");
	
	std::cout <<  (*fptr);
	std::cout <<  (*fptr2);
	//std::cout << dlsym(hndl1,"getComposant1Version()") << std::endl;
	//std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}
