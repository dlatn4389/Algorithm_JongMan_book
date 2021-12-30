#include <iostream>
#include <algorithm>
using namespace std;

#include <queue>

// 쿼드트리를 뒤집은 결과를 반환하는 함수
string reverse_quadtree(queue<char> &q) {
    // 큐에서 원소를 꺼내고 지움
    // 다만 이 과정은 iterator로도 수행할 수 있으니, 미처 생각하지 못함
    char c = q.front();
    q.pop();

    // x가 아니라면 곧바로 return
    if (c=='w' or c=='b') {
        return string(1, c);
    }
    // x라면 네 부분으로 분할
    string left_up = reverse_quadtree(q);
    string right_up = reverse_quadtree(q);
    string left_down = reverse_quadtree(q);
    string right_down = reverse_quadtree(q);
    
    // 네 부분으로 분할한 후 다시 합침
    return "x"+left_down+right_down+left_up+right_up;
}

int main() {
    string quadtree;
    cin >> quadtree;

    // string의 모든 char을 큐에 추가
    queue<char> q;
    auto iter = quadtree.begin();

    while (iter!=quadtree.end()) {
        q.push(*iter);
        iter++;
    }
    
    cout << reverse_quadtree(q);
}