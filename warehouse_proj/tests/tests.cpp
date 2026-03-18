#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "item.hpp"
#include "safe_vector.hpp"
#include "item_comparator.hpp"

TEST_CASE("Item class tests", "[item]") {
    SECTION("Constructor and getters") {
        Item<int> item1(5, 100);
        REQUIRE(item1.getId() == 5);
        REQUIRE(item1.getValue() == 100);
        
        Item<int> item2;
        REQUIRE(item2.getId() == int());
        REQUIRE(item2.getValue() == int());
    }
    
    SECTION("Setter") {
        Item<int> item(1, 50);
        REQUIRE(item.getId() == 1);
        REQUIRE(item.getValue() == 50);
        
        item.setValue(75);
        REQUIRE(item.getValue() == 75);
        REQUIRE(item.getId() == 1);
    }
    
    SECTION("Different types") {
        Item<double> item1(1.5, 100.5);
        REQUIRE(item1.getId() == Catch::Approx(1.5));
        REQUIRE(item1.getValue() == Catch::Approx(100.5));
        
        Item<char> item2('A', 'B');
        REQUIRE(item2.getId() == 'A');
        REQUIRE(item2.getValue() == 'B');
        
        Item<std::string> item3("id1", "value1");
        REQUIRE(item3.getId() == "id1");
        REQUIRE(item3.getValue() == "value1");
    }
}

TEST_CASE("SafeVector basic operations", "[safevector]") {
    
    SECTION("Constructor and initial state") {
        SafeVector<int> vec;
        REQUIRE(vec.getSize() == 0);
    }
    
    SECTION("Push back and access") {
        SafeVector<int> vec;
        
        vec.pushBack(10);
        REQUIRE(vec.getSize() == 1);
        REQUIRE(vec.getIndex(0) == 10);
        
        vec.pushBack(20);
        vec.pushBack(30);
        REQUIRE(vec.getSize() == 3);
        REQUIRE(vec.getIndex(0) == 10);
        REQUIRE(vec.getIndex(1) == 20);
        REQUIRE(vec.getIndex(2) == 30);
    }
    
    SECTION("Vector growth") {
        SafeVector<int> vec;
        
        // Push many elements to trigger growth
        for(int i = 0; i < 100; i++) {
            vec.pushBack(i);
        }
        
        REQUIRE(vec.getSize() == 100);
        for(int i = 0; i < 100; i++) {
            REQUIRE(vec.getIndex(i) == i);
        }
    }
    
    SECTION("Modify elements") {
        SafeVector<int> vec;
        vec.pushBack(5);
        vec.pushBack(10);
        
        vec.getIndex(0) = 15;
        REQUIRE(vec.getIndex(0) == 15);
        REQUIRE(vec.getIndex(1) == 10);
    }
}

TEST_CASE("SafeVector with Item type", "[safevector][item]") {
    
    SECTION("Store Items") {
        SafeVector<Item<int>> items;
        
        items.pushBack(Item<int>(3, 100));
        items.pushBack(Item<int>(1, 50));
        items.pushBack(Item<int>(2, 100));
        items.pushBack(Item<int>(4, 25));
        
        REQUIRE(items.getSize() == 4);
        
        REQUIRE(items.getIndex(0).getId() == 3);
        REQUIRE(items.getIndex(0).getValue() == 100);
        
        REQUIRE(items.getIndex(1).getId() == 1);
        REQUIRE(items.getIndex(1).getValue() == 50);
        
        REQUIRE(items.getIndex(2).getId() == 2);
        REQUIRE(items.getIndex(2).getValue() == 100);
        
        REQUIRE(items.getIndex(3).getId() == 4);
        REQUIRE(items.getIndex(3).getValue() == 25);
    }
    
    SECTION("Modify Items in vector") {
        SafeVector<Item<int>> items;
        items.pushBack(Item<int>(1, 10));
        
        items.getIndex(0).setValue(20);
        REQUIRE(items.getIndex(0).getId() == 1);
        REQUIRE(items.getIndex(0).getValue() == 20);
    }
}

TEST_CASE("SafeVector move operations", "[safevector][move]") {
    
    SECTION("Move constructor") {
        SafeVector<int> vec1;
        vec1.pushBack(1);
        vec1.pushBack(2);
        vec1.pushBack(3);
        
        SafeVector<int> vec2(vec1); // Move constructor
        
        REQUIRE(vec2.getSize() == 3);
        REQUIRE(vec2.getIndex(0) == 1);
        REQUIRE(vec2.getIndex(1) == 2);
        REQUIRE(vec2.getIndex(2) == 3);
        
        // vec1 should be empty after move
        REQUIRE(vec1.getSize() == 0);
    }
    
    SECTION("Move assignment") {
        SafeVector<int> vec1;
        vec1.pushBack(1);
        vec1.pushBack(2);
        
        SafeVector<int> vec2;
        vec2.pushBack(10);
        
        vec2.moveAssignment(vec1);
        
        REQUIRE(vec2.getSize() == 2);
        REQUIRE(vec2.getIndex(0) == 1);
        REQUIRE(vec2.getIndex(1) == 2);
        
        // vec1 should be empty after move
        REQUIRE(vec1.getSize() == 0);
    }
    
    SECTION("Self move assignment") {
        SafeVector<int> vec;
        vec.pushBack(1);
        vec.pushBack(2);
        
        vec.moveAssignment(vec); // Should do nothing
        
        REQUIRE(vec.getSize() == 2);
        REQUIRE(vec.getIndex(0) == 1);
        REQUIRE(vec.getIndex(1) == 2);
    }
}

TEST_CASE("ItemComparator tests", "[comparator]") {
    
    SECTION("Compare by value then id") {
        ItemComparator<int> comp;
        
        Item<int> item1(1, 100);
        Item<int> item2(2, 100);
        Item<int> item3(1, 50);
        
        // Same value, compare by id
        REQUIRE(comp(item1, item2)); // 100,1 < 100,2
        REQUIRE_FALSE(comp(item2, item1));
        
        // Different values, compare by value
        REQUIRE(comp(item3, item1)); // 50,1 < 100,1
        REQUIRE_FALSE(comp(item1, item3));
        
        // Equal items
        Item<int> item4(1, 100);
        REQUIRE_FALSE(comp(item1, item4));
        REQUIRE_FALSE(comp(item4, item1));
    }
    
    SECTION("Sorting with comparator") {
        SafeVector<Item<int>> items;
        ItemComparator<int> comp;
        
        items.pushBack(Item<int>(3, 100));
        items.pushBack(Item<int>(1, 50));
        items.pushBack(Item<int>(2, 100));
        items.pushBack(Item<int>(4, 25));
        
        // Simple bubble sort using comparator
        for(size_t i = 0; i < items.getSize(); i++) {
            for(size_t j = i + 1; j < items.getSize(); j++) {
                if(comp(items.getIndex(j), items.getIndex(i))) {
                    auto temp = items.getIndex(i);
                    items.getIndex(i) = items.getIndex(j);
                    items.getIndex(j) = temp;
                }
            }
        }
        
        // Expected order: (4,25), (1,50), (2,100), (3,100)
        REQUIRE(items.getIndex(0).getId() == 4);
        REQUIRE(items.getIndex(0).getValue() == 25);
        
        REQUIRE(items.getIndex(1).getId() == 1);
        REQUIRE(items.getIndex(1).getValue() == 50);
        
        REQUIRE(items.getIndex(2).getId() == 2);
        REQUIRE(items.getIndex(2).getValue() == 100);
        
        REQUIRE(items.getIndex(3).getId() == 3);
        REQUIRE(items.getIndex(3).getValue() == 100);
    }
}

TEST_CASE("Edge cases", "[edge]") {
    
    SECTION("Empty vector operations") {
        SafeVector<int> vec;
        REQUIRE(vec.getSize() == 0);
        
        // Access should still work (though might be undefined behavior)
        // Not testing actual access as it would crash
    }
    
    SECTION("Single element") {
        SafeVector<int> vec;
        vec.pushBack(42);
        
        REQUIRE(vec.getSize() == 1);
        REQUIRE(vec.getIndex(0) == 42);
    }
    
    SECTION("Multiple push backs") {
        SafeVector<int> vec;
        
        for(int i = 0; i < 1000; i++) {
            vec.pushBack(i);
        }
        
        REQUIRE(vec.getSize() == 1000);
        REQUIRE(vec.getIndex(500) == 500);
        REQUIRE(vec.getIndex(999) == 999);
    }
}