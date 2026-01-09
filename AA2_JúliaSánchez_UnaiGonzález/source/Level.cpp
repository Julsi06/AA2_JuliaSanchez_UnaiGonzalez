#include "Level.h"
#include <fstream>
#include <iostream>
#include "Vector2.h"

static float ReadFloat(const std::string& line)
{
    return std::stof(line.substr(
        line.find(">") + 1,
        line.find("</") - line.find(">") - 1));
}

static int ReadInt(const std::string& line)
{
    return std::stoi(line.substr(
        line.find(">") + 1,
        line.find("</") - line.find(">") - 1));
}

Level LoadLevelFromFile(const std::string& path)
{
    Level level;
    std::ifstream file(path);

    if (!file.is_open())
    {
        std::cout << "ERROR: FILE NOT OPENED" << std::endl;
        return level;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.find("<wave>") != std::string::npos)
        {
            WaveData wave;
            while (std::getline(file, line) && line.find("</wave>") == std::string::npos)
            {
                if (line.find("<spawned_enemy_id>") != std::string::npos)
                    wave.enemyType = static_cast<EnemyType>(ReadInt(line));

                else if (line.find("<duration>") != std::string::npos)
                    wave.duration = ReadFloat(line);

                else if (line.find("<amount>") != std::string::npos)
                    wave.amount = ReadInt(line);

                else if (line.find("<positions>") != std::string::npos)
                {
                    while (std::getline(file, line) && line.find("</positions>") == std::string::npos)
                    {
                        if (line.find("<position>") != std::string::npos)
                        {
                            Vector2 pos;
                            std::getline(file, line); pos.x = ReadFloat(line);
                            std::getline(file, line); pos.y = ReadFloat(line);

                            wave.positions.push_back(pos);

                            while (std::getline(file, line) && line.find("</position>") == std::string::npos)
                                ;
                        }
                    }
                }
            }

            level.waves.push_back(wave);
        }
    }

    std::cout << "LEVEL WAVES: " << level.waves.size() << "\n";
    return level;
}