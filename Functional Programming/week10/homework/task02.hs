import Data.List

main::IO()
main = do
    -- you may get slightly different results eg. [3, 4, 5] on test 1 <- not a problem
    print $ listLeaves [(1, 2, 3), (2, 4, 5)] -- == [4, 3, 5]
    print $ listLeaves [(2, 4, 5), (1, 2, 3)]-- == [4, 5, 3]
    print $ listLeaves [(1, 2, 3), (3, 4, 5), (5, 6, 9)] -- == [2, 4, 6, 9]
    print $ listLeaves [] == [] -- my test

type BinaryTree = [(Int, Int, Int)]

listLeaves :: BinaryTree -> [Int]
listLeaves tree = nub $ concat [[x, y] | (x,y,z) <- tree, notParent y]
  where
    notParent d = notElem d $ map (\ (x,y,z) -> x) tree