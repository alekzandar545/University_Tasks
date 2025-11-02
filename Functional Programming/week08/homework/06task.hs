import Data.List

main :: IO()
main = do
    print $ sumUnique [[1,2,3,2], [1,-4],[1]] == 2
    print $ sumUnique [[1,2,3,2],[-4,-4],[5]] == 9
    print $ sumUnique [[2,2,2], [3,3,3],[4,4,4]] == 0
    print $ sumUnique [[2,2,2], [3,3,3],[4,4,3]] == 3 --my test
    print $ sumUnique [[1,2,3],[4,5,6],[7,8,9]] == 45

-- all lambdas on functional level
sumUnique :: [[Int]] -> Int
sumUnique = sum . concat . filter ((== 1) . length) . concat .  map (group . sort)
