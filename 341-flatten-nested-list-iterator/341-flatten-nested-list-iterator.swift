/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public func isInteger() -> Bool
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     public func getInteger() -> Int
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public func setInteger(value: Int)
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public func add(elem: NestedInteger)
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     public func getList() -> [NestedInteger]
 * }
 */

class NestedIterator {
    private var result: [Int] = []
    private var currIdx = 0;

    init(_ nestedList: [NestedInteger]) {
        result = getIntArrayFrom(list: nestedList)
    }
    
    func getIntArrayFrom(list: [NestedInteger]) -> [Int] {
        var result: [Int] = []
        result = list.flatMap { $0.isInteger() ? [$0.getInteger()] : getIntArrayFrom(list: $0.getList()) }
        return result
    }
    
    func next() -> Int {
        let ans = result[currIdx];
        currIdx += 1;
        return ans;
    }
    
    func hasNext() -> Bool {
        return currIdx < result.count;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * let obj = NestedIterator(nestedList)
 * let ret_1: Int = obj.next()
 * let ret_2: Bool = obj.hasNext()
 */