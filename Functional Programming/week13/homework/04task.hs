import Data.List

main::IO()
main = do
    print $ leavesAreEqual t1 t2 == True
    print $ leavesAreEqual t3 t4 == False
    print $ getLeaves t1 == [1, 26, 32] --my test
    print $ leavesAreEqual t2 t3 == True --my test

data Tree = Nil | Node Int Tree Tree

t1 :: Tree
t1 = Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 26 Nil Nil) (Node 32 Nil Nil)))

t2 :: Tree
t2 = Node 25 (Node 10 (Node 1 Nil Nil) Nil) (Node 30 (Node 32 Nil Nil) (Node 26 Nil Nil))

t3 :: Tree
t3 = Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 26 Nil Nil) (Node 32 Nil Nil)))

t4 :: Tree 
t4 = Node 10 (Node 1 Nil Nil) (Node 25 Nil (Node 30 (Node 27 Nil Nil) (Node 32 Nil Nil)))

leavesAreEqual :: Tree -> Tree -> Bool
leavesAreEqual t1 t2 = (sort $ getLeaves t1) == (sort $ getLeaves t2)

getLeaves :: Tree -> [Int]
getLeaves Nil = []
getLeaves (Node val Nil Nil) = [val]
getLeaves (Node val left right) = getLeaves left ++ getLeaves right