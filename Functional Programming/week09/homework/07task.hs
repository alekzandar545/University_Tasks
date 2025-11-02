import Data.List

main :: IO()
main = do
    print $ isSorted [-5, -5, -6] == True
    print $ isSorted [1, 2, 3, 10, 100] == True --my test
    print $ isSorted [-5, -5, -4] == True
    print $ isSorted [1, 1, 1, 1, 1, 1, 1, 1, 1] == True
    print $ isSorted [1, 2, 3, 3, 3, 4, 5, 6, 6] == True
    print $ isSorted [1, -1, -3, -3, -3, -4, -5, -6, -6] == True
    print $ isSorted [1, 2, 3, 3, 3, 4, 5, 6, 5] == False
    print $ isSorted [-100, -99, -99, -99] == True
    print $ isSorted [-100, -99, -99, -99, 100] == True
    print $ isSorted [100, 101, -102] == False
    print $ isSorted [1, 2, 3, 4, 5, 6] == True
    print $ isSorted [-1, -2, -3, -4, -5, -6] == True

    print $ isSortedXs [-5, -5, -6] == True
    print $ isSortedXs [1, 2, 3, 10, 100] == True --my test
    print $ isSortedXs [-5, -5, -4] == True
    print $ isSortedXs [1, 1, 1, 1, 1, 1, 1, 1, 1] == True
    print $ isSortedXs [1, 2, 3, 3, 3, 4, 5, 6, 6] == True
    print $ isSortedXs [1, -1, -3, -3, -3, -4, -5, -6, -6] == True
    print $ isSortedXs [1, 2, 3, 3, 3, 4, 5, 6, 5] == False
    print $ isSortedXs [-100, -99, -99, -99] == True
    print $ isSortedXs [-100, -99, -99, -99, 100] == True
    print $ isSortedXs [100, 101, -102] == False
    print $ isSortedXs [1, 2, 3, 4, 5, 6] == True
    print $ isSortedXs [-1, -2, -3, -4, -5, -6] == True

isSorted :: [Int] -> Bool
isSorted (x:y:z:xs) 
 | x > y && y < z = False
 | x < y && y > z = False
 | otherwise = isSorted (y:z:xs)
isSorted _ = True

isSortedXs :: [Int] -> Bool
isSortedXs xs = xs == sort xs || xs == (reverse $ sort xs)


