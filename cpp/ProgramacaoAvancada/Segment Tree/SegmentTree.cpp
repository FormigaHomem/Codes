#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN (long) 101010

using namespace std;

long N, Q, segt[MAXN], v[MAXN];

/* build(idx, l, r): O(N)
idx = posição do nó, [l, r] = intervalo no vetor v*/
void build(int idx, int l, int r){
    if(l == r){
        segt[idx] = v[l];
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;

    build(next, l, mid); // ir para a esquerda
    build(next + 1, mid + 1, r); // ir para a direita

    segt[idx] = segt[next] + segt[next + 1];

    return;
}

/* update(idx, l, r, x, y, k): O(logN)
idx = posição do nó, [l, r] = intervalo no vetor v, [x, y] = intervalo no vetor que quero saber a resposta, k = valor novo*/
void update(int idx, int l, int r, int x, int y, int k){
    if(l > y or r < x) return;
    if(l >= x and r <= y){
        segt[idx] = k;
        return;
    }

    int mid = (l + r) / 2, next = 2 * idx;
    update(next, l, mid, x, y, k);
    update(next + 1, mid + 1, r, x, y, k);

    segt[idx] = segt[next] + segt[next + 1];
    
    return;
}

/* query(idx, l, r, x, y): O(logN)
idx = posição do nó, [l, r] = intervalo no vetor v, [x, y] = intervalo no vetor que quero saber a resposta*/
long query(int idx, int l, int r, int x, int y){
    if(l > y or r < x) return 0;
    if(l >= x and r <= y) return segt[idx];

    int mid = (l + r) / 2, next = 2 * idx;

    return query(next, l, mid, x, y) + query(next + 1, mid + 1, r, x, y);
}

int main(){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    build(1, 0, N);

    cin >> Q;

    while(Q--){
        int task, x, y, k;
        
        cin >> task >> x >> y;

        if(task == 1){
            cin >> k;
            update(1, 0, N, x, y, k);
        }

        else cout << query(1, 0, N, x, y) << endl;
    }
}