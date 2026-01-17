#pragma once
#include <vector>
#include <string>

struct HighscoreEntry
{
    char name[16];
    int score;
};

class HighscoreManager
{
private:
    std::vector<HighscoreEntry> _scores;
    std::string _filename;

public:
    HighscoreManager(const std::string& filename);

    void Load();
    void Save();

    void AddScore(const std::string& name, int score);
    const std::vector<HighscoreEntry>& GetScores() const;
};