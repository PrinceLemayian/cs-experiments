-- Haskell functional programming example
-- A pure, recursive function to calculate the sum of squares of a list

sumOfSquares :: [Int] -> Int
sumOfSquares [] = 0
sumOfSquares (x:xs) = (x * x) + sumOfSquares xs

main :: IO ()
main = do
    let numbers = [1, 2, 3, 4, 5]
    let result = sumOfSquares numbers
    putStrLn ("The sum of squares is " ++ show result)
