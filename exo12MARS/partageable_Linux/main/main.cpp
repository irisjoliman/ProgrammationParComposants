
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>


int main(int argc, char ** argv)
{
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;
	void *  hndl1;
	void *  hndl2;
	int (*fptr)(int, int);
	int (*fptr2)(int, int);
 	char * (*fptr1)();
	hndl1 = dlopen("./libComposant1.so",RTLD_LAZY);
	hndl2 = dlopen("./libComposant2.so",RTLD_LAZY);

	*(void **)(&fptr) = dlsym(hndl1,"composant1");
        *(void **)(&fptr1) = dlsym(hndl1,"getComposant1Version");
	*(void **)(&fptr2) = dlsym(hndl2,"composant2");
	
	valeur1 =   (*fptr)(data1, data2);
	valeur2 =  (*fptr2)(data1, data2);
	std::cout << (*fptr1)() << std::endl;
	dlclose(hndl1);
        dlclose(hndl2);
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}
