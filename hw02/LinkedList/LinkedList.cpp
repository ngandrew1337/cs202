#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include <string>
#include <memory>
#include <list>


using std::cout;
using std::endl;
using std::string;
using std::list;
using std::shared_ptr;


struct Value
{
	Value() : str1_("a"), str2_("a"), str3_("a"), int1_(0), int2_(0), int3_(0)
	{};

	Value(const string& ns1, const string& ns2, const string& ns3, const int& ni1, const int& ni2, const int& ni3)
	: str1_(ns1), str2_(ns2), str3_(ns3), int1_(ni1), int2_(ni2), int3_(ni3)
	{};

	string str1_;
	string str2_;
	string str3_;
	int int1_;
	int int2_;
	int int3_;
};


void printList(const list<shared_ptr<Value>>& list) {
	for (auto v : list) {
		cout << (*v).str1_ << "\n";
	}
	cout << "\n";
}


TEST_CASE("Linked List Operations", "[LinkedList]") {
	list<std::shared_ptr<Value>> testList;

	shared_ptr<Value> sPtr1 = std::make_shared<Value>();
	shared_ptr<Value> sPtr2 = std::make_shared<Value>("b", "b", "b", 1, 1, 1);
	testList.push_back(sPtr1);
	testList.push_back(sPtr2);

	printList(testList);

	REQUIRE((*testList.back()).str1_ == "b");

	
}