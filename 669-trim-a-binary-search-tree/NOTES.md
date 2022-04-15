### Idea:
​
`low <= valid node <= high`
​
if current node is less than low, then
* there is no point to go to it's left subtree
* we should replace it by it's right subtree, in which we may get valid node
* and do apply the same process with new root.
​
else if current node is more than high, then
* there is no point to go to it's right subtree
* we should replace it by it's left subtree, in which we may get valid node
* and do apply the same process with new root.
​
else current node is a valid node, we should check it's
* left subtree and trim it by same above process
* right subtree and trim it by the same process
​
else current node is a valid node