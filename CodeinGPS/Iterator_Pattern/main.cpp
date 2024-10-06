#include<vector>
#include<iostream>
#include<iterator>
#include<unordered_map>

int main(){
	//Create a vector 
	std::vector<int> ints {0,1,2,3,4,5,6,7,8,9};

	// std::cout << "Traditional for loop" << std::endl;
	// for(int i = 0; i < 10; i++){
	// 	std::cout << ints[i] << ";";
	// }
	// std::cout << std::endl << std::endl;;

	// std::cout << "Traditional for-loop (in reverse)" << std::endl;
	// for(int i = 9; i > 0; i--){
	// 	std::cout << ints[i] << ";";
	// }
	// std::cout << std::endl << std::endl;

	// std::cout << "Tranditional for-loop (Slightly improved)" << std::endl;
	// //This time, relying on "size"
	// for(int i = 0; i < ints.size(); i++) {
	// 	std::cout << ints[i] << ";";
	// } 
	// std::cout << std::endl << std::endl;

	// std::cout << "Avoid multiple queries to size" << std::endl;
	// // Tiny optimization for a std::vector, more important
	// // for any data structure without 0(1) lookeup for size.
	// int collectionSize_cached = ints.size();
	// for(int i - 0; i < collectionSize_cached; i++){
	// 	std::cout << ints[i] << ",";
	// }
	// std::cout << std::endl << std::endl;

	// std::cout << "Traditional for loop" << std::endl;
	// for(int i = 0; i < ints.size(); i+=2){
	// 	std::cout << ints[i] << ";";
	// }
	// std::cout << std::endl << std::endl;;

	//Iterators
	// *it - means to read a value
	// ++it - means to advance 1 item
	//it == end(collection) - tests if we're done
	// std::cout << "iterator" << std::endl;
	// for(std::vector<int>::iterator it = ints.begin(); it != ints.end(); ++it){
	// 	std::cout << *it << ",";
	// 	(*it)++;
	// } 
	// std::cout<<std::endl<<std::endl;;


	// std::cout << "Const iterator" << std::endl;
	// for(std::vector<int>::const_iterator it = ints.cbegin(); it != ints.cend(); ++it){
	// 	std::cout << *it << ",";
	// 	(*it)++;
	// }
	// std::cout << std::endl << std::endl;;

	// std::cout << "Reverse iterator" << std::endl;
	// for(std::vector<int>::reverse_iterator it = ints.rbegin(); it != ints.rend(); ++it){
	// 	std::cout << *it << ",";
	// }
	// std::cout<<std::endl<<std::endl;;


	// std::cout << "Controlling advancing of iterators" << std::endl;
	// auto it = ints.begin();
	// //equivalent to 
	// //std::vector<int> it::iterator it = ints.begin();
	// while(it != ints.end()){
	// 	auto element = std::next(it,0);	// Return element at current position
	// 									// 1 would give us the next element
	// 									// 2 would give us 2 elements later
	// 									// etc.
	// 	std::cout << *element << ",";	// Display to the user

	// 	std::advance(it,1);				//equivalent to it++
	// }
	// std::cout << std::endl << std::endl;;

	//Ranged based loops in C++ and beyond
	// Able to do this because of iterators
	// std::cout << "Ranged-based for loops" << std::endl;
	// for(const auto e : ints){
	// 	//Note: You can use int e instead since we know the element
	// 	// for larger objects, I recommend 'const auto& e'
	// 	std::cout << e << " ";	
	// }
	// std::cout << std::endl << std::endl;

	std::cout << "unordered_map iterator example" << std::endl;
	//Create a less trivial data structure
	//Where we don't have random access
	std::unordered_map<std::string,int> people;
	// Add a few people to our map with keys of 'string' and values of 'int'
	people["Tancho"] = 2510;
	people["Rozey"] = 2212;

	using peopleiterator = std::unordered_map<std::string, int>::iterator;

	for(peopleiterator it2 = people.begin(); it2 != people.end(); ++it2){
		std::cout << it2 -> first << " - " << it2->second << std::endl;
	}
	std::cout << std::endl << std::endl;

}