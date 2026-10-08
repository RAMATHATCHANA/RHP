#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<vector<bool>>>& vis,vector<vector<char>>& mat, int r,int c,int fr,int fc,int sr,int sc){
    if(fr > sr || (fr == sr && fc > sc)){
        swap(fr,sr);
        swap(fc,sc);
    }
    int orient;
    if(fr==sr){
        orient=0;
    }else{
        orient=1;
    }
    if(vis[fr][fc][orient]) return false;
    vis[fr][fc][orient]=true;
    if(orient==0){
        int dir[8][4]={
            {-1,0,-1,0},{1,0,1,0},{0,-1,0,-1},{0,1,0,1},
            {0,0,-1,-1},{0,0,1,-1},{-1,1,0,0},{1,1,0,0}
        };
        int far=0,fac=0,sar=0,sac=0;
        for(int i=0;i<8;i++){
            far=fr+dir[i][0];
            fac=fc+dir[i][1];
            sar=sr+dir[i][2];
            sac=sc+dir[i][3];
            if(0<=far && far<r && 0<=fac && fac<c && 0<=sar && sar<r && 0<=sac && sac<c && mat[far][fac]!='H' && mat[sar][sac]!='H'){
                if(i >= 4) {
                    int minr = min({fr, sr, far, sar});
                    int maxr = max({fr, sr, far, sar});
                    int minc = min({fc, sc, fac, sac});
                    int maxc = max({fc, sc, fac, sac});
                    bool blocked = false;
                    for(int x = minr; x <= maxr; x++) {
                        for(int y = minc; y <= maxc; y++) {
                            if(mat[x][y] == 'H') {
                                blocked = true;
                            }
                        }
                    }
                    if(blocked) {
                        continue;
                    }
                }
                if(mat[far][fac]=='S' && mat[sar][sac]=='S'){
                    return true;
                }else{
                    if(dfs(vis,mat,r,c,far,fac,sar,sac)){
                        return true;
                    }
                }
            }
        }
    }else{
        int dir[8][4]={
            {-1,0,-1,0},{1,0,1,0},{0,-1,0,-1},{0,1,0,1},
            {0,0,-1,-1},{0,0,-1,1},{1,-1,0,0},{1,1,0,0} 
        };
        int far=0,fac=0,sar=0,sac=0;
        for(int i=0;i<8;i++){
            far=fr+dir[i][0];
            fac=fc+dir[i][1];
            sar=sr+dir[i][2];
            sac=sc+dir[i][3];
            if(0<=far && far<r && 0<=fac && fac<c && 0<=sar && sar<r && 0<=sac && sac<c && mat[far][fac]!='H' && mat[sar][sac]!='H'){
                if(i >= 4) {
                    int minr = min({fr, sr, far, sar});
                    int maxr = max({fr, sr, far, sar});
                    int minc = min({fc, sc, fac, sac});
                    int maxc = max({fc, sc, fac, sac});
                    bool blocked = false;
                    for(int x = minr; x <= maxr; x++) {
                        for(int y = minc; y <= maxc; y++) {
                            if(mat[x][y] == 'H') {
                                blocked = true;
                            }
                        }
                    }
                    if(blocked) {
                        continue;
                    }
                }
                if(mat[far][fac]=='S' && mat[sar][sac]=='S'){
                    return true;
                }else{
                    if(dfs(vis,mat,r,c,far,fac,sar,sac)){
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}
int main()
{
    int m,n;cin>>m>>n;
    vector<vector<char>> mat(m,vector<char>(n));
    vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(2,false)));
    bool fst=false;
    int fr=-1,fc=-1,sr=-1,sc=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='s'){
                if(!fst){
                    fr=i;fc=j;fst=true;
                }else{
                    sr=i;sc=j;
                }
            }
        }    
    }
    bool res=dfs(vis,mat,m,n,fr,fc,sr,sc);
    if(res){
        cout<<"Path Exists"<<endl;
    }else{
        cout<<"No such path exists."<<endl;
    }
    return 0;
}
