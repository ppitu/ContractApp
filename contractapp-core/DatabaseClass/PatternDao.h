//
// Created by ppitu on 29.08.2021.
//

#ifndef CONTRACTAPP_PATTERNDAO_H
#define CONTRACTAPP_PATTERNDAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Pattern;

class PatternDao {
public:
    explicit PatternDao(QSqlDatabase& database);
    void init() const;
    void addPattern(Pattern& pattern) const;
    [[nodiscard]] std::unique_ptr<std::vector<std::unique_ptr<Pattern>>> patterns() const;

private:
    QSqlDatabase& mDatabase;
};


#endif //CONTRACTAPP_PATTERNDAO_H
