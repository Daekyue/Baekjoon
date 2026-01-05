select SUM(PRICE) AS TOTAL_PRICE
from ITEM_INFO 
group by RARITY
having rarity = 'LEGEND'