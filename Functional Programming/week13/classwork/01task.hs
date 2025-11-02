main::IO()
main = do
    print $ containsWord t1 "acd" == True
    print $ containsWord t1 "cd" == True
    print $ containsWord t1 "af" == False
    print $ containsWord t1 "ac" == False
    print $ containsWord t1 "acdh" == False
    print $ containsWord t1 "b" == False
    print $ containsWord t1 "e" == True
    print $ containsWord t2 "ab" == True
    print $ containsWord t2 "ad" == False
    print $ containsWord t3 "bdh" == True
    print $ containsWord t3 "bdi" == True
    print $ containsWord t3 "ac" == False
    --print $ findStarts t1 'b'

data BTree a = Nil | Node a (BTree a) (BTree a)
 deriving (Show)

t1 :: BTree Char
t1 = Node 'a' (Node 'c' (Node 'f' Nil Nil) (Node 'd' Nil Nil)) (Node 'b' Nil (Node 'e' Nil Nil))

t2 :: BTree Char
t2 = Node 'a' (Node 'c' (Node 'd' Nil Nil) Nil) (Node 'b' Nil Nil)

t3 :: BTree Char
t3 = Node 'a' (Node 'b' (Node 'd' (Node 'h' Nil Nil) (Node 'i' Nil Nil)) (Node 'e' Nil Nil)) (Node 'c' (Node 'f' Nil Nil) (Node 'g' Nil Nil)) 

findStarts :: BTree Char -> Char -> [BTree Char]
findStarts Nil _ = []
findStarts (Node val left right) ch
 | val == ch = (Node val left right) : (findStarts left ch ) ++ (findStarts right ch)
 | otherwise = (findStarts left ch) ++ (findStarts right ch)


containsWord :: BTree Char -> String -> Bool
containsWord tree (x:xs) = helper (head $ (findStarts tree) x) (x:xs)
  where 
    helper _ [] = False -- exhaust case
    helper Nil _ = False -- exhaust case
    helper (Node val Nil Nil) (x:xs) = (val == x) && (length (x:xs) == 1) -- leaf
    helper (Node val left right) (x:xs) = (val == x) && (helper left xs || helper right xs)