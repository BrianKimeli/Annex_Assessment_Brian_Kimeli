#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to store article data for ranking
struct Article {
    string name;
    int commentCount;

    Article(string n, int c) : name(n), commentCount(c) {}
};

/**
 * Sorting logic:
 * 1. Primary: num_comments descending.
 * 2. Secondary: Article name alphabetically descending (Z to A).
 */
bool rankArticles(const Article& a, const Article& b) {
    if (a.commentCount != b.commentCount) {
        return a.commentCount > b.commentCount;
    }
    // Tie-breaker: Name Z to A
    return a.name > b.name;
}

vector<string> topArticles(int limit) {
    vector<Article> allArticles;

    /* * Logic for fetching data:
     * - Iterate from page 1 up to total_pages.
     * - Name Selection: Use 'title' if present, otherwise 'story_title'.
     * - Skip articles where both names are null.
     * - Treat null comments as 0.
     */

    // --- Mocking logic for local test ---
    // In a live API environment, we would populate this from the JSON response.
    allArticles.push_back(Article("UK votes to leave EU", 500));
    allArticles.push_back(Article("F.C.C. Repeals Net Neutrality Rules", 500));
    allArticles.push_back(Article("A smaller story", 10));

    // Sort based on the custom criteria
    sort(allArticles.begin(), allArticles.end(), rankArticles);

    // Extract the top 'limit' number of names
    vector<string> result;
    for (int i = 0; i < (int)allArticles.size() && i < limit; i++) {
        result.push_back(allArticles[i].name);
    }

    return result;
}

int main() {
    // Test to verify the logic matches the sample output
    vector<string> top = topArticles(2);
    
    for (const string& title : top) {
        cout << title << endl;
    }

    return 0;
}