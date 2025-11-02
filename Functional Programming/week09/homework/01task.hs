main::IO()
main = do
    print $ isPresent 0 [0, -1, 2] == True
    print $ isPresent 1 [0, 1, 2] == True
    print $ isPresent 2 [0, 1, -2] == False
    print $ isPresent 3 [0, 1, 2] == False
    print $ isPresent 2 [0, 1, 2] == True --my test

isPresent :: Int -> [Int] -> Bool
isPresent x [] = False
isPresent x (y:ys) = x == y || isPresent x ys
