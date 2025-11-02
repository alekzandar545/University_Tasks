{-Define a function that returns the average of the sum of the squares of two whole numbers.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The right types are used.-}

main :: IO() -- Input (I), Output (O), Stream (())
main = do --we can print only in main
    print $ sqAvg 5 0 == 12.5
    print $ sqAvg 10 13 == 134.5
    print $ sqAvg 1 2 == 2.5 --my test

sqAvg :: Int -> Int -> Double
sqAvg a b = (/ 2) $ fromIntegral $ a * a + b * b