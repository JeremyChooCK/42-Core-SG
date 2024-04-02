#include "main.hpp"

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string s1(av[2]);
        std::string s2(av[3]);
        std::ifstream src(av[1]);
        std::string dstFileName = std::string(av[1]) + ".replace";
        std::ofstream dst(dstFileName);

        if (!src.is_open())
        {
            std::cout << "Error: could not open file" << std::endl;
            return (1);
        }
        if (!dst.is_open())
        {
            std::cout << "Error: could not open file" << std::endl;
            return (1);
        }
        std::string line;
        while (std::getline(src, line))
        {
            size_t pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            dst << line << std::endl;
        }
        src.close();
        dst.close();
    }
}