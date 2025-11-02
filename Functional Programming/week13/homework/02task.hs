main::IO()
main = do
    print $ convert tree == (Node 30 (Node 36 (Node 36 Nil Nil) (Node 35 Nil (Node 33 Nil Nil))) (Node 21 (Node 26 Nil Nil) (Node 15 Nil (Node 8 Nil Nil))))
    print $ convert Nil == Nil --my test

data Tree = Nil | Node Int Tree Tree
  deriving (Show, Eq)

tree :: Tree
tree = Node 4 (Node 1 (Node 0 Nil Nil) (Node 2 Nil (Node 3 Nil Nil))) (Node 6 (Node 5 Nil Nil) (Node 7 Nil (Node 8 Nil Nil)))

testTree :: Tree
testTree = Nil

convert :: Tree -> Tree
convert root = helper root root
    where 
        helper Nil _ = Nil
        helper (Node val left right) root = Node (sumDown root val) (helper left root) (helper right root)

        sumDown Nil _ = 0
        sumDown (Node val left right) origVal
         | origVal <= val  = val + sumDown left origVal + sumDown right origVal
         | otherwise = sumDown left origVal + sumDown right origVal