SELECT categories.name, SUM(products.amount)
FROM products, categories
WHERE products.id_categories = categories.id
GROUP BY categories.name
