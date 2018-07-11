# Easy Set

### 1.IO加速
```c++
// 全局匿名函数
static const auto __________ = []()
{
  ios::sync_with_stdio(false); // 关闭cin与stdin的同步，减小io延时
  cin.tie(nullptr); // 关于cin与cout的绑定，减小<<的flush
  return nullptr;
}();  // 定义后执行
```

### 2.HashMap减少重复计算
- 题目：[Two Sum](1.two-sum.cpp)  O(n^2) → O(n)
- 反向索引：当值很小时，使用数组角标，当值很多时，使用HashMap(unordered_map)
```c++
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    using SizeType = remove_reference_t<decltype(nums)>::size_type;
    // 把历史存入hashmap，避免重复计算
    using ValueToIndexMapType = unordered_map<int, SizeType>;
    ValueToIndexMapType map;
    for (SizeType index = 0; index < nums.size(); ++index)
    {
      const auto foundIterator = map.find(target - nums[index]);
      if (foundIterator != end(map) && foundIterator->second != index)
        return vector<int>{ index, foundIterator->second };
      else
        map.emplace(nums[index], index);    
    }
    throw std::runtime_error("Solution not found");
  }
};
```

### 3.回文数判断：只逆序一半
- 题目：[Palindrome Number](9.palindrome-number.cpp) 
```c++
// 负数不可能是回文数
// 数不可能以零开头，所以非零回文数不可能以0结尾
// 只逆序后面一半，然后与前面一半做对比
class Solution {
public:
  bool isPalindrome(int x) {
    // 注意极端情况
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;

    int reverted = 0;
    while (x > reverted) {
      reverted = reverted * 10 + x % 10;
      x /= 10;
    }
    return (x == reverted || x == reverted / 10);
  }
};
```

### 4.交替记录：二元动规(抢/没抢)
- 题目：[House Robber](198.house-robber.cpp)
```c++
class Solution {
public:
  int rob(vector<int>& nums) {
    int a = 0, b = 0;
    for (std::size_t i = 0; i < nums.size(); i++) {
      // a, b 交替记录最大抢劫金额。(状态：抢/没抢)
      if (i % 2  == 0)
        a = max(a + nums[i], b);
      else
        b = max(b + nums[i], a);
    }
    return max(a, b);
  }
};
```

### 5.利用数组自身记录状态
- 题目：[Find All Numbers Disappeared in an Array](448.find-all-numbers-disappeared-in-an-array.cpp)
```c++
// 特殊要求：时间复杂度O(n)，无额外空间消耗
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    size_t size = nums.size();
    // use the vector itself to mark if numbers has appeared
    // negative if appeared else positive.
    for (size_t i = 0; i < size; i++) {
      size_t index = abs(nums[i]) - 1;
      if (nums[index] > 0)
        nums[index] = -nums[index];
    }
    vector<int> result;
    for (size_t i = 0; i < size; i++) {
      if (nums[i] > 0)
        result.push_back(i + 1);
    }
    return result;
  }
};
```

### 6.统计二进制1的个数
- 题目：[Hamming Distance](461.hamming-distance.cpp)
```c++
class Solution {
public:
  int hammingDistance(int x, int y) {
    int diff = x ^ y, dist = 0;
    while (diff) {
      diff = diff & (diff - 1);
      dist++;
    }
    return dist;
  }
};
```

### new code
[438] Find All Anagrams in a String
[437] Path Sum III
[66] Plus One