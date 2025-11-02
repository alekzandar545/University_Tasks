main::IO()
main = do
    print $ func [2.7, 3.0 ..] 2.2 3 == -0.4399999999999998
    print $ func [0, (-1) ..] 2.2 3 == 29.568000000000005 --my test

func :: (Num a) => [a] -> (a -> Int -> a)
func nums = \ x y -> product $ map (x -) (take y nums)
