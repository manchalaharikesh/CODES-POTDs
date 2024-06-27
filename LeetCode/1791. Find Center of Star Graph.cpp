// DATE: 27-JUN-2024
// Question URL: https://leetcode.com/problems/find-center-of-star-graph/description/

// Question: 1791. Find Center of Star Graph
// Description: There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

//              You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
// Approach: 1. As the graph is a star graph only one center node exists and everyother node must be connected to it. Thus we just need to find the common node in any two edges given.
//              Thus we need to check all four possibilities like, edges[0][0] == edges[1][0], edges[0][0] == edges[1][1], edges[0][1] == edges[1][0], edges[0][1] == edges[1][1].

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] ? edges[0][0] : edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1] == edges[1][0] ? edges[0][1] : edges[0][1];
    }
};