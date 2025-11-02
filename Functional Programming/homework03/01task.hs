import Data.List
import Data.Maybe

main::IO()
main = do
    print $ perimeter [ "7-F7-", 
                        ".FJ|7", 
                        "SJLL7", 
                        "|F--J", 
                        "LJ.LJ"] == 16
    print $ perimeter [ "-.|F7", 
                        ".S-7|", 
                        "L|7||", 
                        "-L-J|", 
                        "L|-JF"] == 8
    print $ perimeter [ "F--7", 
                        "|F-7",
                        ".S.|", 
                        "|L-J"] == 8

perimeter :: [String] -> Int
perimeter matrix = helper matrix (findStart matrix) (findStartWay matrix) 1
    where
        helper matrix curr next len
         | getValue next matrix == 'S' = len
         | otherwise = helper matrix next (findNext curr next matrix) (len + 1)

cellConnections :: Char -> [(Int, Int)]
cellConnections '|' = [(-1, 0), (1, 0)]
cellConnections '-' = [(0, -1), (0, 1)]
cellConnections 'L' = [(-1, 0), (0, 1)]
cellConnections 'J' = [(-1, 0), (0, -1)]
cellConnections '7' = [(0, -1), (1, 0)]
cellConnections 'F' = [(1, 0), (0, 1)]
cellConnections 'S' = [(0, -1), (0, 1), (-1, 0), (1, 0)]
cellConnections '.' = []

findStart :: [String] -> (Int, Int)
findStart matrix = (row, col)
  where
    row = fromJust $ findIndex (elem 'S') matrix --did this the lazy way with data.maybe
    col = fromJust $ elemIndex 'S' (matrix !! row)

getValue :: (Int, Int) -> [String] -> Char
getValue (r, c) matrix = (matrix !! r) !! c

validPosition :: (Int, Int) -> [String] -> Bool
validPosition (r, c) matrix =
  r >= 0 && r < length matrix && c >= 0 && c < length (head matrix)

findNeighbours :: (Int, Int) -> [String] -> [(Int,Int)]
findNeighbours coords matrix =
  filter (`validPosition` matrix) potentialNeighbours
  where
    (r, c) = coords
    connections = cellConnections $ getValue coords matrix
    potentialNeighbours = [(r + dr, c + dc) | (dr, dc) <- connections]

findNext :: (Int, Int) -> (Int, Int) -> [String] -> (Int, Int)
findNext prev current matrix =
  head $ filter (/= prev) $ findNeighbours current matrix

findStartWay :: [String] -> (Int, Int)
findStartWay matrix =
  head $ filter (\coord -> getValue coord matrix /= '.') (findNeighbours (findStart matrix) matrix)
