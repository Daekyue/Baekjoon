-- 코드를 입력하세요
/*
7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 큰 순서대로 
상위 3개의 맛을 조회하는 SQL 문을 작성해주세요. LIMIT 3
*/
SELECT f.FLAVOR
FROM FIRST_HALF AS f
LEFT JOIN (
  SELECT FLAVOR, SUM(TOTAL_ORDER) AS j_sum
  FROM JULY
  GROUP BY FLAVOR
) AS j ON j.FLAVOR = f.FLAVOR
ORDER BY (f.TOTAL_ORDER + j.j_sum) DESC
LIMIT 3
