SELECT products.name
FROM products, providers
WHERE products.amount BETWEEN 10 AND 20
AND providers.name LIKE 'P%'
AND products.id_providers = providers.id
