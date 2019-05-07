#include <thread>
#include <chrono>
#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

struct Point
{
int x, y;
Point() {std::cout << this << " Point ctor is called.\n";}
~Point() {std::cout << this << " Point dtor is called.\n";}
};

typedef int*(*FP_GET)();
typedef void(*FP_SET)(int);
typedef Point*(*FPOINT_SET)();

void thread_fun(void *dll_handle)
{
	std::cout << "thread_fun\n";
	//std::cout << "1 thread: " << get_local_point() << std::endl;
	FP_GET fp_get = NULL;
	FP_SET fp_set = NULL;
	FPOINT_SET fpoint_get = NULL;
	fp_get = (FP_GET)dlsym(dll_handle, "get_local_error_no");
	fp_set = (FP_SET)dlsym(dll_handle, "set_local_error_no");
	fpoint_get = (FPOINT_SET)dlsym(dll_handle, "get_local_point");
	if(fp_set && fp_get && fpoint_get) {
		fp_set(3);	
		std::cout << "thread: " << fp_get() << ": " << *(fp_get()) << std::endl;
		std::cout << "thread: " << fpoint_get() << std::endl;
	}
	else
		std::cerr << "dll parse failed " << dlerror() << std::endl;
}


int main()
{
	std::cout << "Begin main:\n";
	void *dll_handle = dlopen("libdllexport.so", RTLD_LAZY);
	if(!dll_handle)	
		std::cerr << "Cannot open lib: " << dlerror() << std::endl;
	std::thread f1(thread_fun, dll_handle);
	std::thread f2(thread_fun, dll_handle);	
	f1.join();
	f2.join();
	if(dlclose(dll_handle))
		std::cerr << "dll close failed " << dlerror() << std::endl;
	pause();
}
