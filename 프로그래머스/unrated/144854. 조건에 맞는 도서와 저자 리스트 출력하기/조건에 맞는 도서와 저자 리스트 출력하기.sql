-- 코드를 입력하세요
SELECT BOOK_ID, AUTHOR_NAME, DATE_FORMAT(PUBLISHED_DATE,"%Y-%m-%d")
FROM BOOK LEFT JOIN AUTHOR USING(AUTHOR_ID)
WHERE CATEGORY="경제"
ORDER BY PUBLISHED_DATE