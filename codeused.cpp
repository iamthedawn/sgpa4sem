// CG Calculator for Whole Batch
// See the output in RESULT.txt file
#include <bits/stdc++.h>
using namespace std;
map<string, string> names;
vector<string> ids;
#define double long double
map<int, string> get(ifstream &read)
{
    vector<char> vec;
    map<int, string> ans;
    char c = read.get();
    vec.push_back(c);
    int i = 1;
    while (!(read.eof()))
    {
        vec.push_back(c);
        c = read.get();
        if (c == '\n')
        {
            string id, name;
            int j = 0;
            for (j = vec.size() - 6; j >= 0; j--)
                if (vec[j] != '1' && vec[j] != '0' && vec[j] != '2' && vec[j] != '3' && vec[j] != '4' && vec[j] != '5' && vec[j] != '6' && vec[j] != '7' && vec[j] != '8' && vec[j] != '9')
                    name.push_back(vec[j]);
                else
                    break;
            for (; j >= 0; j--)
                if (vec[j] == ' ')
                    break;
                else
                    id.push_back(vec[j]);
            reverse(id.begin(), id.end());
            reverse(name.begin(), name.end());
            names[id] = name;
            ids.push_back(id);
            string str;
            str.push_back(vec[vec.size() - 1]);
            str.push_back(vec[vec.size() - 2]);
            ans[i] = str;
            i += 1;
            vec.clear();
        }
    }
    read.close();
    return ans;
}
map<double, double> fin;
vector<pair<string, int>> courses = {{"MAT102.txt", 3}, {"ECT102.txt", 3}, {"CST102.txt", 3}, {"CST104.txt", 3}, {"HST102.txt", 1}, {"HST104.txt", 2}, {"ECP102.txt", 1}, {"CSP102.txt", 1}, {"CSP112.txt", 2}, {"HSP104.txt", 1}, {"OTD102.txt", 1}};
vector<string> grades = {"AA", "BA", "BB", "CB", "CC", "DC", "DD"};
int main()
{
    freopen("RESULT.html", "w", stdout);
    ifstream read;
    vector<bool> F(176, 0);
    for (int j = 0; j < 11; j++)
    {
        // if (j == 7)
        // continue;
        read.open(courses[j].first);
        map<int, string> ans = get(read);
        int bns = 0, coe = courses[j].second;
        for (int i = 1; i <= 176; i++)
        {
            bool f = 1;
            for (int k = 0; k < grades.size(); k++)
                if (ans[i] == grades[k])
                {
                    bns = (10 - k) * coe;
                    f = 0;
                    break;
                }
            if (f)
            {
                F[i - 1] = 1;
                // cout << j << " " << i << " " << ans[i] << " " << '\n';
            }
            fin[i] += bns;
        }
    }

    vector<pair<float, string>> final(176);
    for (int i = 1; i <= 176; i++)
    {
        final[i - 1].second = names[ids[i - 1]];
        final[i - 1].first = fin[i] / 21;
    }
    sort(final.begin(), final.end());
    int p = 1;
    double u = final[175].first;
    for (int i = 175; i >= 0; i--)
    {
        if (!F[i])
        {
            if (final[i].first != u)
                p++;
            cout << p << " " << final[i].second << " " << final[i].first << " <br>\n";
            u = final[i].first;
        }
    }
    // for (int i = 1; i <= 176; i++)
    // {
    //     cout << "<tr>"
    //          << " ";
    //     cout << " <td>"
    //          << " " << ids[i - 1] << " </td>  "
    //          << "<td>"
    //          << " " << names[ids[i - 1]] << " </td> ";
    //     (!F[i - 1])
    //         ? cout << "<td> " << std::fixed << std::setprecision(3)
    //                << (fin[i] / (21.0000)) << "</td>"
    //                << "</tr>\n"
    //         : cout
    //               << "<td> NA </td>"
    //               << "</tr>\n";
    // }

    return 0;
}
