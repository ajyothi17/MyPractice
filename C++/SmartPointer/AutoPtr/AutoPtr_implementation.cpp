#include <iostream>
#include <stdlib.h>

using namespace std;

class Test1
{
	private:
		Test1()
		{

		}
		
		~Test1()
		{
		
		}

	public:
		static Test1* createObj()
		{
			cout << "In test1 create" << endl;
			return new Test1();
		}
		static void deleteObj(Test1* obj)
		{
			cout << "In test1 delete" << endl;
			delete obj;
		}
};

template <typename T>
class AutoPtr
{
	private:
		void* operator new(size_t size)
		{
			return malloc(size);
		}

		void operator delete(void *test)
		{
			free(test);
		}

		T *ptr;
	public:
		AutoPtr()
		{
			cout << "In test2 const" << endl;
			ptr = T :: createObj();
		}
	
		AutoPtr (AutoPtr &) = delete; // In order to avoid memory leak caused by copy constructor
		AutoPtr operator=(AutoPtr &) = delete;
		
		~AutoPtr()
		{
			cout << "In test2 dest" << endl;
			T :: deleteObj(ptr);
		}
};

int main(void)
{
//	Test1 *test = Test1 :: createObj();

//	Test1 :: deleteObj(test);


	AutoPtr <Test1>obj; //= new Test2();
//	Test2 *obj2 = new Test2();
	AutoPtr <Test1>obj2 = obj;

//	obj = obj2;

	return 0;
}
