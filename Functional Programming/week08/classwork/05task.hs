main :: IO()
main = do
    print $ isImage [] [] == True
    print $ isImage [1, 2, 3] [2, 3, 4] == True
    print $ isImage [1, 2, 3] [4, 6, 9] == False
    print $ isImage [1, 2, 3] [2, 5, 4] == False

isImage :: [Int] -> [Int] -> Bool
isImage xs ys = all (\ x y -> x == y) [y - x | y <- ys, x <- xs]