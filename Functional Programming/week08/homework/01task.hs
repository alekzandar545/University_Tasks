main :: IO()
main = do
    print $ addN [1, 2, 3, 4, 5] 9999999999999999999999 == [10000000000000000000000,10000000000000000000001,10000000000000000000002,10000000000000000000003,10000000000000000000004]
    print $ addN [1, 1, 1, 1, 1] 1 == [2, 2, 2, 2, 2] --my test
    print $ sqAddN [1, 2, 3, 4, 5] 5 -- == [36,49,64,81,100]
    print $ sqAddN [1, 2, 3, 4, 5] 1 == [4,9,16,25,36] --my test
    print $ divByN [1, 2, 3, 4, 5] 5 == [0.2,0.4,0.6,0.8,1.0]
    print $ divByN [2, 4, 6, 8, 10] (-5) == [(-0.4),(-0.8),(-1.2),(-1.6),(-2.0)]--my test
    print $ filterByN [1, 2, 3, 4, 5] 3 == [3,4,5]
    print $ filterByN [1, 2, 3, 4, 5] 4 == [4,5] --my test

addN :: (Num a) => [a] -> a -> [a]
addN xs x = map (x +) xs --can i use partial function application when xs is the first argument and x is the second?

sqAddN :: (Num a) => [a] -> a -> [a]
sqAddN xs x = map ((^2) . (+x)) xs

divByN :: [Int] -> Int -> [Double]
divByN _ 0 = error "Division by 0!"
divByN xs x = map ((/ fromIntegral x) . fromIntegral) xs

filterByN :: (Num a, Ord a) => [a] -> a -> [a]
filterByN xs x = filter (>= x) xs

