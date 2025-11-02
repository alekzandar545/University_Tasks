import Data.List

main::IO()
main = do
    print $ genWords t1-- == ["abe","acd","acf","be","cd","cf","d","e","f"]
    print $ genWords t2-- == ["ab","acd","b","cd","d"]
    print $ genWords t3-- == ["abdh","abdi","abe","acf","acg","bdh","bdi","be","cf","cg","dh","di","e","f","g","h","i"]

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
    helper (Node val Nil Nil) str = (val == (head str)) && (length str == 1) -- leaf
    helper (Node v left right) (x:xs) = (v == x) && (helper left xs || helper right xs)

--generate from root and then cut off the beginnings

genFromRoot :: BTree Char -> [String]
genFromRoot Nil = [[]]
genFromRoot (Node val Nil Nil) = [[val]]
genFromRoot (Node val left right) = [val : rest | rest <- genWords left ++ genWords right]

genWords :: BTree Char -> [String]
genWords (Node val left right) = genFromRoot right