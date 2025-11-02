main::IO()
main = do
    print $ levelSum numberBTree 1 == 11 -- (5 + 6)
    print $ findDepth numberBTree == 3 -- quick test
    print $ cone numberBTree == True
    print $ cone testTree == True

data Tree = Nil | Node Int Tree Tree

numberBTree :: Tree
numberBTree = Node 10 (Node 5 (Node 1 Nil Nil) (Node 9 Nil Nil)) (Node 6 (Node 8 Nil Nil) (Node 7 Nil Nil))

testTree :: Tree
testTree = Nil

levelSum :: Tree -> Int -> Int
levelSum Nil _ = 0
levelSum (Node val left right) level
 | level == 0 = val
 | otherwise = levelSum left (level - 1) + levelSum right (level - 1)

findDepth :: Tree -> Int
findDepth Nil = 0
findDepth (Node _ left right) = max (1 + findDepth left) (1 + findDepth right)

cone :: Tree -> Bool
cone Nil = True
cone tree = helper tree (findDepth tree - 1)
    where
        helper tree 0 = True -- in case its only 1 elem   
        helper tree 1 = True
        helper tree level
         | levelSum tree level > levelSum tree (level - 1) = helper tree (level - 1)
         | otherwise = False
