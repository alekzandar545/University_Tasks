import Data.List

main::IO()
main = do
    print $ numAdvance 5 [10,9,8,7,7,7,5,5] == 6
    print $ numAdvance 2 [0,0,0,0] == 0
    print $ numAdvance 3 [10,9,8,7,7,7,5,5] == 3
    print $ numAdvance 1 [10,9,8,7,7,7,5,5] == 1
    print $ numAdvance 2 [10,9,8,7,7,7,5,5] == 2

numAdvance :: (Num a, Ord a) => Int -> ([a] -> Int)
numAdvance k = (\ xs -> 
                if length xs < k || xs /= (reverse $ sort xs)
                then error "Invalid list"
                else length [x | x <- xs, x >= (xs !! (k-1)), x > 0])