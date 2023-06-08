#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define pbds tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

void treeTCgenerator()
{
    ll numberOfNodes = 1e5;

    srand(time(0));

    cout << numberOfNodes << "\n";

    pbds includedInTree;
    pbds notIncludedInTree;

    ll root = 1;//almost centroid

    //uncomment the below line to create random root
    //root = ((ll) rand() * rand()) % n + 1;

    includedInTree.insert(root);

    for (ll i = 1; i <= numberOfNodes; i++)
    {
        if(i != root){
            notIncludedInTree.insert(i);
        }
    }
    
    for (ll i = 0; i < numberOfNodes - 1; i++)
    {
        ll r = rand();
        ll incSize = includedInTree.size();

        r %= incSize;

        auto itU = includedInTree.find_by_order(r);
        ll u = *itU;

        r = rand();
        
        ll notIncSize = notIncludedInTree.size();

        r %= notIncSize;

        auto itV = notIncludedInTree.find_by_order(r);
        ll v = *itV;

        notIncludedInTree.erase(itV);
        includedInTree.insert(v);

        cout << u << " " << v << "\n";
    }
}
