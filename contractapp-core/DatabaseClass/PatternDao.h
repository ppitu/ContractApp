#ifndef PATTERNDAO_H
#define PATTERNDAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Pattern;

class PatternDao
{
public:
    explicit PatternDao(QSqlDatabase& database);
    void init() const;
    void addPattern(Pattern& pattern) const;
    void updatePattern(const Pattern& pattern) const;
    void removePattern(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Pattern>>> patterns() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // PATTERNDAO_H
