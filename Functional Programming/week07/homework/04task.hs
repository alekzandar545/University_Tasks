{-Description:

Two numbers are amicable if the sum of the divisors of
one of them is equal to the other. Define a predicate 
that checks whether two numbers are amicable.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The right types are used.
List comprehension is used.
True and/or False are not explicitly returned.-}

main :: IO()
main = do
    print $ areAmicable 200 300 == False
    print $ areAmicable 220 284 == True
    print $ areAmicable 284 220 == True
    print $ areAmicable 1184 1210 == True
    print $ areAmicable 2620 2924 == True
    print $ areAmicable 6232 6368 == True
    print $ areAmicable 32141 2158125 == False -- my Test
    
areAmicable :: Int -> Int -> Bool
areAmicable num check = sum [x | x <- [1 .. div num 2], mod num x == 0] == check