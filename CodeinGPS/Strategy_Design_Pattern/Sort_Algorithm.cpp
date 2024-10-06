#include<iostream>
#include <memory>

struct ISorts{
	~ISorts(){}

	virtual void Sort(/* container, params */) = 0;
};

struct InsertionSort : public ISorts{
	void Sort(/* container, params */) override {
		std::cout << "InsertionSort::Sort\n";
	}
};

struct BubbleSort : public ISorts{
	void Sort(/* container, param */) override{
		std::cout << "BubbleSort::Sort\n";
	}
};

void generic_sort(/*container, params */) {
	std::unique_ptr<ISorts> sorting_algo = std::make_unique<BubbleSort>();

	int collectionSize = 52;
	if(collectionSize < 16){
		sorting_algo = std::make_unique<BubbleSort>();
	} else if(collectionSize >= 16 && collectionSize <64){
		sorting_algo = std::make_unique<InsertionSort>();
	}
	sorting_algo->Sort();
}

bool unitest1(){
	std::vector some_vector{1,3,6,4,2,5};

	std::unique_ptr<ISorts> sorting_algo = std::make_unique<BubbleSort>();
	sorting_algo -> Sort;

	return std::is_sorted(some_vector.begin(), some_vector.end());
}

bool unitest2(){
	std::vector some_vector{1,3,6,4,2,5};

	std::unique_ptr<ISorts> sorting_algo = std::make_unique<InsertionSort>();
	sorting_algo->Sort();

	return std::is_sorted(some_vector.begin(), some_vector.end());
}

int main(){

	generic_sort(/* container, params */);

	return 0;
}

// //Execution Policy || Modern C++ design
// template< class ExcutionPolicy, class ForwardIt, class T, class BinaryOp>
// T reduce( ExcutionPolicy&& policy, 
// 	ForwardIt first, ForwardIt last, T init, BinaryOp binary_op );

// template<class RandomIt, class Compare>
// constexpr void sort_heap(RandomIt first, RandomIt last, Compare comp);

// template<
// class T,
// class Allocator = std::allocator<T>
// > class vector;
// namespace pmr {
// 	template<class T>
// 	using vector = std::vector<T, std::pmr::polymorphic_allocator<T>>;
// }