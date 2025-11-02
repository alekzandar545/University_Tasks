main::IO()
main = do
    print $ prodEvens [1 .. 6] == 15
    print $ prodEvens [] == 1 --my test
    print $ prodEvens [7.66, 7, 7.99, 7] == 61.2034

prodEvens :: (Num a) => [a] -> (a)
prodEvens = foldr (\(i,val) res-> if even i then res*val else res) 1 . zip [0 ..]

--foldr :: (a -> b -> b) -> b -> [a] -> b