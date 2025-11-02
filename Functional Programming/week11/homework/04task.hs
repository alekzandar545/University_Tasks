main::IO()
main = do
    print $ isGraceful t1 == True
    print $ isGraceful t2 == False
    print $ isGraceful t3 == True --my test

data Tree = Nil | Node Int [Tree]
  deriving (Show)

t1 :: Tree
t1 = Node 1 [Node 3 [], Node 5 [], Node 7 [], Node 9 []]

t2 :: Tree
t2 = Node 7 [Node 9 [Node 5 [], Node 2 []]]

t3 :: Tree
t3 = Nil

isGraceful :: Tree -> Bool
isGraceful Nil = True
isGraceful (Node val children) = all (\ (Node chVal _) -> mod (val - chVal) 2 == 0) children && all isGraceful children
