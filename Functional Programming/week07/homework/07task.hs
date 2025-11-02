{-Description:

A number is perfect if and only if it is natural and equal 
    to the sum of its divisors excluding the number itself. 
    Define a predicate that checks whether a number is perfect.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
List comprehension is used.
True and/or False are not explicitly returned.-}

main :: IO()
main = do
    print $ isPerfect 1 == False
    print $ isPerfect 6 == True
    print $ isPerfect 495 == False
    print $ isPerfect 33550336 == True
    print $ isPerfect 321511413 == False --my test

isPerfect :: Int -> Bool
isPerfect num = num == sum [x | x <- [1 .. num - 1], mod num x == 0]

--notes for std::cin type of actions we specify the output type
--there is a hack where we use :l to see the types from the type iferrence