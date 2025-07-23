# Write your MySQL query statement below
SELECT NAME 
FROM Customer
WHERE referee_id is null OR referee_id!=2
