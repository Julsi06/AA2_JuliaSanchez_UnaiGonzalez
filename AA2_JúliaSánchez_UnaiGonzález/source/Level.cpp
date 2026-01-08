#include "Level.h"
#include <fstream>
#include <iostream>

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

                else if (line.find("<amount>") != std::string::npos)
                    wave.amount = ReadInt(line);

                else if (line.find("<startX>") != std::string::npos)
                    wave.startX = ReadFloat(line);

                else if (line.find("<startY>") != std::string::npos)
                    wave.startY = ReadFloat(line);

                else if (line.find("<spacingX>") != std::string::npos)
                    wave.spacingX = ReadFloat(line);

                else if (line.find("<spacingY>") != std::string::npos)
                    wave.spacingY = ReadFloat(line);

                else if (line.find("<startYTop>") != std::string::npos)
                    wave.startYTop = ReadFloat(line);

                else if (line.find("<startYBottom>") != std::string::npos)
                    wave.startYBottom = ReadFloat(line);

                else if (line.find("<minY>") != std::string::npos)
                    wave.minY = ReadFloat(line);

                else if (line.find("<maxY>") != std::string::npos)
                    wave.maxY = ReadFloat(line);

                else if (line.find("<minSpacingX>") != std::string::npos)
                    wave.minSpacingX = ReadFloat(line);

                else if (line.find("<maxSpacingX>") != std::string::npos)
                    wave.maxSpacingX = ReadFloat(line);
                
                else if (line.find("<velocity>") != std::string::npos)
                    wave.velocity = ReadFloat(line);

                else if (line.find("<positions>") != std::string::npos &&
                    wave.enemyType == EnemyType::AMOEBA)
                {
                    while (std::getline(file, line) && line.find("</positions>") == std::string::npos)
                    {
                        if (line.find("<position>") != std::string::npos)
                        {
                            AmoebaSpawnData data;

                            std::getline(file, line); data.position.x = ReadFloat(line);
                            std::getline(file, line); data.position.y = ReadFloat(line);

                            std::getline(file, line);
                            data.separateDir.x = std::stof(line.substr(line.find("x=\"") + 3));
                            data.separateDir.y = std::stof(line.substr(line.find("y=\"") + 3));

                            std::getline(file, line);
                            data.groupDir.x = std::stof(line.substr(line.find("x=\"") + 3));
                            data.groupDir.y = std::stof(line.substr(line.find("y=\"") + 3));

                            wave.amoebaData.push_back(data);
                        }
                    }
                }

                else if (line.find("<positions>") != std::string::npos &&
                    wave.enemyType == EnemyType::BEHOLDER)
                {
                    while (std::getline(file, line) && line.find("</positions>") == std::string::npos)
                    {
                        if (line.find("<position>") != std::string::npos)
                        {
                            BeholderSpawnData data;

                            std::getline(file, line); data.position.x = ReadFloat(line);
                            std::getline(file, line); data.position.y = ReadFloat(line);

                            std::getline(file, line);
                            data.dir.x = std::stof(line.substr(line.find("x=\"") + 3));
                            data.dir.y = std::stof(line.substr(line.find("y=\"") + 3));

                            wave.beholderData.push_back(data);
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