
main :: IO()
main = do 
    print $ revOneLine 123 == 321
    print $ revOneLineMagic 123 == 321
    print $ sumDivsOneLineLC 6 == 12
    print $ sumDivsOneLineHOF 6 == 12
    print $ primeOneLineLC 6 == False
    print $ primeOneLineHOF 17 == True

primeOneLineHOF :: Int -> Bool
primeOneLineHOF a = null $ filter (\ x -> mod a x == 0) [2 .. a-1] 

primeOneLineLC ::  Int -> Bool
primeOneLineLC a = null [x | x <- [2 .. a-1], mod a x == 0]

sumDivsOneLineHOF :: Int -> Int
sumDivsOneLineHOF a = sum $ filter (\ x -> mod a x == 0) [1 .. a]  

sumDivsOneLineLC :: Int -> Int
sumDivsOneLineLC a = sum [x | x <- [1 .. a], mod a x == 0]

revOneLine :: (Num a, Show a) => a -> Int
revOneLine a = read $ reverse $ show a

revOneLineMagic :: (Num a, Show a) => a -> Int
revOneLineMagic = read . reverse . show


