/* * Task: Retrieve top 3 scoring students.
 * Sorting: Score (highest first), then ID (lowest first) for ties.
 */

SELECT 
    ID, 
    NAME
FROM 
    STUDENT
ORDER BY 
    SCORE DESC, 
    ID ASC
LIMIT 3;