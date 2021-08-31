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
    explicit Pattern(int vector_size = 0);
    void setName(const QString& name);
    [[nodiscard]] QString getName() const;
    void setId(int id);
    [[nodiscard]] int getId() const;

    QVector<QString> mTitles;
    QVector<QString> mParagraphs;

private:
    int mId{};
    QString mName;
};

Q_DECLARE_METATYPE(Pattern)

#endif //CONTRACTAPP_PATTERN_H
