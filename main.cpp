#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printName(int maxIdx, vector<string> lines);
int searchForLongestLine(vector<string> lines);

int main()
{

    vector<string> lines;
    int maxIdx;

    while (!cin.eof())
    {
        string line;
        getline(cin, line);

        if (cin.fail())
        {
            //error
            cout << "ERROR" <<endl;
            break;
        }

        lines.push_back(line);
    }

    maxIdx = searchForLongestLine(lines);

    printName(maxIdx, lines);

    return 0;
}


void printName(int maxIdx, vector<string> lines)
{
    int spaceNr = 0;
    for(int idx=0; idx<lines.size(); ++idx)
    {
        if( lines.at(idx).size()<lines.at(maxIdx).size() )
        {
            spaceNr = lines.at(maxIdx).size() - lines.at(idx).size();
            for(int sIdx=0; sIdx<spaceNr/2; ++sIdx)
            {
                cout<<" ";
            }
            cout<<lines.at(idx);
            for(int sIdx=0; sIdx<spaceNr/2; ++sIdx)
            {
                cout<<" ";
            }
            cout<<endl;
        } else
        {
            cout<<lines.at(idx)<<endl;
        }
    }
}


int searchForLongestLine(vector<string> lines)
{
    int longestIdx = 0;
    for(int idx=1; idx<lines.size(); ++idx)
    {
        if( lines.at(idx).size()>lines.at(longestIdx).size() )
        {
            longestIdx = idx;
        }
    }
    //cout<<"longest: "<<longestIdx<<endl;
    return longestIdx;
}
