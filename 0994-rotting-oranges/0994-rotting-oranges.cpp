class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                auto [i, j] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        grid[ni][nj] == 1) {

                        grid[ni][nj] = 2;
                        fresh--;

                        q.push({ni, nj});
                    }
                }
            }

            minutes++;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes == 0 ? 0 : minutes - 1;
    }
};


#pragma GCC optimize("Ofast")
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void *operator new(size_t size)
{
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void *ptr, unsigned long) {}
void operator delete(void *ptr) {}
void operator delete[](void *ptr) {}