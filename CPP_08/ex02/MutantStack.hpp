#ifndef MUTANT_STACK
#define MUTANT_STACK

template <typename T>
class Mutant
{
	private:

	public:
		Mutant();
		Mutant(const Mutant &src);
		Mutant& operator=(const Mutant &src);
		~Mutant();

		//Element access
		void top(T elem); //peek at top element/last thing inserted

		//Capacity
		void empty(); //check if empty
		void size();

		//Modifiers
		void push(T elem); //push on top
		void pop(); //remove from top (LIFO restriction) //call pop back
		void push_range(); //c++23 - should implement?
		void emplace(); //c++11 - should implement?
		void swap(); //c++11 - should implement?

		//returns iterator
		void begin();
		void end();


};

#endif