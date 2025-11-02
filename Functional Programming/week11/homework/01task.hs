main::IO()
main = do
    print $ height numberBTree == 4
    print $ height charBTree == 3

    print $ average numberBTree == 16.22222222222222
    --print $ average charBTree -- should not work

    print $ sumLeaves numberBTree == 119
    -- print $ sumLeaves charBTree -- shouldn't work

    print $ areEqual numberBTree (Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 4 (Node 2 Nil Nil) (Node 5 Nil Nil))) == False
    print $ areEqual charBTree charBTree == True
    print $ areEqual charBTree numberBTree == False -- my test
    print $ areEqual numberBTree (Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 8 (Node 2 Nil Nil) (Node 5 Nil (Node 21 Nil Nil)))) == False

    print $ setLevels numberBTree == Node (0,5) (Node (1,12) (Node (2,1) (Node (3,96) Nil Nil) Nil) (Node (2,0) Nil Nil)) (Node (1,4) (Node (2,2) Nil Nil) (Node (2,5) Nil (Node (3,21) Nil Nil)))
    print $ setLevels charBTree == Node (0,'k') (Node (1,'a') (Node (2,'h') Nil Nil) (Node (2,'s') Nil Nil)) (Node (1,'l') (Node (2,'e') Nil Nil) (Node (2,'l') Nil Nil))

    print $ mirrorTree numberBTree == Node 5 (Node 4 (Node 5 (Node 21 Nil Nil) Nil) (Node 2 Nil Nil)) (Node 12 (Node 0 Nil Nil) (Node 1 Nil (Node 96 Nil Nil)))
    print $ mirrorTree charBTree == Node 'k' (Node 'l' (Node 'l' Nil Nil) (Node 'e' Nil Nil)) (Node 'a' (Node 's' Nil Nil) (Node 'h' Nil Nil))

data BTree a = Nil | Node a (BTree a) (BTree a)
 deriving (Show, Eq)

charBTree :: BTree Char
charBTree = Node 'k' (Node 'a' (Node 'h' Nil Nil) (Node 's' Nil Nil)) (Node 'l' (Node 'e' Nil Nil) (Node 'l' Nil Nil))

numberBTree :: BTree Int
numberBTree = Node 5 (Node 12 (Node 1 (Node 96 Nil Nil) Nil) (Node 0 Nil Nil)) (Node 4 (Node 2 Nil Nil) (Node 5 Nil (Node 21 Nil Nil)))

height :: BTree a -> Int
height Nil = 0
height (Node val left right) = 1 + max (height left) (height right)

size :: BTree a -> Int
size Nil = 0
size (Node _ left right) = 1 + size left + size right

sumTree :: (Num a) => BTree a -> a
sumTree Nil = 0
sumTree (Node value left right) = value + sumTree left + sumTree right

average :: (Num a, Integral a) => BTree a -> Double
average tree = fromIntegral (sumTree tree) / fromIntegral (size tree)

sumLeaves :: (Num a) => BTree a -> a
sumLeaves Nil = 0
sumLeaves (Node val Nil Nil) = val
sumLeaves (Node _ left right) = sumLeaves left + sumLeaves right

--root right left -> root left right
areEqual :: (Eq a) => BTree a -> BTree a -> Bool
areEqual t1 t2 = t1 == t2

setLevels :: BTree a -> BTree (Int, a)
setLevels tree = helper tree 0
  where 
    helper Nil _ = Nil
    helper (Node val left right) level = Node (level, val) (helper left (level + 1)) (helper right (level + 1))

mirrorTree :: BTree a -> BTree a
mirrorTree Nil = Nil
mirrorTree (Node val left right) = Node val (mirrorTree right) (mirrorTree left)


