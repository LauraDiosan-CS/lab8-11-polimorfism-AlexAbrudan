#include "Utils.h"

vector<string> split_string(string input, char delim)
{
    vector <string> res;
    string buff{ "" };
    for (auto n : input)
    {
        if (n != delim)
            buff += n;
        else
            if (n == delim && buff != "")
            {
                res.push_back(buff);
                buff = "";
            }
    }
    if (buff != "")
        res.push_back(buff);
    return res;
}