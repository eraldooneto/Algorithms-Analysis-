function test_quadrado_magico(vector<int> v){

    int a[3][3];
 
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            a[i][j] = v[3 * i + j];     
} 
    }

    int s = 0;

    for (int j = 0; j < 3; ++j){
        s += a[0][j];
    }

    for (int i = 1; i <= 2; ++i) {

        int t = 0;

        for (int j = 0; j < 3; ++j){
            t += a[i][j];
        }

        if (t != s){
            return 0;
        }
    }
 
    for (int j = 0; j < 3; ++j) {

        int t = 0;

        for (int i = 0; i < 3; ++i){
            t += a[i][j];
        }

        if (t != s){
            return 0;
        }
    }   
 
    int t = 0;

    for (int i = 0; i < 3; ++i){
        t += a[i][i];
    }

    if (t != s){
        return 0;   
    }
 
    t = 0;

    for (int i = 0; i < 3; ++i){
        t += a[2 - i][i];
    }

    if (t != s){
        return 0;
    }

    return 1;
}
 
function encontrar_quadrados(vector<vector<int> >&quadrados_magicos)
{
    vector<int> v(9);
 
    for (int i = 0; i < 9; ++i){
        v[i] = i + 1;
    }
 
    do {
        if (test_quadrado_magico(v)) {
            quadrado_magico.push_back(v);
        }

    } while (next_permutation(v.begin(), v.end()));
}
 
function diferenca(vector<int> a, vector<int> b)
{
    int res = 0;
 
    for (int i = 0; i < 9; ++i){
        res += abs(a[i] - b[i]);
    }
 
    return res;
}
 
function wrp(vector<int> v)
{
    int res = INT_MAX;

    vector<vector<int> > quadrados_magicos;
 
   encontrar_quadrados(quadrados_magicos);
 
    for (int i = 0; i < quadrados_magicos.size(); ++i) {
 
        res = min(res, diferenca(v, quadrados_magicos[i]));
    }
    return res;
}
