main::IO()
main = do
    print $ canSplitWord t1 "BDCGI" -- True ("BDC" и "GI")
    print $ canSplitWord t1 "BDGI" -- True ("BD" и "GI")
    print $ canSplitWord t1 "BDCGIH" -- True ("BDC" и"GIH")
    print $ canSplitWord t1 "BGIH" -- False
    print $ canSplitWord t1 "BCDGI" -- False
    print $ canSplitWord t1 "BDGH" -- False
    print $ findAllWords t1
data BTree a = Nil | Node Char (BTree a) (BTree a)
    deriving (Show)

t1 :: BTree Char
t1 = Node 'F' (Node 'B' (Node 'A' Nil Nil)(Node 'D'(Node 'C' Nil Nil)(Node 'E' Nil Nil))) (Node 'G' Nil (Node 'I' (Node 'H' Nil Nil)Nil))

findAllWords :: BTree Char -> [String]
findAllWords Nil = []
findAllWords (Node val Nil Nil) = [[val]]
findAllWords (Node val left right) =
             [(val : elem) | elem <- findAllWords left, extractVal left == head elem] ++
             [(val : elem) | elem <- findAllWords right, extractVal right == head elem] ++
             (findAllWords left) ++
             (findAllWords right) ++ [[val]]
    where
        extractVal (Node val _ _) = val


canSplitWord :: BTree Char -> String -> Bool
canSplitWord (Node _ left right) word = elem word [a ++ b | a <- findAllWords left, b <- findAllWords right, length a > 1, length b > 1]