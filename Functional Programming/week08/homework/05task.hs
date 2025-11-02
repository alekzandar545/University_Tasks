main :: IO()
main = do
    print $ reverseOrdSuff 37563 == 36
    print $ reverseOrdSuff 32763 == 367
    print $ reverseOrdSuff 32567 == 7
    print $ reverseOrdSuff 32666 == 6
    print $ reverseOrdSuff 32687 == 78 --my test

reverseOrdSuff :: Int -> Int
reverseOrdSuff d = read $ reverse $ helper [] (reverse $ show d)
  where
    helper res [] = res
    helper [] (x:xs) = helper [x] xs
    helper (r:res) (x:xs)
     | x > r = helper (x:r:res) xs 
     | otherwise = (r:res)