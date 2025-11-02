{-Description:

Define a predicate that checks whether the digits of a 
non-negative whole number are ordered in an ascending order.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The right types are used.
True and/or False are not explicitly returned.-}

import Data.List

main :: IO()
main = do
    print $ hasIncDigits 1244 == True
    print $ hasIncDigits 12443 == False
    print $ hasIncDigits 1244233 == False --my test

hasIncDigits :: Int -> Bool
hasIncDigits x = show x == (sort $ show x)