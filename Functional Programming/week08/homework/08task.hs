import Data.List
import Data.Char
main :: IO ()
main = do
    print $ reduceStr "dabAcCaCBAcCcaDD" == "dabCBAcaDD" -- dabAcCaCBAcCcaDD -> dabAaCBAcCcaDD -> dabCBAcCcaDD -> dabCBAcaDD
    print $ reduceStr "bAaB" == "" -- my test

reduceStr :: [Char] -> [Char]
reduceStr str = reverse $ helper str []
 where
    helper [] res = res
    helper (c:cs) [] = helper cs [c]
    helper (c:cs) (x:xs)
     | x /= c && toLower x == toLower c = helper cs xs -- ! 
     | otherwise = helper cs (c:x:xs)
