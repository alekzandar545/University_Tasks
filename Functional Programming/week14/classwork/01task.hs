import Data.Char

main::IO()
main = do
    print $ reversibleNumbers 20
    print $ reversibleNumbers 31
    print $ reversibleNumbers 10

reversibleNumbers :: Int -> [Int] 
reversibleNumbers x = [num | num <- [1 .. x], oddNums (num + rev num), mod num 10 /= 0]
    where
        oddNums = all (odd . digitToInt) . show
        rev = read . reverse . show