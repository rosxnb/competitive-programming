#include <iostream>
#include <vector>
#include <climits>

int tsp(const std::vector<std::vector<int>>& distances, int current_pos, int visited_cities, int total_cities, std::vector<std::vector<int>>& dp)
{
    // reached final node? return distance from final node to start node
    if ( visited_cities == (1 << total_cities) - 1 )
        return distances[current_pos][0];

    int& computed = dp[visited_cities][current_pos];
    if (computed != -1)
        return computed;

    // cities remained to explore?
    int ans = INT_MAX;
    for (int city = 0; city < total_cities; ++city)
    {
        bool not_visited = ( visited_cities & (1 << city) ) == 0;
        if (not_visited)
        {
            int subprob = distances[current_pos][city] + tsp(distances, city, (visited_cities | (1 << city)), total_cities, dp);
            ans         = std::min(ans, subprob);
        }
    }

    return computed = ans;
}

int main()
{
    std::vector<std::vector<int>> distances = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    }; // Ans: 85
    int total_cities    = distances.size();

    // dp array
    // total state possible is: 2^N
    std::vector<std::vector<int>> dp( (1 << total_cities), std::vector<int>(total_cities, -1) );

    // using bitmasking to recored visited cities
    int start_pos       = 3;
    int visited_cities  = 1 << start_pos;
    std::cout << tsp(distances, start_pos, visited_cities, total_cities, dp) << std::endl;

    return 0;
}
