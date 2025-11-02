main::IO()
main = do
    print $ subLists [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 2 == [[1, 2], [3, 4], [5, 6], [7, 8], [9, 10]]
    print $ subLists [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 4 == [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10]]
    print $ subLists [1,2] 4 == [[1,2]] --my test


-- without helper
subLists :: [a] -> Int -> [[a]]
subLists [] _ = []
subLists xs k
 | length xs > k = (take k xs) : subLists (drop k xs) k
 | otherwise = xs : subLists [] k
