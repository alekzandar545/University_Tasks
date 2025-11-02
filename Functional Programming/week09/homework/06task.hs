main :: IO()
main = do
    print $ isImage [] [] == (False, 0) -- my test
    print $ isImage [1, 2, 3, 4] [2, 3, 4, 7] == (False, 0) -- my test
    print $ isImage [1, 2, 3, 4] [2, 3, 4, 5] == (True, 1)
    print $ isImage [1, 2, 3, 4] [4, 5, 6, 7] == (True, 3)
    print $ isImage [4, 5, 6, 7] [1, 2, 3, 4] == (True, -3)
    print $ isImage [1, 2, 3, 4] [4, 5, 6, 6] == (False, 0)
    print $ isImage [1, 2] [-1, -2] == (False, 0)
    print $ isImage [1, 2, 3, 4] [2, 3, 4, 4] == (False, 0)

type Tuple = (Bool, Int)

isImage :: [Int] -> [Int] -> Tuple
isImage (x:xs) (y:ys)
 | all (\ d -> d == y - x) $ zipWith (-) (y:ys) (x:xs) = (True, y - x)
 | otherwise = (False, 0)