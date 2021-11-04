#include "PatternDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>

#include "Database/DatabaseManager.h"

#include "Class/Pattern.h"

PatternDao::PatternDao(QSqlDatabase &database) :
    mDatabase(database)
{

}

void PatternDao::init() const
{
    if(!mDatabase.tables().contains("pattern"))
        {
            QSqlQuery query(mDatabase);
            query.exec("CREATE TABLE pattern (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(50), T1 VARCHAR(20)," \
            "T2 VARCHAR(20), T3 VARCHAR(20), T4 VARCHAR(20), T5 VARCHAR(20), T6 VARCHAR(20), T7 VARCHAR(20), T8 VARCHAR(20)," \
            "T9 VARCHAR(20), T10 VARCHAR(20), T11 VARCHAR(20), T12 VARCHAR(20), P1 VARCHAR(200), P2 VARCHAR(200), P3 VARCHAR(200)," \
            "P4 VARCHAR(200), P5 VARCHAR(200), P6 VARCHAR(200), P7 VARCHAR(200), P8 VARCHAR(200), P9 VARCHAR(200), P10 VARCHAR(200)," \
            "P11 VARCHAR(200), P12 VARCHAR(200))");
        }
}

void PatternDao::addPattern(Pattern &pattern) const
{
    QSqlQuery query(mDatabase);
        query.prepare("INSERT INTO pattern (name, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) " \
        "VALUES (:name, :t1, :t2, :t3, :t4, :t5, :t6, :t7, :t8, :t9, :t10, :t11, :t12, :p1, :p2, :p3, :p4, :p5, :p6, :p7, :p8, :p9, :p10, :p11, :p12)");
        query.bindValue(":name", pattern.getName());
        for(int i = 0; i < 12; ++i)
        {
            if(i >= pattern.getTitlesSize())
            {
                query.bindValue(":t" + QString::number(i + 1), "");
                query.bindValue(":p" + QString::number(i + 1), "");
            } else
            {
                query.bindValue(":t" + QString::number(i + 1), pattern.getTitle(i));
                query.bindValue(":p" + QString::number(i + 1), pattern.getParagraph(i));
            }
        }

        query.exec();
        pattern.setId(query.lastInsertId().toInt());
        DatabaseManager::debugQuery(query);
}

void PatternDao::updatePattern(const Pattern &pattern) const
{
    QSqlQuery query(mDatabase);
        query.prepare("UPDATE pattern SET name = (:name), T1 = (:t1), T2 = (:t2), T3 = (:t3), T4 = (:t4), T5 = (:t5),"\
        "T6 = (:t6), T7 = (:t7), T8 = (:t8), T9 = (:t9), T10 = (:t10), T11 = (:t11), T12 = (:t12), P1 = (:p1),  P2 = (:p12),"\
        " P3 = (:p3), P4 = (:p4), P5 = (:p5), P6 = (:p6), P7 = (:p7), P8 = (:p8), P9 = (:p9), P10 = (:p10), P11 = (:p11), P12 = (:p12)");
        query.bindValue(":name", pattern.getName());
        for(int i = 0; i < 12; ++i)
        {
            if(i >= pattern.getTitlesSize())
            {
                query.bindValue(":t" + QString::number(i + 1), "");
                query.bindValue(":p" + QString::number(i + 1), "");
            } else
            {
                query.bindValue(":t" + QString::number(i + 1), pattern.getTitle(i));
                query.bindValue(":p" + QString::number(i + 1), pattern.getParagraph(i));
            }
        }

        query.exec();
        DatabaseManager::debugQuery(query);
}

void PatternDao::removePattern(int id) const
{
    QSqlQuery query(mDatabase);
        query.prepare("DELETE FROM pattern WHERE id = (:id)");
        query.bindValue(":id", id);
        query.exec();
        DatabaseManager::debugQuery(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Pattern> > > PatternDao::patterns() const
{
    QSqlQuery query("SELECT * FROM pattern");
        query.exec();
        DatabaseManager::debugQuery(query);

        std::unique_ptr<std::vector<std::unique_ptr<Pattern>>> list(new std::vector<std::unique_ptr<Pattern>>());
        while(query.next())
        {
            std::unique_ptr<Pattern> pattern(new Pattern());
            pattern->setId(query.value("id").toInt());
            pattern->setName(query.value("name").toString());
            for(int i = 0; i < 12; i++)
            {
                pattern->addTitle(query.value("T" + QString::number(i + 1)).toString());
                pattern->addParagraph(query.value("P" + QString::number(i + 1)).toString());
            }
            list->push_back(std::move(pattern));
        }

        return list;
}
