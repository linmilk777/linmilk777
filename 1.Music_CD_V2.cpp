/*23
23
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10005;
int main()
{
  int m, n, cd[25], dp[maxn];
  bool vis[25][maxn];
  while ( scanf( "%d %d", &m, &n ) != EOF )
  {
    int i, j;
    for ( i = 1 ; i <= n ; i++ )
      scanf("%d", &cd[i]);

    memset( dp, 0, ( m + 1 ) * sizeof( dp[0] ) );
    memset( vis, false, sizeof(vis) ) ;

    /*
    something add....
    */
    for ( i = n ; i >= 1; i --)
    {
      for ( j = m ; j >= cd[i] ; j-- )
      {
        if ( dp[j] < dp[j-cd[i]] + cd[i] )
        {
          dp[j] = dp[j-cd[i]] + cd[i];
          vis[i][j] = true;
        }
      }
    }

    for ( i = 1, j = dp[m] ; i <= n, j > 0 ; i++ )
    {
      if ( vis[i][j] )
      {
        printf("%d ", cd[i]);
        //  printf("%d %d\n", i, j);
        j -= cd[i];
      }
    }

    printf( "sum:%d\n", dp[m] );
  }
  return 0;
}
