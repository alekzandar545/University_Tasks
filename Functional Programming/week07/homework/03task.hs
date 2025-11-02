{-Define a predicate that checks whether a non-negative whole number is a palindrome.

Acceptance criteria:

Add one new test case. Place a comment after it with the words my test.
All tests pass.
The right types are used.
True and/or False are not explicitly returned.-}

main :: IO()
main = do
    print $ isPalindrome 6 ==True
    print $ isPalindrome 1010 == False
    print $ isPalindrome 505 == True
    print $ isPalindrome 123321 == True
    print $ isPalindrome 654 == False
    print $ isPalindrome 12021 == True -- my test

isPalindrome :: Int -> Bool
isPalindrome x = x == (read $ reverse $ show x)
