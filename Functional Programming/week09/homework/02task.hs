main::IO()
main = do
    print $ removeFirst 5 [5, 1, 5, 3, 5] == [1, 5, 3, 5]
    print $ removeFirst 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeFirst 1 [5, 1, 5, 3, 5] == [5, 5, 3, 5] --my test

-- without helper
removeFirst :: Int -> [Int] -> [Int]
removeFirst _ [] = []
removeFirst x (y:ys) 
 | x /= y = y : removeFirst x ys
 | otherwise = ys