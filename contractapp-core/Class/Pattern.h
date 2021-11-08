#ifndef PATTERN_H
#define PATTERN_H

#include <QString>
#include <QVector>
#include <QMetaType>

#include "contractapp-core_global.h"

class CONTRACTAPPCORE_EXPORT Pattern
{
public:
    explicit Pattern(int vector_size = 0);
    void setName(const QString& name);
    void setId(int id);
    QString getName() const;
    int getId() const;

    void removeTitle();
    void addTitle(const QString& value);
    void removeParagraph();
    void addParagraph(const QString& value);
    void setParagraph(int index, const QString& value);
    int getTitlesSize() const;
    int getParagraphsSize() const;
    QString getParagraph(int index) const;
    QString getTitle(int index) const;
    void clear();

private:
    int mId{};
    QString mName{};
    QVector<QString> mTitles;
    QVector<QString> mParagraphs;
};

Q_DECLARE_METATYPE(Pattern);

#endif // PATTERN_H
