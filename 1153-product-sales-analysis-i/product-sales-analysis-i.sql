# Write your MySQL query statement below
SELECT Product.product_name, Sales.year, Sales.price
FROM Sales
LEFT JOIN Product on Sales.product_id=Product.Product_id