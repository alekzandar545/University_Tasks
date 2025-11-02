import Data.List

main::IO()
main = do
    print $ isValidSudoku [[1, 2, 3, 4, 5, 6, 7, 8],
                           [5, 6, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 7, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]] == True
    print $ isValidSudoku [[1, 6, 3, 4, 5, 6, 7, 8],
                           [5, 2, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 7, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]] == False
    print $ isValidSudoku [[1, 2, 3, 4, 5, 6, 7, 8],
                           [5, 6, 7, 8, 1, 2, 3, 4],
                           [2, 3, 4, 1, 6, 5, 8, 7],
                           [6, 5, 8, 7, 2, 3, 4, 1],
                           [3, 4, 1, 2, 2, 8, 5, 6],
                           [7, 8, 5, 6, 3, 4, 1, 2],
                           [4, 1, 2, 3, 8, 7, 6, 5],
                           [8, 7, 6, 5, 4, 1, 2, 3]] == False

checkValidity :: [[Int]] -> Bool
checkValidity = all (\ xs -> length xs == 8) . map (\ xs -> nub xs)

isValidSudoku :: [[Int]] -> Bool
isValidSudoku matrix = checkRows && checkCols && checkBoxes
 where
    checkRows = checkValidity matrix
    checkCols = checkValidity $ transpose matrix 
    checkBoxes = all checkValidity (extractBoxes matrix)
      where
        extractBoxes [] = []
        extractBoxes (r1:r2:rest)
            | null r1 || null r2 = extractBoxes rest
            | otherwise = [take 4 r1 ++ take 4 r2] : extractBoxes ((drop 4 r1):(drop 4 r2):rest)

                