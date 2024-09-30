#include "Base.hpp"

Base*	generate(void)
{
	int roll;
	srand(time(0));
	roll = rand() % 100;
	if (roll <= 33)
	{
		std::cout << "Generating A" << std::endl;
		return new A;
	}
	else if (roll > 33 && roll <= 66)
	{
		std::cout << "Generating B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Generating C" << std::endl;
		return new C;
	}
}

void	identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
		std::cout << "Identified p pointer as A" << std::endl;	
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "Identified p pointer as B" << std::endl;	
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "Identified p pointer as C" << std::endl;	
	else	
		std::cout << "Unidentified p pointer" << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified p ref as A" << std::endl;
	}
	catch (const std::exception& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "Identified p ref as B" << std::endl;
		}
		catch (const std::exception& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "Identified p ref as C" << std::endl;
			}
			catch (const std::exception& e){
				std::cout << "Unidentified p reference" << std::endl;
			}
		}
	}
}

int	main(void)
{
	Base *p1 = generate();
	identify(p1);
	identify(*p1);
	Base *p2 = generate();
	identify(p2);
	identify(*p2);
	Base *p3 = generate();
	identify(p3);
	identify(*p3);
	delete p1;
	delete p2;
	delete p3;
}
