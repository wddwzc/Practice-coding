/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        aux.resize(n);
        counter.resize(n);
        index.resize(n);
        for (int i = 0; i < n; i++) index[i] = i;
        //归并排序并统计
        mergeAndCount(nums, 0, n - 1);
        //遍历获取统计结果
        for (int i = 0; i < n; i++) {
            res.push_back(counter[i]);
        }
        return res;
    }
    //归并排序入口
    void mergeAndCount(vector<int> &nums, int l, int r) {
        if (l == r) return;
        int m = l + (r - l) / 2;
        mergeAndCount(nums, l, m);
        mergeAndCount(nums, m + 1, r);
        //检查已排序的部分
        if (nums[index[m]] > nums[index[m + 1]]) {
            sortAndCount(nums, l, m, r);
        }
    }
    //子数组排序并统计
    void sortAndCount(vector<int> &nums, int l, int m, int r) {
        for(int i = l; i <= r; i++) aux[i] = index[i];
        int i = l, j = m + 1;
        for (int k = l; k <= r; k++) {
            if (i > m) {
                index[k] = aux[j++];
            } else if (j > r) {
                index[k] = aux[i++];
                //排序的是索引数组，仍然可以通过索引找到原来数组中的元素，并更新统计值
                //右边先走完，那么右边的都是逆序
                counter[index[k]] += (r - m);
            } else if (nums[aux[i]] <= nums[aux[j]]) {
                index[k] = aux[i++];
                //插入左边的元素时，统计已经产生的逆序部分
                counter[index[k]] += (j - m - 1);
            } else {
                index[k] = aux[j++];
            }
        }
    }

    vector<int> index;
    vector<int> aux;
    vector<int> counter;
}

// @lc code=end


// 暴力方法超时


// 二分查找   倒序遍历，构建有序序列（题解）
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted, counts(n);
        for (int i = n - 1; i >= 0; --i) {
            int ind = binarySearch(sorted, nums[i]);
            counts[i] = ind;
            sorted.insert(sorted.begin() + ind, nums[i]);
        }
        return counts;
    }

    int binarySearch(vector<int> &arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                right = mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            } 
            else if (arr[mid] > target) {
                right = mid;
            }
        }
        return left;
    }
};

// 二分查找  倒序遍历  构建有序序列
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n);
        for (int i = n - 1; i>=0; --i) {
            counts[i] = binarySearch(orderedList, nums[i]);
            orderedList.insert(orderedList.begin() + counts[i], nums[i]);
        }
        return counts;
    }

    int binarySearch(vector<int>& ordered, int target) {
        int lo = 0, hi = ordered.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == ordered[mid]) {
                hi = mid;
            }
            else if (target < ordered[mid]) {
                hi = mid;
            }
            else if (target > ordered[mid]) {
                lo = mid + 1;
            }
        }
        return lo;
    }
    vector<int> orderedList;
};


// 离散化树状数组（题解）
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        Discretization(nums);
        counts.resize(nums.size() + 1, 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int id = getId(nums[i]);
            res[i] = Query(id - 1);
            Update(id);
        }
        return res;
    }

private:
    vector<int> counts, numbers;
    int LowBit(int x) {
        return x & (-x);
    }
    void Update(int pos) {
        while (pos < counts.size()) {
            counts[pos] += 1;
            pos += LowBit(pos);
        }
    }
    int Query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += counts[pos];
            pos -= LowBit(pos);
        }
        return ret;
    }
    void Discretization(vector<int>& nums) {
        numbers.assign(nums.begin(), nums.end());
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    }
    
    int getId(int x) {
        return lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1;
    }
};