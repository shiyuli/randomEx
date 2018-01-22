#include <string>
#include <map>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#define random()(rand()%100/100.0)

class randomEx
{
public:
    randomEx(std::map<std::string, float> _map)
    {
        inMap = _map;
    }

    std::string get()
    {
        std::map<std::string, float>::iterator it;

        std::string keyArr[inMap.size()];
        float valueArr[inMap.size()+1] = {0};

        int i(0);
        for(it = inMap.begin(); it != inMap.end(); ++it)
        {
            if(i <= inMap.size())
            {
                keyArr[i] = it->first;
            }

            valueArr[i+1] = it->second + valueArr[i];
            i++;
        }

        // srand((int)time(NULL));

        float probability = random();

        // std::cout << probability << std::endl;

        for(int i(0); i < sizeof(valueArr)/sizeof(float) - 1; ++i)
        {
            if(valueArr[i] < probability && probability <= valueArr[i+1])
            {
                return keyArr[i];
            }
            // std::cout << valueArr[i] << ", " << valueArr[i+1] << std::endl;
        }
    }

private:
    std::map<std::string, float> inMap;
};

int main()
{
    std::map<std::string, float> inMap;

    inMap.insert(std::pair<std::string, float>("A", 0.2));
    inMap.insert(std::pair<std::string, float>("B", 0.3));
    inMap.insert(std::pair<std::string, float>("C", 0.5));

    randomEx *r = new randomEx(inMap);

    int nA(0);
    int nB(0);
    int nC(0);
    float total(1000);

    for(int i(0); i < total; ++i)
    {
        const std::string result = r->get();

        if(result == "A")
        {
            nA++;
        }
        else if(result == "B")
        {
            nB++;
        }
        else if(result == "C")
        {
            nC++;
        }
    }

    std::cout << "A: " << nA/total << std::endl;
    std::cout << "B: " << nB/total << std::endl;
    std::cout << "C: " << nC/total << std::endl;
    system("pause");

    delete r;
    r = NULL;

    return 0;
}
