#include <iostream>

class Counter
{
	public:
		static int counter;

		Counter()
		{
		
		}
};

Counter :: counter = 0;

template <typename T>
class SharedPtr
{
	public:
		SharedPtr()
		{
			Counter :: counter++;
		}
};

int main(void)
{
	return 0;
}
