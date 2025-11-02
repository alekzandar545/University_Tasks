data Color = Red | Green | Blue
  deriving (Eq, Show)
data Tree = Empty | Node Color Tree Tree

main::IO()
main = do 
    print $ minDepthGreenNode colorTree == 2
    --print $ minDepthGreenNode testTree == 0 -- my test (error)
    print $ minDepthGreenNode colorTree2 == 0 --my test

testTree :: Tree
testTree = Empty

colorTree2 :: Tree
colorTree2 = Node Green (Node Red (Node Green Empty Empty) Empty) (Node Red (Node Blue (Node Green Empty Empty) (Node Red Empty Empty)) Empty)

colorTree :: Tree
colorTree = Node Blue (Node Red (Node Green Empty Empty) Empty) (Node Red (Node Blue (Node Green Empty Empty) (Node Red Empty Empty)) Empty)

getLevel :: Tree -> Int -> [Color]
getLevel Empty _ = []
getLevel (Node color _ _) 0 = [color]
getLevel (Node _ left right) k = getLevel left (k - 1) ++ getLevel right (k - 1)

minDepthGreenNode :: Tree -> Int
minDepthGreenNode tree = findLevel 0
  where
    findLevel level
     | getLevel tree level == [] = error "No greens!"
     | elem Green (getLevel tree level) = level
     | otherwise = findLevel (level+1)