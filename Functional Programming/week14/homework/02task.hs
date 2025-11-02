main::IO()
main = do
    print $ controller "" == ""
    print $ controller "........" == "00000000"
    print $ controller "P...." == "12345"
    print $ controller "P.P.." == "12222"
    print $ controller "..P...O..." == "0012343210"
    print $ controller "P.P.P...." == "122234555"

controller :: String -> String
controller input = helper input 0 0
  where
    bounds x = min 5 (max 0 x)
    helper [] _ _ = []
    helper ('P' : rest) curr 1 = show (bounds curr) ++ helper rest (bounds curr) 0
    helper ('P' : rest) curr state = show (bounds (curr + 1)) ++ helper rest (bounds (curr + 1)) 1
    helper ('O' : rest) curr state = show (bounds (curr - 1)) ++ helper rest (bounds (curr - 1)) (-state)
    helper ('.' : rest) curr state = show (bounds (curr + state)) ++ helper rest (bounds (curr + state)) state
