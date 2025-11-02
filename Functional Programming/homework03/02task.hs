import Data.List
import Data.Maybe

main::IO()
main = do
    print $ findStartWay [ "7-F7-", 
                        ".FJ|7", 
                        "SJLL7", 
                        "|F--J", 
                        "LJ.LJ"] == (2,1) -- my test
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
---------------------------------------------------------
    print $ numEnclosed ["...|.....|...",
                         ".S---7..F--7.",
                         ".|...|--|..|.",
                         ".L---J..L--J.",
                         "...|.....|..."] == 1
    print $ validFill   ["...|.....|...",
                         ".S---7..F--7.",
                         ".|...|--|..|.",
                         ".L---J..L--J.",
                         "...|.....|..."] (2,9) == False --my test
    print $ numEnclosed [".F--S--7.",
                         ".|F---7|.",
                         ".||...||.",
                         ".|L-7FJ|.",
                         ".L--JL-J."] == 1
    print $ numEnclosed [".S-------7.",
                         ".|F-----7|.",
                         ".||.....||.",
                         ".|L-7.F-J|.",
                         ".|..|.|..|.",
                         ".L--J.L--J.",
                         "..........."] == 2
    print $ numEnclosed [".S--------7.",
                         ".|.F----7.|.",
                         ".|.|....|.|.",
                         ".|.|....|.|.",
                         ".|.L-7F-J.|.",
                         ".|...||...|.",
                         ".L---JL---J."] == 3
    print $ numEnclosed ["..F-S-7.",
                          ".FJF-7L7",
                          "FJFJ.L7|",
                          "L-J...LJ"] == 0

----------------------PLAN------------------------------------
-- 1. keep the coords of the loop in a list
-- 2. go through every dot and flood it
-- 3. if the flood was succesful (neighbors are only other dots or parts of the loop) then increment with 1
-- 4. otherwise keep flooded dots in a list and go back to 2. with the flooded dots filtered out

numEnclosed :: [String] -> Int
numEnclosed matrix = helper matrix (0, 0) [] 0
  where
    height = length matrix
    width = length $ head matrix

    helper matrix (x, y) traversed count
      | x * width + y + 1 == height * width = count
      | getValue (x, y) matrix == '.' 
        && validFill matrix (x, y) 
        && (not $ elem (x, y) traversed) =
          helper matrix (x + (div (y + 1) width), mod (y + 1) width) (floodFill matrix (x, y) ++ traversed) (count + 1)
      | otherwise = helper matrix (x + (div (y + 1) width), mod (y + 1) width) traversed count


validFill :: [String] -> (Int, Int) -> Bool
validFill matrix curr = all (\ x -> valid x) (floodFill matrix curr)
    where
        valid pos = length [coords | coords <- findAllNeighbours pos matrix, (getValue coords matrix == '.') || (elem coords (getLoopCoords matrix))] == 4
                
floodFill :: [String] -> (Int, Int) -> [(Int,Int)]
floodFill matrix curr = nub $ helper matrix curr []
    where
        helper matrix curr traversed
         | getValue curr matrix == '.' = curr : concat [helper matrix coords (coords : traversed)| coords <- findAllNeighbours curr matrix, not $ elem coords traversed]
         | otherwise = [] 

getLoopCoords :: [String] -> [(Int,Int)]
getLoopCoords matrix = helper matrix (findStart matrix) (findStartWay matrix) []
    where
        helper matrix curr next traversed
         | getValue next matrix == 'S' = (curr : traversed)
         | otherwise = helper matrix next (findNext curr next matrix) (curr : traversed)


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

findAllNeighbours :: (Int, Int) -> [String] -> [(Int, Int)]
findAllNeighbours coords matrix =
  filter (`validPosition` matrix) potentialNeighbours
  where
    (r, c) = coords
    connections = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    potentialNeighbours = [(r + dr, c + dc) | (dr, dc) <- connections]       

findNext :: (Int, Int) -> (Int, Int) -> [String] -> (Int, Int)
findNext prev current matrix =
  head $ filter (/= prev) $ findNeighbours current matrix

findStartWay :: [String] -> (Int, Int)
findStartWay matrix =
  head $ filter (\coord -> getValue coord matrix /= '.') (findNeighbours (findStart matrix) matrix)
