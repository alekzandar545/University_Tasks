main::IO()
main = do
    print $ maxDepthBlueNode t1 == 2
    print $ maxDepthBlueNode t2 == 0 --my test
    print $ maxDepthBlueNode Empty

data Color = Red | Green | Blue
  deriving (Eq)
data Tree = Empty | Node Color Tree Tree

t1 :: Tree
t1 = Node Blue 
    (Node Red 
        (Node Green Empty Empty)
        Empty)
    (Node Red 
        (Node Blue 
            (Node Green Empty Empty) 
            (Node Red Empty Empty)) 
        Empty)

t2 :: Tree
t2 = Node Blue Empty Empty

maxDepthBlueNode :: Tree -> Int
maxDepthBlueNode tree = helper tree 0
  where
    helper :: Tree -> Int -> Int
    helper Empty _ = -1
    -- helper (Node Blue left right) currentDepth = currentDepth
    helper (Node color left right) currentDepth =
        let
            newDepth = if color == Blue then currentDepth else -1
            leftDepth = helper left (currentDepth + 1)
            rightDepth = helper right (currentDepth + 1)
        in
            maximum [newDepth, leftDepth, rightDepth]
