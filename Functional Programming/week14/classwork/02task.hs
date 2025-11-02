import Data.List

main::IO()
main = do
    print $ (findUniques db) 4
    print $ (findUniques db) 8
    print $ (findUniques db) 32
    
db = [("SICP", 1996), ("Learn You a Haskell for Great Good", 2011),
      ("Real World Haskell", 2008), ("Programming in Haskell", 2011)]

findUniques :: [(String, Int)] -> (Int -> [String])
findUniques list = (\ k -> [title | (title, year) <- list, length title >= k , notElem year (getInvalidYears list)])
    where
        getInvalidYears = concat . filter ((> 1) . length) . group . sort . snd . unzip