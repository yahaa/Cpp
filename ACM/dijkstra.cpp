//Dijkstra　　　未优化版本

//适用于　　单源且边权值为非负　　有向无向都可以


void Dijkstra(int s, int n){      //把图上的所有点分为　　走过　　　和　　未走过   两个集合
    for (int i = 0; i < n; i++)dis[i] = INF;
    for (int i = 0; i < n; i++) vis[i] = 0;
    dis[s] = 0;   //起点到自己的距离当然为０，dijkstra求的即为起点到所有点的最短路
                  //第一步未走过的集合只有起点
    for (int i = 0; i < n; i++){
        int x;
        int min_dis=INF;
        for (int j = 0; j < n; j++){    //在走过的集合中找到链接到未走过的集合的点的距离最短的点
            if (!vis[j] && dis[j] <=min_dis){
                x = j;
                min_dis = dis[j];
            }
        }
            vis[x] = 1;     //标记为已走过，即加入一走集合中
            
            for (int j = 0; j < n; j++){//更新起点到每一个点的距离
                dis[j]=min(dis[j], dis[x] + G[x][j]);
            }
        }
}


/*1)算法思想：设G=(V,E)是一个带权有向图，把图中顶点集合V分成两组，
第一组为已求出最短路径的顶点集合（用S表示，初始时S中只有一个源点，
以后每求得一条最短路径 , 就将加入到集合S中，直到全部顶点都加入到S中，算法就结束了），
第二组为其余未确定最短路径的顶点集合（用U表示），按最短路径长度的递增次序依次
把第二组的顶点加入S中。在加入的过程中，总保持从源点v到S中各顶点的最短路径长度不大于从源点v到U中任何顶点的最短路径长度。
此外，每个顶点对应一个距离，S中的顶点的距离就是从v到此顶点的最短路径长度，
U中的顶点的距离，是从v到此顶点只包括S中的顶点为中间顶点的当前最短路径长度。

2)算法步骤：

a.初始时，S只包含源点，即S＝{v}，v的距离为0。U包含除v外的其他顶点，
即:U={其余顶点}，若v与U中顶点u有边，则<u,v>正常有权值，若u不是v的出边邻接点，则<u,v>权值为∞。

b.从U中选取一个距离v最小的顶点k，把k，加入S中（该选定的距离就是v到k的最短路径长度）。

c.以k为新考虑的中间点，修改U中各顶点的距离；若从源点v到顶点u的距离（经过顶点k）比原来距离（不经过顶点k）短，
则修改顶点u的距离值，修改后的距离值的顶点k的距离加上边上的权。

d.重复步骤b和c直到所有顶点都包含在S中。*/