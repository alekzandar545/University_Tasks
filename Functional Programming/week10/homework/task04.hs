main::IO()
main = do
    print $ getAreas [Circle 5, Rectangle 2.5 4.5, Rectangle 5.5 20.6, Triangle 5.3 3.9 4.89, Cylinder 20 30] == [78.53981633974483,11.25,113.30000000000001,9.127927385194024,6283.185307179587]
    print $ maxArea [Circle 5, Rectangle 2.5 4.5, Rectangle 5.5 20.6, Triangle 5.3 3.9 4.89, Cylinder 20 30] == Cylinder 20.0 30.0
    print $ maxArea [Circle 5] == Circle 5.0 -- my test
data Shape a = Circle a | Rectangle a a | Triangle a a a | Cylinder a a
    deriving (Show, Eq, Read, Ord)

area :: (Num a, Floating a) => Shape a -> a
area (Circle r) = pi*r*r
area (Rectangle x y) = x*y
area (Triangle x y z) = sqrt $ p * (p - x) * (p - y) * (p - z)
    where p = (x + y + z) / 2 
area (Cylinder r h) = 2*pi*r*h + 2*pi*r*r

getAreas :: (Num a, Floating a) => [Shape a] -> [a]
getAreas = map area 

maxArea :: (Num a, Floating a, Ord a) => [Shape a] -> Shape a
maxArea = foldl1 (\ acc x -> if area x > area acc then x else acc)
