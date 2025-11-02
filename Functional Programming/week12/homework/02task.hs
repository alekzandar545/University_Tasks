main::IO()
main = do
    print $ highestCapital [Country "Bulgaria" "Sofia" [City "Varna" 0 16, City "Plovdiv" 120 14, City "Sofia" 420 13], Country "Germany" "Berlin" [City "Munich" 200 15, City "Berlin" 150 12, City "Ulm" 210 15], Country "France" "Paris" [City "Paris" 180 15, City "Nice" 0 14, City "Lyon" 500 13]] == "France" --pretty sure its france in the example
    print $ highestCapital [Country "Bulgaria" "Sofia" [City "Varna" 0 16, City "Plovdiv" 120 14, City "Sofia" 420 13], Country "Germany" "Berlin" [City "Munich" 200 15, City "Berlin" 150 12, City "Ulm" 210 15]] == "Bulgaria" --my example

type Name = String
type Capital = Name
type AvgYearlyTemperature = Double
type Elevation = Int
data City = City Name Elevation AvgYearlyTemperature
data Country = Country Name Capital [City]

-- without getName
highestCapital :: [Country] -> Name
highestCapital = fst . foldl (\(resName, maxElev) (Country name capital cities) -> if elev (Country name capital cities) > maxElev then (name, elev (Country name capital cities)) else (resName, maxElev)) ("", -1)
    where
        elev (Country _ _ cities) = maximum [e | (City _ e _) <- cities]

