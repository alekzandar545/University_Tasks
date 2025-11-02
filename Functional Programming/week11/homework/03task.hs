main::IO()
main = do
    print $ ordered t1 == True
    print $ ordered t2 == False

data Tree = Nil | Node Int Int Tree Tree

t1 :: Tree
t1 = Node 3 10 (Node 5 8 (Node 6 7 Nil Nil) (Node 4 9 Nil Nil)) (Node 2 12 Nil (Node 1 15 Nil Nil))

t2 :: Tree
t2 = Node 3 10 (Node 5 8 (Node 6 7 Nil Nil) (Node 7 9 Nil Nil)) (Node 2 12 Nil (Node 1 15 Nil Nil))

ordered :: Tree -> Bool
ordered Nil = True
ordered (Node a b left right) = a < b && leftCheck left && rightCheck right && ordered left && ordered right
  where
    leftCheck Nil = True
    leftCheck (Node x y _ _) = x > a && y < b
    rightCheck Nil = True
    rightCheck (Node x y _ _) = x < a && y > b
    
