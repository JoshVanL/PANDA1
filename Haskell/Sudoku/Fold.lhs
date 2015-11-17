Preamble
========

The following lines define this module and make sure that your
definitions won't conflict with those from the `Prelude`.

> module Fold where
> import Prelude hiding (sum, product, length, and, or, all, some, filter)

Tasks
=====

The tasks for you to complete are below:

> -- TODO #F1
> sum :: Num a => [a] -> a
> sum (x:xs) = foldr (+) 0 (x:xs)

> -- TODO #F2
> product :: Num a => [a] -> a
> product (x:xs) = foldr (*) 1 (x:xs)

> -- TODO #F3
> and :: [Bool] -> Bool
> and (x:xs) = foldr (&&) True (x:xs)

> -- TODO #F4
> or :: [Bool] -> Bool
> or (x:xs) = foldr (||) False (x:xs)

> -- TODO #F5
> all :: (a -> Bool) -> [a] -> Bool
> all p []  = False
> all p xs = and (map p xs)

> -- TODO #F6
> some :: (a -> Bool) -> [a] -> Bool
> some p [] = False
> some p xs = or (map p xs)

> -- TODO #F7
> length :: [a] -> Int
> length xs = foldr inc 0 xs
>       where inc _ b = b + 1

> -- TODO #F8
> filter :: (a -> Bool) -> [a] -> [a]
> filter p xs = foldr (addtolist) [] xs where
>       addtolist a bs
>        | p a = a:bs
>        | otherwise = bs

> -- TODO #F9
> group :: Eq a => [a] -> [[a]]
> group = foldr f [] where
>    f x [] = [[x]]
>    f x ((y:ys):yss)
>         | x == y = (x:y:ys):yss
>         | otherwise = [x]:((y:ys):yss)

> -- TODO #F10
> transpose :: [[a]] -> [[a]]
> transpose = foldr f g where
>        f = zipWith (:)
>        g = repeat []

> -- TODO #F11
> permute :: [a] -> [[a]]
> permute = undefined
