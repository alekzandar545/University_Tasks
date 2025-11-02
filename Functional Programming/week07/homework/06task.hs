{-Description:

Define two predicates - isPrimeG and isPrimeLC, that check whether a number is prime.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
isPrimeG is implemented using guards.
isPrimeLC is implemented using list comprehension.
isPrimeLC is implemented on a single line.
True and/or False are not explicitly returned in isPrimeLC.-}

main :: IO()
main = do
    print $ isPrimeG 1 == False
    print $ isPrimeG 2 == True
    print $ isPrimeG 3 == True
    print $ isPrimeG 6 == False
    print $ isPrimeG 61 == True
    print $ isPrimeG 1232161 == False -- my test

    print $ isPrimeLC 1 == False
    print $ isPrimeLC 2 == True
    print $ isPrimeLC 3 == True
    print $ isPrimeLC 6 == False
    print $ isPrimeLC 61 == True
    print $ isPrimeLC 1232161 == False -- my test

isPrimeG :: Int -> Bool
isPrimeG num = helper 2 && num /= 1
 where
    helper count
     | count > (round $ sqrt $ fromIntegral num) = True
     | mod num count == 0 = False
     | otherwise = helper (count + 1)
        

isPrimeLC :: Int -> Bool
isPrimeLC num = null [x | x <- [2 .. num-1], mod num x == 0] && num /= 1