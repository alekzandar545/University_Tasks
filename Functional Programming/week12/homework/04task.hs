import Data.List

main::IO()
main = do
    print $ closestAverage [(Temp 1 23.6), (Temp 6 24.2), (Temp 11 24.2), (Temp 16 21.2), (Temp 21 23.8), (Temp 26 26.5), (Temp 31 24.5)] == 21
    print $ closestAverage [(Temp 1 23.1)] == 1 --my test

data Measuring = Temp Int Float

-- avg :: (Num a) => [a] => Double
findAverage :: [Measuring] -> Float
findAverage measurements = total / count
  where
    total = sum [val | (Temp _ val) <- measurements]
    count = fromIntegral $ length measurements

-- without "get"-ter type functions
-- utilize LC
closestAverage :: [Measuring] -> Int
closestAverage measurements = fst $ foldl (\ (resDay,resVal) (Temp day val) -> if abs (resVal - avg) < abs (val - avg) then (resDay,resVal) else (day,val)) (0,-100) measurements
    where
        avg = findAverage measurements
    