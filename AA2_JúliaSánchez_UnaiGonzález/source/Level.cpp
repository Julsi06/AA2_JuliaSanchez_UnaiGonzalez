#include "Level.h"
#include <fstream>
#include <iostream>

Level LoadLevelFromFile(const std::string& path)
{
    Level level;
    std::ifstream file(path);

    std::cout << "Trying to open file: " << path << std::endl;

    if (!file.is_open())
    {
        std::cout << "ERROR: FILE NOT OPENED" << std::endl;
        return level;
    }

    std::cout << "FILE OPENED OK" << std::endl;


    std::string line;

    while (std::getline(file, line))
    {
        if (line.find("<wave>") != std::string::npos)
        {
            WaveData wave;
            wave.amount = 0;
            wave.enemyType = EnemyType::AMOEBA;

            std::getline(file, line);
            if (line.find("<spawned_enemy_id>") != std::string::npos)
            {
                int id = std::stoi(
                    line.substr(
                        line.find(">") + 1,
                        line.find("</") - line.find(">") - 1
                    )
                );
                wave.enemyType = static_cast<EnemyType>(id);
            }

            std::getline(file, line);
            if (line.find("<amount>") != std::string::npos)
            {
                wave.amount = std::stoi(
                    line.substr(
                        line.find(">") + 1,
                        line.find("</") - line.find(">") - 1
                    )
                );
            }

            level.waves.push_back(wave);
        }
    }

    file.close();
    return level;
}