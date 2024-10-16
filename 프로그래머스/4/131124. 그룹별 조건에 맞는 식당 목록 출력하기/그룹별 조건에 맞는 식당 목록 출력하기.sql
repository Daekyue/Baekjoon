# MEMBER_PROFILE와 REST_REVIEW 테이블에서 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회하는 SQL문을 작성해주세요. 
# 회원 이름, 리뷰 텍스트, 리뷰 작성일이 출력되도록 작성해주시고, 결과는 리뷰 작성일을 기준으로 오름차순, 
# 리뷰 작성일이 같다면 리뷰 텍스트를 기준으로 오름차순 정렬해주세요.
SELECT
P.MEMBER_NAME,
R.REVIEW_TEXT,
DATE_FORMAT(R.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_TEXT
FROM MEMBER_PROFILE AS P
JOIN REST_REVIEW AS R
ON P.MEMBER_ID = R.MEMBER_ID

WHERE P.MEMBER_ID IN
    (
        SELECT
        MEMBER_ID
        FROM REST_REVIEW

        GROUP BY MEMBER_ID
        HAVING COUNT(REVIEW_TEXT)=
            (SELECT
                COUNT(REVIEW_TEXT)
             FROM REST_REVIEW

             GROUP BY MEMBER_ID
             ORDER BY COUNT(REVIEW_TEXT) DESC
             LIMIT 1
            )
    )
ORDER BY REVIEW_DATE ASC, REVIEW_TEXT ASC