import Data.Char

main::IO()
main = do
    print $ size charBTree
    print $ sumTree numberBTree
    print $ traverseDFS charBTree

    print $ getLevel numberBTree 2 == [1, 0, 2, 5]
    print $ getLevel charBTree 1 == "al"
    print $ getLevel charBTree 3 == []

    print $ traverseBFS numberBTree == [5,12,4,1,0,2,5,96,21]
    print $ traverseBFS charBTree == "kalhsel"
    
    print $ mapTree numberBTree (*2) == Node 10 (Node 24 (Node 2 (Node 192 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 8 (Node 4 Nil Nil) (Node 10 Nil (Node 42 Nil Nil)))
    print $ mapTree numberBTree (show) == Node "5" (Node "12" (Node "1" (Node "96" Nil Nil) Nil) (Node "0" Nil Nil)) (Node "4" (Node "2" Nil Nil) (Node "5" Nil (Node "21" Nil Nil)))
    print $ mapTree charBTree (toUpper) == Node 'K' (Node 'A' (Node 'H' Nil Nil) (Node 'S' Nil Nil)) (Node 'L' (Node 'E' Nil Nil) (Node 'L' Nil Nil))


data BTree a = Nil | Node a (BTree a) (BTree a)

charBTree :: BTree Char
charBTree = Node 'k' (Node 'a' (Node 'h' Nil Nil) (Node 's' Nil Nil)) (Node 'l' (Node 'e' Nil Nil) (Node 'l' Nil Nil))

numberBTree :: BTree Int
numberBTree = Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 4 (Node 2 Nil Nil) (Node 5 Nil (Node 21 Nil Nil)))

size :: BTree a -> Int
size Nil = 0
size (Node val left right) = 1 + size left + size right

sumTree :: (Num a) => BTree a -> a
sumTree Nil = 0
sumTree (Node val left right) = val + sumTree left + sumTree right

traverseDFS :: BTree a -> [a]
traverseDFS Nil = []
traverseDFS (Node val left right) = traverseDFS left ++ (val : traverseDFS right)

getLevel :: BTree a -> Int -> [a]
getLevel Nil _ = []
getLevel (Node val left right) 0 = [val]
getLevel (Node val left right) lvl = getLevel left (lvl-1) ++ getLevel right (lvl-1)

traverseBFS :: BTree a -> [a]
traverseBFS Nil = []
traverseBFS t = helper t 0
  where
    helper t k
     | null (getLevel t k) = []
     | otherwise = (getLevel t k) ++ helper t (k + 1)

mapTree :: BTree a -> (a -> a) -> BTree a
mapTree Nil _ = Nil
mapTree (Node val left right) f = Node (f val) (mapTree left f) (mapTree right f)

