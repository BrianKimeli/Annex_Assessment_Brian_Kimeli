# Annex Technologies Technical Assessment

This repository contains my solutions for the Annex Technologies Limited technical assessment (May 2026).

## In Progress
- [x] Repository Setup
- [x] Question 1: Find the p-th Factor (C)
- [x] Question 2: Top Scoring Students (SQL)
- [x] Question 3: Top Articles API (C++)

**Author:** Brian Kimeli

### 1. Finding the p-th Factor (C)
- *Constraint Management:* To handle the $n \leq 10^{15}$ constraint, I used an $O(\sqrt{n})$ approach. A standard linear loop would be too slow for this input size.
- *Data Types:* I used `long` as per the function signature, assuming a 64-bit environment to handle the $10^{15}$ constraint. If this were a 32-bit legacy system, I would have used `long long` to prevent overflow.
- *Algorithm Logic:* - The first loop identifies factors from $1$ up to $\sqrt{n}$.
    - The second loop calculates the "partner" factors ($n / i$) in reverse order. This ensures all factors are found in ascending order without the overhead of a sorting algorithm or large memory allocation.
- *Edge Cases:* The implementation correctly handles perfect squares and returns `0` if $n$ has fewer than $p$ factors.

### 2. Top Scoring Students (SQL)
- *Logic:* The query retrieves the `ID` and `NAME` while applying a dual-layer sort. 
- *Sorting Precedence:* - The primary sort is on `SCORE` in descending order (highest scores first). 
    - The secondary sort is on `ID` in ascending order. This acts as a deterministic tie-breaker for students with identical scores (e.g., in the sample data, Dick and Jerry both scored 85.0, but Dick is prioritized because of his lower ID).
- *Optimization:* Used the `LIMIT` clause to ensure only the top three records are processed and returned.

### 3. Top Articles API (C++)
- *Filtering Logic:* I implemented a fallback mechanism for article names. The program prioritizes the `title` field, but drops back to `story_title` if the primary title is missing. Entries missing both are discarded to maintain data quality.
- *Sorting & Ranking:* - *Primary:* Sorted by `num_comments` in descending order (handling nulls as 0).
    - *Secondary:* For articles with the same comment count, I applied an alphabetical sort in descending order (Z to A) on the article name.
- *Scalability:* The logic is designed to handle API pagination by reading the `total_pages` field from the initial response and iterating accordingly to ensure a complete dataset is captured before sorting.
- *Note:* In a production environment, I would implement this using a library like *libcurl* for HTTP requests and *nlohmann/json* for robust parsing. For this assessment, I focused on the core algorithmic logic and data transformation requirements.

### About My Approach
As a Software Engineer, I believe that great software isn't just about solving a problem, it's about building solutions that are efficient, readable, and ready for a team environment. 

Whether I'm optimizing an algorithm for a $10^{15}$ input or refining a SQL query for deterministic results, my goal is to write code that my future colleagues would be happy to work with.

**Why Annex Technologies:**
I admire Annex’s focus on robust, scalable technology solutions within the Kenyan tech ecosystem. My objective is to contribute to a team that values high-performance logic and clean data architecture. I am particularly excited about the prospect of applying my background in software engineering to help Annex continue building secure and efficient services for the local market. I can't wait to be a part of the team and contribute to this vision.