-- 코드를 작성해주세요
# SELECT ID
# FROM ECOLI_DATA
# WHERE PARENT_ID IN(
#         SELECT ID
#         FROM ECOLI_DATA
#         WHERE PARENT_ID IN
#         (
#             SELECT ID
#             FROM ECOLI_DATA
#             WHERE ISNULL(PARENT_ID)
#         )
#     )
# ORDER BY ID
SELECT e3.id
FROM ECOLI_DATA AS e3
    JOIN ECOLI_DATA AS e2 
        ON e3.PARENT_ID = e2.ID
    JOIN ECOLI_DATA AS e1 
        ON e2.PARENT_ID = e1.ID
WHERE e1.PARENT_ID IS NULL
ORDER BY e3.ID;