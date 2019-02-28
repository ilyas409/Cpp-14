#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <array>
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
        own::print(";");
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
        if (m.size() == 0) return;
        print(m.size()); print(" x "); print(m[0].size());
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
     @brief: prints an unordered set with a generic type
     */
    template <class T>
    void print(const std::unordered_set<T> us){
        own::print("{");
        for (auto &e : us){
            own::print(e);
            own::print(", ");
        }
        own::print("}\n");
    }
    
    void print(const int *arr[]){
        own::print(*arr[0]);
        own::print("\n");
    }
    
    template <size_t rows, size_t cols>
    void print(int (&array)[rows][cols]){
        print(rows); print(" x "); print(cols);
        print("\n");
        for (size_t i = 0; i < rows; ++i){
            std::cout << i << ": ";
            for (size_t j = 0; j < cols; ++j)
                std::cout << array[i][j] << '\t';
            std::cout << std::endl;
        }
    }
    
};
int main() {
   
    std::vector<int> v(3, 1);
    own::print("\nvector:\n");
    std::fill(v.begin(), v.end(), 0);
    own::print(v);
    
    std::vector<std::vector<int>> matrixVector(3, {1,2,3});
    own::print("\n2d vector:\n");
    own::print(matrixVector);

    std::unordered_map<int, std::string> um = {{10, "a"},{20, "b"}};
    own::print("\nunordered map:\n");
    own::print(um);

    std::unordered_set<int> us = {10, 20, 30};
    own::print("\nunordered set:\n");
    own::print(us);

    own::print("\n2d array:\n");
    int matrixArray[3][3];
    memset(matrixArray, 0, sizeof(matrixArray[0][0]) * 3 * 3);
    own::print(matrixArray);
    
    int matrixArray2[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    
    own::print(matrixArray2);
    
}
