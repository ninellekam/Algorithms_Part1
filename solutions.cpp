#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
# 1: Urlencode
Replace all spaces in the given string by "%20" inplace.
Example: "Hello nigga " -> "Hello%20nigga%20"
*/
void urlencode(std::string& s) {
  const auto spaces_count = std::count(s.begin(), s.end(), ' ');

  int old_size = s.size();
  s.resize(s.size() + spaces_count * 2);

  int write_pos = s.size() - 1;
  for (int i = old_size - 1; i >= 0; --i) {
    if (s[i] != ' ') {
      s[write_pos--] = s[i];
    } else {
      s[write_pos--] = '0';
      s[write_pos--] = '2';
      s[write_pos--] = '%';
    }
  }
}

/*
# 2: Find shit index
Given a sorted (asc order) array of unique integers which was cyclically shifted
to the right for K positions. Find minimum K.

Example: [3, 4, 1, 2] -> 2
Example: [2, 3, 4, 1] -> 3
Example: [1, 2, 3, 4] -> 0
*/
int find_shift_index(const std::vector<int>& arr) {
  if (arr.size() < 2) {
    return 0;
  }

  int low = 0, high = arr.size() - 1;
  while (low < high) {
    int mid = low + (high - low) / 2;
    // rotation exists
    if (arr[mid] > arr[high]) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}


/*
# 3: Remove duplicates from sorted array
Example: [1, 1, 2, 3, 3, 4] -> [1, 2, 3, 4]
*/
void remove_duplicates(std::vector<int>& arr) {
    if(arr.size() < 2) {
        return;
    }
    int unique_index = 0;
    for(int i = 1; i < arr.size(); ++i) {
        if(arr[unique_index] != arr[i]) {
            arr[++unique_index] = arr[i];
        }
    }
    arr.erase(arr.begin() + unique_index + 1, arr.end());
}


/*
# 4: Write shared ptr (without thread-safe control block)
*/
template<typename T>
class shared_ptr {
private:
    struct control_block_t {
        T* data_pointer_;
        std::size_t ref_count_;        
    };

control_block_t* control_block_;

public:
    shared_ptr() = delete; // should be, but doesn't matter

    shared_ptr(T* ptr) : control_block_(new control_block_t{ptr, 1}) {}

    ~shared_ptr() {
        if(--this->control_block_->ref_count_ == 0) {
            delete this->control_block_->data_pointer_;
            delete this->control_block_;
        }
    }

    shared_ptr(const shared_ptr& other) {
        this->control_block_ = other.control_block_;
        ++this->control_block_->ref_count_;
    }

    shared_ptr& operator=(const shared_ptr& other) {
        if(this == &other) {
            return *this;
        }
        this->~shared_ptr();
        this->control_block_ = other.control_block_;
        ++this->control_block_->ref_count_;
        return *this;
    }
    
    T& operator*() {
        return *this->control_block_->data_pointer_;
    }
    T* operator->() {
        return this->control_block_->data_pointer_;
    }

    shared_ptr(shared_ptr&&) = delete; // Almost the same as copying
    shared_ptr& operator=(shared_ptr&&) = delete; // Almost the same as copying
};


/*
# 5: Reverse linked list
*/
struct ListNode {
    int val;
    ListNode* next;
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, *cur = head, *next = nullptr;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/*
# 6: Remove smiles from string inplace.
Smiles example :-), :-)), :-)))..., :-(, :-((, ...

Example: 
"::-))-"  ->  ":)"
*/

void remove_smiles(std::string& str) {
  int write_pos = 0;
  const char* s = str.c_str();
  while (*s) {
    if (*s == ':' && *(s + 1) == '-' && (*(s + 2) == ')' || *(s + 2) == '(')) {
      char bracket = *(s + 2);
      s += 3;
      while (*s == bracket) {
        ++s;
      }
    } else {
      str[write_pos++] = *s;
      s += 1;
    }
  }
  str.erase(str.begin() + write_pos, str.end());
}


/*
# 7: Subarray with zero sum.
Given an array. Return subarray begin and end indices of this array which has zero sum
Example: [1, 2, 3, -1, -2, 5] -> {2, 4}
*/

std::pair<int, int> subarray_with_zero_sum(const std::vector<int>& arr)  {
    std::unordered_map<int, int> mp; // sum of subarray [0, i] -> i
    mp[0] = 1;

    int sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        const auto it = mp.find(sum);
        if(it != mp.end()) {
            return {it->second + 1, i};
        } else {
            mp[sum] = i;
        }
    }

    return {-1, -1};
}

int main() {
  // # 1
  std::string s = " hello  a ";
  urlencode(s);
  std::cout << "Urlencode test: " << s << std::endl;

  // # 2
  std::vector<int> v1 = {3, 4, 1, 2};
  std::cout << "Find shit index test: " << find_shift_index({3, 4, 1, 2})
            << "  " << find_shift_index({1, 2, 3, 4, 5}) << "  "
            << find_shift_index({2, 3, 4, 5, 1}) << std::endl;

  // # 3
  std::vector<int> v2{1, 1, 2, 3, 3, 4};
  remove_duplicates(v2);
  std::cout << "Remove duplicates test: ";
  for(int elem : v2) {
      std::cout << elem << "  ";
  }
  std::cout << std::endl;

  // # 4
  shared_ptr<int> ptr(new int{5});
  auto ptr2(ptr);
  shared_ptr<int> ptr3 = ptr2;
  ptr2 = ptr3;
  std::cout << *ptr2 << std::endl;


  // # 6
  std::string smiles = "aaa:-)))bb-))cc:-()()(dd--:-:-)";
  remove_smiles(smiles);
  std::cout << "Remove smiles test: " << smiles << std::endl;

  // # 7
  std::vector<int> v4{1, 2, 3, -1, -2, 4};
  const auto& pr = subarray_with_zero_sum(v4);
  std::cout << "Subarray with zero sum: " << pr.first << "  " << pr.second << std::endl;
  return 0;
}