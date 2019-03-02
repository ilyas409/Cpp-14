#include <vector>
#include <string>
#include <algorithm>

namespace utils{
  template <class T>
  T max(const std::vector<T> &v){
    return *std::max_element(v.begin(), v.end());
  }
  template <size_t size, class T>
  T max(const T(&a)[size]){
    return *std::max_element(a, a + size);
  }
  
  std::vector<std::string> split(const std::string &input,
                                 char delimeter = ' '){
    std::vector<std::string> res;
    std::string temp = "";
    for (const char& c : input){
      if (c == delimeter){
        res.push_back(temp);
        temp.erase();
      } else {
        temp += c;
      }
    }
    if (temp.size() > 0){
      res.push_back(temp);
    }
    return res;
  }
  
};
