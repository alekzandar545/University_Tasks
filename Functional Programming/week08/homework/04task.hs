main :: IO()
main = do
    print $ primesInRange 1 100 == [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
    print $ primesInRange 100 1 == [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
    print $ primesInRange 0 1 == [] --my test

isPrime :: Int -> Bool
isPrime d = null [x | x <- [2 .. floor $ sqrt $ fromIntegral d], mod d x == 0]

primesInRange :: Int -> Int -> [Int]
primesInRange a b = [x | x <- [min a b .. max a b], isPrime x, x > 1]
    