#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>  // std::pair, std::make_pair
namespace own{
    /**
     @brief: prints a single element
    */
    template <class T>
    void print(const T &v){
        std::cout << v;
    }
    
    /**
     @brief: prints a pair
     */
    template <class T, class TT>
    void print(const std::pair<T, TT> &pair){
        own::print(pair.first);
        own::print(": ");
        own::print(pair.second);
        own::print("; ");
    }
    /**
     @brief: prints a vector element
    */
    template <class T>
    void print(const std::vector<T> &v){
        for (auto &e : v){
            own::print(e);
            own::print(", ");
        }
        std::cout << std::endl;
    }
    /**
     @brief: prints a matrix (vector of vectors)
    */
    template <class T>
    void print(const std::vector<std::vector<T>> &m){
        for (auto &v : m){
            own::print(v);
        }
    }
    /**
     @brief: prints an unordered map with generic types
     */
    template <class T, class TT>
    void print(const std::unordered_map<T, TT> um){
        own::print("{");
        for (auto &pair : um){
            own::print(pair);
        }
        own::print("}");
    }
    /**
     @brief: prints an unordered map with a generic type
     */
    template <class T>
    void print(const std::unordered_set<T> us){
        own::print("{");
        for (auto &e : us){
            own::print(e);
            own::print(", ");
        }
        own::print("}");
    }
};

class Generic{
public:
   
};

int main() {
    std::vector<std::vector<int>> matrix(10, {1,2,3});
    own::print("matrix:\n");
    own::print(matrix);
    
    std::vector<int> v(3, 1);
    own::print("vector:\n");
    own::print(v);
    
    std::fill(v.begin(), v.end(), 0);
    own::print(v);
    
    std::unordered_map<int, std::string> um = {{10, "a"},{20, "b"}};
    own::print("unordered map:\n");
    own::print(um);
    
    std::unordered_set<int> us = {10, 20, 30};
    own::print("unordered set:\n");
    own::print(us);
    
}
