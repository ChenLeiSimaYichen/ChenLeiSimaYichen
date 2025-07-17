#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

// 定义棋子类型枚举
enum Type { S, A, V, H };

// 定义棋子结构体
struct Chess {
    Type type;    // 棋子类型
    int x, y;     // 棋子坐标
    // 构造函数，初始化棋子类型和坐标
    Chess(Type t, int xx, int yy) : type(t), x(xx), y(yy) {}
    // 定义小于运算符，用于棋子排序（先比较类型，再比较x坐标，最后比较y坐标）
    bool operator<(const Chess& other) const {
        if (type != other.type) return type < other.type;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// 定义游戏状态结构体
struct State {
    vector<Chess> pieces;  // 该状态下的所有棋子
    bool skillUsed;        // 是否使用过易位技能
    int time;              // 到达该状态的时间
    // 构造函数，初始化状态
    State(const vector<Chess>& p, bool s, int t) : pieces(p), skillUsed(s), time(t) {}
    // 定义大于运算符，用于优先队列比较
    bool operator>(const State& other) const {
        // 考虑技能使用情况，未使用技能的状态可能有更优潜力
        int thisPotential = time + (skillUsed ? 3 : 0);
        int otherPotential = other.time + (other.skillUsed ? 3 : 0);
        if (thisPotential != otherPotential) {
            return thisPotential > otherPotential;
        }
        // 潜力相同，时间短的优先
        return time > other.time;
    }
};

// 判断位置是否合法（在0<=x<4且0<=y<5范围内）
bool isLegal(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 5;
}

// 检查棋子移动后是否与其他棋子冲突（排除当前移动的棋子本身）
bool isConflict(const Chess& moved, const vector<Chess>& pieces, size_t excludeIndex) {
    vector<pair<int, int>> occupied;
    // 根据移动棋子的类型，确定其占据的位置
    switch (moved.type) {
    case S:
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                occupied.emplace_back(moved.x + i, moved.y + j);
        break;
    case V:
        for (int i = 0; i < 2; ++i)
            occupied.emplace_back(moved.x, moved.y + i);
        break;
    case H:
        for (int i = 0; i < 2; ++i)
            occupied.emplace_back(moved.x + i, moved.y);
        break;
    case A:
        occupied.emplace_back(moved.x, moved.y);
        break;
    }
    // 检查占据的位置是否有非法坐标
    for (auto& pos : occupied)
        if (!isLegal(pos.first, pos.second)) return true;

    // 检查与其他棋子是否冲突
    for (size_t j = 0; j < pieces.size(); ++j) {
        if (j == excludeIndex) continue; // 跳过当前移动的棋子
        const auto& p = pieces[j];
        vector<pair<int, int>> pOccupied;
        // 根据其他棋子的类型，确定其占据的位置
        switch (p.type) {
        case S:
            for (int i = 0; i < 2; ++i)
                for (int k = 0; k < 2; ++k)
                    pOccupied.emplace_back(p.x + i, p.y + k);
            break;
        case V:
            for (int i = 0; i < 2; ++i)
                pOccupied.emplace_back(p.x, p.y + i);
            break;
        case H:
            for (int i = 0; i < 2; ++i)
                pOccupied.emplace_back(p.x + i, p.y);
            break;
        case A:
            pOccupied.emplace_back(p.x, p.y);
            break;
        }
        // 检查是否有位置重叠（冲突）
        for (auto& pos1 : occupied)
            for (auto& pos2 : pOccupied)
                if (pos1 == pos2) return true;
    }
    return false;
}

// 生成状态键（用于哈希表记录状态）
string getKey(const vector<Chess>& pieces, bool skillUsed) {
    vector<Chess> sorted = pieces;
    sort(sorted.begin(), sorted.end()); // 排序棋子，确保相同布局生成相同键
    string key = skillUsed ? "1" : "0"; // 记录是否使用过技能
    for (const auto& p : sorted)
        key += to_string(p.type) + to_string(p.x) + to_string(p.y); // 拼接棋子信息
    return key;
}

// 解析输入字符串为棋子向量
vector<Chess> parseInput() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<Chess> pieces;
    string token;
    while (iss >> token) {
        Type t;
        // 根据输入字符确定棋子类型
        if (token[0] == 'S') t = S;
        else if (token[0] == 'A') t = A;
        else if (token[0] == 'V') t = V;
        else if (token[0] == 'H') t = H;
        int x = token[1] - '0'; // 解析x坐标
        int y = token[2] - '0'; // 解析y坐标
        pieces.emplace_back(t, x, y); // 添加棋子到向量
    }
    return pieces;
}


int main()
{
    vector<Chess> initial = parseInput(); // 解析输入得到初始棋子布局
    Chess s_piece = initial[0];
    // 初始位置就是终点，直接输出0
    if (s_piece.x == 1 && s_piece.y == 3) {
        cout << 0 << endl;
        return 0;
    }

    priority_queue<State, vector<State>, greater<State>> pq; // 优先队列（潜在时间短的优先）
    unordered_map<string, int> visited; // 记录状态的最短到达时间

    pq.emplace(initial, false, 0); // 初始状态入队（未使用技能，时间0）
    string initialKey = getKey(initial, false); // 初始状态键
    visited[initialKey] = 0; // 记录初始状态时间

    const int dx[] = { 1, -1, 0, 0 }; // 移动方向（上下左右）
    const int dy[] = { 0, 0, 1, -1 };

    while (!pq.empty())
    {
        State current = pq.top(); // 取出当前时间最短的状态
        pq.pop();

        // 检查当前状态是否已找到更优解（已有更短时间到达该状态）
        if (visited[getKey(current.pieces, current.skillUsed)] < current.time) continue;

        // 检查当前状态是否到达终点（S棋子到达(1,3)）
        for (const auto& p : current.pieces) {
            if (p.type == S && p.x == 1 && p.y == 3) {
                cout << current.time << endl;
                return 0;
            }
        }

        // 生成所有可能的移动
        for (size_t i = 0; i < current.pieces.size(); ++i) {
            Chess piece = current.pieces[i];
            // 普通移动（四个方向）
            for (int dir = 0; dir < 4; ++dir) {
                int nx = piece.x + dx[dir]; // 计算新坐标
                int ny = piece.y + dy[dir];
                Chess moved(piece.type, nx, ny); // 移动后的棋子
                vector<Chess> newPieces = current.pieces;
                newPieces[i] = moved; // 更新棋子布局

                // 检查移动是否冲突
                if (!isConflict(moved, newPieces, i)) {
                    int newTime = current.time;
                    // 如果是S棋子且已使用技能，移动时间增加4（根据规则）
                    if (piece.type == S && current.skillUsed)
                        newTime += 4;
                    else
                        newTime += 1; // 否则时间加1
                    string key = getKey(newPieces, current.skillUsed); // 生成新状态键
                    // 如果新状态未记录或新时间更短，更新记录并入队
                    if (!visited.count(key) || visited[key] > newTime) {
                        visited[key] = newTime;
                        pq.emplace(newPieces, current.skillUsed, newTime);
                    }
                    // 检查新状态是否到达终点
                    for (const auto& p : newPieces) {
                        if (p.type == S && p.x == 1 && p.y == 3) {
                            cout << newTime << endl;
                            return 0;
                        }
                    }
                }
            }
            // 易位技能（仅S棋子且未使用过技能时）
            if (piece.type == S && !current.skillUsed) {
                for (int dir = 0; dir < 4; ++dir) {
                    int adjX = piece.x + dx[dir]; // 计算相邻坐标
                    int adjY = piece.y + dy[dir];
                    for (size_t j = 0; j < current.pieces.size(); ++j) {
                        if (j == i) continue; // 跳过自己
                        const Chess& adj = current.pieces[j];

                        // 检查是否是H类型且位置符合易位条件
                        if (adj.type == H && adj.x == adjX && (adj.y == piece.y + 2 || adj.y == piece.y - 1)) {
                            Chess newS(S, adjX, adjY); // S移动后的位置
                            Chess newAdj = adj; // 被交换棋子
                            // 被交换棋子基于S原位置反方向移动两格
                            newAdj.x = piece.x;
                            newAdj.y = piece.y - dy[dir] * 2;
                            vector<Chess> newPieces = current.pieces;
                            newPieces[i] = newS;
                            newPieces[j] = newAdj;

                            bool conflict = false;
                            // 检查新位置是否冲突
                            conflict |= isConflict(newS, newPieces, i);
                            conflict |= isConflict(newAdj, newPieces, j);
                            if (!conflict) {
                                string key = getKey(newPieces, true); // 标记使用了技能
                                int newTime = current.time + 1;
                                // 检查是否更优
                                if (!visited.count(key) || newTime < visited[key]) {
                                    visited[key] = newTime;
                                    pq.emplace(newPieces, true, newTime);
                                }
                                // 检查新状态是否到达终点
                                for (const auto& p : newPieces) {
                                    if (p.type == S && p.x == 1 && p.y == 3) {
                                        cout << newTime << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                        // 检查是否是V类型且位置符合易位条件
                        if (adj.type == V && adj.y == adjY && (adj.x == piece.x + 2 || adj.x == piece.x - 1)) {
                            Chess newS(S, adjX, adjY);
                            Chess newAdj = adj;
                            // 被交换棋子基于S原位置反方向移动两格
                            newAdj.x = piece.x - dx[dir] * 2;
                            newAdj.y = piece.y - dy[dir] * 2;
                            vector<Chess> newPieces = current.pieces;
                            newPieces[i] = newS;
                            newPieces[j] = newAdj;

                            bool conflict = false;
                            conflict |= isConflict(newS, newPieces, i);
                            conflict |= isConflict(newAdj, newPieces, j);
                            if (!conflict) {
                                string key = getKey(newPieces, true);
                                int newTime = current.time + 1;
                                if (!visited.count(key) || newTime < visited[key]) {
                                    visited[key] = newTime;
                                    pq.emplace(newPieces, true, newTime);
                                }
                                // 检查新状态是否到达终点
                                for (const auto& p : newPieces) {
                                    if (p.type == S && p.x == 1 && p.y == 3) {
                                        cout << newTime << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
}
