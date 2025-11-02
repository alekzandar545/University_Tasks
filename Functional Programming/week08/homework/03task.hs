-- Description:

-- Define two functions - mergeLinearRec and mergeXs, that accept two sorted lists and combine them into one that is also sorted.

-- Acceptance criteria:

-- Add one new test case. Place a comment after it with the words my test.
-- All tests pass.
-- mergeLinearRec is defined using a linearly recursive process.
-- mergeXs is not recursive.
-- mergeXs is defined on a single line.
import Data.List

main :: IO()
main = do
    print $ mergeLinearRec [1, 2, 3] [2, 3, 4, 5, 6] == [1, 2, 3, 4, 5, 6]
    print $ mergeLinearRec [1, 2, 3] [2] == [1, 2, 3]
    print $ mergeLinearRec [1, 2, 3] [7, 8, 9] == [1, 2, 3, 7, 8, 9]
    print $ mergeLinearRec [2, 3, 4, 5, 6] [1, 2, 3] == [1,2,3,4,5,6]
    print $ mergeLinearRec [2] [1, 2, 3] == [1,2,3]
    print $ mergeLinearRec [7, 8, 9] [1, 2, 3] == [1,2,3,7,8,9]
    print $ mergeLinearRec [7, 9, 11] [8, 10, 12] == [7,8,9,10,11,12]
    print $ mergeLinearRec [7, 9, 11] [8, 10, 12, 13] == [7,8,9,10,11,12,13] --my test
    
    print $ mergeXs [1, 2, 3] [2, 3, 4, 5, 6] == [1, 2, 3, 4, 5, 6]
    print $ mergeXs [1, 2, 3] [2] == [1, 2, 3]
    print $ mergeXs [1, 2, 3] [7, 8, 9] == [1, 2, 3, 7, 8, 9]
    print $ mergeXs [2, 3, 4, 5, 6] [1, 2, 3] == [1,2,3,4,5,6]
    print $ mergeXs [2] [1, 2, 3] == [1,2,3]
    print $ mergeXs [7, 8, 9] [1, 2, 3] == [1,2,3,7,8,9]
    print $ mergeXs [7, 9, 11] [8, 10, 12] == [7,8,9,10,11,12]
    print $ mergeXs [7, 9, 11] [8, 10, 12, 13] == [7,8,9,10,11,12,13] --my test

-- without helper
mergeLinearRec :: [Int] -> [Int] -> [Int]
mergeLinearRec [] [] = []
mergeLinearRec xs [] = xs
mergeLinearRec [] ys = ys
mergeLinearRec (x:xs) (y:ys)
    | x > y = y : mergeLinearRec (x:xs) ys
    | x < y = x : mergeLinearRec xs (y:ys)
    | otherwise = x : mergeLinearRec xs ys 

mergeXs :: [Int] -> [Int] -> [Int]
mergeXs xs ys = sort $ nub $ xs ++ ys