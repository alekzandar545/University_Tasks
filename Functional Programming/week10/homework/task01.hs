type Node = Int
type Graph = [(Node, [Node])]
type Path = [Node]

main :: IO ()
main = do
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 0 1 == [[1]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1, 2], [1, 3]]
    print $ simplePaths [(1, [2, 3, 4]), (2, [3, 4]), (3, []), (4, [])] 1 1 == [[1,2],[1,3],[1,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 2 1 == [[1, 2, 3], [1, 2, 4]]
    print $ simplePaths [(1, [2, 3]), (2, [3, 4]), (3, []), (4, [])] 1 2 == [[2,3],[2,4]]
    print $ simplePaths [(1, [2, 3]), (2, [3]), (3, []), (4, [])] 1 2 == [[2,3]]
    print $ simplePaths [(1, [2, 3]), (2, [3]), (13, []), (4, [])] 1 2 == [[2,3]] --my test (error)

--should throw error when child is not a val and when original input is wrong

simplePaths :: Graph -> Int -> Int -> [Path]
simplePaths graph len index = findPaths startNode len
  where
    startNode = graph !! (index - 1)
    findChildren val = head [children | (v, children) <- graph, v == val] --only one rly
    findPaths :: (Node, [Node]) -> Int -> [Path]
    findPaths (val, children) 0 = [[val]] 
    findPaths (val, children) k =
        [ val : path | child <- children, path <- findPaths (child, findChildren child) (k - 1), 
            if elem child $ map (\ (v,ch) -> v) graph then True else error ("Child is not a node!")]
