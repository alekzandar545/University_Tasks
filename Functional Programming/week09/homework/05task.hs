main :: IO ()
main = do
    print $ combine [(1,2)] == (1,2) -- my test
    print $ combine [(1, 2), (1, 2)] == (11, 22)
    print $ combine [(3, 9), (8, 7), (7, 9), (8, 8), (5, 0), (9, 2)] == (377802, 989859)

type Tuple a = (a, a)

-- on functional level with fold
combine :: (Ord a, Integral a) => [Tuple a] -> Tuple a
combine = foldl (\ (acc1, acc2) (x, y) -> (acc1* 10 + min x y, acc2*10 + max x y)) (0,0)

