main :: IO()
main = do
    print $ sumUnevenLC 5 50 == 621
    print $ sumUnevenLC 50 1 == 625
    print $ sumUnevenLC 564 565 == 565

    print $ sumUnevenHOF 5 50 == 621
    print $ sumUnevenHOF 50 1 == 625
    print $ sumUnevenHOF 564 565 == 565

sumUnevenLC :: Int -> Int -> Int
sumUnevenLC x y = sum [d | d <- [min a b .. max x y], mod d 2 /= 0]

sumUnevenHOF :: Int -> Int -> Int
sumUnevenHOF x y = sum $ filter (\ d -> mod d 2 /= 0) [min x y .. max x y]