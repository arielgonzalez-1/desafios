SELECT customers.name, orders.id
FROM customers, orders
WHERE orders.orders_date BETWEEN '2016-01-01' AND '2016-06-30'
AND customers.id = orders.id_customers
