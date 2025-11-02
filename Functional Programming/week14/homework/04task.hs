main::IO()
main = do
    print $ maximumLevel t1
    print $ maximumLevel t2
    print $ maximumLevel t3

data BTree a = Nil | Node a (BTree a) (BTree a)

t1:: BTree Int
t1 = Node 94 (Node 73 Nil (Node 80 Nil Nil)) (Node 87 (Node 73 Nil Nil) Nil)

t2:: BTree Int
t2 = Node 94 (Node 73 Nil (Node 80 Nil Nil)) (Node 87 (Node 73 Nil Nil) (Node 7 Nil Nil))

t3:: BTree Int
t3 = Node 94 (Node 0 Nil (Node 42 Nil Nil)) (Node 0 (Node 42 Nil Nil) (Node 42 Nil Nil))

--sum of all levels in a list and then extraxt max going >= from left to right
--find depth
--for each depth find level sum
--stuff into list
findDepth :: BTree a -> Int
findDepth Nil = 0
findDepth (Node _ left right) = max (1 + findDepth left) (1 + findDepth right)

findLevelSum :: (Num a) => BTree a -> Int -> a
findLevelSum Nil _ = 0
findLevelSum (Node val _ _) 1 = val
findLevelSum (Node _ left right) level = findLevelSum left (level - 1) + findLevelSum right (level - 1)

--maximumLevel :: BTree a -> Int
maximumLevel tree = fst $ foldr (\ (i1,v1) (i2,v2) -> if (v1 > v2) then (i1,v1) else (i2,v2)) (-1, -1) $ zip [1 ..] $ map (\ n -> findLevelSum tree n) [1 .. (findDepth tree)]

