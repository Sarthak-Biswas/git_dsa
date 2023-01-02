# Dijkstras Important notes :

## Priority queue in C++ stl :
1. For max-heap  
   ```priority_queue<int>```
2. For min-heap  
   ```priority_queue<int, vector<int>, greater<int>>```
3. For pairs (max-heap on first element in pair)  
   ```priority_queue<pair<int, int>>```
4. For pairs (min-heap on first element in pair)  
   ```priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>```
5. For pairs (max/min-heap on second element in pair)  
   ```priority_queue<pair<int, int>, vector<pair<int, int>>, myComp>```  
   Use a custom operator overloading

### About opertor overloading :
- Use this for max-heap  
   ```
   struct myComp{
        bool operator()(
            pair<int,int> const &a,
            pair<int,int> const &b
        ){
            return a.second>b.second;
        }
    };
    ```
- Use this for min-heap  
   ```
   struct myComp{
        bool operator()(
            pair<int,int> const &a,
            pair<int,int> const &b
        ){
            return a.second<b.second;
        }
    };
    ```

## Concept :
- Priority queue stores the edges of shortest path.
- If edge shorter than this exists from the edge to child edge, it is pushed in the queue.
- Repeat until priority queue is empty or destination edge is reached.
- It works because no negative edge exists. So this greedy approach works.

## Drawbacks :
- Does not work for negative weights.
- Slower than directed topological shortest path.
- Time complexity = O(V.logE)