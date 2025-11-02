main :: IO()

-- Define a function sumSpecialPrimes n d that returns the sum of the first n prime numbers that contain a digit d.

main = do
    print $ sumSpecialPrimes 5 2 == 392
    print $ sumSpecialPrimes 5 3 == 107
    print $ sumSpecialPrimes 10 3 == 462
    print $ sumSpecialPrimes 3 7 /= 197  -- my test

isPrime x = x > 1 && null [d | d <- [2 .. floor . sqrt $ fromIntegral x], mod x d == 0]

sumSpecialPrimes :: Int -> Int -> Int
sumSpecialPrimes n d = sum $ take n $ filter (\ p -> isPrime p && containsDigit d p) [2..]
    where
    containsDigit d n = elem (head $ show d) (show n)
