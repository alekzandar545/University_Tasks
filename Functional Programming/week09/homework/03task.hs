main::IO()
main = do
    print $ removeAll 5 [5] == []
    print $ removeAll 4 [4, 4] == []
    print $ removeAll 5 [1] == [1]
    print $ removeAll 5 [5, 1, 5, 3, 5] == [1, 3]
    print $ removeAll 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeAll 10 [5, 1, 5, 3, 5] == [5, 1, 5, 3, 5] --my test

    print $ removeAllHOF 5 [5] == []
    print $ removeAllHOF 4 [4, 4] == []
    print $ removeAllHOF 5 [1] == [1]
    print $ removeAllHOF 5 [5, 1, 5, 3, 5] == [1, 3]
    print $ removeAllHOF 3 [5, 1, 5, 3, 5] == [5, 1, 5, 5]
    print $ removeAllHOF 10 [5, 1, 5, 3, 5] == [5, 1, 5, 3, 5] --my test

removeAllHOF :: Int -> [Int] -> [Int]
removeAllHOF x xs = filter (\ d -> d /= x) xs

-- without helper
removeAll :: Int -> [Int] -> [Int]
removeAll x [] = []
removeAll x (y:ys)
 |x == y = removeAll x ys
 |otherwise = y : removeAll x ys
