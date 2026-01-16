#include "HighscoreManager.h"
#include <fstream>
#include <algorithm>
#include <cstring>

HighscoreManager::HighscoreManager(const std::string& filename)
    : _filename(filename)
{
    Load();
}

void HighscoreManager::Load()
{
    _scores.clear();

    std::ifstream file(_filename, std::ios::binary);
    if (!file.is_open())
        return;

    HighscoreEntry entry;
    while (file.read(reinterpret_cast<char*>(&entry), sizeof(entry)))
    {
        _scores.push_back(entry);
    }
}

void HighscoreManager::Save()
{
    std::ofstream file(_filename, std::ios::binary | std::ios::trunc);
    for (const auto& e : _scores)
    {
        file.write(reinterpret_cast<const char*>(&e), sizeof(e));
    }
}

void HighscoreManager::AddScore(const std::string& name, int score)
{
    HighscoreEntry entry{};

    size_t len = name.size();
    if (len > 15) len = 15;
    for (size_t i = 0; i < len; i++)
        entry.name[i] = name[i];
    entry.name[len] = '\0';

    entry.score = score;

    _scores.push_back(entry);

    std::sort(_scores.begin(), _scores.end(),
        [](const HighscoreEntry& a, const HighscoreEntry& b)
        {
            return a.score > b.score;
        });

    if (_scores.size() > 10)
        _scores.resize(10);

    Save();
}

const std::vector<HighscoreEntry>& HighscoreManager::GetScores() const { return _scores; }
