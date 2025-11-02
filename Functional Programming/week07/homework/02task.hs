{-Define a function for calculating the GCD of two whole numbers.
Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
Normally, you would use the built-in function gcd. This is the only time when you should not use it.
myGcdG is implemented using guards.
myGcdPM is implemented using pattern matching.
The right types are used.
Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The right types are used.-}

main ::IO()
main = do
    print $ myGcdG 5 13 == 1
    print $ myGcdG 13 1235 == 13
    print $ myGcdG 48 18 == 6 --my test

    print $ myGcdPM 5 13 == 1 --pattern matching
    print $ myGcdPM 13 1235 == 13
    print $ myGcdPM 48 18 == 6 --my test
    
myGcdG :: Int -> Int -> Int
myGcdG a b
 | a == 0 = b
 | b == 0 = a
 | otherwise = myGcdG b (mod a b)

myGcdPM :: Int -> Int -> Int
myGcdPM a 0 = a
myGcdPM 0 b = b
myGcdPM a b = myGcdPM b (mod a b)
