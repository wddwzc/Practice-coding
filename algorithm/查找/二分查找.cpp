// 二分查找：在list中查找key，返回其索引
public static <T> int binarySearch(List<? extends Comparable<? super T>> list, T key) {
    if(list instanceof RandomAccess || list.size()<BINARYSEARCH_THRESHOLD) {
        return Collections.indexedBinarySearch(list, key);
    } else {
        return Collections.iteratorBinarySearch(list, key);
    }
}
private static <T> int indexedBinarySearch(List<? extends Comparable<? super T>> list, T key) {
        int low = 0;
        int high = list.size() - 1;
        while(low<=high) {
            int mid = (low + high) >>> 1;
            Comparable<? super T> midVal = list.get(mid);
            int cmp = midVal.compareTo(key);
            if(cmp<0) {
                low = mid + 1;
            } else if(cmp>0) {
                high = mid - 1;
            } else {
                return mid; // key found
            }
        }
        return -(low + 1);  // key not found
    }