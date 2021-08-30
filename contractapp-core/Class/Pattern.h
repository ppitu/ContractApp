//
// Created by ppitu on 29.08.2021.
//

#ifndef CONTRACTAPP_PATTERN_H
#define CONTRACTAPP_PATTERN_H

#include <QString>
#include <QVector>
#include <QMetaType>

class Pattern {
public:
    Pattern();
    void setName(const QString& name);
    QString getName() const;
    void setId(int id);
    int getId() const;

    QVector<QString> mTitles;
    QVector<QString> mParagraphs;

private:
    int mId;
    QString mName;
};

Q_DECLARE_METATYPE(Pattern)

#endif //CONTRACTAPP_PATTERN_H
