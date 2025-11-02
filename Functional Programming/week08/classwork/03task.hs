main :: IO()
main = do
    print $ getPalindromesLC 132465 == 8
    print $ getPalindromesLC 654546 == 8
    print $ getPalindromesLC 100001 == 100012
    print $ getPalindromesLC 21612 == 21614
    print $ getPalindromesLC 26362 == 26364

    print $ getPalindromesHOF 132465 == 8
    print $ getPalindromesHOF 654546 == 8
    print $ getPalindromesHOF 100001 == 100012
    print $ getPalindromesHOF 21612 == 21614
    print $ getPalindromesHOF 26362 == 26364

isPalindrome :: (Num a, Show a, Eq a, Read a) => a -> Bool
isPalindrome x = (read $ reverse $ show x) == x

getPalindromesHOF :: Int -> Int
getPalindromesHOF a = maximum palis + minimum palis
 where
    palis = filter (\ x -> isPalindrome x) $ filter (\ x -> mod a x == 0) [2 .. a]

getPalindromesLC :: (Integral a, Show a, Read a) => a -> a
getPalindromesLC a = minimum palis + maximum palis
 where
    palis = [x | x <- [2 .. a], isPalindrome x, mod a x == 0] 